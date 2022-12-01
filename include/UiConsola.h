#ifndef UICONSOLA_H
#define UICONSOLA_H

#include <iostream>
#include <windows.h>


using namespace std;

class UiConsola
{
    public:
       static UiConsola& getIntancia();
       UiConsola(const UiConsola&) = delete;
       UiConsola& operator = (const UiConsola&) = delete;
       
       void borrarPantalla();
       void imprimir(string, int);
       void imprimirPersonalizado(int, string, bool, int);
       void imprimirError(string, int );
       void imprimirAlerta(string);
       void imprimirInfo(string);
       void imprimirHecho(string);
       void barraProgreso(int, int);
       void leer(int&, string);
       void leer(double&, string);
       void leer(string&, string);
       void leerDesicion(bool&, string);
       void menuOpciones(string[], int);
       void espaciadores(int, string);
       void mostrarColoresDisponibles();
       enum alinear{
        CENTER, LEFT, RIGHT, TAB
       };
private:
    UiConsola();
    int saltoLinea = 1;
};

#endif 
