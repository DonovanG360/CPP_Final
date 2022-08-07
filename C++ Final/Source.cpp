// Donovan Green
// CIS 1202
// 7-6-2022
// Personal Budget Calculator

// My thoughts is that this project is going to act as a monthly budget calculator that allows users to add their own items to the system

#include "BudgetItem.h"
#include "MonthlyExpense.h"
#include "SingleExpense.h"
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
void newItem(vector<BudgetItem> &);
void allItems(vector<BudgetItem>);
int addExpense(vector<BudgetItem>&);

// ************************
//      MAIN FUNCTION
// ************************

int main() {
	int uChoice = 0;
	vector<BudgetItem> Items;
	cout << "Welcome to the monthly expense calculator!" << endl;
	do {
		cout << "\n";
		uChoice = displayMenu();

		switch (uChoice) {
			case 1: {
				newItem(Items);
				break;
			}
			case 2: {
				addExpense(Items);
				break;
			}

			case 4: {
				allItems(Items);
				break;
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
	cout << "1. Add New Item" << endl;
	cout << "2. Add a monthly expense" << endl;
	cout << "3. Delete a certain item" << endl;
	cout << "4. See all Items" << endl;
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

	cout << "\n";
	return uChoice;
}

// *******************************
//		ADD NEW ITEM FUNCTION
// *******************************

void newItem(vector<BudgetItem> &totalItems, vector<) {
	string name;
	cout << "Please enter the name of the monthly expense: "; cin.ignore(1, '\n');  getline(cin, name);
	BudgetItem newItem(name);
	totalItems.push_back(newItem);
}

// ****************************************
//      ADD A MONTHLY EXPENSE FUNCTION
// ****************************************

int addExpense(vector<BudgetItem> &allItems) {
	char uChoice = 'a';
	string name;
	int x = 0;
	cout << "Enter the name of the item you want to add to (case sensitive): "; cin.ignore(1, '\n'); getline(cin, name);
	for (int i = 0; i < allItems.size(); i++) {
		if (name.compare(allItems.at(i).getBudgetItemName())) {
			x = i;
		}
		else {
			cout << "Could not find item of the title " << name;
			return 0;
		}
	}
	double expense;
	while (tolower(uChoice) != 'q') {
		cout << "Enter in expense #" << allItems.at(x).getPreviousExpensesSize() << ": "; cin >> expense;
		// Input Validation
		if (expense < 0) {
			bool isValInput = false;
			while (isValInput == false) {
				cout << "Expense cannot be negative! Please enter a valid expense: "; cin >> expense;
				if (expense > 0) {
					isValInput = true;
				}
			}
		}
		allItems.at(x).setPreviousExpenses(expense);
		cout << "Type 'q' to stop entering expenses, type 'c' to continue: "; cin >> uChoice;
	}
	return 1;
}



// ********************************
//      SEE ALL ITEMS FUNCTION
// ********************************

void allItems(vector<BudgetItem> allItems) {
	cout << "Now displaying all items . . . " << endl;
	for (int i = 0; i < allItems.size(); i++) {
		cout << "Name: " << allItems.at(i).getBudgetItemName();
		for (int j = 0; j < allItems.at(i).getPreviousExpensesSize(); j++) {
			cout << "\tExpense #" << j + 1 << ": " << allItems.at(i).getPreviousExpenses(j) << endl;
		}
		cout << "\n";
	}
}