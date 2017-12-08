#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main() {
	int player_money = 100;
	int dealer_money = 900;
	Player p1(player_money);
	Player dealer(dealer_money);
	while (p1.showMoney() > 0 && dealer.showMoney() > 0) {
		bool player_under = true;
		bool dealer_under = true;
		Hand h1;
		Hand h2;
		p1.set_hand(h1);
		dealer.set_hand(h2);
		int bet;
		cout << "You have $" << p1.showMoney();
		cout << endl << "Enter bet: ";
		cin >> bet;


		cout << "Your cards: " << endl << h1;
		char response;
		cout << "Your total is: " << h1.get_total() << ". Do you want another card? (y/n)";
		cin >> response;
		int cardcounter = 1;

		while (response == 'y') {
			cout << endl;
			p1.giveCard();
			cout << "New Card: " << p1.get_hand().get_card(cardcounter) << endl;
			cardcounter++;
			cout << "Your cards: " << endl << p1.get_hand();
			cout << "Your total is: " << p1.get_hand().get_total();
			if (p1.get_hand().get_total() < 7.5) {
				cout << ". Do you want another card? (y/n)";
				cin >> response;
			}
			else if (p1.get_hand().get_total() == 7.5)
				break;
			else {
				player_under = false;
				break;
			}

		}


		cout << endl << endl << "Dealer's cards: " << endl << h2;
		cout << "The dealer's total is: " << h2.get_total() << ".";
		int dcardcounter = 1;
		while (dealer.get_hand().get_total() < 5.5) {
			cout << endl << endl;
			dealer.giveCard();
			cout << "New Card: " << dealer.get_hand().get_card(dcardcounter) << endl;
			dcardcounter++;
			cout << "Dealer's cards: " << endl << dealer.get_hand();
			char response;
			cout << "The dealer's total is: " << dealer.get_hand().get_total();
			if (dealer.get_hand().get_total() > 7.5) {
				dealer_under = false;
				break;
			}

		}
		bool won = true;
		if (player_under == false) {
			cout << endl << "Too bad. You lose: " << bet << endl << endl;
			p1.change_money(bet, !won);
			dealer.change_money(bet, won);
		}
		else if (dealer_under == false) {
			cout << endl << "You win " << bet << endl <<endl;
			p1.change_money(bet, won);
			dealer.change_money(bet, !won);
		}
		else if (p1.get_hand().get_total() < dealer.get_hand().get_total()) {
			cout << endl << "Too bad. You lose: " << bet << endl << endl;
			p1.change_money(bet, !won);
			dealer.change_money(bet, won);
		}
		else if (p1.get_hand().get_total() > dealer.get_hand().get_total()) {
			cout << endl << "You win " << bet << endl << endl;
			p1.change_money(bet, won);
			dealer.change_money(bet, !won);
		}
		else {
			cout << endl << "Nobody wins!" << endl << endl;
		}

	}
	if (p1.showMoney() <= 0)
		cout << endl << "You have $0. GAME OVER!\n Come back when you have more money.\n\n Bye!\n\n";
	else
		cout << endl << "Congratulations! You beat the casino.\n\n Bye!\n" << endl;
		system("PAUSE"); //cin.get was not working
	return 0;
}
