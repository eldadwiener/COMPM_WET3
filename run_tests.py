#!/usr/bin/python
import os
import glob
import re

def compile():
    os.system("make")
    # compile success examples
    for fileName in sorted(glob.glob("./tests/example*.cmm"), key = lambda x: (int(re.sub('\D','',x)),x)):
        print("Compiling " + fileName)
        os.system("./rx-cc " + fileName)
    print("")
    # compile fail examples
    print("\nCompiling failexamples, these should all fail to compile\n")
    for fileName in sorted(glob.glob("./tests/fail*.cmm"), key = lambda x: (int(re.sub('\D','',x)),x)):
        print("Compiling " + fileName)
        os.system("./rx-cc " + fileName)
    print("")
    n = 1
    while(True):
        isTestNFile = re.compile("[^0-9]*" + str(n) + "[^0-9]*\.rsk")
        files = ""
        for fileName in os.listdir("tests"):
            if(isTestNFile.match(fileName) is not None):
                files = files + " tests/" + fileName
        if(files == ""):
            break
        print("Linking test number " + str(n) + ", Files: " + files)
        os.system("./rx-linker " + files)
        os.system("cp out.e tests/example" + str(n) + ".e")
        n = n + 1

def runTests(n = -1, auto = False):
    if (n == -1):
        for fileName in sorted(glob.glob("./tests/*.e"), key = lambda x: (int(re.sub('\D','',x)),x)):
            print("Running " + fileName)
            if ( auto == False ):
                os.system("./rx-vm1.1 " + fileName)
            else :
                inName = fileName[0:-1] + "in"
                outName = fileName[0:-2] + ".myout"
                if ( inName in glob.glob("./tests/*.in") ):
                    os.system("./rx-vm1.1 " + fileName + " <" + inName + " >" + outName)
                else:
                    os.system("./rx-vm1.1 " + fileName + " >" + outName)

    else:
        os.system("./rx-vm1.1 tests/example" + str(n) + ".e")

def diff():
    for fileName in sorted(glob.glob("./tests/*.myout"), key = lambda x: (int(re.sub('\D','',x)),x)):
        print("Running diff for " + fileName[0:-6])
        os.system("diff " + fileName + " " + fileName[0:-5] + "out")

def clearCompiledFiles():
    os.system("rm tests/*\.rsk")
    os.system("rm tests/*\.e")
    os.system("rm tests/*\.myout")

if __name__ == "__main__":
    clearCompiledFiles()
    compile()
    n = raw_input("Run executables? y/n (enter test # for a specific test)").lower()
    if (n == "y"):
        auto = raw_input("Run automatically with diff? y/n (some tests take user input otherwise)")
        runTests(auto = (auto == "y"))
        diff()
    else:
        try:
            runTests(n = int(n))
        except:
            pass
