// sample main file, replace this with your own code
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <CollectionContainer.hpp>
#include <sstream>
#include <Map.hpp>
#include <RecipeBook.hpp>
#include <Exception/BaseException.hpp>
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
    if(!items.isKeyExist(name)){
      if(type == "TOOL"){
        items.insertItem(name, new ToolItem(id, name));
      }
      else{
        items.insertItem(name, new NonToolItem(id, name, category));
      }
    }
    if(!items.isKeyExist(category)&&category!="-"){
      items.insertItem(category, new NonToolItem(CATEGORY_ID, "*", category)); // ini bener kan non tool?
    }
  }

  // read recipes
  for (const auto &entry :
    filesystem::directory_iterator(configPath + "/recipe")) {
    // cout << entry.path() << endl;
    // // read from file and do something
    ifstream recipeConfigFile(entry.path());
    vector<string> v;
    for(string line; getline(recipeConfigFile, line);){
      v.push_back(line);
    }
    int n, m;
    stringstream ssSize(v[0]);
    ssSize >> n >> m;
    vector<Slot> vSlot;
    for(int i=0; i<n; i++){
      stringstream ssItems(v[i+1]);
      for(int j=0; j<m; j++){
        string itemName;
        ssItems >> itemName;
        if(itemName!="-"){
          vSlot.push_back(Slot(i*m+j, items[itemName], 1));
        }
        else{
          vSlot.push_back(Slot());
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
  CollectionContainer inventory;
  CraftingTable craftingTable;

  // sample interaction
  string command;
  while (cin >> command) {
    try{
      if (command == "EXPORT") {
        string outputPath;
        cin >> outputPath;
        ofstream outputFile(outputPath);
        outputFile << inventory;
      } else if (command == "CRAFT") {

      } else if (command == "GIVE") {
        
      } else if (command == "MOVE") {
        
      } else if (command == "DISCARD"){

      } else if (command == "USE") { 
      
      } else if (command == "MULTIMOVE") {
      
      } else if (command == "MULTICRAFT") {
      
      } else {
        cout << "Invalid command" << endl;
      }
    } catch(BaseException* e){
      cout << e->what() << "\n";
    }
  }
  return 0;
}
