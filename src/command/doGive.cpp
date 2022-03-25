#include <command.hpp>

void doGive(Inventory& inventory, Map<string, Item*> items) {
  string itemName;
  int itemQty;
  cin >> itemName >> itemQty;
  if (itemQty <= 0) {
    throw new WrongCommandException(INVALID_PARAMETER);
  }
  inventory.giveItem(items[itemName], itemQty);
  cout << "\nYou have been given \x1B[33m" << itemQty
       << "\x1B[0m item(s) of \x1B[36m" << itemName << "\x1B[0m\n\n";
}