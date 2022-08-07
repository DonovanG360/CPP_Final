#include "MonthlyExpense.h"

MonthlyExpense::MonthlyExpense() {
	paymentDueDate = "";
	budgetItemName = "";
}

void MonthlyExpense::setPreviousExpenses(double expenses) {
	previousExpenses.push_back(expenses);
}

void MonthlyExpense::setNewDate(string date) {
	paymentDueDate = date;
}

string MonthlyExpense::getDate() {
	return paymentDueDate;
}

double MonthlyExpense::getPreviousExpenses(int index) {
	return previousExpenses.at(index);
}

int MonthlyExpense::getPreviousExpensesSize() {
	return previousExpenses.size();
}