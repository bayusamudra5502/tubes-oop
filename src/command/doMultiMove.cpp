#include <command.hpp>

void doMultiMove(CraftingTable& ct, Inventory& i) {
  int n;
  string src, dest;

  cin >> src >> n >> dest;

  CraftingTable ctTmp(ct);
  Inventory iTmp(i);

  vector<string> res;
  if (src[0] == 'I') {
    iTmp.moveItem(src, n, vector({dest}), &ctTmp);
  } else {
    ctTmp.moveItem(src, n, vector({dest}), &iTmp);
  }

  ct = ctTmp;
  i = iTmp;
}