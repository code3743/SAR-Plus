#ifndef  USUARIO_H
#define USUARIO_H

#include "Persona.h"

class Usuario: public Persona 
{
public:
	Usuario();
	void setContrasenna(string);
	string getContrasenna();
private:
	string contrasenna;
};


#endif // ! USUARIO_H
