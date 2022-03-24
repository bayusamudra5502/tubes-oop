#pragma once

#include <string>
#include <tuple>
using namespace std;

struct InventoryMap {
  char type;
  int row;
  int col;

  friend bool operator==(const InventoryMap &i, const InventoryMap &j) {
    return j.type == i.type && j.row == i.row && j.col == i.col;
  }
};

struct InventoryMap extractId(string id, int maxCol);