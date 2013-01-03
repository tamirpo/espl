import sys
import random
finish = 0
guessed=0
f = open('long-words.txt', 'r+')
lineList = f.readlines()

guess = sys.stdin.readline();
while guess!="quit":
  match = random.choice(lineList)
  print match
  state = match.split()
  
  while finish==0:
    if guess in match:
      indexes = match.find_all(guess)
      for index in indexes:
	state[index] = guess
	guessed+=1
    if guessed==len(match):
      finish=1
    else:
      guess = sys.stdin.readline()

