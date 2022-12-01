#include "ConfiguracionModelDB.h"


ConfiguracionModelDB::ConfiguracionModelDB(string nombre, string nit, bool estado) {
	nombreNegocio = nombre;
	NIT = nit;
	this->estado = estado;
}
ConfiguracionModelDB::ConfiguracionModelDB() {
	nombreNegocio = "";
	NIT = "";
	estado = false;
}
string ConfiguracionModelDB::getNombreNegocio() {
	return nombreNegocio;
}
string ConfiguracionModelDB::getNIT() {
	return NIT;
}

bool ConfiguracionModelDB::getEstado() {
	return estado;
}

void ConfiguracionModelDB::setNombreNegocio(string nombre) {
	nombreNegocio = nombre;
}
void ConfiguracionModelDB::setNIT(string NIT) {
	this->NIT = NIT;
}
void ConfiguracionModelDB::setEstado(bool estado) {
	this->estado = estado;
}