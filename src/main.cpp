// sample main file, replace this with your own code
#include <Inventory.hpp>
#include <Map.hpp>
#include <RecipeBook.hpp>
#include <command.hpp>
#include <exception/BaseException.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <loader.hpp>
#include <sstream>
#include <string>
#include <util.hpp>
#include <exception/WrongCommandException.hpp>
using namespace std;

int main() {
  Map<string, Item*> items;
  RecipeBook recipes;

  try {
    loadItem(items);
    loadRecipe(items, recipes);
  } catch (BaseException* err) {
    cerr << err->what() << endl;
    return -1;
  }

  Inventory inventory;
  CraftingTable craftingTable;

  // sample interaction
  string command;
  while (cin >> command) {
    try {
      if (command == "EXPORT") {
        doExport(inventory);
      } else if (command == "SHOW") {
        doShow(inventory, craftingTable);
      } else if (command == "CRAFT") {
        doCraft(craftingTable, inventory, recipes);
      } else if (command == "GIVE") {
        doGive(inventory, items);
      } else if (command == "MOVE") {
        doMove(inventory, craftingTable);
      } else if (command == "MULTIMOVE") {
        doMultiMove(craftingTable, inventory);
      } else if (command == "DISCARD") {
        doDiscard(inventory);
      } else if (command == "USE") {
        doUse(inventory);
      } else if (command == "MULTICRAFT") {
        doMultiCraft(craftingTable, inventory, recipes);
      } else {
        throw new WrongCommandException(INVALID_COMMAND);
      }
    } catch (BaseException* e) {
      cout << e->what() << "\n";
    } catch(invalid_argument* e){
      cout << "invalid_argument: " << e->what() << "\n";
    }
  }
  return 0;
}
