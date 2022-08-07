#include "SingleExpense.h"

SingleExpense::SingleExpense() {
	cost = 0;
	budgetItemName = "";
}

SingleExpense::SingleExpense(float price, string name) {
	cost = price;
	budgetItemName = name;
}

void SingleExpense::setCost(float itemCost) {
	cost = itemCost;
}

float SingleExpense::getCost() {
	return cost;
}