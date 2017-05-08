//
// Created by henn on 24.04.17.
//
#include <string>
#include <vector>
#include"Ringpuffer.h"

#ifndef ADSPRAKTIKUM2_3129944_MENUE_H
#define ADSPRAKTIKUM2_3129944_MENUE_H

class Menue {

private:
	
	std::vector<std::string> MenueText={" 1) Backup einfuegen"," 2) Backup suchen "," 3) Alle Backups ausgeben "};
	std::string preUserCommandText="?> ";
	
	std::string insertText = "+ Neuen Datensatz einfuegen " ;
	std::string afterInsertText = "+ Ihr Datensatz wurde hinzugefuegt. ";
	
	std::string searchText = "Nach welchen Daten soll gesucht werden? ";
	

public:
	
	
	void showSelectionMenue() const;
	
	int readMenueSelection();
	
	void callRingpufferMethods(int codeInt, Ringpuffer& Ring);
	
	std::string readSearchWord();
	

};





#endif //ADSPRAKTIKUM2_3129944_MENUE_H
