#ifndef ROL_H
#define ROL_H

#include <iostream>

using namespace std;

class Rol
{
public: 
	Rol();
	Rol(string, int);
	int getBaseSalarial();
	string getNombreRol();
	void setBaseSalarial(int);
	void setNombreRol(string);
private:
	int baseSalarial;
	string nombreRol;
};
#endif
