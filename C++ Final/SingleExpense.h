#pragma once
#include "BudgetItem.h"
class SingleExpense : public BudgetItem {
	private:
		double cost;
	public:
		SingleExpense();
		void setCost(double);
		double getCost();
};

