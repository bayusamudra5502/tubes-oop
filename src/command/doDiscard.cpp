#include <command.hpp>
#include <util.hpp>

void doDiscard(Inventory& inventory) {
  string location;
  int count;
  cin >> location >> count;

  struct InventoryMap map = extractId(location, MAX_INVENTORY_COL);
  inventory.deleteItem({map.row, map.col}, count);
}