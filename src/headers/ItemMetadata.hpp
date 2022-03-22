#pragma once

#include <string>
using namespace std;

typedef enum ItemType { NONTOOLS, TOOLS } ItemType;

typedef struct ItemMetadata {
  int itemId;
  string name;
  string category;
  ItemType type;
} ItemMetadata;
