# wordle.py is a program for a simplified version of the word game wordle.
# This is fully implemented in python, and you should use it as a reference
# for HW1, for which you should provide a new implementation in C++.
# Sara Krehbiel, 9/24/25

import random

# specify word bank filename, word length, and max number of guesses
filename = 'wordbank.txt'
num_letters = 5 # can't change this if you want to use wordbank.txt
num_guesses = 6

# display basic instructions to the console
def give_instructions():
	print('\nWelcome to wordle! Try to guess a 5-letter word.')
	print('When you guess, the program will report whether each letter:')
	print('  * is in the correct spot')
	print('  ! is in the word in the wrong spot')
	print('  - is not in the word')
	print('E.g., if the secret were PLANE a guess and response might be:')
	print('  train')
	print('  --*-!')

# open word back file and pick and return a random word from it
def get_word():
	f = open(filename)
	all_words = f.readlines()
	f.close()
	word = all_words[random.randrange(len(all_words))].strip().upper()
	return word

# solicit a user guess; require correct #letters, capitalize automatically
def get_guess():
	guess = input().upper()
	while len(guess) != num_letters:
		print('Your guess must be',num_letters,'letters.')
		guess = input().upper()
	return guess

# report the letter-by-letter similarity of a guess to a secret word
def process_guess(guess, secret):
	response = ''
	for i in range(num_letters):
		letter = guess[i]
		# check whether the ith letter is in the correct spot
		if secret[i] == letter:
			response += '*'
		else:
			# check whether the ith letter is (elsewhere) in the secret
			in_word = False
			for j in range(num_letters):
				if secret[j] == letter:
					in_word = True
					break
			if in_word:
				response += '!'
			else:
				response += '-'
	return response

# script for the program; you'll need to put this all in a main function!

# give instructions and pick word
give_instructions()
#secret = get_word()
#print(secret) # you may print out the randomly chosen word for testing
secret = 'PLANE' # or hardcode your own word!
print('The secret word has been selected. Start guessing!\n')

# play game
for i in range(num_guesses):
	guess = get_guess()
	response = process_guess(guess,secret)	
	print(response)
	if guess == secret: break

# report outcome
if guess == secret:
	print('\nYou guessed the word!')
else:
	print('You ran out of guesses before guessing the word:',secret)
