
#include <string>

#ifndef ADSPRAKTIKUM2_3129944_RINGNODE_H
#define ADSPRAKTIKUM2_3129944_RINGNODE_H

class Ringnode {
private:

	int OldAge;
	std::string Description="";
	std::string SymbolicData="";
	Ringnode* next= nullptr;

public:
	Ringnode(int age,std::string desc,std::string symData);
	Ringnode(int age);
	int getAge(void);
	void setAge(int age);
	void setDescription(std::string desc);
	void setData(std::string dta);
	void setNextNode(Ringnode* nxt);
	std::string getDescription(void);
	std::string getData(void);
	Ringnode* getNextPointer(void);

};







#endif //ADSPRAKTIKUM2_3129944_RINGNODE_H
