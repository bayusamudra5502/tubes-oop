#pragma once
#include <bits/stdc++.h>

#include <ItemMetadata.hpp>

using namespace std;
const int MXNONTOOL = 64;
const int MXTOOL = 1;
class Item {
 protected:
  ItemMetadata metadata;
  int mxStack;  // banyaknya item maksimal perslot
 public:
  Item();
  Item(const ItemMetadata& item);
  Item(const Item& other);
  bool operator==(const Item& other);
  bool operator>(const Item& other);
  bool operator<(const Item& other);
  bool operator!=(const Item& other);
  Item& operator=(const Item& other);
  string getName() const;
  int getMaxStack() const;
};

class NonToolItem : public Item {
 private:
 public:
  string getCategory() const;
};

class ToolItem : public Item {
 private:
  int health;  // 10-damage
 public:
  void useItem();
  void setHealth(int newHealth);
};