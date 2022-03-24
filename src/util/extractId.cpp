#include <util.hpp>

struct InventoryMap extractId(string id, int maxCol) {
  struct InventoryMap result;
  result.type = id[0];

  int pos = stoi(id.substr(1));
  result.row = pos / maxCol;
  result.col = pos % maxCol;

  return result;
}
