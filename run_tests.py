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
        os.system("cp out.e tests/out" + str(n) + ".e")
        n = n + 1

def runTests(n = -1):
    if (n == -1):
        for fileName in sorted(glob.glob("./tests/*.e"), key = lambda x: (int(re.sub('\D','',x)),x)):
            print("\nRunning " + fileName)
            os.system("./rx-vm1.1 " + fileName)
    else:
        os.system("./rx-vm1.1 tests/out" + str(n) + ".e")

def clearCompiledFiles():
    os.system("rm tests/*\.rsk")
    os.system("rm tests/*\.e")

if __name__ == "__main__":
    clearCompiledFiles()
    compile()
    n = raw_input("Run executables? y/n (enter test # for a specific test)").lower()
    if (n == "y"):
        runTests()
    else:
        try:
            runTests(int(n))
        except:
            pass
