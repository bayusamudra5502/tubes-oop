// sample main file, replace this with your own code
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <CollectionContainer.hpp>
#include <sstream>

using namespace std;

int main() {
  string configPath = "./config";
  string itemConfigPath = configPath + "/item.txt";

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
    // TODO pake variabelnya
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
      //cout << line << "\n";
    }
    int n, m;
    stringstream ss1(v[0]);
    ss1 >> n >> m;
    string itemName[n][m];
    for(int i=0; i<n; i++){
      stringstream ss2(v[i+1]);
      for(int j=0; j<m; j++){
        ss2 >> itemName[i][j];
      }
    }
    stringstream ss3(v.back());
    string outItemName;
    int outQty;
    ss3 >> outItemName >> outQty;
    
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
