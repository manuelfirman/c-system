#include "managervendedores.h"
#include "vendedor.h"
#include <limits>

ManagerVendedores::ManagerVendedores()
    : vendedores(nullptr), cantidad(0), capacidad(10) {
    vendedores = new Vendedor[capacidad];
    cargarVendedores();
}

ManagerVendedores::~ManagerVendedores() {
    delete[] vendedores;
}

void ManagerVendedores::redimensionar(int nuevaCapacidad) {
    Vendedor* nuevosVendedores = new Vendedor[nuevaCapacidad];
    for (int i = 0; i < cantidad; ++i) {
        nuevosVendedores[i] = vendedores[i];
    }
    delete[] vendedores;
    vendedores = nuevosVendedores;
    capacidad = nuevaCapacidad;
}

void ManagerVendedores::agregarVendedor(const Vendedor& vendedor) {
    if (cantidad == capacidad) {
        redimensionar(capacidad == 0 ? 1 : capacidad * 2);
    }
    vendedores[cantidad++] = vendedor;
}

void ManagerVendedores::cargarVendedores() {
    Vendedor vendedor;
    int pos = 0;
    while (vendedor.leerDeDisco(pos)){
        agregarVendedor(vendedor);
        pos++;
    }
}

void ManagerVendedores::registrarVendedor() {
    std::cout << "===== REGISTRAR NUEVO VENDEDOR ======" << std::endl;

    //int id;
    char apellidos[50];
    char nombres[50];
    //int dia, mes, anio;
    float sueldo;
    Fecha nacimiento;
    Fecha ingreso;

    /*
    std::cout << "Ingrese ID: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while(!buscarId(id)){
        std::cout << "El ID ingresado ya existe. Intente nuevamente con otro." << std::endl;
        std::cout << "Ingrese ID: ";
        std::cin >> id;
    }
    */
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Ingrese apellidos: ";
    //std::getline(std::cin, apellidos);
    std::cin.getline(apellidos, 50);

    std::cout << "Ingrese nombres: ";
    std::cin.getline(nombres, 50);

    std::cout << "Ingrese sueldo: ";
    std::cin >> sueldo;

    std::cout << "Ingrese fecha de nacimiento (dd/mm/yyyy): ";
    std::cin >> nacimiento;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Ingrese fecha de ingreso (dd/mm/yyyy): ";
    std::cin >> ingreso;

    Vendedor nuevoVendedor;

    nuevoVendedor.setId(cantidad+1);
    nuevoVendedor.setApellidos(apellidos);
    nuevoVendedor.setNombres(nombres);
    nuevoVendedor.setNacimiento(nacimiento);
    nuevoVendedor.setEstado(true);
    nuevoVendedor.setSueldo(sueldo);
    nuevoVendedor.setIngreso(ingreso);

    agregarVendedor(nuevoVendedor);
    if (nuevoVendedor.grabarEnDisco())
        std::cout << "Vendedor registrado correctamente.\n";
    else
        std::cout << "Error. No se pudo registrar el vendedor.\n";
    system("pause");
}

void ManagerVendedores::listarVendedores() {
    std::cout << "======================================" << std::endl;
    std::cout << "======= LISTADO DE VENDEDORES ========" << std::endl;
    std::cout << "======================================" << std::endl << std::endl;
    std::cout << "Ingrese '1' para mostrar solo los vendedores activos." << std::endl;
    std::cout << "Ingrese cualquier otro caracter para mostrar todos los vendedores." << std::endl << std::endl;

    char opcion;
    std::cin >> opcion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < cantidad; ++i) {
         if (opcion == '1' && !vendedores[i].getEstado()) {
            continue;
        }
        std::cout << "--------------------------------------" << std::endl;
        vendedores[i].toString();
        std::cout << "--------------------------------------" << std::endl << std::endl;
    }

    system("pause");
}

void ManagerVendedores::listarVendedoresVenta() {

    std::cout << "ID\tNOMBRE\tAPELLIDO\n";
    for (int i = 0; i < cantidad; ++i) {
         if (!vendedores[i].getEstado()) {
            continue;
        }
        vendedores[i].toStringShort();
    }
}

void ManagerVendedores::setEstadoVendedor(int id, bool estado)
{
    if(id < 0) {
        std::cout << "Ingrese un ID valido" << std::endl;
        return;
    }

    bool encontrado = false;

    for(int i=0; i<cantidad; i++){
        if(vendedores[i].getId() == id){
            vendedores[i].setEstado(estado);
            vendedores[i].modificarEnDisco(i);
            std::cout << "Vendedor dado de " << (estado ? "ALTA" : "BAJA") << "..." << std::endl;
            encontrado = true;
            break;
        }
    }

    if(!encontrado){
        std::cout << "No se encontro un vendedor con el ID proporcionado" << std::endl;
    }
    system("pause");
}


bool ManagerVendedores::buscarId(int id)
{
    Vendedor vendedor;
    int pos = 0;
    while(vendedor.leerDeDisco(pos)){
        if(vendedor.getId() == id){
            return true;
        }
        pos++;
    }
    return false;
}

Vendedor ManagerVendedores::obtenerVendedor(int id)
{
    Vendedor vendedor;
    Vendedor aux;
    int pos = 0;
    while(aux.leerDeDisco(pos)){
        if(aux.getId() == id){
            return aux;
        }
        pos++;
    }
    return vendedor;
}
