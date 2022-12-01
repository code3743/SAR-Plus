#include "Persona.h"

Persona::Persona() {

}

void Persona::setNombre(string nombre) {
	this->nombre = nombre;
}

void Persona::setApellido(string apellido) {
	this->apellido = apellido;
}

void Persona::setDocumento(string documento) {
	this->documento = documento;
}

void Persona::setTelefono(string telefono) {
	this->telefono = telefono;
}

string Persona::getNombre() {
	return nombre;
}

string Persona::getApellido() {
	return apellido;
}

string Persona::getDocumento() {
	return documento;
}

string Persona::getTelefono() {
	return telefono;
}

