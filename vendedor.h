#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "persona.h"
#include "fecha.h"

class Vendedor : public Persona
{
    private:
        float _sueldo;
        Fecha _ingreso;

    public:
        Vendedor();
        virtual ~Vendedor();

        // getters
        float getSueldo();
        Fecha getIngreso();

        // setters
        void setSueldo(float valor);
        void setIngreso(Fecha fecha);

        // file
        bool grabarEnDisco();
        bool leerDeDisco(int pos);
        bool modificarEnDisco(int pos);

        void toString();
};

#endif // VENDEDOR_H
