#ifndef CLIENTE_H
#define CLIENTE_H
#include "persona.h"

class Cliente : public Persona
{
    private:
        char _domicilio[50];
        char _telefono[15];
        char _mail[100];
        int _idGeneroFavorito;

    public:
        Cliente();
        virtual ~Cliente();

        // getters
        const char* getDomicilio() const;
        const char* getTelefono() const;
        const char* getMail() const;
        int getIdGeneroFavorito() const;

        // setters
        void setDomicilio(const char* domicilio);
        void setTelefono(const char* telefono);
        void setMail(const char* mail);
        void setIdGeneroFavorito(int idGeneroFavorito);

        // file
        bool grabarEnDisco();
        bool leerDeDisco(int pos);
        bool modificarEnDisco(int pos);

        void toString();
        void toStringShort();
};

#endif // CLIENTE_H
