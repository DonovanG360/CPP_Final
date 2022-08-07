#include "BudgetItem.h"

/*     CONSTRUCTORS     */

BudgetItem::BudgetItem() {
	budgetItemName = "";
}

BudgetItem::BudgetItem(string name) {
	budgetItemName = name;
}

/*     SET MEMBER FUNCTIONS     */

void BudgetItem::setBudgetItemName(string name) {
	budgetItemName = name;
}


/*     GET MEMBER FUNCTIONS     */

string BudgetItem::getBudgetItemName() {
	return budgetItemName;
}
