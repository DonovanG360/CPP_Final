#include "MonthlyExpense.h"

/*     CONSTRUCTORS     */

MonthlyExpense::MonthlyExpense() : BudgetItem() {
	paymentDueDate = 1;
}

MonthlyExpense::MonthlyExpense(int date, string name) : BudgetItem(name) {
	paymentDueDate = date;
}

/*     SET MEMBER FUNCTIONS     */

void MonthlyExpense::setPreviousExpenses(float expenses) {
	previousExpenses.push_back(expenses);
}

void MonthlyExpense::setNewDate(int date) {
	paymentDueDate = date;
}

/*     GET MEMBER FUNCTIONS     */

int MonthlyExpense::getDate() {
	return paymentDueDate;
}

float MonthlyExpense::getPreviousExpenses(int index) {
	return previousExpenses.at(index);
}

int MonthlyExpense::getPreviousExpensesSize() {
	return previousExpenses.size();
}