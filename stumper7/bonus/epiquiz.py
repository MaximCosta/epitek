#!/bin/python3
print('Welcome to Epitech Quiz')
Aer = input("Entrer l'Aer qui vous corrige : ")
answer=input('Are you ready to play the Epitech Quiz ? (yes/no) :')
score=0
total_questions=4

if answer.lower()=='yes':
    answer=input('Question 1: What is the best programming language?')
    if answer.lower()=='python':
        score += 1
        print('correct')
    else:
        print('Wrong Answer :(')

    answer=input('Question 2: Do you like Epitech School? ')
    if answer.lower()=='yes':
        score += 1
        print('correct')
    else:
        print('Wrong Answer :(')

    answer=input('Question 3: What is the name of your favourite website for learning Programming language? ')
    if answer.lower()=='stackoverflow':
        score += 1
        print('correct')
    else:
        print('Wrong Answer :(')

    answer=input('Question 4: Who is the best Aer?')
    if answer.lower() == Aer:
        score += 1
        print('correct the best Aer is ' + Aer)
    else:
        print('Wrong Answer, the best Aer is ' + Aer)

print('Thankyou for Playing this small quiz game, you attempted',score,"questions correctly!")
mark=(score/total_questions)*100
print('Marks obtained:',mark)
print('BYE!')

