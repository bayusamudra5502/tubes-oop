#include <CollectionContainer.hpp>

CollectionContainer::CollectionContainer() {
  this->mxCol = 3;
  this->mxRow = 9;
  this->Type = 'I';
}

CollectionContainer::CollectionContainer(int mxRow, int mxCol) {
  this->mxRow = mxRow;
  this->mxCol = mxCol;
  this->Type = 'I';
  for (int i = 0; i < this->mxRow; i++) {
    vector<Slot> s;
    for (int j = 0; j < this->mxCol; j++) {
      Slot slot(i*mxCol+j);
      s.push_back(slot);
    }
    container.push_back(s);
  }
}

CollectionContainer::CollectionContainer(int mxRow, int mxCol, char type){
  this->mxRow = mxRow;
  this->mxCol = mxCol;
  this->Type = type;
}

// copy constructor
CollectionContainer::CollectionContainer(const CollectionContainer &cc) {
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
CollectionContainer::~CollectionContainer() {
  this->container.clear();
}

// operator
CollectionContainer &CollectionContainer::operator=(CollectionContainer &cc) {
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

bool CollectionContainer::operator==(CollectionContainer &cc) {
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

Slot CollectionContainer::operator[](const Position &pos) const{
  if(pos.row > this->mxRow || pos.row < 0 || pos.col > this->mxCol || pos.col < 0){
      // throw
  }
  return this->container[pos.row][pos.col];
}

char CollectionContainer::getType() const{
  return this->Type;
}

void CollectionContainer::insertItem(Position p, Item* item, int count) {
    if(p.row > this->mxRow || p.row < 0 || p.col > this->mxCol || p.col < 0){
      // throw
    }
    this->container[p.row][p.col].insert(item, count);
}

void CollectionContainer::deleteItem(Position p, int count ) {
    if(p.row > this->mxRow || p.row < 0 || p.col > this->mxCol || p.col < 0){
      // throw
    }

    this->container[p.row][p.col].remove(count);
}

bool CollectionContainer::isEmpty(Position p) const {
  if(p.row > this->mxRow || p.row < 0 || p.col > this->mxCol || p.col < 0){
      // throw
  }
  return this->container[p.row][p.col].empty();
}

ostream &operator<<(ostream &stream, const CollectionContainer &cc) {
  vector<int> mx(cc.mxCol, -1);
  for (int i=0; i<cc.mxRow; i++) {
    for(int j=0; j<cc.mxCol; j++) {
      mx[j] = max(mx[j], cc[{i, j}].get_contents()->getNameLength());
    }
    for(int j=0; j<cc.mxCol; j++){
      stream << "[" << cc.getType() << (cc[{i, j}].get_id()<10?" ":"") << cc[{i, j}].get_id() << " ";
      cc[{i, j}].get_contents()->print(stream, mx[j]);
      stream << " " << cc[{i, j}].get_occupied();
      stream << "] ";
    }
    stream << "\n";
  }

  return stream;
}

ofstream &operator<<(ofstream& stream, const CollectionContainer &cc){
  for(int i=0; i<cc.mxRow; i++){
    for(int j=0; j<cc.mxCol; j++){
      stream << cc[{i, j}].get_contents()->getItemId() << ":" << cc[{i, j}].get_occupied();
    }
    stream << "\n";
  }
  return stream;
}