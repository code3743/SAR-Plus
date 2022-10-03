#ifndef UICONSOLA_H
#define UICONSOLA_H


class UiConsola
{
    public:
       static void borrarPantalla();

       enum Colores  {
       Azul, Amarillo, Rojo, Verde
       };

       static void imprimir(int);

};

#endif // UICONSOLA_H
