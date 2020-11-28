fc = 1

def factorial(num, fc):
  if num < 0:
    print("Can't calculate the factorial of a negative number :/")
  elif num == 0:
    print("0! = 1")
  else:
    for i in range(1, num + 1):
      fc = fc * i
    print(f"{num}! = {fc}")

factorial(0, fc) # Number to make the factorial
