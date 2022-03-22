#include <CraftingTable.hpp>

CraftingTable::CraftingTable() : CollectionContainer(3, 3) {}

bool CraftingTable::operator==(const CraftingTable& ct) {
  for (int i = 0; i < this->mxRow; i++) {
    for (int j = 0; j < this->mxCol; j++) {
    }
  }

  return true;
}