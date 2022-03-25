#include <Inventory.hpp>

Inventory::Inventory() {
  this->mxCol = 9;
  this->mxRow = 3;
  this->Type = 'I';
  for (int i = 0; i < 3; i++) {
    vector<Slot> s;
    for (int j = 0; j < 9; j++) {
      Slot slot(i * mxCol + j);
      s.push_back(slot);
    }
    container.push_back(s);
  }
}

Inventory::Inventory(int mxRow, int mxCol) {
  this->mxRow = mxRow;
  this->mxCol = mxCol;
  this->Type = 'I';
  for (int i = 0; i < this->mxRow; i++) {
    vector<Slot> s;
    for (int j = 0; j < this->mxCol; j++) {
      Slot slot(i * mxCol + j);
      s.push_back(slot);
    }
    container.push_back(s);
  }
}

Inventory::Inventory(int mxRow, int mxCol, char type) {
  this->mxRow = mxRow;
  this->mxCol = mxCol;
  this->Type = type;
  for (int i = 0; i < this->mxRow; i++) {
    vector<Slot> s;
    for (int j = 0; j < this->mxCol; j++) {
      Slot slot(i * mxCol + j);
      s.push_back(slot);
    }
    container.push_back(s);
  }
}

// copy constructor
Inventory::Inventory(const Inventory &cc) {
  this->mxRow = cc.mxRow;
  this->mxCol = cc.mxCol;
  this->Type = cc.Type;
  for (int i = 0; i < this->mxRow; i++) {
    vector<Slot> s;
    for (int j = 0; j < this->mxCol; j++) {
      s.push_back(cc.container[i][j]);
    }
    container.push_back(s);
  }
}

// destructor
Inventory::~Inventory() { this->container.clear(); }

// operator
Inventory &Inventory::operator=(Inventory &cc) {
  this->container.clear();
  this->mxRow = cc.mxRow;
  this->mxCol = cc.mxCol;
  this->Type = cc.Type;
  for (int i = 0; i < this->mxRow; i++) {
    vector<Slot> s;
    for (int j = 0; j < this->mxCol; j++) {
      Slot ss = cc.container[i][j];
      s.push_back(ss);
    }
    container.push_back(s);
  }

  return *this;
}

bool Inventory::operator==(Inventory &cc) {
  bool output = this->Type == cc.Type;
  if (this->mxCol == cc.mxCol && this->mxRow == cc.mxRow) {
    int i = 0;
    while (i < this->mxRow && output) {
      int j = 0;
      while (j < this->mxCol && output) {
        if (this->container[i][j].operator!=(cc.container[i][j])) {
          output = false;
        } else {
          j++;
        }
      }
      i++;
    }
  } else {
    output = false;
  }
  return output;
}

Slot Inventory::operator[](const Position &pos) const {
  if (pos.row > this->mxRow || pos.row < 0 || pos.col > this->mxCol ||
      pos.col < 0) {
    throw new IndexOutBondCC(mxRow, mxCol, pos.row, pos.col);
  }
  return this->container[pos.row][pos.col];
}

char Inventory::getType() const { return this->Type; }
int Inventory::getmxCol() { return this->mxCol; }

void Inventory::giveItem(Item *item, int Qty) {
  Position idSlotKosong = {-1, -1};
  vector<Position> pos;
  vector<int> qtyTemp;
  for (int i = 0; i < this->mxRow && Qty; i++) {
    for (int j = 0; j < this->mxCol && Qty; j++) {
      if (this->container[i][j].empty() && idSlotKosong.col == -1) {
        idSlotKosong = {i, j};
      } else if (*this->container[i][j].get_contents() == *item) {
        pos.push_back({i, j});
        int tmp = min(Qty, this->container[i][j].get_available_slot());
        qtyTemp.push_back(tmp);
        Qty -= tmp;
      }
    }
  }
  if (Qty > 0) {
    if (idSlotKosong.col == -1) {
      throw InventoryOverflow(item->getName(), Qty);
    } else {
      this->insertItem(idSlotKosong, item, Qty);
      for (int i = 0; i < (int)pos.size(); i++) {
        this->insertItem(pos[i], item, qtyTemp[i]);
      }
    }
  } else {
    for (int i = 0; i < (int)pos.size(); i++) {
      this->insertItem(pos[i], item, qtyTemp[i]);
    }
  }
}

