#!/bin/python3

import subprocess
from random import randint as rd
import os


class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


tests = [
    "", "", [], "",
    "test : %c", "test : a", ['a'], "",
    "test : %%", "test : %", [], "",
    "test : %46", "test : %46", [], "",
    "Hello World!\\n", "Hello World!\n", [], "",
    "%s", "Nilson Musk", ["Nilson Musk"], "",
    "je %S", "je test \\006 \\006", ["test \\6 \\6"], "",
    "test : %d", "test : 30", [30], "",
    "test : %d", "test : -30", [-30], "",
    "test : %x", "test : 1e", [30], "",
    "test : %X", "test : 1E", [30], "",
    "test : %o", "test : 36", [30], "",
    "test : %#x", "test : 0x1e", [30], "",
    "test : %#X", "test : 0X1E", [30], "",
    "test : %#o", "test : 036", [30], "",
    "test : %S", "test : \\035 \\036", ["var:str"], """char str[] = "0 0";str[0] = 29; str[2] = 30;""",
    "test : %d", "test : 2147483647", [2147483647], "",
    "test : %ld", "test : 4294967294", [4294967294], "",
]


def makefile(string, param, extra):
    file1 = """void my_printf(char *buf, ...);int main(void){"""
    file2 = """my_printf("""
    file3 = """);return 0;}"""
    string = '"'+string+'"'
    for elt in param:
        if isinstance(elt, int):
            string += ', ' + str(elt)
        elif "var:" in elt:
            string += ", " + elt[4:]
        elif len(elt) == 1:
            string += ", '" + elt + "'"
        else:
            string += ', "' + elt + '"'
    open('main.c', 'w+').write(file1 + extra + file2 + string + file3)


def main():
    PASSED = 0
    FAILED = 0
    for index in range(0, len(tests), 4):
        makefile(tests[index], tests[index + 2], tests[index + 3])
        command = "make && make clean; gcc main.c -L. -Iinclude/ -lmy;"
        subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        command = "./a.out"
        result = subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        command = "make fclean"
        subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        if os.path.exists("a.out"):
            os.remove("a.out")
        try:
            out = result.stdout.decode("utf8") if result.stdout else ""
            err = result.stderr.decode("utf8") if result.stderr else ""
            if out == tests[index+1]:
                print(f"{bcolors.OKGREEN}{index//4} => PASSED {bcolors.ENDC}")
                PASSED += 1
            else:
                print(f"{bcolors.FAIL}{index//4} => FAILED{bcolors.ENDC}")
                print(f"==(main)=> {open('main.c').read()} ==(out)=> {out} ==(err)=> {err}")
                FAILED += 1
        except Exception as e:
            print(f"{bcolors.FAIL}{index//4} => FAILED{bcolors.ENDC}")
            print(f"main.c => {open('main.c').read()} ==(err)=> {result.stderr}")
            FAILED += 1
        if os.path.exists("main.c"):
            os.remove("main.c")
    print(f"\n {bcolors.OKGREEN}PASSED => {PASSED}{bcolors.ENDC}    {bcolors.FAIL}FAILED => {FAILED}{bcolors.ENDC}")


if __name__ == '__main__':
    main()

# -     Left justify.                                    //TODO
# 0  	  Field is padded with 0's instead of blanks.       //TODO
# +	  Sign of number always O/P.                        //TODO
# blank  Positive values begin with a blank.
# # 	  Various uses:
#     %#o (Octal) 0 prefix inserted.                      //TODO
#     %#x (Hex)   0x prefix added to non-zero values.     //TODO
#     %#X (Hex)   0X prefix added to non-zero values.     //TODO
