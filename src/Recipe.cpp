#include <Recipe.hpp>
#include <Slot.hpp>

Recipe::Recipe() : CollectionContainer() {}

Recipe::Recipe(int row, int col, vector<Slot> item, Slot result)
    : CollectionContainer(row, col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      Position pos = {i, j};
      Slot content = item[i * col + j];

      this->insertItem(pos, content.get_contents(), content.get_occupied());
    }
  }

  this->result = result;
}

bool Recipe::operator==(const Recipe& r) {
  if (r.mxCol != this->mxCol || r.mxRow != this->mxCol ||
      this->result != r.result) {
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

  return true;
}

Slot Recipe::getResult() const { return this->result; }