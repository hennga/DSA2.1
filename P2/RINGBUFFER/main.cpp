#include <iostream>
#include <vector>
#include <string>
#include "Menue.h"
#include "Ringpuffer.h"


int main() {
   Ringpuffer Puffer;
   Menue m1;

   if (Puffer.getAnzahlGenutzteNodes() == 0) {
	   std::cout << "Das Backup-System ist leer, bitte fuegen sie ein Backup hinzu" << std::endl;
   }

   while(42) {

	  m1.showSelectionMenue();

	  m1.callRingpufferMethods(m1.readMenueSelection(), Puffer);

   }


}
