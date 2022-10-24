
import random

from FileReadWrite import *

DATA_FILE_PATH = 'score.txt'

if not fileExists(DATA_FILE_PATH):
    print('welcome to this game')
    score = 0

else:
    score = readFile(DATA_FILE_PATH)
    print('welcome back your current score is',score)
    score = int(score)




def randomeNumberGen():
    return random.randrange(0,11)
while True:
    number1 = randomeNumberGen()
    number2 = randomeNumberGen()


    awnser = number1 + number2

    question = 'what is the awnser to', str(number1), '+', str(number2)

    userAwnser = input(question)
    if userAwnser == '':
        break
    userAwnser = int(userAwnser)

    number1 =int(number1)
    number2 =int(number2)

    if userAwnser == awnser:
        print('correct u got it')
        score = score + 1
        
    else:
        print(userAwnser,' is incorect')
        score = score - 1

    print('your current score is',score)

# write out user score thought a file
score = str(score)
writeFile(DATA_FILE_PATH,score)
