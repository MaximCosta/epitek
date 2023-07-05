#!/bin/python3
import sys

def count_words(sentence, search):
    count_letters = {x: 0 for x in search} if search else {}
    for letter in set(sentence):
        count_letters[letter] = sentence.count(letter)
    return count_letters

def main():
    param = {"-t": 0, "-r": 0, "string": "", "search": False}
    args = sys.argv
    if len(args) == 1:
        print('Usage: python3 textcount.py [-t] [-r] "string" "search_string"')
        return
    args.pop(0)
    param['-t'] = 1 if '-t' in args else 0
    param['-r'] = 1 if ('-r' in args) else 0
    args.remove('-t') if '-t' in args else None
    args.remove('-r') if param['-r'] else None
    if (len(args) == 0):
        print('Usage: python3 textcount.py [-t] [-r] "string" "search_string"')
        return
    param['string'] = args.pop(0)
    if (len(args) != 0):
        param['search'] = args.pop(0)
    count_letters = count_words(param['string'], param['search'])
    count_letters = sorted(count_letters.items(), key=lambda x: x[param['-t']], reverse=param['-t'])
    count_letters = [(x[0], str(x[1])) for x in count_letters if not param['search'] or x[0] in param['search']]
    if (not param["-r"]):
        print('\n'.join(map(':'.join, count_letters)))
        return
    grouped_letters = {}
    for letter in count_letters:
        if letter[1] in sorted(grouped_letters, key=lambda x: x[0]):
            grouped_letters[letter[1]] += f",{letter[0]}"
        else:
            grouped_letters[letter[1]] = letter[0]
    print('\n'.join(map(lambda x: f"{x[1]}:{x[0]}", sorted(grouped_letters.items(), key=lambda x: x[not param["-t"]], reverse=param["-t"]))))

if __name__ == '__main__':
    main()
