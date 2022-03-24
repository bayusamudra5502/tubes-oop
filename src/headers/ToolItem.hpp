#pragma once
#include <Item.hpp>

class ToolItem : public Item {
  int health;  // bernilai awal 10, akan dikurangi 1 per penggunaan toolitem

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
  void print(ostream&, int);
};