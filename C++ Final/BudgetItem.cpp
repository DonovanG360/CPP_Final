#include "BudgetItem.h"

/*     CONSTRUCTORS     */

BudgetItem::BudgetItem() {
	numExpenses = 0;
	budgetItemName = "";
	numExpenses++;
}

/*     SET MEMBER FUNCTIONS     */

void BudgetItem::setBudgetItemName(string name) {
	budgetItemName = name;
}

void BudgetItem::setPreviousExpenses(double expenses) {
	previousExpenses.push_back(expenses);
}

/*     GET MEMBER FUNCTIONS     */

string BudgetItem::getBudgetItemName() {
	return budgetItemName;
}

double BudgetItem::getPreviousExpenses(int index) {
	return previousExpenses.at(index);
}