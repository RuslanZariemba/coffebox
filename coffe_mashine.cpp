#include<iostream>

using namespace std;

void printMenu();
bool checkCoin(double coin);

const double BYN2 = 2.0;
const double BYN1 = 1.0;
const double BYN05 = 0.5;
const double BYN02 = 0.2;
const double BYN01 = 0.1;
const double COST_ESPR = 2.5;
const double COST_CAP = 3.0;
const double COST_LAT = 3.5;

int main()
{	double credit = 0.0;
	double coin = 0.0;

	printMenu();

	while (true)
	{
		cout << "Insert money please..." << endl;
		cin >> coin;
		if (checkCoin(coin)) {
			credit += coin;			
		} else {
			cout << "We accept denominations: 2, 1, 0,5, 0,2, 0,1 BYN" << endl;
		}
		cout << "You have " << credit << " credit." << endl;	
	}
	return 0;
}

void printMenu()
{
	cout << "1) Espresso 2.5 BYN" << endl;
	cout << "2) Capuchino 3 BYN" << endl;
	cout << "3) Latte 3.5 BYN" << endl;
	cout << "0) Enter to system menu" << endl;
	cout << "________________________" << endl;
}
bool checkCoin(double coin)
{
	if (coin == BYN2 or coin == BYN1 or coin == BYN05 or coin == BYN02 or coin == BYN01) {
		return true;
	} else {
		return false;
	}
}

