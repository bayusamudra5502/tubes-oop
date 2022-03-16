#include <Slot.hpp>

Slot::Slot(){

}

Slot::Slot(int id){

}

Slot::Slot(int id, Item* item){

}

Slot::Slot(int id, Item* item, int used){

}

Slot::Slot(const Slot& other){

}

Slot::~Slot(){

}

Slot& Slot::operator=(Slot& other){

}

bool Slot::empty(){
    return this->contents==NULL;
}

bool Slot::full(){

}

void Slot::insert(int count=1){

}

void Slot::remove(int count=1){

}

ofstream& operator<<(ofstream& stream, const Slot& slot){

}