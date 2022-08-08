// Donovan Green
// CIS 1202
// 7-6-2022
// Personal Budget Calculator

// Code is intended to be used as a way to store and total up recent expenses

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


// ***************************
//      EXCEPTION CLASSES
// ***************************

class titleNotFound {};

// ***********************************
//      SEARCH ALGORITHM TEMPLATE
// ***********************************

template <typename T>
int searchAlgo(vector<T> expense, string name) {
	int x;
	bool isFound = false;
	for (int i = 0; i < expense.size(); i++) {
		if (name == expense.at(i).getBudgetItemName()) {
			x = i;
			isFound = true;
			return x;
		}
	}
	if (isFound == false) {
		throw titleNotFound();
	}
}

// ***************************************
//      DELETE SPECIFIC ITEM TEMPLATE
// ***************************************

// Note: the use of a template made the implementation of this function incredibly simple
template <typename T>
void deletion(vector<T> &expenses) {
	string name;
	cout << "\nPlease enter the name of the item you would like to delete (case sensitive): "; cin.ignore(1, '\n'); getline(cin, name);
	try {
		int x = searchAlgo(expenses, name);
		expenses.erase(expenses.begin() + x);
		cout << name <<" has been successfully erased!" << endl;
	}
	catch (titleNotFound) {
		cout << "Item of name " << name << " does not exist";
	}
}

// **********************
//      PROTOTYPES
// **********************


int displayMenu();
void newItem(vector<MonthlyExpense> &, vector<SingleExpense> &);
void allItems(vector<MonthlyExpense>, vector<SingleExpense> );
void submitPayment(vector<MonthlyExpense> &);
int grabUChoice();
void totalAllExpenses(vector<MonthlyExpense>, vector<SingleExpense>);
void totalSpecificExpense(vector<MonthlyExpense>);

// ************************
//      MAIN FUNCTION
// ************************

int main() {
	int uChoice = 0;
	vector<SingleExpense> singlePurchases;
	vector<MonthlyExpense> monthlyExpenses;
	cout << "Welcome to the monthly expense calculator!" << endl;
	do {
		cout << "\n";
		uChoice = displayMenu();

		switch (uChoice) {
			case 1: {
				newItem(monthlyExpenses, singlePurchases);
				break;
			}
			case 2: {
				submitPayment(monthlyExpenses);
				break;
			}
			case 3: {
				int newChoice = grabUChoice();
				if (newChoice == 1) {
					deletion(monthlyExpenses);
				}
				else {
					deletion(singlePurchases);
				}
				break;
			}
			case 4: {
				allItems(monthlyExpenses, singlePurchases);
				break;
			}
			case 5: {
				totalAllExpenses(monthlyExpenses, singlePurchases);
				break;
			}
			case 6: {
				totalSpecificExpense(monthlyExpenses);
				break;
			}
		}

	} while (uChoice != 7);

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
	cout << "1. Add new item" << endl;
	cout << "2. Submit a monthly payment" << endl;
	cout << "3. Delete a certain item" << endl;
	cout << "4. See all Items" << endl;
	cout << "5. Add all expenses" << endl;
	cout << "6. Add expenses for a specific expense" << endl;
	cout << "7. Quit" << endl;
	cout << "   Please enter your choice: "; cin >> uChoice;
	// Basic input validation, might replace with an exception later.
	if (uChoice < 1 || uChoice > 7) {
		bool isValInput = false;
		while (isValInput == false) {
			cout << "Invalid Input: Please input a valid choice: ";
			cin >> uChoice;
			if (uChoice > 0 && uChoice < 8) {
				isValInput = true;
			}
		}
	}

	cout << "\n";
	return uChoice;
}

// ***************************
//		GRAB USER CHOICE
// ***************************

int grabUChoice() {
	int uChoice;
	cout << "   Is this a: " << endl;
	cout << "1. Monthly expense" << endl;
	cout << "2. Single time purchase" << endl;
	cout << "   Enter your choice: "; cin >> uChoice;
	// Input validation
	if (uChoice != 1 && uChoice != 2) {
		bool isValInput = false;
		while (isValInput == false) {
			cout << "Input is invalid please enter a valid choice: "; cin >> uChoice;
			if (uChoice == 1 || uChoice == 2) {
				isValInput = true;
			}
		}
	}
	return uChoice;
}

// *******************************
//		ADD NEW ITEM FUNCTION
// *******************************

void newItem(vector<MonthlyExpense> &monthlyItems, vector<SingleExpense> &singleItems) {
	string name;
	int uChoice;
	bool isValInput;
	uChoice = grabUChoice();
	cout << "\n";
	switch (uChoice) {
		// IF MONTHLY EXPENSE IS CHOSEN
		case 1: {
			int date;
			cout << "Please enter the name of the monthly expense:       "; cin.ignore(1, '\n');  getline(cin, name);
			cout << "Please enter the day the payment is due each month: "; cin >> date;
			// Input validation
			if (date > 31 || date < 1) {
				isValInput = false;
				while (isValInput == false) {
					cout << "Invalid date: Please enter a new date: "; cin >> date;
					if (date > 0 && date <= 31) {
						isValInput = true;
					}
				}
			}
			MonthlyExpense newExpense(date, name);
			monthlyItems.push_back(newExpense);
			break;
		}
		// IF SINGLE EXPENSE IS CHOSEN
		case 2: {
			float cost;
			cout << "Please enter the purchase name:  "; cin.ignore(1, '\n'); getline(cin, name);
			cout << "Please enter the cost:          $"; cin >> cost;
			if (cost < 0) {
				isValInput = false;
				while (isValInput == false) {
					cout << "Please enter a valid price: $"; cin >> cost;
					if (cost > 0) {
						isValInput = true;
					}
				}
			}
			SingleExpense newPurchase(cost, name);
			singleItems.push_back(newPurchase);
			break;
		}
	}
}

