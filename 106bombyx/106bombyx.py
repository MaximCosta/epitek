#!/usr/bin/env python3
##
## EPITECH PROJECT, 2022
## 106bombyx
## File description:
## 106bombyx
##

import sys

def help(av):
    if (len(av) == 2 and av[1] == "-h"):
        print("""USAGE
    ./106bombyx n [k | i0 i1]
DESCRIPTION
    n       number of first generation individuals
    k       growth rate from 1 to 4
    i0      initial generation (included)
    i1      final generation (included)""")
        sys.exit(0)

def growth(av):
    try:
        n = float(sys.argv[1])
        k = float(sys.argv[2])
    except ValueError:
        print("Wrong argument type")
        sys.exit(84)
    for i in range(100):
        print(i + 1, '%.2f' % n)
        n = k * n * ((1000 - n) / 1000)
        if (n < 0):
            sys.exit(84)

def scheme(av):
    try:
        n = int(sys.argv[1])
        k1 = int(sys.argv[2])
        k2 = int(sys.argv[3])
    except ValueError:
        print("Wrong argument type")
        sys.exit(84)
    k = 1.00
    while k < 4.00:
        for i in range(1, k1):
            n = k * n * ((1000 - n) / 1000)
            if (n < 0):
                sys.exit(84)
        for i in range(k2 - k1 + 1):
            print('%.2f' % k, '%.2f' % n)
            n = k * n * ((1000 - n) / 1000)
            if (n < 0):
                sys.exit(84)
        k += 0.01
    return (0)

def error_handler(av):
    if (int(av[1]) < 0):
        sys.exit(84)
    if (int(av[2]) < 0):
        sys.exit(84)
    if (len(av) == 4):
        if (int(av[3]) < 0):
            sys.exit(84)

def main():
    help(sys.argv)
    error_handler(sys.argv)
    if (len(sys.argv) == 3):
        growth(sys.argv)
    if (len(sys.argv) == 4):
        scheme(sys.argv)
if __name__ == "__main__":
    sys.exit(main())