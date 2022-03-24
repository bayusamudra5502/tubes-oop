// sample main file, replace this with your own code
#include <Inventory.hpp>
#include <Map.hpp>
#include <RecipeBook.hpp>
#include <command.hpp>
#include <exception/BaseException.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <util.hpp>

using namespace std;

int main() {
  string configPath = "./config";
  string itemConfigPath = configPath + "/item.txt";
  Map<string, Item*> items;
  RecipeBook recipes;

  // read item from config file
  ifstream itemConfigFile(itemConfigPath);
  for (string line; getline(itemConfigFile, line);) {
    // cout << line << endl;
    stringstream ss(line);
    int id;
    string name;
    string category;
    string type;
    ss >> id >> name >> category >> type;
    if (!items.isKeyExist(name)) {
      if (type == "TOOL") {
        items.insertItem(name, new ToolItem(id, name));
      } else {
        items.insertItem(name, new NonToolItem(id, name, category));
      }
    }
    if (!items.isKeyExist(category) && category != "-") {
      items.insertItem(category, new NonToolItem(CATEGORY_ID, "*", category));
    }
  }
  // read recipes
  for (const auto& entry :
       filesystem::directory_iterator(configPath + "/recipe")) {
    // cout << entry.path() << endl;
    // // read from file and do something
    ifstream recipeConfigFile(entry.path());
    vector<string> v;
    for (string line; getline(recipeConfigFile, line);) {
      v.push_back(line);
    }
    int n, m;
    stringstream ssSize(v[0]);
    ssSize >> n >> m;
    vector<Slot> vSlot;
    for (int i = 0; i < n; i++) {
      stringstream ssItems(v[i + 1]);
      for (int j = 0; j < m; j++) {
        string itemName;
        ssItems >> itemName;
        if (itemName != "-") {
          Slot slot(i * m + j, items[itemName], 1);
          vSlot.push_back(slot);
        } else {
          Slot slot(i * m + j);
          vSlot.push_back(slot);
        }
      }
    }
    stringstream ssOut(v.back());
    string outItemName;
    int outQty;
    ssOut >> outItemName >> outQty;

    Slot outSlot(0, items[outItemName], outQty);
    Recipe recipe(n, m, vSlot, outSlot);
  }
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
      } else if (command == "DISCARD") {
        doDiscard(inventory);
      } else if (command == "USE") {
      } else if (command == "MULTIMOVE") {
      } else {
        cout << "Invalid command" << endl;
      }
    } catch (BaseException* e) {
      cout << e->what() << "\n";
    }
  }
  return 0;
}
