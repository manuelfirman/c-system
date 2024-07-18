#include "carrito.h"

Carrito::Carrito() : libros(nullptr), cantidad(0), capacidad(1)
{
    libros = new Libro[capacidad];
}

Carrito::~Carrito()
{
    //dtor
}

void Carrito::redimensionar(int nuevaCapacidad) {
    Libro* nuevosLibros = new Libro[nuevaCapacidad];
    for (int i = 0; i < cantidad; ++i) {
        nuevosLibros[i] = libros[i];
    }
    delete[] libros;
    libros = nuevosLibros;
    capacidad = nuevaCapacidad;
}

void Carrito::agregarLibro(const Libro& libro) {
    if (cantidad == capacidad) {
        redimensionar(capacidad == 0 ? 1 : capacidad * 2);
    }
    libros[cantidad++] = libro;
}


bool Carrito::eliminarLibro(int indice)
{
    if (indice < 0 || indice > cantidad) {
        std::cerr << "Índice fuera de rango." << std::endl;
        return false;
    }
    for (int i = indice; i < cantidad - 1; ++i) {
        libros[i] = libros[i + 1];
    }
    --cantidad;
    return true;
}

void Carrito::listarItems()
{
    std::cout << "====== CARRITO =======" << std::endl;
    std::cout << "ITEM\tID\tPRECIO\tTITULO" << std::endl;
    for(int i=0; i < cantidad; i++){
        std::cout << i+1 << "\t"; libros[i].toStringShort();
    }
}

int Carrito::obtenerCantidad() const {
    return cantidad;
}

// Método para acceder a los libros
const Libro& Carrito::obtenerLibro(int indice) const {
    if (indice < 0 || indice >= cantidad) {
        throw std::out_of_range("Índice fuera de rango.");
    }
    return libros[indice];
}

void Carrito::resetCarrito()
{
    capacidad = 1;
    cantidad = 0;
    libros = new Libro[capacidad];
}
