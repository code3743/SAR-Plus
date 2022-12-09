#include "Empleado.h"


Empleado::Empleado() {

}

Empleado::Empleado(string nombre, string apellido, string telefono, string documento, string rol, string fecha):Persona(nombre, apellido, telefono, documento) {
	this->rol = rol;
	fechaVinvulacion.setFechaForma(fecha);
}

string Empleado::getFechaVinculacion() {
	return fechaVinvulacion.getFecha();
}

string Empleado::getRol() {
	return rol;
}

void Empleado::setRol(string rol) {
	this->rol = rol;
}
void Empleado::setFechaVinculacion(Fecha fechaVinculacion) {
	this->fechaVinvulacion = fechaVinculacion;
}

void Empleado::setFechaVinculacion(string fecha) {
	fechaVinvulacion.setFechaForma(fecha);
}