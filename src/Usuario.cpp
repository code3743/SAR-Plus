#include "Usuario.h"

Usuario::Usuario() {

}

Usuario::Usuario(string nombre, string apellido, string telefono, string documento, string contrasenna, bool admin):Persona(nombre, apellido, telefono, documento) {
	this->contrasenna = contrasenna;
	this->admin = admin;
}

void Usuario::setContrasenna(string contrasenna) {
	this->contrasenna = contrasenna;
}

void Usuario::establecerComoAdmin(bool admin) {
	this->admin = admin;
}

bool Usuario::esAdmin() {
	return admin;
}

string Usuario::getContrasenna() {
	return contrasenna;
}