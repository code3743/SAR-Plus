#ifndef ROLES_H
#define ROLES_H

#include <iostream>
#include <vector>
#include "UiConsola.h"
#include "Rol.h"
using namespace std;
class Roles
{
public:
	bool crearRol();
	void editarRol(int);
	string* listadoRoles();

private:
	vector<Rol> rolesDisponibles;
	bool existeRol(string);
};


#endif