// ****************************************
//      ADD A MONTHLY EXPENSE FUNCTION
// ****************************************

void submitPayment(vector<MonthlyExpense> &allMonths) {
	char uChoice = 'a';
	string name;
	int x = 0;
	cout << "Enter the name of the item you want to submit for (case sensitive): "; cin.ignore(1, '\n'); getline(cin, name);
	try {
		x = searchAlgo(allMonths, name);

		double expense;
		while (tolower(uChoice) != 'q') {
			cout << "Enter in expense #" << allMonths.at(x).getPreviousExpensesSize() + 1 << ": $"; cin >> expense;
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
			allMonths.at(x).setPreviousExpenses(expense);
			cout << "Type 'q' to stop entering expenses, type 'c' to continue: "; cin >> uChoice;
			// input validation
			if (tolower(uChoice) != 'q' && tolower(uChoice) != 'c') {
				bool isValInput = false;
				while (isValInput == false) {
					cout << "Type 'q' to stop entering expenses, type 'c' to continue: "; cin >> uChoice;
					if (tolower(uChoice) == 'q' || tolower(uChoice) == 'c') {
						isValInput = true;
					}
				}
			}
		}
	}
	catch (titleNotFound) {
		cout << "Expense called " << name << " not found";
	}
}

// ********************************
//      SEE ALL ITEMS FUNCTION
// ********************************

void allItems(vector<MonthlyExpense> monthlyExpenses, vector<SingleExpense> purchases) {

	if (purchases.size() != 0) {
		cout << "Now displaying all items . . . " << endl;
		for (int x = 0; x < purchases.size(); x++) {
			cout << "\nName: " << purchases.at(x).getBudgetItemName() << endl;
			cout << "Purchase Cost: $" << right << setw(12) << fixed << setprecision(2) << purchases.at(x).getCost() << endl;
		}
	}

	if (monthlyExpenses.size() != 0) {
		cout << "\nNow displaying all monthly expenses . . . " << endl;
		cout << "\n";
		for (int i = 0; i < monthlyExpenses.size(); i++) {
			cout << "Name: " << monthlyExpenses.at(i).getBudgetItemName() << endl;
			cout << "Payment Date: " << monthlyExpenses.at(i).getDate() << endl;
			for (int j = 0; j < monthlyExpenses.at(i).getPreviousExpensesSize(); j++) {
				cout << "\tExpense #" << j + 1 << ": $" << right << setw(12) << monthlyExpenses.at(i).getPreviousExpenses(j) << endl;
			}
			cout << "\n";
		}
	}
	
}

// ****************************
//      TOTAL ALL EXPENSES
// ****************************

void totalAllExpenses(vector<MonthlyExpense> allMonthlyExpenses, vector<SingleExpense> everySinglePurchase) {
	float subtotalMonth = 0;
	float subtotalPurchase = 0;
	float total = 0;
	cout << "Now totaling all expenses . . . " << endl;
	for (int i = 0; i < everySinglePurchase.size(); i++) {
		subtotalPurchase = subtotalPurchase + everySinglePurchase.at(i).getCost();
	}
	for (int i = 0; i < allMonthlyExpenses.size(); i++) {
		for (int j = 0; j < allMonthlyExpenses.at(i).getPreviousExpensesSize(); j++) {
			subtotalMonth = subtotalMonth + allMonthlyExpenses.at(i).getPreviousExpenses(j);
		}
	}
	total = subtotalMonth + subtotalPurchase;
	cout << "The total for all purchases is:        $" << right << setw(12) << fixed << setprecision(2) << subtotalPurchase << endl;
	cout << "The total for all monthly payments is: $" << right << setw(12) << fixed << setprecision(2) << subtotalMonth << endl;
	cout << "The total put together is:             $" << right << setw(12) << fixed << setprecision(2) << total << endl;
}

// ****************************************************************
//      TOTAL EXPENSES FOR A SPECIFIC MONTHLY PAYMENT FUNCTION
// ****************************************************************

void totalSpecificExpense(vector<MonthlyExpense> allMonthlyExpenses) {
	string name;
	float totalMonth = 0;
	cout << "Please enter the name of the monthly expense (case sensitive): "; cin.ignore(1, '\n');  getline(cin, name);
	try {
		int x = searchAlgo(allMonthlyExpenses, name);
		cout << "\n";
		for (int i = 0; i < allMonthlyExpenses.at(x).getPreviousExpensesSize(); i++) {
			totalMonth = totalMonth + allMonthlyExpenses.at(x).getPreviousExpenses(i);
		}
		cout << "The total for " << name << " is : $" << fixed << setprecision(2) << totalMonth << "\n" << endl;
	}
	catch (titleNotFound) {
		cout << "Expense called " << name << " not found\n";
	}
}