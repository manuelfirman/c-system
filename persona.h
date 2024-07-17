#ifndef PERSONA_H
#define PERSONA_H
#include "fecha.h"


class Persona
{
    protected:
        int _id;
        char _apellidos[50];
        char _nombres[50];
        Fecha _nacimiento;
        bool _estado;
    public:
        Persona();
        virtual ~Persona();

        // getters
        int getId();
        const char* getApellidos();
        const char* getNombres();
        Fecha getNacimiento();
        bool getEstado();

        // setters
        void setId(int id);
        void setApellidos(const char* apellidos);
        void setNombres(const char* nombres);
        void setNacimiento(Fecha fechaNac);
        void setEstado(bool estado);

        bool grabarEnDisco(FILE* file) const;
        bool leerDeDisco(FILE* file);

        virtual void toString();
};

#endif // PERSONA_H
