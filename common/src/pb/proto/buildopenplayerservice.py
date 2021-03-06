import os
from os import system
import md5tool
import shutil
import threading
import _thread
import protofilearray
from multiprocessing import cpu_count

local = threading.local()

local.rpcarry = []
local.servicenames = []
local.playerservice = ''
local.service = ''
local.hfilename = ''
local.playerservice = ''
local.playerservicearray = []
local.fileservice = []

threads = []
local.pkg = ''
cpkg = 'package'
yourcodebegin = '///<<< BEGIN WRITING YOUR CODE'
yourcodeend = '///<<< END WRITING YOUR CODE'
rpcbegin = '///<<<rpc begin'
rpcend = '///<<<rpc end'
tabstr = '    '
cpprpcpart = 2
cppmaxpart = 4
controller = '(EntityPtr& entity'
servicedir = './md5/'
protodir = 'logic_proto/'
playerservicedir = '../../../../gateway_server/src/service'

if not os.path.exists(servicedir):
    os.makedirs(servicedir)

def gen(readfilename, filename):
    fullfilename = servicedir + filename
    newstr =  '#include <unordered_set>\n'
    newstr += 'std::unordered_set<uint32_t> g_open_player_msgids{\n'
    with open(servicedir + readfilename,'r', encoding='utf-8') as file:
        for fileline in file:
            if fileline.find('};') >= 0:
                msgid = fileline.split(',')[1].replace('}', '').replace(';', '')
                newstr += tabstr  + msgid + '};\n'
                break
            elif fileline.find('C2SRequest') >= 0:
                msgid = fileline.split(',')[1].replace('}', '').replace('"', '')
                newstr += tabstr  + msgid + ',\n'
    with open(fullfilename, 'w', encoding='utf-8')as file:
        file.write(newstr)

def md5copy(filename, writedir):
    if not filename.endswith("open_service.cpp"):
        return
    gennewfilename = servicedir + filename
    filenamemd5 = gennewfilename + '.md5'
    error = None
    emptymd5 = False
    if  not os.path.exists(filenamemd5):
        emptymd5 = True
    else:
        error = md5tool.check_against_md5_file(gennewfilename, filenamemd5)              
    fullfilename = writedir + '/' + filename
    if error == None and os.path.exists(fullfilename) and emptymd5 == False:
        return
    print("copy %s ---> %s" % (gennewfilename, fullfilename))
    md5tool.generate_md5_file_for(gennewfilename, filenamemd5)
    shutil.copy(gennewfilename, fullfilename)
def md5copydir():
    for (dirpath, dirnames, filenames) in os.walk(servicedir):
        for filename in filenames:        
            md5copy(filename, '../../../../gateway_server/src/service')

gen('msgmap.cpp', 'open_service.cpp')
md5copydir()
