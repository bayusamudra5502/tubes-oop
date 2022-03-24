#pragma once 
#include <Item.hpp>

class NonToolItem : public Item {
 private:
  string category;

 public:
  NonToolItem();
  NonToolItem(const NonToolItem& copy);
  NonToolItem(int itemId, string name, string category);
  bool operator==(const Item& other);
  bool operator!=(const Item& other);
  ~NonToolItem();
  Item* clone();
  NonToolItem& operator=(const NonToolItem& other);
  string getCategory() const;
};