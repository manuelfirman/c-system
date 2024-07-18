#ifndef LIBRO_H
#define LIBRO_H
#include "fecha.h"

class Libro
{
    private:
        int _id;
        char _titulo[50];
        int _idGenero;
        int _stock;
        float _precio;
        Fecha _publicacion;
        bool _estado;
    public:
        Libro();
        virtual ~Libro();

        // getters
        int getId();
        const char* getTitulo();
        int getIdGenero();
        int getStock();
        float getPrecio();
        Fecha getFechaPublicacion();
        bool getEstado();


        // setters
        void setId(int id);
        void setTitulo(const char* titulo);
        void setIdGenero(int idGenero);
        void setStock(int stock);
        void setPrecio(float precio);
        void setFechaPublicacion(Fecha fecha);
        void setEstado(bool estado);

        // file
        bool grabarEnDisco();
        bool leerDeDisco(int pos);
        bool modificarEnDisco(int pos);

        void toString();
        void toStringExtendido();


};

#endif // LIBRO_H
