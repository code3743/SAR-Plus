#include "Roles.h"

Roles::Roles(vector<Rol> roles) {
	rolesDisponibles = roles;
}

Roles::Roles(){}

bool Roles::crearRol(string nombre, int baseSalarial ) {
	Rol nuevoRol = Rol(nombre, baseSalarial);
	if (existeRol(nombre)) return false;

	rolesDisponibles.push_back(nuevoRol);
	return true;
}

bool Roles::editarRol(int indexRol, string nombre, int baseSalarial) {
	if (existeRol(nombre)) return false;
	rolesDisponibles[indexRol].setNombreRol(nombre);
	rolesDisponibles[indexRol].setBaseSalarial(baseSalarial);
	return true;
}

bool Roles::existeRol(string nombreRol) {
	for (int i = 0; i < rolesDisponibles.size(); i++) {
		if (rolesDisponibles[i].getNombreRol() == nombreRol) return true;
	}
	return false;
}

void Roles::eliminarRol(int indexRol) {
	rolesDisponibles.erase(rolesDisponibles.begin() + indexRol);
}

vector<Rol> Roles::getRoles() {
	return rolesDisponibles;
}

//string* Roles::listadoRoles() {
//	const int length = rolesDisponibles.size() ;
//	string *roles;
//	roles = new string[length];
//	for (int i = 0; i < length; i++) {
//		roles[i] = rolesDisponibles[i].getNombreRol();
//	}
//	return roles;
//}
//
//int Roles::totalRoles() {
//	return rolesDisponibles.size();
//}