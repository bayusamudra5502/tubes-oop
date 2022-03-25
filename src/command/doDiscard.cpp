#include <command.hpp>
#include <util.hpp>

void doDiscard(Inventory& inventory) {
  string location;
  int count;
  cin >> location >> count;
  if ((location[0] != 'I' && location[0] != 'C') || count <= 0) {
    throw new WrongCommandException(INVALID_PARAMETER);
  }

  struct InventoryMap map = extractId(location, MAX_INVENTORY_COL);
  string s = inventory[{map.row, map.col}].get_contents()->getName();
  inventory.deleteItem({map.row, map.col}, count);
  cout << "\nDiscard complete. \x1B[33m" << count
       << "\x1B[0m item(s) of \x1B[36m" << s
       << "\x1B[0m has been discarded.\n\n";
}