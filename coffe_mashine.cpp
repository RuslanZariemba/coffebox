#include<iostream>

using namespace std;

void getByn();
void printByn();
void printMenu();
bool checkCoin(double coin);
bool checkCreditForDrink(int select, double coin);
void paymentDrink(double cost);


double byn = 0.0;
int cup = 7;
const int MAX_CUPS = 700;
const double BYN2 = 2.0;
const double BYN1 = 1.0;
const double BYN05 = 0.5;
const double BYN02 = 0.2;
const double BYN01 = 0.1;
const double COST_ESPR = 2.5;
const double COST_CAP = 3.0;
const double COST_LAT = 3.5;

int main()
{	
	int select = 0;

	while(true)
	{	
		printByn();
		printMenu();
		cin >> select;
			
		if(select == 1) 
		{
			getByn();
		}
		else if(select == 2)
		{
			if (checkCreditForDrink(select, byn))
			{
				paymentDrink(COST_ESPR);
				cout << "Take Your espresso" << endl;
				cout << endl;
			}
		}
		else if(select == 3)
		{
			if (checkCreditForDrink(select, byn))
			{
				paymentDrink(COST_CAP);
				cout << "Take Your cappuchino" << endl;
				cout << endl;
			}
		}
		else if(select == 4)
		{
			if (checkCreditForDrink(select, byn))
			{
				paymentDrink(COST_LAT);
				cout << "Take Your latte" << endl;
				cout << endl;
			}
		}
		else if(select == 0)
		{
			cout << "0) Enter to system menu" << endl;
		}
		else
		{
			cout << "You need select 1,2,3,4 or 0" << endl;
		}
	}

	return 0;
}

void printMenu()
{
	cout << "----------------------------" << endl;
	cout << "1) Insert credit" << endl;
	cout << "2) Espresso 2.5 credit" << endl;
	cout << "3) Capuchino 3 credit" << endl;
	cout << "4) Latte 3.5 credit" << endl;
	cout << "0) Enter to system menu" << endl;
	cout << "----------------------------" << endl;
	cout << "Select please 1,2,3,4 or 0 -> ";
}

void printByn() 
{
	cout << "Now you have: " << byn << " BYN" << endl;
}

void getByn() {
	double coin = 0.0;
	while (true) {
		cout << "Insert credit: ";
		cin >> coin;
		
		if (coin == 0) {
			break;
		} else if (checkCoin(coin)) {
		byn += coin;
		printByn();
		}
	}
}


bool checkCoin(double coin)
{
	if (coin == BYN2 or coin == BYN1 or coin == BYN05 or coin == BYN02 or coin == BYN01) {
		return true;
	} else {
		cout << "We accept denominations: 2, 1, 0,5, 0,2, 0,1 BYN" << endl;
		return false;
	}
}

bool checkCreditForDrink(int select, double coin)
{
	if (
	(select == 2 and coin >= COST_ESPR) or
	(select == 3 and coin >= COST_CAP) or 
	(select == 4 and coin >= COST_LAT)) {
		return true;
	} else {
		cout << "You need more money for it" << endl;
		return false;
	}
}

void paymentDrink(double cost)
{
	byn -= cost;
	cup --;
}
