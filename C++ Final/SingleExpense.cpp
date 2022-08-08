#include "SingleExpense.h"

/*     CONSTRUCTORS     */

SingleExpense::SingleExpense() : BudgetItem() {
	cost = 0;
}

SingleExpense::SingleExpense(float price, string name) : BudgetItem(name) {
	cost = price;
}

/*     SET MEMBER FUNCTIONS     */

void SingleExpense::setCost(float itemCost) {
	cost = itemCost;
}

/*     GET MEMBER FUNCTIONS     */

float SingleExpense::getCost() {
	return cost;
}