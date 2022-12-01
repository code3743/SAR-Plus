#include "Rol.h"

Rol::Rol() {

}

Rol::Rol(string nombreRol, int baseSalarial) {
	this->nombreRol = nombreRol;
	this->baseSalarial = baseSalarial;
}

void Rol::setNombreRol(string nombreRol) {
	this->nombreRol = nombreRol;
}
void Rol::setBaseSalarial(int baseSalarial) {
	this->baseSalarial = baseSalarial;
}

string Rol::getNombreRol() {
	return nombreRol;
}

int Rol::getBaseSalarial() {
	return baseSalarial;
}