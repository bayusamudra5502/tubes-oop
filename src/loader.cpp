#include <RecipeBook.hpp>
#include <Slot.hpp>
#include <loader.hpp>

const string configPath = "./config";
const string itemConfigPath = configPath + "/item.txt";

void loadItem(Map<string, Item *> &items) {
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
}

void loadRecipe(Map<string, Item *> items, RecipeBook &recipes) {
  // read recipes
  for (const auto &entry :
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
    recipes.insert(recipe);
  }
}