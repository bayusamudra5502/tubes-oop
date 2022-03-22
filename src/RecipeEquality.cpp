#include <CraftingTable.hpp>
#include <Recipe.hpp>

bool operator==(const CraftingTable& ct, const Recipe& r) {
  for (int i = 0; i + r.mxRow <= 3; i++) {
    for (int j = 0; j + r.mxCol <= 3; j++) {
    }
  }
}

bool operator==(const Recipe& r, const CraftingTable& ct) { return ct == r; }