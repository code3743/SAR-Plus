#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include "DataBase.h"
#include "UiConsola.h"
#include "PanelAdministrativo.h"
#include "MarcarIngreso.h"

using namespace std;

class Login
{
public:
	void iniciarSesion();

private:
	string documento;
	string contrasenna;

	DataBase& db = DataBase::getInstancia();
	UiConsola& uiConsola = UiConsola::getIntancia();

	PanelAdministrativo dashBoard;
	MarcarIngreso marcacion;
};

#endif
