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
using namespace std;

int main() {
  Map<string, Item*> items;
  RecipeBook recipes;

  loadItem(items);
  loadRecipe(items, recipes);

  Inventory inventory;
  CraftingTable craftingTable;

  // sample interaction
  string command;
  while (cin >> command) {
    try {
      if (command == "EXPORT") {
        string outputPath;
        cin >> outputPath;
        ofstream outputFile(outputPath);
        outputFile << inventory;
      } else if (command == "SHOW") {
        cout << craftingTable << "\n";
        cout << inventory << "\n";
      } else if (command == "CRAFT") {
      } else if (command == "GIVE") {
        string itemName;
        int itemQty;
        cin >> itemName >> itemQty;
        inventory.giveItem(items[itemName], itemQty);
      } else if (command == "MOVE") {
        string src;
        int N;
        cin >> src >> N;
        vector<string> dest(N);
        for (int i = 0; i < N; i++) {
          cin >> dest[i];
        }
        if (src[0] == 'I') {
          inventory.moveItem(src, N, dest, &craftingTable);
        } else {
          craftingTable.moveItem(src, N, dest, &inventory);
        }
      } else if (command == "DISCARD") {
        doDiscard(inventory);
      } else if (command == "USE") {
        doUse(inventory);
      } else if (command == "MULTIMOVE") {
      } else if (command == "MULTICRAFT") {
      } else {
        cout << "Invalid command" << endl;
      }
    } catch (BaseException* e) {
      cout << e->what() << "\n";
    }
  }
  return 0;
}
