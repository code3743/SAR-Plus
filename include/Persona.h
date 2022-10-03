#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using namespace std;


class Persona
{
    public:
        
        virtual void setNombre() = 0;
        virtual void setApelllido() = 0;
        virtual void setDocumento() = 0;
        virtual void setCorreo() = 0;
        virtual void setPass() = 0;

        virtual string getNombre() = 0;
        virtual string getApelllido() = 0;
        virtual string getDocumento() = 0;
        virtual string getCorreo() = 0;
        virtual string getPass() = 0;
    protected:

    private:
        string nombre;
        string apellido;
        string docuemento;
        string correo;
        string pass;
};

#endif // PERSONA_H
