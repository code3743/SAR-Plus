#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using namespace std;
class Persona
{
	Persona();
	void setNombre(string);
	void setApellido(string);
	void setDocumento(string);
	void setTelefono(string);

	string getNombre();
	string getApellido();
	string getTelefono();
	string getDocumento();
private:
	string nombre;
	string apellido;
	string documento;
	string telefono;

};

#endif
