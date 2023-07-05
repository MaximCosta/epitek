#!/bin/python3
import os

step = [
'''










''',
'''









━━━━━━━━━━━━━━
''',
'''







┏━━━━━━━━━━━━┓
┃            ┃
┗━━━━━━━━━━━━┛
''',
'''
    ┌────╮
    │    ┊
    │
    │
    │
    │
    │ ╱
┏━━━┷━┷━━━━━━┓
┃            ┃
┗━━━━━━━━━━━━┛
''',
'''
    ┌────╮
    │    ┊
    │   😥
    │
    │
    │
    │ ╱
┏━━━┷━┷━━━━━━┓
┃            ┃
┗━━━━━━━━━━━━┛
''',
'''
    ┌────╮
    │    ┊
    │   😥
    │   ╲│╱
    │
    │
    │ ╱
┏━━━┷━┷━━━━━━┓
┃            ┃
┗━━━━━━━━━━━━┛
''',
'''
    ┌────╮
    │    ┊
    │   😥
    │   ╲│╱
    │   ╱│╲
    │
    │ ╱
┏━━━┷━┷━━━━━━┓
┃            ┃
┗━━━━━━━━━━━━┛
'''
]

def main():
    idstep = 0
    word = 'epitech is the best school in the world'
    find = '_______ __ ___ ____ ______ __ ___ _____'
    victory = False
    print('Welcome to the game of hangman')
    print('You have to find the sentence')
    while (not victory):
        os.system('clear')
        print(step[idstep])
        print(find)
        print('\n')
        letter = input('Enter a letter: ')
        letter = " " if not letter else letter
        if (letter[0] in word):
            for i in range(len(word)):
                if (word[i] == letter[0]):
                    find = find[:i] + letter[0] + find[i + 1:]
        else:
            idstep += 1
        if (idstep == len(step)):
            victory = True
            print("You lost")
        if (find == word):
            victory = True
            print("You won")
    print('The word was: ' + word)

if __name__ == '__main__':
    os.system('clear')
    main()
