#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"
#include "Fecha.h"

class Empleado : public Persona
{
public:

	Empleado();
	Empleado(string, string, string, string, string, string);
	string getRol();
	string getFechaVinculacion();
	void setRol(string);
	void setFechaVinculacion(Fecha);
	void setFechaVinculacion(string);
private:
	string rol;
	Fecha fechaVinvulacion;
};


#endif 