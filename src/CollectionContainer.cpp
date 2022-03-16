#include <CollectionContainer.hpp>

CollectionContainer::CollectionContainer()
{
    this -> mxCol = 0;
    this -> mxRow = 0;
}

CollectionContainer::CollectionContainer(int mxRow, int mxCol)
{
    this -> mxRow = mxRow;
    this -> mxCol = mxCol;
}

// copy constructor
CollectionContainer::CollectionContainer(const CollectionContainer &cc)
{
    this -> mxRow = cc.mxRow;
    this -> mxCol = cc.mxCol;
}

// destructor
CollectionContainer::~CollectionContainer()
{
}

// operator
CollectionContainer &CollectionContainer::operator=(CollectionContainer &cc)
{
    CollectionContainer(cc);
}

void CollectionContainer::insertItem(Position p, Item *Item)
{
}

void CollectionContainer::deleteItem(Position p)
{
}

void CollectionContainer::getIterator(Position p)
{
}