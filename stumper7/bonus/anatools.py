#!/bin/python3
import sys

def help():
    print("Bienvenus dans anatools")
    print("\t-i <text>\t\tvous renvois toutes les combinaisons possible.")
    print("\t-a <text> <text>\tvous dira si le deux sequences sont des anagram (-ai case sensitive)")
    print("\t-p <text>\t\t vous dira si votre séquence et un palindrome")

def permit(elt: str):
    if len(elt) <= 1:
        yield elt
    else:
        for p in permit(elt[1:]):
            for i in range(len(elt)):
                yield p[:i] + elt[0:1] + p[i:]

def anagram(a: str, b: str) -> bool:
    return sorted(a.lower()) == sorted(b.lower())

def anagrami(a: str, b: str) -> bool:
    return sorted(a) == sorted(b)

def palindrome(a: str):
    return a == a[::-1]

def main() -> None:
    try:
        if (sys.argv[1] == "-h"): help()
        if (sys.argv[1] == "-i"): print('\n'.join(list(permit(sys.argv[2]))))
        if (sys.argv[1] == "-a"): print("Oui" if anagram(sys.argv[2], sys.argv[3]) else "Non")
        if (sys.argv[1] == "-ai"): print("Oui" if anagrami(sys.argv[2], sys.argv[3]) else "Non")
        if (sys.argv[1] == "-p"): print("Oui" if palindrome(sys.argv[2]) else "Non")
    except IndexError:
        print("il manque des arguments, -h pour plus d'info")
    except Exception as e:
        print("Error ", e)

if __name__ == '__main__':
    main()
