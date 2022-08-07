#pragma once
#include "BudgetItem.h"
class MonthlyExpense : public BudgetItem {
	private:
		vector<float> previousExpenses;
		int paymentDueDate;
	public:
		MonthlyExpense();
		MonthlyExpense(int, string);
		void setPreviousExpenses(float);
		void setNewDate(int);
		int getDate();
		float getPreviousExpenses(int);
		int getPreviousExpensesSize();
};

