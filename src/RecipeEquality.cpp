#include <CraftingTable.hpp>
#include <Recipe.hpp>

bool operator==(const CraftingTable& ct, const Recipe& r) {
  for (int i = 0; i + r.mxRow <= ct.mxRow; i++) {
    for (int j = 0; j + r.mxCol <= ct.mxCol; j++) {
      CraftingTable ctNew, ctNewReverse;

      for (int k = 0; k < r.mxRow; k++) {
        for (int l = 0; l < r.mxCol; l++) {
          Position pos = {k + i, l + j};
          Slot content = r.container[k][l];
          ctNewReverse.insertItem(pos, content.get_contents(),
                                  content.get_occupied());
        }
      }

      ctNew = ctNewReverse;
      for (int k = 0; k < ct.mxRow; k++) {
        reverse(ctNewReverse.container[k].begin(),
                ctNewReverse.container[k].end());
      }

      if (ctNew == ct || ctNewReverse == ct) {
        return true;
      }
    }
  }

  return false;
}

bool operator==(const Recipe& r, const CraftingTable& ct) { return ct == r; }