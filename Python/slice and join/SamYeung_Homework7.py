#HW7
#highest 5 scores

import random
from FileReadWrite import *

def addNewScoreToList(scoreList, newScore):
    scoreList.append(newScore)
    scoreList.sort()
    scoreList.pop(0)

def printPlace(place):
    if place >= 11 or place <= 13:
        print('You got', str(place)+'th', 'place')
    elif place % 10 == 1:
        print('You got', str(place)+'st', 'place')
    elif place % 10 == 2:
        print('You got', str(place)+'nd', 'place')
    elif place % 10 == 3:
        print('You got', str(place)+'rd', 'place')
    else:
        print('You got', str(place)+'th', 'place')


N_HIGH_SCORES = 5

DATA_FILE_PATH = ('SamYeung_HW7_highestScores.txt') #path to file

if not fileExists(DATA_FILE_PATH): #First time!
    print('Welcome to my Highest', N_HIGH_SCORES,'Scores Game')
    print()
    scoreList = [] #initialize
    for i in range(0, N_HIGH_SCORES):
        scoreList.append(0)

else:
    scoreList = readFile(DATA_FILE_PATH).split(',')
    scoreList = [int(score) for score in scoreList]

    if N_HIGH_SCORES < len(scoreList):
        print('The number of High Scores has been changed.')
        for i in range(0, len(scoreList) - N_HIGH_SCORES):
            scoreList.pop(0)
    elif N_HIGH_SCORES > len(scoreList):
        print('The number of High Scores has been changed.')
        for i in range(0, N_HIGH_SCORES - len(scoreList)):
            scoreList.append(0)

    scoreList.sort()
    print('Welcome back')
    print()

restartGameN = 0
while True:
    newScore = random.randrange(1, 101)
    print('Your score for this round is:', newScore)

    if newScore > scoreList[-1]: #highest score
        print('Wow, a new all time high score!')
        addNewScoreToList(scoreList, newScore)
        printPlace(1)
        restartGameN = 0
    elif newScore == scoreList[-1]: #same highest score
        print('Wow, same as all time high score!')
        addNewScoreToList(scoreList, newScore)
        printPlace(1)
        restartGameN = 0
    else:
        for score in scoreList[0:(N_HIGH_SCORES)]: #compare all element because of the 'else' part below
            if newScore >= score:
                place = N_HIGH_SCORES - scoreList.index(score)
                restartGameN = 0
            elif newScore < scoreList[0]:
                print("That score is too small. :(")
                
                restartGameN += 1  #if score was too small N_HIGH_SCORES times in a row, ask user to restart game
                if restartGameN == N_HIGH_SCORES:
                    restartGameN = 0
                    restart = input('Your score is always smallest. Do you want to erase the scoreboard to restart the game? (y/n) ')
                    if restart.lower() == 'y' or restart.lower() == 'yes':
                        print('Welcome to my Highest', N_HIGH_SCORES,'Scores Game')
                        scoreList = [] #initialize
                        for i in range(0, N_HIGH_SCORES):
                            scoreList.append(0)
                break
            else:
                # newScore > score in somepoint (first 'if' part under for loop)
                print('That score gets on the high scores list')
                printPlace(place)
                addNewScoreToList(scoreList, newScore)
                break

    print('High scores list is:')
    for score in scoreList:
        print(score)

    userinput = input('Do you want to continue? (y/n) ')
    print()
    if not (userinput.lower() == 'y' or userinput.lower() == 'yes'):
        break

scoreList = [str(score) for score in scoreList]
scoreString = ','.join(scoreList)
writeFile(DATA_FILE_PATH, scoreString)
