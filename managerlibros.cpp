#include "managerlibros.h"
#include "libro.h"
#include <limits>

ManagerLibros::ManagerLibros() : libros(nullptr), cantidad(0), capacidad(10)
{
    libros = new Libro[capacidad];
    cargarLibros();
}

ManagerLibros::~ManagerLibros()
{
     delete[] libros;
}

void ManagerLibros::redimensionar(int nuevaCapacidad) {
    Libro* nuevosLibros = new Libro[nuevaCapacidad];
    for (int i = 0; i < cantidad; ++i) {
        nuevosLibros[i] = libros[i];
    }
    delete[] libros;
    libros = nuevosLibros;
    capacidad = nuevaCapacidad;
}

void ManagerLibros::agregarLibro(const Libro& libro) {
    if (cantidad == capacidad) {
        redimensionar(capacidad == 0 ? 1 : capacidad * 2);
    }
    libros[cantidad++] = libro;
}

void ManagerLibros::cargarLibros() {
    Libro libro;
    int pos = 0;
    while (libro.leerDeDisco(pos)){
        agregarLibro(libro);
        pos++;
    }
}

void ManagerLibros::registrarLibro() {
    std::cout << "===== REGISTRAR NUEVO LIBRO ======" << std::endl;

    int id, idGenero, stock;
    char titulo[50];
    float precio;
    Fecha publicacion;
    bool estado;

    std::cout << "Ingrese ID: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    /*
    while(!buscarId(id)){
        std::cout << "El ID ingresado ya existe. Intente nuevamente con otro." << std::endl;
        std::cout << "Ingrese ID: ";
        std::cin >> id;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    */

    std::cout << "Ingrese el titulo: ";
    std::cin.getline(titulo, 50);

    std::cout << "Ingrese el ID del genero: ";
    std::cin >> idGenero;

    std::cout << "Ingrese el stock: ";
    std::cin >> stock;

    std::cout << "Ingrese el precio : $";
    std::cin >> precio;

    std::cout << "Ingrese fecha de publicacion (dd/mm/yyyy): ";
    std::cin >> publicacion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    Libro nuevoLibro;

    nuevoLibro.setId(id);
    nuevoLibro.setTitulo(titulo);
    nuevoLibro.setIdGenero(idGenero);
    nuevoLibro.setStock(stock);
    nuevoLibro.setPrecio(precio);
    nuevoLibro.setFechaPublicacion(publicacion);
    nuevoLibro.setEstado(true);

    agregarLibro(nuevoLibro);

    if (nuevoLibro.grabarEnDisco())
        std::cout << "Libro registrado correctamente.\n";
    else
        std::cout << "Error. No se pudo registrar el libro.\n";
    system("pause");
}

void ManagerLibros::listarLibros() {
    std::cout << "======================================" << std::endl;
    std::cout << "======= LISTADO DE LIBROS ========" << std::endl;
    std::cout << "======================================" << std::endl << std::endl;
    std::cout << "Ingrese '1' para mostrar solo los libros activos." << std::endl;
    std::cout << "Ingrese cualquier otro caracter para mostrar todos los libros." << std::endl << std::endl;

    char opcion;
    std::cin >> opcion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < cantidad; ++i) {
         if (opcion == '1' && !libros[i].getEstado()) {
            continue;
        }
        std::cout << "--------------------------------------" << std::endl;
        libros[i].toString();
        std::cout << "--------------------------------------" << std::endl << std::endl;
    }

    system("pause");
}

void ManagerLibros::listarLibrosVenta() {

    std::cout << "ID\tTITULO\tN GENERO\tSTOCK\tPRECIO" << std::endl;
    for (int i = 0; i < cantidad; ++i) {
         if (!libros[i].getEstado()) {
            continue;
        }
        libros[i].toString();
    }
}

void ManagerLibros::setEstadoLibro(int id, bool estado)
{
    if(id < 0) {
        std::cout << "Ingrese un ID valido" << std::endl;
        return;
    }

    bool encontrado = false;

    for(int i=0; i<cantidad; i++){
        if(libros[i].getId() == id){
            libros[i].setEstado(estado);
            libros[i].modificarEnDisco(i);
            std::cout << "Libro dado de " << (estado ? "ALTA" : "BAJA") << "..." << std::endl;
            encontrado = true;
            break;
        }
    }

    if(!encontrado){
        std::cout << "No se encontro un libro con el ID proporcionado" << std::endl;
    }
    system("pause");
}


bool ManagerLibros::buscarId(int id)
{
    Libro libro;
    int pos = 0;
    while(libro.leerDeDisco(pos)){
        if(libro.getId() == id){
            return true;
        }
        pos++;
    }
    return false;
}

Libro ManagerLibros::getLibro(int id)
{
    Libro aux;
    Libro libro;
    int pos = 0;
    while(aux.leerDeDisco(pos)){
        if(aux.getId() == id){
            libro.setId(aux.getId());
            libro.setTitulo(aux.getTitulo());
            libro.setIdGenero(aux.getIdGenero());
            libro.setStock(aux.getStock());
            libro.setFechaPublicacion(aux.getFechaPublicacion());
            libro.setEstado(aux.getEstado());
            libro.setPrecio(aux.getPrecio());

            return libro;
        }
        pos++;
    }

    return libro;
}
