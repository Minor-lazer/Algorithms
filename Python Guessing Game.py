#Basic Guessing Game Using Python
#Developer - Dernyt-TPE

import random
pcRand=random.randint(0, 1000)
index=int()
def prompt(wrongGuess):
    global index

    if wrongGuess > pcRand:
        if index==0:print("Oops! Again Guess is incorrect")
        index = 0
        nextGuess=int(input("Guess a number less than "+ str(wrongGuess) +"\n"))
        prompt(nextGuess)

    elif wrongGuess < pcRand:
        if index == 0: print("Oops! Again Guess is incorrect")
        index = 0
        nextGuess = int(input("Guess a number more than " + str(wrongGuess)+ "\n"))
        prompt(nextGuess)

    elif wrongGuess == pcRand:
        print("Congratulations! Your Guess is correct - You Won")


#prompting user for guess no.
guess=int(input("Guess a number\n"))
if (guess==pcRand):
    print("Congratulations! Your Guess is correct - You Won")
else:
    print("Oops! Guess is incorrect")
    index=1
    prompt(guess)
