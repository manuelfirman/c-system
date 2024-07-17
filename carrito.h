#ifndef CARRITO_H
#define CARRITO_H
#include "libro.h"

class Carrito
{
    private:
        int cantidad;
        int capacidad;
        Libro* libros;
        int* cantLibros;

         void redimensionar(int nuevaCap);
    public:
        Carrito();
        virtual ~Carrito();

        void agregarLibro(const Libro& libro);
        bool eliminarLibro(int indice);

        void listarItems();
        int obtenerCantidad() const;
        const Libro& obtenerLibro(int indice) const;

        void resetCarrito();
};

#endif // CARRITO_H
