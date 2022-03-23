#pragma once
#include <bits/stdc++.h>

#include <ItemMetadata.hpp>

using namespace std;

const int MXNONTOOL = 64;
const int MXTOOL = 1;

class Item {
 protected:
  int mxStack;  // banyaknya item maksimal perslot
  int itemId;
  string name;
  ItemType type;

 public:
  Item();
  Item(const Item& other);
  Item(int itemId, string name, ItemType type, int maxStack);
  bool operator==(const Item& other);
  bool operator>(const Item& other);
  bool operator<(const Item& other);
  bool operator!=(const Item& other);
  virtual Item& operator=(const Item& other);
  string getName() const;
  int getMaxStack() const;
  int getItemId() const;
  ItemType getType() const;
};

class NonToolItem : public Item {
 private:
  string category;

 public:
  NonToolItem();
  NonToolItem(const NonToolItem& copy);
  NonToolItem(int itemId, string name, string category, int maxStack);
  NonToolItem& operator=(const NonToolItem& other);
  string getCategory() const;
};

class ToolItem : public Item {
  int health; //bernilai awal 10, akan dikurangi 1 per penggunaan toolitem

 public:
  ToolItem();
  ToolItem(const ToolItem& copy);
  ToolItem(int itemId, string name);
  ToolItem& operator=(const ToolItem& other);

  void useItem();
  void setHealth(int newHealth);
};