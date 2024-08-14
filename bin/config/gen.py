#!/usr/bin/env python
# coding=utf-8
import os
import subprocess

import logging
# Set up logging configuration
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

# Create directories if they don't exist
if not os.path.exists("generated/cpp/"):
    os.makedirs("generated/cpp/")
if not os.path.exists("generated/proto/"):
    os.makedirs("generated/proto/")
if not os.path.exists("generated/proto/cpp/"):
    os.makedirs("generated/proto/cpp")
if not os.path.exists("generated/proto/go/"):
        os.makedirs("generated/proto/go/")
if not os.path.exists("generated/json"):
    os.makedirs("generated/json")
if not os.path.exists("../../pkg/config/src/pbc/"):
    os.makedirs("../../pkg/config/src/pbc/")
if not os.path.exists("../../pkg/config/src/"):
    os.makedirs("../../pkg/config/src/")

# Define commands to execute
commands = [
    "python xlstojson.py",
    "python xlstopb.py",
    "python tipxlsxtoproto.py",
    "python operatorxlsxtoproto.py",
    "python xlstocpp.py",
    "python xlstocppid.py",
    "python buildprotocpp.py",
    "python buildprotogo.py",
    "python md5tool.py md5copy ./generated/cpp/ ../../pkg/config/src/",
    "python md5tool.py md5copy ./generated/proto/cpp/ ../../pkg/config/src/pbc/",
    "python md5tool.py md5copy ./generated/proto/go/pb/game/ ../../node/login/pb/game/",
    "python md5tool.py md5copy ./generated/proto/go/pb/game/ ../../node/db/pb/game/",
    "python genxlsmd5.py"
]

# Execute commands and capture return codes
for command in commands:
    try:
        result = subprocess.run(command, shell=True, check=True, capture_output=True, text=True)
        logger.info(result.stdout)
    except subprocess.CalledProcessError as e:
        logger.error(f"Error running command '{command}': {e}")
