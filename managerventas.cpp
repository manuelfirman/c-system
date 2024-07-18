#include "managerventas.h"
#include "venta.h"
#include <limits>
#include <string.h>

ManagerVentas::ManagerVentas() : ventas(nullptr), cantidad(0), capacidad(10)
{
    ventas = new DetalleVenta[capacidad];
    cargarVentas();

}


ManagerVentas::~ManagerVentas() {
    delete[] ventas;
}

void ManagerVentas::redimensionar(int nuevaCapacidad) {
    DetalleVenta* nuevasVentas = new DetalleVenta[nuevaCapacidad];
    for (int i = 0; i < cantidad; ++i) {
        nuevasVentas[i] = ventas[i];
    }
    delete[] ventas;
    ventas = nuevasVentas;
    capacidad = nuevaCapacidad;
}

void ManagerVentas::agregarVenta(const DetalleVenta& venta) {
    if (cantidad == capacidad) {
        redimensionar(capacidad == 0 ? 1 : capacidad * 2);
    }
    ventas[cantidad++] = venta;
}

void ManagerVentas::cargarVentas() {
    DetalleVenta venta;
    int pos = 0;
    while (venta.leerDeDisco(pos)){
        agregarVenta(venta);
        pos++;
    }
}

void ManagerVentas::actualizarVentas() {
    DetalleVenta venta;
    int pos = 0;
    while (venta.leerDeDisco(pos)){
        agregarVenta(venta);
        pos++;
    }
}


void ManagerVentas::registrarVenta() {
    std::cout << "===== REGISTRAR NUEVA VENTA ======" << std::endl;

    int id;
    int idVendedor;
    int idCliente;
    char formaPago[50];
    Fecha fecha;
    bool envio;

    std::cout << "Ingrese ID de la Venta: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    /*
    while(!buscarId(id)){
        std::cout << "El ID ingresado ya existe. Intente nuevamente con otro." << std::endl;
        std::cout << "Ingrese ID: ";
        std::cin >> id;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Ingrese ID del Cliente: ";
    std::cin >> idCliente;

    std::cout << "Ingrese ID del Vendedor: ";
    std::cin >> idVendedor;

    std::cout << "Ingrese nombres: ";
    std::cin.getline(formaPago, 50);

    std::cout << "Ingrese envio (1 con envio - 0 sin envio): ";
    std::cin >> envio;

    std::cout << "Ingrese fecha de nacimiento (dd/mm/yyyy): ";
    std::cin >> fecha;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Venta nuevaVenta;

    nuevaVenta.setId(id);
    nuevaVenta.setIdCliente(idCliente);
    nuevaVenta.setIdVendedor(idVendedor);
    nuevaVenta.setEnvio(envio);
    nuevaVenta.setFecha(fecha);

    agregarVenta(nuevaVenta);

    if (nuevaVenta.grabarEnDisco())
        std::cout << "Venta registrada correctamente.\n";
    else
        std::cout << "Error. No se pudo registrar la venta.\n";
    */
    system("pause");
}

int ManagerVentas::getCantidad()
{
    return cantidad;
}

void ManagerVentas::listarVentas() {
    std::cout << "======================================" << std::endl;
    std::cout << "======= LISTADO DE VENTAS ========" << std::endl;
    std::cout << "======================================" << std::endl << std::endl;
    std::cout << "Ingrese '1' para mostrar solo los ventas activos." << std::endl;
    std::cout << "Ingrese cualquier otro caracter para mostrar todos los ventas." << std::endl << std::endl;

    char opcion;
    std::cin >> opcion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < cantidad; ++i) {
/*
         if (opcion == '1' && !ventas[i].getEstado()) {
            continue;
        }
        */
        std::cout << "--------------------------------------" << std::endl;
        ventas[i].toString();
        std::cout << "--------------------------------------" << std::endl << std::endl;
    }

    system("pause");
}

void ManagerVentas::listarDetalleVentas() {
    std::cout << "======================================" << std::endl;
    std::cout << "======= LISTADO DE VENTAS ========" << std::endl;
    std::cout << "======================================" << std::endl << std::endl;

    for (int i = 0; i < cantidad; ++i) {
        std::cout << "--------------------------------------" << std::endl;
        ventas[i].toString();
        std::cout << "--------------------------------------" << std::endl << std::endl;
    }

    system("pause");
}

void ManagerVentas::setEstadoVenta(int id, bool estado)
{
    if(id < 0) {
        std::cout << "Ingrese un ID valido" << std::endl;
        return;
    }

    bool encontrado = false;
/*
    for(int i=0; i<cantidad; i++){
        if(ventas[i].getId() == id){
            //ventas[i].setEstado(estado);
            ventas[i].modificarEnDisco(i);
            std::cout << "Vendedor dado de " << (estado ? "ALTA" : "BAJA") << "..." << std::endl;
            encontrado = true;
            break;
        }
    }

    if(!encontrado){
        std::cout << "No se encontro un vendedor con el ID proporcionado" << std::endl;
    }
    */
    system("pause");
}


bool ManagerVentas::buscarId(int id)
{
    Venta venta;
    int pos = 0;
    while(venta.leerDeDisco(pos)){
        if(venta.getId() == id){
            return true;
        }
        pos++;
    }
    return false;
}

void ManagerVentas::filtrarPorLibro(const char* titulo)
{
    DetalleVenta venta;
    int pos = 0;
    bool encontrado = false;
    while(venta.leerDeDisco(pos)){
        if(strcmp(venta.getTituloLibro(), titulo) == 0){
            encontrado = true;
            std::cout << "--------------------------------" << std::endl;
            venta.toString();
            std::cout << "--------------------------------" << std::endl;
        }
        pos++;
    }
    if(!encontrado) std::cout << "No se encontraron ventas del libro " << titulo << std::endl;
    system("pause");
}

void ManagerVentas::filtrarPorCliente(const char* nombre)
{
    DetalleVenta venta;
    int pos = 0;
    bool encontrado = false;
    while(venta.leerDeDisco(pos)){
        if(strcmp(venta.getNombreCliente(), nombre) == 0){
            encontrado = true;
            std::cout << "--------------------------------" << std::endl;
            venta.toString();
            std::cout << "--------------------------------" << std::endl;
        }
        pos++;
    }
    if(!encontrado) std::cout << "No se encontraron ventas del libro " << nombre << std::endl;
    system("pause");
}

void ManagerVentas::filtrarPorVendedor(const char* nombre)
{
    DetalleVenta venta;
    int pos = 0;
    bool encontrado = false;
    while(venta.leerDeDisco(pos)){
        if(strcmp(venta.getNombreVendedor(), nombre) == 0){
            encontrado = true;
            std::cout << "--------------------------------" << std::endl;
            venta.toString();
            std::cout << "--------------------------------" << std::endl;
        }
        pos++;
    }
    if(!encontrado) std::cout << "No se encontraron ventas del libro " << nombre << std::endl;
    system("pause");
}
