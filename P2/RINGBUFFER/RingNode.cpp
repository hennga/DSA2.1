
#include "RingNode.h"

void Ringnode::setDescription(std::string desc) {
   this -> Description = desc;
}

void Ringnode::setData(std::string dta) {
   this-> SymbolicData=dta;
}

void Ringnode::setAge(int age) {
   OldAge=age;
}

void Ringnode::setNextNode(Ringnode *nxt) {
   next=nxt;
}

Ringnode::Ringnode(int age) {
   this->setAge(age);
}

Ringnode::Ringnode(int age,std::string desc,std::string symData){

   this->setAge(age);
   this->setData(symData);
   this->setDescription(desc);
}

int Ringnode::getAge() {
   return OldAge;
}
std::string Ringnode::getData() {
   return SymbolicData;
}
std::string Ringnode::getDescription() {
   return Description;
}

Ringnode* Ringnode::getNextPointer() {
   return next;

}
