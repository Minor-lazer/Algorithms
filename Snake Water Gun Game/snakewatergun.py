import random
print("Snake Water Gun Game")
i=0
countuser=0
countcomp=0
while(True):
    if i+1 <=10:
        a = "Snake", "Water", "Gun"

        random_choice = random.choice(a)

        enter = input("Enter Snake,Water or Gun: ")

        user = enter.capitalize()
        
        i=i+1
        print("Game number :",i)
        print("Game left :",10-i)

        if user=="Snake" and random_choice=="Water":
            print("Computer:",random_choice)
            print("Winner is User\n")
            countuser=countuser+1
            continue
        elif user=="Water" and random_choice=="Snake":
            print("Computer:", random_choice)
            print("Winner is Computer\n")
            countcomp=countcomp+1
            continue
        elif user=="Snake" and random_choice=="Gun":
            print("Computer:", random_choice)
            print("Winner is Computer\n")
            countcomp = countcomp + 1
            continue
        elif user=="Gun" and random_choice=="Snake":
            print("Computer:", random_choice)
            print("Winner is User\n")
            countuser = countuser + 1
            continue
        elif user=="Water" and random_choice=="Gun":
            print("Computer:", random_choice)
            print("Winner is User\n")
            countuser = countuser + 1
            continue
        elif user=="Gun" and random_choice=="Water":
            print("Computer:", random_choice)
            print("Winner is Computer\n")
            countcomp = countcomp + 1
            continue
        elif user=="Snake" and random_choice=="Snake":
            print("Computer:", random_choice)
            print("Its Draw\n")
            continue
        elif user=="Water" and random_choice=="Water":
            print("Computer:", random_choice)
            print("Its Draw\n")
            continue
        elif user=="Gun" and random_choice=="Gun":
            print("Computer:", random_choice)
            print("Its Draw\n")
            continue
        else:
            print("Wrong input from the user\n")
            i=i-1
            continue


    elif i>=10:
            print("User Wins: ", countuser)
            print("Computer Wins: ", countcomp)
            if countuser > countcomp:
                print("Series win by user")
            elif countuser==countcomp:
                print("Series is draw")
            else:
                print("Series win by computer")
            break



