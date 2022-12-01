//#include "Roles.h"
//
//
//bool Roles::crearRol() {
//	Rol nuevoRol;
//	string nombre;
//	int baseSalarial;
//	/*UiConsola::leer(nombre, "Nombre del Rol: ");
//	UiConsola::leer(baseSalarial, "Valor de la Hora: ");*/
//	if (existeRol(nombre)) return false;
//	nuevoRol = Rol(nombre, baseSalarial);
//	rolesDisponibles.push_back(nuevoRol);
//	return true;
//}
//
//void Roles::editarRol(int rol) {
//	string nombre;
//	int baseSalarial;
//	/*
//	UiConsola::leer(nombre, "Nombre del Rol: ");
//	UiConsola::leer(baseSalarial, "Valor de la Hora: ");*/
//
//	rolesDisponibles[rol].setNombreRol(nombre);
//	rolesDisponibles[rol].setBaseSalarial(baseSalarial);
//
//}
//
//bool Roles::existeRol(string nombreRol) {
//	for (int i = 0; i < rolesDisponibles.size(); i++) {
//		if (rolesDisponibles[i].getNombreRol() == nombreRol) return true;
//	}
//	return false;
//}
//
//string* Roles::listadoRoles() {
//	const int length = rolesDisponibles.size() ;
//	string *roles;
//	roles = new string[length];
//	for (int i = 0; i < length; i++) {
//		roles[i] = rolesDisponibles[i].getNombreRol();
//	}
//	return roles;
//}