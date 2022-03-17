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
            s.push_back(Slot(i*mxCol + j+1));
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
    for(auto& p: this->container){
        for(auto q: p){
            q.~Slot();
        }
        p.clear();
    }
    this->container.clear();
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

    return *this;
}

void CollectionContainer::insertItem(Position p, Item *item, int count=1)
{
    if (this->container[p.row][p.col].full())
    {
        // exception
    }
    else if (this->container[p.row][p.col].empty())
    {
        this->container[p.row][p.col].insert(item, count);
    }
    else
    {
        if (this->container[p.row][p.col].get_contents()->getName() != item->getName())
        {
            // exception, nama tidak sama
        }
        else
        {
            this->container[p.row][p.col].insert(item, count);
        }
    }
}

void CollectionContainer::deleteItem(Position p, int count)
{
    if (this->container[p.row][p.col].empty())
    {
        // exception
    }
    else
    {
        this->container[p.row][p.col].remove(count);
    }
}

void CollectionContainer::getIterator(Position p)
{
}

bool CollectionContainer::isEmpty(Position p) {
    return this -> container[p.row][p.col].empty();
}

ofstream &operator<<(ofstream &stream, const CollectionContainer &cc){
    for(auto p: cc.container){
        for(auto q: p){
            stream << q;
        }
    }
    return stream;
}