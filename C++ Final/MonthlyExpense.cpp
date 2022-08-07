#include "MonthlyExpense.h"

MonthlyExpense::MonthlyExpense() {
	paymentDueDate = 1;
	budgetItemName = "";
}

MonthlyExpense::MonthlyExpense(int date, string name) {
	paymentDueDate = date;
	budgetItemName = name;
}

void MonthlyExpense::setPreviousExpenses(double expenses) {
	previousExpenses.push_back(expenses);
}

void MonthlyExpense::setNewDate(int date) {
	paymentDueDate = date;
}

int MonthlyExpense::getDate() {
	return paymentDueDate;
}

double MonthlyExpense::getPreviousExpenses(int index) {
	return previousExpenses.at(index);
}

int MonthlyExpense::getPreviousExpensesSize() {
	return previousExpenses.size();
}