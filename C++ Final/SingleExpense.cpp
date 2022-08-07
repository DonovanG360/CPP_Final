#include "SingleExpense.h"

SingleExpense::SingleExpense() {
	cost = 0;
	budgetItemName = "";
}

void SingleExpense::setCost(double itemCost) {
	cost = itemCost;
}

double SingleExpense::getCost() {
	return cost;
}