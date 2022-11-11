#!/usr/bin/env python
# coding=utf-8
import hashlib
import optparse
import os
import os.path
import sys
import shutil
import md5tool
import genpublic
from os import system

md5str = 'md5/'
protobufdir = '../third_party/protobuf/src/'

commoncppout = 'md5/common_proto/'

srcdir = '../common/src/pb/pbc/'
if not os.path.exists(srcdir):
    os.makedirs(srcdir)

def gen(walkdir, dest_dir, filename):
    if not (filename[-6:].lower() == '.proto'):
        return
    proto_destfilename = walkdir +  filename
    proto_md5_destfilename = md5str + filename + '.md5'
    error = None
    first = False
    if not os.path.exists(proto_md5_destfilename):
        first = True
    else:
        error = md5tool.check_against_md5_file(proto_destfilename, proto_md5_destfilename)
    pbcdir = dest_dir + walkdir.replace('./', '')
    head_destfilename = pbcdir + filename.replace('.proto', '') + '.pb.h'
    cpp_destfilename = pbcdir + filename.replace('.proto', '') + '.pb.cc'
    if error == None and os.path.exists(head_destfilename) and os.path.exists(cpp_destfilename) :
        return
    print('copy %s %s' % (head_destfilename, cpp_destfilename))
    if not os.path.exists(proto_md5_destfilename):
        md5tool.generate_md5_file_for(proto_destfilename, proto_md5_destfilename)
    commond = 'protoc  -I=./ -I=./logic_proto/ -I=./component_proto/ -I=./common_proto/ -I=%s --cpp_out=%s %s' % (protobufdir, dest_dir, proto_destfilename)
    system(commond)

def gen_protoc(walkdir, dest_dir):
    if not os.path.exists(dest_dir):
        os.makedirs(dest_dir)
    for filename in os.listdir(walkdir):
        gen(walkdir, dest_dir, filename)

def genmd5(walkdir):
    for filename in os.listdir(walkdir):
        if not (filename[-6:].lower() == '.proto'):
            continue            
        md5tool.generate_md5_file_for(walkdir + filename, md5str + filename + '.md5')

        
genpublic.makedirs()
gen_protoc('./logic_proto/', '../common/src/pb/pbc/')
gen_protoc('./component_proto/',  '../common/src/pb/pbc/')
gen_protoc('./event_proto/',  '../common/src/pb/pbc/')
gen_protoc('./common_proto/',  '../common/src/pb/pbc/')
genmd5('./component_proto/')
genmd5('./logic_proto/')
genmd5('./event_proto/')
