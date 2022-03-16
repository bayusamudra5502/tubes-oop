#include <CollectionContainer.hpp>

CollectionContainer::CollectionContainer()
{
    this->mxCol = 0;
    this->mxRow = 0;
}

CollectionContainer::CollectionContainer(int mxRow, int mxCol)
{
    this->mxRow = mxRow;
    this->mxCol = mxCol;
    for (int i = 0; i < this->mxRow; i++)
    {
        vector<Slot> s;
        for (int j = 0; j < this->mxCol; j++)
        {
            s.push_back(Slot());
        }
        container.push_back(s);
    }
}

// copy constructor
CollectionContainer::CollectionContainer(const CollectionContainer &cc)
{
    this->mxRow = cc.mxRow;
    this->mxCol = cc.mxCol;
    for (int i = 0; i < this->mxRow; i++)
    {
        vector<Slot> s;
        for (int j = 0; j < this->mxCol; j++)
        {
            s.push_back(cc.container[i][j]);
        }
        container.push_back(s);
    }
}

// destructor
CollectionContainer::~CollectionContainer()
{
}

// operator
CollectionContainer &CollectionContainer::operator=(CollectionContainer &cc)
{
    this->container.clear();
    this->mxRow = cc.mxRow;
    this->mxCol = cc.mxCol;
    for (int i = 0; i < this->mxRow; i++)
    {
        vector<Slot> s;
        for (int j = 0; j < this->mxCol; j++)
        {
            s.push_back(cc.container[i][j]);
        }
        container.push_back(s);
    }
}

void CollectionContainer::insertItem(Position p, Item *item)
{
    if (this->container[p.row][p.col].full())
    {
        // exception
    }
    else if (this->container[p.row][p.col].empty())
    {
        Slot s = Slot(0,item);
        this->container[p.row][p.col].operator=(s);
    }
    else
    {
        if (this->container[p.row][p.col].get_contents()->get_name() != item->get_name())
        {
            // exception, nama tidak sama
        }
        else
        {
            this->container[p.row][p.col].insert();
        }
    }
}

void CollectionContainer::deleteItem(Position p)
{
    if (this->container[p.row][p.col].empty())
    {
        // exception
    }
    else
    {
        this->container[p.row][p.col].remove();
    }
}

void CollectionContainer::getIterator(Position p)
{
}

bool CollectionContainer::isEmpty(Position p) {
    return this -> container[p.row][p.col].empty();
}