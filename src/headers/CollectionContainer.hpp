#pragma once
#include <Slot.hpp>

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

    void insertItem(int idxPosisi, Item *Item);
    void deleteItem(int idxPosisi);
    void getIterator(int idxPosisi);
    //friend ofstream &operator<<(ofstream &stream, const CollectionContainer &cc);
};
