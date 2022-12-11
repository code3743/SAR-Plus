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
	Roles();
	Roles(vector<Rol>);

	bool crearRol(string, int);
	bool editarRol(int, string, int);
	void eliminarRol(int);
	vector<Rol> getRoles();

private:
	vector<Rol> rolesDisponibles;
	bool existeRol(string);
};


#endif
