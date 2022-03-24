#include <command.hpp>
#include <util.hpp>

void doDiscard(Inventory& inventory) {
  string location;
  int count;
  cin >> location >> count;

  try {
    struct InventoryMap map = extractId(location, MAX_INVENTORY_COL);
    inventory.deleteItem({map.col, map.row}, count);
  } catch (IndexOutBondCC* err) {
    cout << "Slot index not found" << endl;
  } catch (SlotUnderflow* err) {
    cout << "Item is not enough" << endl;
  }
}