// Donovan Green
// CIS 1202
// 7-6-2022
// Personal Budget Calculator


// My thoughts is that this project is going to act as a monthly budget calculator that allows users to add their own items to the system

#include "BudgetItem.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include<iomanip>
#include<string>
#include<cstring>
#include<cmath>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

// **********************
//      PROTOTYPES
// **********************

int displayMenu();
void addItem(vector<BudgetItem> &);

// ************************
//      MAIN FUNCTION
// ************************

int main() {
	int uChoice = 0;
	vector<BudgetItem> Items;
	do {
		uChoice = displayMenu();

		switch (uChoice) {
			case 1: {
				addItem(Items);
			}
		}

	} while (uChoice != 8);

	cout << "\n\nThank you for using my program! " << endl;
	system("pause");
	return 0;
}

// *******************************
//      DISPLAY MENU FUNCTION
// *******************************

int displayMenu() {
	int uChoice = 0;

	cout << "   Menu" << endl;
	cout << "1. Add New Item " << endl;
	cout << "2. See all Items" << endl;
	cout << "3. Delete a certain item" << endl;
	cout << "4. Add a monthly expense" << endl;
	cout << "5. Add all expenses" << endl;
	cout << "6. Add expenses for a specific expense" << endl;
	cout << "7. Save" << endl;
	cout << "8. Quit" << endl;
	cout << "   Please enter your choice: "; cin >> uChoice;
	// Basic input validation, might replace with an exception later.
	if (uChoice < 1 || uChoice > 8) {
		bool isValInput = false;
		while (isValInput == false) {
			cout << "Invalid Input: Please input a valid choice: ";
			cin >> uChoice;
			if (uChoice > 0 && uChoice < 9) {
				isValInput = true;
			}
		}
	}

	return uChoice;
}

// *******************************
//		ADD NEW ITEM FUNCTION
// *******************************

void addItem(vector<BudgetItem> &totalItems) {
	string name;
	cout << "Please enter the name of the monthly expense: "; cin.ignore(1, '\n');  getline(cin, name);
	BudgetItem newItem(name);
	totalItems.push_back(newItem);
}