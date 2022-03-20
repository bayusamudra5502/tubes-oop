#include <bits/stdc++.h>

using namespace std;
const int MXNONTOOL = 64;
const int MXTOOL = 1;
const string TOOLNAME = "TOOL";
const string NONTOOLNAME = "NONTOOL";
class Item {
 protected:
  string name;
  // string type/ int type
  int mxStack;  // banyaknya item maksimal perslot
 public:
  Item(const Item& other);
  bool operator==(const Item& other);
  bool operator>(const Item& other);
  bool operator<(const Item& other);
  bool operator!=(const Item& other);
  Item& operator=(const Item& other);
  virtual string getName() = 0;
  int getMaxStack();
};

class NonToolItem : public Item {
 private:
 public:
  string getName();
};

class ToolItem : public Item {
 private:
  int health;  // 10-damage
 public:
  string getName();
  void useItem();
};