#ifndef UICONSOLA_H
#define UICONSOLA_H

#include <iostream>
#include <windows.h>

using namespace std;
class UiConsola
{
    public:
       static void borrarPantalla();
       static void imprimir(string);
       static void imprimirPersonalizado(int, string, bool);
       static void imprimirError(string);
       static void imprimirAlerta(string);
       static void imprimirInfo(string);
       static void imprimirHecho(string);
       static void barraProgreso(int, int);
       static void leer(int&, string);
       static void leer(double&, string);
       static void leer(string&, string);


};

#endif // UICONSOLA_H
