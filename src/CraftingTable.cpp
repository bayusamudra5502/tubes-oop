#include <CraftingTable.hpp>

CraftingTable::CraftingTable() : Inventory(3, 3, 'C') {}

CraftingTable::CraftingTable(const CraftingTable& ct)
    : Inventory(ct) {}
Inventory* CraftingTable::clone(){
  return new CraftingTable(*this);
}
bool CraftingTable::operator==(const CraftingTable& ct) {
  CraftingTable cp(ct);

  for (int i = 0; i < this->mxRow; i++) {
    for (int j = 0; j < this->mxCol; j++) {
      Position pos = {i, j};
      if ((*this)[pos] != cp[pos]) {
        return false;
      }
    }
  }
  
  return true;
}

void CraftingTable::craft(){
  CraftingTable* tempC = new CraftingTable(*this);
  try{
    for(int i=0; i<this->mxRow; i++){
      for(int j=0; j<this->mxCol; j++){
        this->deleteItem({i, j}, 1);
      }
    }
  }catch(exception e){
    this->operator=(*tempC);
    throw e;
  }
}
