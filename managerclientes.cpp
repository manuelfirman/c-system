#include "managerclientes.h"
#include "cliente.h"
#include <limits>
#include <string.h>
ManagerClientes::ManagerClientes() : clientes(nullptr), cantidad(0), capacidad(10)
{
    clientes = new Cliente[capacidad];
    cargarClientes();
}

ManagerClientes::~ManagerClientes()
{
     delete[] clientes;
}

void ManagerClientes::redimensionar(int nuevaCapacidad) {
    Cliente* nuevosClientes = new Cliente[nuevaCapacidad];
    for (int i = 0; i < cantidad; ++i) {
        nuevosClientes[i] = clientes[i];
    }
    delete[] clientes;
    clientes = nuevosClientes;
    capacidad = nuevaCapacidad;
}

void ManagerClientes::agregarCliente(const Cliente& cliente) {
    if (cantidad == capacidad) {
        redimensionar(capacidad == 0 ? 1 : capacidad * 2);
    }
    clientes[cantidad++] = cliente;
}

void ManagerClientes::cargarClientes() {
    Cliente cliente;
    int pos = 0;
    while (cliente.leerDeDisco(pos)){
        agregarCliente(cliente);
        pos++;
    }
}

void ManagerClientes::registrarCliente() {
    std::cout << "===== REGISTRAR NUEVO CLIENTE ======" << std::endl;

    //int id;
    char apellidos[50];
    char nombres[50];
    float sueldo;
    Fecha nacimiento;
    char domicilio[50];
    char telefono[15];
    char mail[100];
    int idGeneroFavorito;

    /*
    std::cout << "Ingrese ID: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(!buscarId(id)){
        std::cout << "El ID ingresado ya existe. Intente nuevamente con otro." << std::endl;
        std::cout << "Ingrese ID: ";
        std::cin >> id;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    */
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Ingrese apellidos: ";
    std::cin.getline(apellidos, 50);

    std::cout << "Ingrese nombres: ";
    std::cin.getline(nombres, 50);

    std::cout << "Ingrese fecha de nacimiento (dd/mm/yyyy): ";
    std::cin >> nacimiento;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Ingrese domicilio: ";
    std::cin.getline(domicilio, 50);

    std::cout << "Ingrese telefono: ";
    std::cin.getline(telefono, 15);

    std::cout << "Ingrese mail: ";
    std::cin.getline(mail, 100);

    std::cout << "Ingrese numero de genero favorito: ";
    std::cout << "1. Terror\n2.Ciencia Ficcion\n3.Comedia\n4.Anime\n5.Drama" << std::endl;
    std::cin >> idGeneroFavorito;

    Cliente nuevoCliente;

    nuevoCliente.setId(cantidad+1);
    nuevoCliente.setApellidos(apellidos);
    nuevoCliente.setNombres(nombres);
    nuevoCliente.setNacimiento(nacimiento);
    nuevoCliente.setEstado(true);

    nuevoCliente.setDomicilio(domicilio);
    nuevoCliente.setTelefono(telefono);
    nuevoCliente.setMail(mail);
    nuevoCliente.setIdGeneroFavorito(idGeneroFavorito);

    agregarCliente(nuevoCliente);
    if (nuevoCliente.grabarEnDisco())
        std::cout << "Cliente registrado correctamente.\n";
    else
        std::cout << "Error. No se pudo registrar el vendedor.\n";
    system("pause");
}

void ManagerClientes::listarClientes() {
    std::cout << "======================================" << std::endl;
    std::cout << "======= LISTADO DE CLIENTES ========" << std::endl;
    std::cout << "======================================" << std::endl << std::endl;
    std::cout << "Ingrese '1' para mostrar solo los vendedores activos." << std::endl;
    std::cout << "Ingrese cualquier otro caracter para mostrar todos los vendedores." << std::endl << std::endl;

    char opcion;
    std::cin >> opcion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < cantidad; ++i) {
         if (opcion == '1' && !clientes[i].getEstado()) {
            continue;
        }
        std::cout << "--------------------------------------" << std::endl;
        clientes[i].toString();
        std::cout << "--------------------------------------" << std::endl << std::endl;
    }

    system("pause");
}

void ManagerClientes::listarClientesVenta() {
    std::cout << "ID\tNOMBRE\tAPELLIDO\n";
    for (int i = 0; i < cantidad; ++i) {
         if (!clientes[i].getEstado()) {
            continue;
        }
        clientes[i].toStringShort();
    }

}

void ManagerClientes::setEstadoCliente(int id, bool estado)
{
    if(id < 0) {
        std::cout << "Ingrese un ID valido" << std::endl;
        return;
    }

    bool encontrado = false;

    for(int i=0; i<cantidad; i++){
        if(clientes[i].getId() == id){
            clientes[i].setEstado(estado);
            clientes[i].modificarEnDisco(i);
            std::cout << "Cliente dado de " << (estado ? "ALTA" : "BAJA") << "..." << std::endl;
            encontrado = true;
            break;
        }
    }

    if(!encontrado){
        std::cout << "No se encontro un cliente con el ID proporcionado" << std::endl;
    }
    system("pause");
}


bool ManagerClientes::buscarId(int id)
{
    Cliente cliente;
    int pos = 0;
    while(cliente.leerDeDisco(pos)){
        if(cliente.getId() == id){
            return true;
        }
        pos++;
    }
    return false;
}

Cliente ManagerClientes::obtenerCliente(int id)
{
    Cliente cliente;
    Cliente aux;
    int pos = 0;
    while(aux.leerDeDisco(pos)){
        if(aux.getId() == id){
            return aux;
        }
        pos++;
    }
    return cliente;
}

void ManagerClientes::filtrarPorNombre(const char* nombre)
{
    Cliente cliente;
    int pos = 0;
    bool encontrado = false;
    while(cliente.leerDeDisco(pos)){
        if(strcmp(cliente.getNombres(), nombre) == 0){
            encontrado = true;
            std::cout << "--------------------------------" << std::endl;
            cliente.toString();
            std::cout << "--------------------------------" << std::endl;
        }
        pos++;
    }
    if(!encontrado) std::cout << "No se encontraron clientes con ese nombre: " << nombre << std::endl;
    system("pause");
}

void ManagerClientes::filtrarPorGenero(int idGenero)
{
    Cliente cliente;
    int pos = 0;
    bool encontrado = false;
    while(cliente.leerDeDisco(pos)){
        if(cliente.getIdGeneroFavorito() == idGenero){
            encontrado = true;
            std::cout << "--------------------------------" << std::endl;
            cliente.toString();
            std::cout << "--------------------------------" << std::endl;
        }
        pos++;
    }
    if(!encontrado) std::cout << "No se encontraron clientes con ese genero: " << idGenero << std::endl;
    system("pause");
}

void ManagerClientes::filtrarPorEdad(int edadMin, int edadMax)
{
    Cliente cliente;
    int pos = 0;
    int edad;
    bool encontrado = false;
    while(cliente.leerDeDisco(pos)){
        edad = 2024 - cliente.getNacimiento().getAnio();
        if(edad > edadMin && edad < edadMax){
            encontrado = true;
            std::cout << "--------------------------------" << std::endl;
            cliente.toString();
            std::cout << "--------------------------------" << std::endl;
        }
        pos++;
    }
    if(!encontrado) std::cout << "No se encontraron clientes con ese rango de edad" << std::endl;
    system("pause");
}
