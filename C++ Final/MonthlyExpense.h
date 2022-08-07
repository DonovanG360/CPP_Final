#pragma once
#include "BudgetItem.h"
class MonthlyExpense : public BudgetItem {
	private:
		vector<double> previousExpenses;
		int paymentDueDate;
	public:
		MonthlyExpense();
		MonthlyExpense(int, string);
		void setPreviousExpenses(double);
		void setNewDate(int);
		int getDate();
		double getPreviousExpenses(int);
		int getPreviousExpensesSize();
};

