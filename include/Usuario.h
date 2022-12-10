#ifndef  USUARIO_H
#define USUARIO_H

#include "Persona.h"

class Usuario : public Persona
{
public:
	Usuario();
	Usuario(string, string, string, string, string, bool);
	void setContrasenna(string);
	string getContrasenna();
	void establecerComoAdmin(bool);
	bool esAdmin();
private:
	string contrasenna;
	bool admin = false;
};


#endif // ! USUARIO_H
