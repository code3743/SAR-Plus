#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using namespace std;


class Persona
{
    public:
        Persona();
        virtual ~Persona();
        void setNombre();
        void setApelllido();
        void setDocumento();
        void setCorreo();
        void setPass();

        void setNombre(string);
        void setApelllido(string);
        void setDocumento(string);
        void setCorreo(string);
        void setPass(string);

        string getNombre();
        string getApelllido();
        string getDocumento();
        string getCorreo();
        string getPass();

    private:
        string nombre;
        string apellido;
        string docuemento;
        string correo;
        string pass;
};

#endif // PERSONA_H
