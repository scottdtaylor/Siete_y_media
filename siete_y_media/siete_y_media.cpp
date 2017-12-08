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
	bool player_under = true;
	bool dealer_under = true;
	int player_money = 100;
	int dealer_money = 900;
	Player p1(player_money);
	Player dealer(dealer_money);
	while (player_under && dealer_under) {
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
			int cardcounter = 1;
			p1.giveCard();
			cout << "New Card: " << p1.get_hand().get_card(cardcounter) << endl;
			cardcounter++;
			cout << "Your cards: " << endl << p1.get_hand();
			char response;
			cout << "Your total is: " << p1.get_hand().get_total();
			if (p1.get_hand().get_total() > 7.5)

				". Do you want another card? (y/n)";
			cin >> response;
		}

		cout << "Dealer's cards: " << endl << h2;
		cout << "The dealer's total is: " << h2.get_total() << "." << endl << endl;
	}
	return 0;
}
