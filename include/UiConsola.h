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
       void imprimirPersonalizado(int, string, int);
       void imprimirError(string, int );
       void imprimirAlerta(string, int);
       void imprimirInfo(string, int);
       void imprimirHecho(string, int);
       void barraProgreso(int, int);
       void leer(int&, string, int);
       void leer(double&, string, int);
       void leer(string&, string, int);
       void leerDesicion(bool&, string);
       void menuOpciones(string[], int);
       void espaciadores(int, string);
       void mostrarColoresDisponibles();
       void espacio();
       enum alinear{
        CENTER, LEFT, RIGHT, TAB
       };
private:
    UiConsola();
    int saltoLinea = 1;
};

#endif 
