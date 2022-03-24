#pragma once 
#include "Item.hpp"

class NonToolItem : public Item {
 private:
  string category;

 public:
  NonToolItem();
  NonToolItem(const NonToolItem& copy);
  NonToolItem(int itemId, string name, string category);
  virtual bool operator==(const Item& other);
  virtual bool operator!=(const Item& other);
  virtual ~NonToolItem();
  virtual Item* clone();
  NonToolItem& operator=(const NonToolItem& other);
  string getCategory() const;
};