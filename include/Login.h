#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include "DataBase.h"
using namespace std;

class Login
{
	


	static bool iniciarSesion();



private:
	string usuario;
	string contrasenna;
	DataBase& db = DataBase::getInstancia();
};

#endif
