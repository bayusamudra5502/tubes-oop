#pragma once
#include <Item.hpp>

class Slot{
    private:
        int id;
        Item* contents;
        int available_slot;
    public:
        Slot();
        Slot(int id);
        Slot(int id, Item* item);
        Slot(int id, Item* item, int used);
        Slot(const Slot& other);
        ~Slot();
        Slot& operator=(Slot& other);

        bool empty();
        bool full();
        void insert(int count=1); 
        void remove(int count=1);

        friend ofstream& operator<<(ofstream& stream, const Slot& slot);
};