#pragma once
#include <Slot.hpp>


struct Position {
    int row,col;
};

class CollectionContainer
{
private:
    vector<vector<Slot>> container;
    int mxRow; // banyak baris
    int mxCol; // banyak kolom
public:
    // constructor
    CollectionContainer();
    CollectionContainer(int mxRow, int mxCol);

    // copy constructor
    CollectionContainer(const CollectionContainer &cc);

    // destructor
    ~CollectionContainer();
    // operator
    CollectionContainer &operator=(CollectionContainer &cc);

    void insertItem(Position p, Item *Item);
    void deleteItem(Position p);
    void getIterator(Position p);
    //friend ofstream &operator<<(ofstream &stream, const CollectionContainer &cc);
};
