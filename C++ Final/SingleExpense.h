#pragma once
#include "BudgetItem.h"
class SingleExpense : public BudgetItem {
	private:
		float cost;
	public:
		SingleExpense();
		SingleExpense(float, string);
		void setCost(float);
		float getCost();
};

