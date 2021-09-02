#!/usr/bin/env python
# coding=utf-8
import xlrd
import xlwt
import json
import os.path
from os import listdir
from os.path import isfile, join

keyrowidx = 4
protodir = "cpp/"
xlsdir = "xlsx/"

def getColNames(sheet):
        rowSize = sheet.row_len(keyrowidx)
        colValues = sheet.row_values(keyrowidx, 0, rowSize )
        columnNames = []
        for value in colValues:
                columnNames.append(value)
        return columnNames

def getRowData(row, columnNames):
        rowData = {}
        counter = 0
        for cell in row:
                if columnNames[counter].strip() != "key":
                        counter +=1
                        continue
                rowData[str(cell.value)] = cell.value
                counter +=1
        return rowData

def getSheetData(sheet, columnNames):
        nRows = sheet.nrows
        sheetData = []
        row = sheet.row(0)
        rowData = getRowData(row, columnNames)
        sheetData.append(rowData)

        return sheetData

def getWorkBookData(workbook):
        nsheets = workbook.nsheets
        workbookdata = {}
        for idx in range(0, nsheets):
                worksheet = workbook.sheet_by_index(idx)
                columnNames = getColNames(worksheet)
                sheetdata = getSheetData(worksheet, columnNames)
                workbookdata[worksheet.name] = sheetdata

        return workbookdata

def getcpph(datastring, sheetname):
        s = "#include <memory>\n"
        s += "#include <umordered_map>\n"
        s += '#include "%s.pb.h; \n' % (sheetname)
        s += 'class %sconfig\n{\npublic:\n' % (sheetname)
        s += '  using rowptr = const %s_row*;\n'% (sheetname)
        s += '  using keydatastype = std::umordered_map<uint32, rowptr>;\n'
        s += '  void load();\n'
        s += '  rowptr key_id(uint32 keyid);\n'
        counter = 0
        pd = ''
        for d in datastring:
                for v in d.values():
                        s += '  rowptr key_%s(uint32 keyid)const;\n' % (v) 
                        pd += ' keydatastype key_data_%s_\n'%(counter)
                        counter += 1
        s += 'private:\n %s_table data_;\n' % (sheetname)
        s += ' keydatastype key_data_;\n'
        s += pd
        s += '};\n'
        return s;

def getcpp(datastring, sheetname):
        s = '#include "%s_config.h; \n' % (sheetname)
        s += 'void %sconfig::load()\n{\n data_.clear();\n' % (sheetname)
        s += ' auto contents = File2String(filename);\n'
        s += ' google::protobuf::StringPiece sp(contents.data(), contents.size());\n'
        s += ' google::protobuf::util::JsonStringToMessage(sp, &key_data_);\n'
        
        s += ' for (int32_t i = 0; i < data_.data_size(); ++i)\n {\n'
        s += '   auto& d = data_.data(i);\n'
        counter = 0
        for d in datastring:
                for v in d.values(): 
                        s += '   key_data_%s_.clear();\n' % (counter) 
                        counter += 1
                s += ' }\n'

        s += ' for (int32_t i = 0; i < data_.data_size(); ++i)\n {\n'
        s += '   auto& d = data_.data(i);\n'
        counter = 0
        for d in datastring:
                for v in d.values(): 
                        s += '   key_data_%s_.emplace(d.%s(), &d);\n' % (counter,v) 
                        counter += 1
                s += ' }\n'
        s += '}\n'
        
      
        s += ' const %s_row* key_id(uint32 keyid);\n{\n' % (sheetname)
        s += '  auto it = key_data_.find(keyid);\n  return it == key_data_.end() ? nullptr : it->second;\n}\n'

        counter = 0
        for d in datastring:
                for v in d.values(): 
                        s += 'const %s_row* key_%s(uint32 keyid)\n{\n' % (sheetname,v)
                        s += '  auto it = key_data_%s_.find(keyid);\n  return it == key_data_%s_.end() ? nullptr : it->second;\n}\n'% (counter,counter) 
                        counter += 1
        return s;

def main():
        if not os.path.exists(protodir):
                os.makedirs(protodir) 
        for filename in listdir(xlsdir):
                filename = xlsdir + filename
                if filename.endswith('.xlsx') or filename.endswith('.xls'):
                        workbook = xlrd.open_workbook(filename)
                        workbookdata = getWorkBookData(workbook)
                        for sheetname in workbookdata :
                                outputh = open(protodir + sheetname + "_config.h", "w", encoding="utf-8")
                                s =getcpph(workbookdata[sheetname], sheetname)
                                outputh.write(s)
                                outputh.close()
                                outputcpp = open(protodir + sheetname + "_config.cpp", "w", encoding="utf-8")
                                s =getcpp(workbookdata[sheetname], sheetname)
                                outputcpp.write(s)
                                outputcpp.close()
                       
main()
