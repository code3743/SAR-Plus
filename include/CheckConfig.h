#ifndef CHECKCONFIG_H
#define CHECKCONFIG_H

#include "DataBase.h"
#include <iostream>

class CheckConfig
{
public:
	CheckConfig(DataBase&);
	bool configuracionCompleta();

private:
	DataBase& db;
};

#endif