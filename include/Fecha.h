#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <string>

using namespace std;

class Fecha {
public:
	string getFecha();
	Fecha(int, int, int);
	Fecha();
	void establecerFecha(int, int, int);
	void setFechaForma(string);
private:
	int dia;
	int mes;
	int anio;
	string fechaForma = "00-00-0000";
};

#endif