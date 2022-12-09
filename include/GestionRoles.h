#ifndef GESTIONROLES_H
#define GESTIONROLES_H

#include <iostream>
#include "Roles.h"
#include "UiConsola.h"
#include "DataBase.h"


using namespace std;

class GestionRoles {
public:
	void menuRoles();
	void crearRol(Roles&);
	void editarRol(Roles&);
	void eliminarRol(Roles&);
	void listaRoles(Roles&);
	bool finalizarConfigRoles(Roles&);
private:
	UiConsola& uiConsola = UiConsola::getIntancia();
	DataBase& db = DataBase::getInstancia();
};





#endif // GESTIONROLES_H