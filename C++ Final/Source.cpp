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

// ************************
//      MAIN FUNCTION
// ************************

int main() {
	int uChoice = 0;
	BudgetItem TEST;
	do {
		uChoice = displayMenu();
	} while (uChoice != 6);

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
	cout << "5. Save" << endl;
	cout << "6. Quit" << endl;
	cout << "   Please enter your choice: "; cin >> uChoice;
	// Basic input validation, might replace with an exception later.
	if (uChoice < 1 || uChoice > 6) {
		bool isValInput = false;
		while (isValInput == false) {
			cout << "Invalid Input: Please input a valid choice: ";
			cin >> uChoice;
			if (uChoice > 0 && uChoice < 7) {
				isValInput = true;
			}
		}
	}

	return uChoice;
}