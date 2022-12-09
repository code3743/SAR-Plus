#ifndef CHECKCONFIG_H
#define CHECKCONFIG_H

#include "DataBase.h"
#include "UiConsola.h"
#include <iostream>

class CheckConfig
{
public:

	bool configuracionCompleta();

private:
	DataBase& db = DataBase::getInstancia();
	UiConsola& uiConsola = UiConsola::getIntancia();
};

#endif