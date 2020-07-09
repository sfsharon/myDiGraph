#!/usr/bin/env python
"""
myDiGraphTest.py
Run tests for myDiGraph program
The input vectors are devided between two directories : "noPath" which do not have a path from first to last node, and "Path" who do have a path.
"""

import os
import subprocess
import sys
import time

# ------------------------------------
# Module constants
# ------------------------------------
MY_DI_GRAPH_EXE         = r"../VS_Project/x64/Debug/myDiGraph.exe"
TEST_VECTOR_NO_PATH_DIR = r"../testVectors/noPath"
TEST_VECTOR_PATH_DIR    = r"../testVectors/Path"
LOG_DIR                 = r"../Logs"

# Time constant for log files (manifest, query and debugLog)    
CURR_TIME_STRING = time.strftime("%d_%m_%Y__%H_%M_%S")

print ("*** --------------------------------------------")
print ("*** ---           myDiGraphTest.py           ---")
print ("*** --------------------------------------------")


# ------------------------------------
# Inputs with required path
# ------------------------------------
for filename in os.listdir(TEST_VECTOR_PATH_DIR) :
    fileFullPath = os.path.join(TEST_VECTOR_PATH_DIR, filename)
    myDiGraphTest = subprocess.run([MY_DI_GRAPH_EXE, fileFullPath])
    status = ""
    if myDiGraphTest.returncode == 0 : 
        status = "OK" 
    else :
        staus = "ERROR"        
    print ("*** Tested " + fileFullPath + " " + status)    


# ------------------------------------
# Inputs without required path
# ------------------------------------
for filename in os.listdir(TEST_VECTOR_NO_PATH_DIR) :
    fileFullPath = os.path.join(TEST_VECTOR_NO_PATH_DIR, filename)
    myDiGraphTest = subprocess.run([MY_DI_GRAPH_EXE, fileFullPath])
    status = ""
    if myDiGraphTest.returncode != 0 : 
        status = "OK" 
    else :
        staus = "ERROR"        
    print ("*** Tested " + fileFullPath + " " + status)  
   