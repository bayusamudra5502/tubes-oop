#pragma once
#include <bits/stdc++.h>

#include <ItemMetadata.hpp>

using namespace std;

const int MXNONTOOL = 64;
const int MXTOOL = 1;
const int MXNULL = 1;
const int CATEGORY_ID = -2;

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
  virtual bool operator==(const Item& other);
  virtual bool operator>(const Item& other);
  virtual bool operator<(const Item& other);
  virtual bool operator!=(const Item& other);
  virtual Item& operator=(const Item& other);
  virtual ~Item();
  string getName() const;
  int getMaxStack() const;
  int getItemId() const;
  bool isEmpty();
  virtual int getNameLength();
  virtual Item* clone();
  ItemType getType() const;
  virtual void print(ostream&, int);
};

