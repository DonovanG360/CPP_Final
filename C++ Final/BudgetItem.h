#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class BudgetItem {
	private:
		string budgetItemName;
		vector<double> previousExpenses;
	public:
		BudgetItem();
		void setBudgetItemName(string);
		void setPreviousExpenses(double);
		string getBudgetItemName();
		double getPreviousExpenses(int);
};

