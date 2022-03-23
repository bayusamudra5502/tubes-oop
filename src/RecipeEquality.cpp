#include <CraftingTable.hpp>
#include <Recipe.hpp>

bool operator==(const CraftingTable& ct, const Recipe& r) {
  for (int i = 0; i + r.mxRow <= 3; i++) {
    for (int j = 0; j + r.mxCol <= 3; j++) {
      CraftingTable ctNew;

      for (int k = 0; k < r.mxRow; k++) {
        for (int l = 0; l < r.mxCol; l++) {
          Position pos = {k + i, l + j};
          Slot content = r.container[k][l];
          ctNew.insertItem(pos, content.get_contents(),
                           content.get_occupied());
        }
      }

      if (ctNew == ct) {
        return true;
      }
    }
  }

  // Mirror Search
  for (int i = 0; i + r.mxRow <= 3; i++) {
    for (int j = 0; j + r.mxCol <= 3; j++) {
      CraftingTable ctNew;

      for (int k = 0; k < r.mxRow; k++) {
        for (int l = 0; l < r.mxCol; l++) {
          Position pos = {k + i, l + j};
          Slot content = r.container[k][r.mxCol - l];
          ctNew.insertItem(pos, content.get_contents(),
                           content.get_occupied());
        }
      }

      if (ctNew == ct) {
        return true;
      }
    }
  }

  return false;
}

bool operator==(const Recipe& r, const CraftingTable& ct) { return ct == r; }