#include <command.hpp>

void doMultiMove(CraftingTable& ct, Inventory& i) {
  int n;
  string src, dest;

  cin >> src >> n >> dest;
  if(n<=0){
    throw new WrongCommandException(INVALID_PARAMETER);
  }
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
  cout << "\nYou successfully moved " << n << " item(s).\n\n";
}