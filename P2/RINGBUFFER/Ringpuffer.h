
#include "RingNode.h"

#ifndef ADSPRAKTIKUM2_3129944_RINGPUFFER_H
#define ADSPRAKTIKUM2_3129944_RINGPUFFER_H

class Ringpuffer {

private:
	Ringnode *Anker;
	int AnzahlGenutzteNodes = 0;
	int GroesseRingpuffer;

public:
	Ringpuffer(int anzahlNodes = 6);

	Ringnode *getAnker() const;

	Ringnode *addNode();

	void searchNode(std::string dataToBeFound);

	void printRingpuffer(void);

	Ringnode *getNextForAdd(void);

	void incrementAnzahlGenutzteNodes(void);

	int getAnzahlGenutzteNodes(void);

	void setAnker(Ringnode* newAnker);




};









#endif //ADSPRAKTIKUM2_3129944_RINGPUFFER_H
