#include <CollectionContainer.hpp>

CollectionContainer::CollectionContainer() {
  this->mxCol = 0;
  this->mxRow = 0;
}

CollectionContainer::CollectionContainer(int mxRow, int mxCol) {
  this->mxRow = mxRow;
  this->mxCol = mxCol;
  
  for (int i = 0; i < this->mxRow; i++) {
    vector<Slot> s;
    for (int j = 0; j < this->mxCol; j++) {
      Slot slot(i*mxCol+j);
      s.push_back(slot);
    }
    container.push_back(s);
  }
}

// copy constructor
CollectionContainer::CollectionContainer(const CollectionContainer &cc) {
  this->mxRow = cc.mxRow;
  this->mxCol = cc.mxCol;
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
  bool output = true;
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
  return this->container[pos.row][pos.col];
}

void CollectionContainer::insertItem(Position p, Item* item, int count) {
  if (this->container[p.row][p.col].full()) {
    // exception
  } else if (this->container[p.row][p.col].empty()) {
    this->container[p.row][p.col].insert(item, count);
  } else {
    if (this->container[p.row][p.col].get_contents()->getName() !=
        item->getName()) {
      // exception, nama tidak sama
    } else {
      this->container[p.row][p.col].insert(item, count);
    }
  }
}

void CollectionContainer::deleteItem(Position p, int count ) {
  if (this->container[p.row][p.col].empty()) {
    // exception
  } else {
    this->container[p.row][p.col].remove(count);
  }
}

bool CollectionContainer::isEmpty(Position p) const {
  return this->container[p.row][p.col].empty();
}

ostream &operator<<(ostream &stream, const CollectionContainer &cc) {
  vector<int> mx(cc.mxCol, -1);
  for (int i=0; i<cc.mxRow; i++) {
    for(int j=0; j<cc.mxCol; j++) {
      mx[j] = max(mx[j], cc[{i, j}].get_contents()->getNameLength());
    }
    for(int j=0; j<cc.mxCol; j++){
      stream << "[I" << (cc[{i, j}].get_id()<10?" ":"") << cc[{i, j}].get_id() << " ";
      cc[{i, j}].get_contents()->print(stream, mx[j]);
      stream << " " << cc[{i, j}].get_occupied();
      stream << "] ";
    }
    stream << "\n";
  }

  return stream;
}