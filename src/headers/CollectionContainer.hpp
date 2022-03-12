#ifndef COLLECTION_CONTAINER_HPP
#define COLLECTION_CONTAINER_HPP

template <class item>
class CollectionContainer {
    private:
        item container;
        int idxType;
        int size;
    public:
        collectionContainer(int size);
        insertItem(int idxType, int idxPosisi, item Item);
        deleteItem(int idxType, int idxPosisi);
        getIterator(int idxType, int idxPosisi);
};

#endif