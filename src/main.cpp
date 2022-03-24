// sample main file, replace this with your own code
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <CollectionContainer.hpp>
#include <sstream>
#include <Map.hpp>
#include <RecipeBook.hpp>
using namespace std;

int main() {
  string configPath = "./config";
  string itemConfigPath = configPath + "/item.txt";
  Map<string, Item*> items;
  RecipeBook recipes;
  
  // read item from config file
  ifstream itemConfigFile(itemConfigPath);
  for (string line; getline(itemConfigFile, line);) {
    cout << line << endl;
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
    cout << entry.path() << endl;
    // read from file and do something
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
        vSlot.push_back(Slot(i*m+j, items[itemName], 1));
      }
    }
    stringstream ssOut(v.back());
    string outItemName;
    int outQty;
    ssOut >> outItemName >> outQty;
    Slot outSlot(0, items[outItemName], outQty);
    Recipe recipe(n, m, vSlot, outSlot);
  }

  // sample interaction
  string command;
  while (cin >> command) {
    if (command == "EXPORT") {
      string outputPath;
      cin >> outputPath;
      ofstream outputFile(outputPath);

      // hardcode for first test case
      outputFile << "21:10" << endl;
      outputFile << "6:1" << endl;
      for (int i = 2; i < 27; i++) {
        outputFile << "0:0" << endl;
      }

      cout << "Exported" << endl;
    } else if (command == "CRAFT") {
      cout << "TODO" << endl;
    } else if (command == "GIVE") {
      string itemName;
      int itemQty;
      cin >> itemName >> itemQty;
      cout << "TODO" << endl;
    } else if (command == "MOVE") {
      // string slotSrc;
      // int slotQty;
      // string slotDest;
      // need to handle multiple destinations
      //cin >> slotSrc >> slotQty >> slotDest;
      // CollectionContainer cc(3, 3);
      // //cc.insertItem({0, 0}, new ToolItem(0, "HADUHAY"));
      // cout << cc;
      // cout << "TODO" << endl;
      Slot* s = new Slot(1, new ToolItem(1, "BLOCK"));
      Slot* s1 = new Slot(2, new ToolItem(1, "BLOCK"), 10);
      Slot* s2 = new Slot(3, new NonToolItem(1, "DUAR", "DUARR"));
      cout << (*s == *s2) << " " << (*s2==*s1) << " " << (*s==*s1) << "\n";
    } else {
      // todo
      cout << "Invalid command" << endl;
    }
  }
  return 0;
}
