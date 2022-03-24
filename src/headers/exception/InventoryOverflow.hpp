#pragma once

#include <exception/BaseException.hpp>
#include <Item.hpp>

class InventoryOverflow : public BaseException {
    private:
        string itemName;
        int qty;
    public:
        InventoryOverflow(string itemName, int qty);
        virtual string what();
};