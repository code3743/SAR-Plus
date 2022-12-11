#ifndef MARCARINGRESO_H
#define MARCARINGRESO_H

#include <iostream>
#include "DataBase.h"
#include <sys/time.h>
#include <ctime>
#include "Empleado.h"

using namespace std;

class MarcarIngreso
{
public:
	string ingresarCedula(Empleado);
private:
	DataBase& db = DataBase::getInstancia();
	string obtenerFechaHoraActual();
};

#endif
