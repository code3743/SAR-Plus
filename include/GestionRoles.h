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
	
protected:
	void setRoles(vector<Rol>);
	vector<Rol> getRoles();
	void crearRol();
	void editarRol();
	void eliminarRol();
	void listaRoles();
	bool finalizarConfigRoles();
	
private:
	UiConsola& uiConsola = UiConsola::getIntancia();
	DataBase& db = DataBase::getInstancia();
	Roles roles;
};





#endif // GESTIONROLES_H