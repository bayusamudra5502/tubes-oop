#pragma once
#include <Slot.hpp>

class CollectionContainer {
    private:
        vector<vector<Slot>> container;
        int mxRow; // banyak baris
        int mxCol; // banyak kolom
    public:
        CollectionContainer(int mxRow, int mxCol);
        void insertItem(int idxPosisi, Item* Item);
        void deleteItem(int idxPosisi);
        void getIterator(int idxPosisi);
};
