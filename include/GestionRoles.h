#ifndef GESTIONROLES_H
#define GESTIONROLES_H

#include <iostream>
#include "UiConsola.h"
#include "DataBase.h"
#include "Rol.h"
#include <vector>

using namespace std;

class GestionRoles {
public:
	void menuRoles();
	~GestionRoles();
	
protected:
	void setRoles(vector<Rol>);
	void crearRol();
	void editarRol();
	void eliminarRol();
	vector<Rol> getRoles();
	void listaRoles();
	bool finalizarConfigRoles();
	
private:
	UiConsola& uiConsola = UiConsola::getIntancia();
	DataBase& db = DataBase::getInstancia();
	vector<Rol> rolesDisponibles;
	bool existeRol(string);
};





#endif // GESTIONROLES_H