Inventory *Inventory::clone() { return new Inventory(*this); }

void Inventory::moveItem(string id, int N, vector<string> destId,
                         Inventory *dest) {
  Inventory *tempThis = this->clone();
  Inventory *tempDest = dest->clone();
  try {
    stringstream ss(id);
    char collectionId;
    int posRaw;

    ss >> collectionId >> posRaw;

    int row = posRaw / this->getmxCol();
    int col = posRaw % this->getmxCol();

    Item *item = this->container[row][col].get_contents();
    this->deleteItem({row, col}, N);

    int rem = N % destId.size();

    for (int i = 0; i < (int)destId.size(); i++) {
      char cId;
      int pRaw;

      stringstream ssN(destId[i]);
      ssN >> cId >> pRaw;
      if (cId != collectionId) {
        col = pRaw % dest->getmxCol();
        row = pRaw / dest->getmxCol();
        dest->insertItem({row, col}, item, N / destId.size() + rem);
      } else {
        col = pRaw % this->getmxCol();
        row = pRaw / this->getmxCol();
        this->insertItem({row, col}, item, N / destId.size() + rem);
      }

      rem--;
      rem = rem > 0 ? rem : 0;
    }

  } catch (BaseException *e) {
    this->operator=(*tempThis);
    dest->operator=(*tempDest);
    throw e;
  }
}

void Inventory::useItem(int row, int col) {
  this->container[row][col].useItem();
}

void Inventory::insertItem(Position p, Item *item, int count) {
  if (p.row > this->mxRow || p.row < 0 || p.col > this->mxCol || p.col < 0) {
    throw new IndexOutBondCC(mxRow, mxCol, p.row, p.col);
  }
  this->container[p.row][p.col].insert(item, count);
}

void Inventory::deleteItem(Position p, int count) {
  if (p.row > this->mxRow || p.row < 0 || p.col > this->mxCol || p.col < 0) {
    throw new IndexOutBondCC(mxRow, mxCol, p.row, p.col);
  }

  this->container[p.row][p.col].remove(count);
}

bool Inventory::isEmpty(Position p) const {
  if (p.row > this->mxRow || p.row < 0 || p.col > this->mxCol || p.col < 0) {
    throw new IndexOutBondCC(mxRow, mxCol, p.row, p.col);
  }
  return this->container[p.row][p.col].empty();
}

ostream &operator<<(ostream &stream, const Inventory &cc) {
  vector<int> mx(cc.mxCol, -1);
  for (int i = 0; i < cc.mxRow; i++) {
    for (int j = 0; j < cc.mxCol; j++) {
      mx[j] = max(mx[j], cc[{i, j}].get_contents()->getNameLength());
    }
    for (int j = 0; j < cc.mxCol; j++) {
      stream << "[" << cc.getType() << (cc[{i, j}].get_id() < 10 ? " " : "")
             << cc[{i, j}].get_id() << " ";
      cc[{i, j}].get_contents()->print(stream, mx[j]);
      stream << " " << (cc[{i, j}].get_occupied() < 10 ? " " : "")
             << cc[{i, j}].get_occupied();
      stream << "] ";
    }
    stream << "\n";
  }

  return stream;
}

ofstream &operator<<(ofstream &stream, const Inventory &cc) {
  for (int i = 0; i < cc.mxRow; i++) {
    for (int j = 0; j < cc.mxCol; j++) {
      stream << cc[{i, j}].get_contents()->getItemId() << ":"
             << cc[{i, j}].get_occupied();
      stream << "\n";
    }
  }
  return stream;
}