#pragma once
#include <bits/stdc++.h>

using namespace std;
class Item{
    protected:
        string name;
        // string type/ int type
        int mxStack; //banyaknya item maksimal perslot
    public:
        bool operator==(const Item& other);
        bool operator!=(const Item& other);

};

class ToolItem: public Item{
    private:

    public:
};

class NonToolItem: public Item{
    private:
        int health;
    public:
        void useItem();
};