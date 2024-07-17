#ifndef MANAGERLIBROS_H
#define MANAGERLIBROS_H
#include "libro.h"

class ManagerLibros
{
    private:
        int cantidad;
        int capacidad;
        Libro* libros;

        void redimensionar(int nuevaCap);
        bool buscarId(int id);
    public:
        ManagerLibros();
        virtual ~ManagerLibros();

        void cargarLibros();
        void listarLibros();
        void listarLibrosVenta();
        void registrarLibro();
        void agregarLibro(const Libro& libro);
        void setEstadoLibro(int id, bool estado);
        Libro getLibro(int id);
};

#endif // MANAGERLIBROS_H
