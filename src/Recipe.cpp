#include <Recipe.hpp>
#include <Slot.hpp>

Recipe::Recipe() : CollectionContainer() {}

Recipe::Recipe(int row, int col, vector<Slot> item)
    : CollectionContainer(row, col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      Position pos = {i, j};
      Slot content = item[i * col + j];

      this->insertItem(pos, *content.get_contents(), content.get_occupied());
    }
  }
}

bool Recipe::operator==(const Recipe& r) {
  if (r.mxCol != this->mxCol || r.mxRow != this->mxCol) {
    return false;
  }

  for (int i = 0; i < r.mxRow; i++) {
    for (int j = 0; j < r.mxCol; j++) {
      Slot s = r.container[i][j];
      if (s != this->container[i][j]) {
        return false;
      }
    }
  }

  return false;
}