import os

def compile():
    os.system("make")

    for fileName in os.listdir("tests"):
        if(fileName.endswith(".cmm")):
            os.system("./rx-cc tests/" + fileName)
    n = 1
    while(True):
        files = ""
        for fileName in os.listdir("tests"):
            if(fileName.endswith(".rsk") and str(n) in fileName):
                files = files + " tests/" + fileName
        if(files == ""):
            break
        os.system("./rx-linker " + files)
        os.system("cp out.e tests/out" + str(n) + ".e")
        n = n + 1

def runTests():
    for fileName in os.listdir("tests"):
        if(fileName.endswith(".e")):
            os.system("./rx-vm1.1 tests/" + fileName)

if __name__ == "__main__":
    compile()
    if (raw_input("Run executables? y/N").lower() == "y"):
        runTests()
