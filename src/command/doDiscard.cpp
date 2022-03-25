#include <command.hpp>
#include <util.hpp>


void doDiscard(Inventory& inventory) {
  string location;
  int count;
  cin >> location >> count;
  if((location[0]!='I'&&location[0]!='C')||count<=0){
    throw new WrongCommandException(INVALID_PARAMETER);
  }

  struct InventoryMap map = extractId(location, MAX_INVENTORY_COL);
  inventory.deleteItem({map.row, map.col}, count);
}