#include <Slot.hpp>

Slot::Slot(){
    this->id = 0;
    this->contents = NULL;
    this->available_slot = MXNONTOOL;
    this->occupied = 0;
}

Slot::Slot(int id){
    this->id = id;
    this->contents = NULL;
    this->available_slot = MXNONTOOL;
    this->occupied = 0;
}

Slot::Slot(int id, Item* item){
    this->id = id;
    this->contents = item;
    this->available_slot = item->getMaxStack();
    this->occupied = 0;
}

Slot::Slot(int id, Item* item, int used){
    if(item->getMaxStack()-used<0){
        //throw exception
    }
    else{
        this->id = id;
        this->contents = item;
        this->available_slot = item->getMaxStack()-used;
        this->occupied = used; 
    }
}

Slot::Slot(const Slot& other){
    this->id = other.id;
    this->contents = other.contents;
    this->available_slot = other.available_slot;
}

Slot::~Slot(){
    delete this->contents;
}

Slot& Slot::operator=(Slot& other){
    this->id = other.id;
    delete this->contents;
    this->contents = other.contents;
    this->available_slot = other.available_slot;
    return *this;
}

bool Slot::empty(){
    return this->contents==NULL;
}

bool Slot::full(){
    return this->available_slot==0;
}

void Slot::insert(Item* item, int count=1){
    if(this->empty()){
        if(item->getMaxStack()-count<0){
            //throw exception
        }
        else{
            this->id = id;
            this->contents = item;
            this->available_slot = item->getMaxStack()-count;
            this->occupied = count; 
        }
    }
    else{
        if(this->contents->getName() == TOOLNAME){
            // throw exception
        }
        else if(this->available_slot<count){
            //throw exception
        }
        else{
            this->available_slot -= count;
            this->occupied += count;
        }
    }
}

void Slot::remove(int count=1){
    if(this->occupied == 1){
        this->contents = NULL;
        this->occupied = 0;
        this->available_slot = MXNONTOOL;
    }
    else{
        this->occupied -= count;
        this->available_slot += count;   
    }
}

int Slot::get_id() {
    return this->id;
}

Item* Slot::get_contents() {
    return this->contents;
}

int Slot::get_available_slot() {
    return this->available_slot;
}

int Slot::get_occupied(){
    return this->occupied;
}

ofstream& operator<<(ofstream& stream, const Slot& slot){

}