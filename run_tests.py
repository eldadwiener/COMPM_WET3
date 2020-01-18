import os

def compile():
    os.system("make")

    for fileName in os.listdir("tests"):
        if(fileName.endswith(".cmm")):
            print("Compiling " + fileName)
            os.system("./rx-cc tests/" + fileName)
    n = 1
    while(True):
        files = ""
        for fileName in os.listdir("tests"):
            if(fileName.endswith(".rsk") and str(n) in fileName):
                files = files + " tests/" + fileName
        if(files == ""):
            break
        print("Linking test number " + str(n))
        os.system("./rx-linker " + files)
        os.system("cp out.e tests/out" + str(n) + ".e")
        n = n + 1

def runTests(n = -1):
    if (n == -1):
        for fileName in os.listdir("tests"):
            if(fileName.endswith(".e")):
                print("\nRunning " + fileName)
                os.system("./rx-vm1.1 tests/" + fileName)
    else:
        os.system("./rx-vm1.1 tests/out" + str(n) + ".e")

if __name__ == "__main__":
    compile()
    n = raw_input("Run executables? y/n (enter test # for a specific test)").lower()
    if (n == "y"):
        runTests()
    else:
        try:
            runTests(int(n))
        except:
            pass
