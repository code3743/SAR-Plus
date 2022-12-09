#include "Fecha.h"



Fecha::Fecha() {

}

Fecha::Fecha(int dia, int mes, int anio) {
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

void Fecha::establecerFecha(int dia, int mes, int anio) {
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

void Fecha::setFechaForma(string fecha) {
	fechaForma = fecha;
}

string Fecha::getFecha() {
	string diaForma;
	string mesForma;
	if (dia < 10) {
		diaForma = "0" + to_string(dia);
	}
	else diaForma = to_string(dia);

	if ( mes < 10) {
		mesForma = "0" + to_string(mes);
	}
	else mesForma = to_string(mes);

	if (dia > 0 && dia <= 31 && mes > 0 && mes <= 12) {
		fechaForma = diaForma + "-" + mesForma + "-" + to_string(anio);
	}

	return fechaForma;
}