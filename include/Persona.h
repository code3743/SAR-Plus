#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using namespace std;
class Persona
{
public:
	Persona();
	Persona(string, string, string, string);
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
