#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class BudgetItem {
	protected:
		string budgetItemName;
	public:
		BudgetItem();
		BudgetItem(string);
		void setBudgetItemName(string);
		string getBudgetItemName();
};

