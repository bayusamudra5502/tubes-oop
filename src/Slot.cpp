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

int Slot::get_id() {
    return this -> id;
}

Item* Slot::get_contents() {
    return this -> contents;
}

int Slot::get_available_slot() {
    return this -> available_slot;
}

ofstream& operator<<(ofstream& stream, const Slot& slot){

}