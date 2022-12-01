#ifndef MARCARINGRESO_H
#define MARCARINGRESO_H

#include <iostream>
#include "DataBase.h"

using namespace std;

class MarcarIngreso
{
public:
	bool ingresarCedula(string);
private:
	DataBase& db = DataBase::getInstancia();
};

#endif