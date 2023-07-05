#!/bin/python3

import subprocess
from random import randint as rd
import os
import difflib
import time
import math


class bs:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


tests = os.listdir('./maps-intermediate/mouli_maps')


def main():
    PASSED = 0
    FAILED = 0
    i = []
    for index, file in enumerate(tests):
        command = "make && make clean"
        subprocess.run(
            command,
            shell=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )
        d = time.time()
        command = f"./bsq ./maps-intermediate/mouli_maps/{file}"
        result = subprocess.run(
            command,
            shell=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )
        d = time.time() - d
        command = "make fclean"
        subprocess.run(
            command,
            shell=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )
        try:
            out = result.stdout.decode("utf8") if result.stdout else ""
            err = result.stderr.decode("utf8") if result.stderr else ""
            answer = open(
                f"./maps-intermediate/mouli_maps_solved/{file}").read()
            if out == open(f"./maps-intermediate/mouli_maps_solved/{file}").read():
                print(
                    f"{bs.OKGREEN}{str(index).zfill(len(str(len(tests))))} ==({d:.4f})=> PASSED ==(file)=> {file}{bs.ENDC}")
                PASSED += 1
            else:
                print(
                    f"{bs.FAIL}{str(index).zfill(len(str(len(tests))))} ==({d:.4f})=> FAILED ==(file)=> {file}{bs.ENDC}")
                FAILED += 1
        except Exception as e:
            print(
                f"{bs.FAIL}{str(index).zfill(len(str(len(tests))))} => FAILED ==(file)=> {file}{bs.ENDC}")
            FAILED += 1
    print(
        f"\n {bs.OKGREEN}PASSED => {PASSED}{bs.ENDC}    {bs.FAIL}FAILED => {FAILED}{bs.ENDC}")


if __name__ == '__main__':
    main()
