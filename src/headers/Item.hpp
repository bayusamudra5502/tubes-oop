#pragma once
#include <bits/stdc++.h>

#include <ItemMetadata.hpp>

using namespace std;

const int MXNONTOOL = 64;
const int MXTOOL = 1;
const int MXNULL = -1;

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

class NonToolItem : public Item {
 private:
  string category;

 public:
  NonToolItem();
  NonToolItem(const NonToolItem& copy);
  NonToolItem(int itemId, string name, string category);
  virtual ~NonToolItem();
  virtual Item* clone();
  NonToolItem& operator=(const NonToolItem& other);
  string getCategory() const;
};

class ToolItem : public Item {
  int health; //bernilai awal 10, akan dikurangi 1 per penggunaan toolitem

 public:
  ToolItem();
  ToolItem(const ToolItem& copy);
  ToolItem(int itemId, string name);
  virtual ~ToolItem();
  virtual Item* clone();
  ToolItem& operator=(const ToolItem& other);
  int getNameLength();
  int getHealth() const;
  void useItem();
  void setHealth(int newHealth);
  void print(ostream&, int) ;
};