# Siete_y_media
This project is a simple one player card game made in VS 2015. The rules of the game are simple, and bets are made on each round.
There is a deck of cards of 4 suits, 
each suit possesses 7 number cards, one ace, and three face cards. In this game aces are one and all face cards are worth .5. The 
player is given one card and can draw randomly if they have a card sum less than 7.5. The goal is to reach as close to 7.5 as possible 
without passing it. The player faces a dealer who will draw until reaching 5.5. Whoever has the closer total to 7.5 without going over 
wins. If both players bust, the player loses. In a tie no money is exchanged.

## Purpose
The project was mainly a test of git and some basic functionality (branching, commits, tracking and removing files). The actual game itself
is functional although I did not get around to creating a log file for each round. All parts of the rubric should be fulfilled.


## Code Description
The code is fairly simple, made of a loop for each round conditional on players still having money. Within there is a loop for the player 
which takes input on drawing cards and an automatic one for the dealer. The winner is then decided based on card totals.

## Problems
The main problems for me was trying to find some of the git functions in VS and when that failed attempting to use the CLI. For example 
removing a file at first deleted the file until I learned the correct command. 

### Test Cases
I ran some simple cases in which values between 0 and the given amount of money was bet, and performed a series of rounds with combinations of no extra cards, some extra cards, and taking cards until passing 7.5. This resulted in discovering some bugs in which the player, if asking for another card, would continually draw until passing 7.5, which was fixed. I did not prevent betting "impossible" values or if incorrect input was given.
