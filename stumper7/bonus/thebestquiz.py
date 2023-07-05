#!/bin/python3
print('Welcome to the best Quiz')
Aer = input("Entrer l'Aer qui vous corrige : ")
answer=input('Are you ready to play the best Quiz ? (yes/no) :')
score=0
total_questions=6

if answer.lower()=='yes':
    answer=input('Question 1: What is the best video game?')
    a = ['fortnite', 'call of duty', 'minecraft', 'mario']
    if answer.lower() in a:
        score += 1
        print('correct')
    else:
        print('Wrong Answer :(' )
        print('the correct answer was minecraft')

    answer=input('Question 2: What do you like in Epitech School? ')
    tab = ['work in team', 'play video games']
    if answer.lower()in tab:
        score += 1
        print('correct')
    else:
        print('Wrong Answer :(')

    answer=input('Question 3: What is the name of your favourite website for learning Programming language? ')
    if answer.lower()=='github':
        score += 1
        print('correct ')
        print('good job ')
    else:
        print('Wrong Answer :(')

    answer=input('Question 4: Who is the best Aer?')
    if answer.lower() == Aer:
        score += 1
        print('correct the best Aer is ' + Aer)
    else:
        print('Wrong Answer, the best Aer is ' + Aer)

    answer=input('Question 5: Do you like holiday? ')
    if answer.lower() =='yes':
        score += 1
        print('correct')
        print('have a nice holiday because you have your duostumper ')
    else:
        print('Wrong Answer :(')

    answer=input('Question 6: Last question before you go, do you like this quiz?  ')
    if answer.lower() == 'yes':
        score += 1
        print('correct')
        print('have a nice day')
    else:
        print('wrong answer :(')

print('Thankyou for Playing this best quiz game, you attempted',score,"questions correctly!")
mark=(score/total_questions)*100
print('Marks obtained:',mark)
print('BYE!')


