// sample main file, replace this with your own code
#include <Inventory.hpp>
#include <Map.hpp>
#include <RecipeBook.hpp>
#include <command.hpp>
#include <exception/BaseException.hpp>
#include <exception/WrongCommandException.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <loader.hpp>
#include <sstream>
#include <string>
#include <util.hpp>
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
  cout << "\nWELCOME TO TAMBANG JAYA!\n";
  cout << "=============================================\n";
  cout << "type HELP to find out what to do\n\n";
  // sample interaction
  string command;
  cout << "\x1B[34m>\x1B[0m ";
  while (cin >> command) {
    command = toUpperCase(command);

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
      } else if (command == "HELP") {
        help();
      } else if (command == "EXIT") {
        return 0;
      } else {
        throw new WrongCommandException(INVALID_COMMAND);
      }
    } catch (BaseException* e) {
      cout << "\x1B[31m" << e->what() << "\x1B[0m\n";
    }

    cout << "\x1B[34m>\x1B[0m ";
  }
  return 0;
}
