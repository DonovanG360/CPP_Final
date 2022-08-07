#pragma once
#include "BudgetItem.h"
class MonthlyExpense : public BudgetItem {
	private:
		vector<double> previousExpenses;
		string paymentDueDate;
	public:
		MonthlyExpense();
		void setPreviousExpenses(double);
		void setNewDate(string);
		string getDate();
		double getPreviousExpenses(int);
		int getPreviousExpensesSize();
};

