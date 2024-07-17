#include "Menu.h"
#include <iostream>
#include <limits>

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

// INICIAR MENU GENERAL
void Menu::iniciar()
{
    bool salir = false;
    int opt;

    do {
        system("cls");
        std::cout << "=====================================================" << std::endl;
        std::cout << std::string(20, ' ') << "MENU" << std::endl;
        std::cout << "=====================================================" << std::endl;
        std::cout << "1. ADMINISTRAR LIBROS" << std::endl;
        std::cout << "2. ADMINISTRAR VENDEDORES" << std::endl;
        std::cout << "3. ADMINISTRAR CLIENTES" << std::endl;
        std::cout << "4. ADMINISTRAR VENTAS" << std::endl;
        std::cout << std::endl << std::endl;


        std::cout << "9. SALIR" << std::endl;
        std::cout << "\nOpcion: ";
        std::cin >> opt;
        system("cls");
        switch(opt){
            case 1:
                administrarLibros();
                break;
            case 2:
                administrarVendedores();
                break;
            case 3:
                administrarClientes();
                break;
            case 4:
                administrarVentas();
                break;

            case 9:
                salir = true;
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida" << std::endl;
                system("pause");
                break;

        }


    } while(!salir);

    system("pause");
}

// MENU LIBROS
void Menu::administrarLibros()
{
    bool salir = false;
    bool volver = false;

    int opt;

    do {
        system("cls");
        std::cout << "=====================================================" << std::endl;
        std::cout << std::string(20, ' ') << "LIBROS" << std::endl;
        std::cout << "=====================================================" << std::endl;
        std::cout << "1. LISTAR" << std::endl;
        std::cout << "2. FILTRAR" << std::endl;
        std::cout << "3. CARGAR NUEVO LIBRO" << std::endl;
        std::cout << std::endl << std::endl;

        std::cout << "8. VOLVER" << std::endl;
        std::cout << "9. SALIR" << std::endl;
        std::cout << "\nOpcion: ";
        std::cin >> opt;
        system("cls");
        switch(opt){
            case 1:
                // llamar funcion para listar todos los libros
                break;
            case 2:
                menuFiltrarLibros();
                break;
            case 3:
                // llamar funcion para cargar un libro
                break;
            case 8:
                volver = true;
                break;
            case 9:
                salir = true;
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida" << std::endl;
                system("pause");
                break;
        }

        if(salir){
            exit(1);
        }
    } while(!volver);
}


// MENU VENDEDORES
void Menu::administrarVendedores()
{
    bool salir = false;
    bool volver = false;
    int id;

    int opt;

    do {
        system("cls");
        std::cout << "=====================================================" << std::endl;
        std::cout << std::string(20, ' ') << "VENDEDORES" << std::endl;
        std::cout << "=====================================================" << std::endl;
        std::cout << "1. LISTAR VENDEDORES" << std::endl;
        std::cout << "2. CARGAR NUEVO VENDEDOR" << std::endl;
        std::cout << "3. BAJA VENDEDOR" << std::endl;
        std::cout << "4. ALTA VENDEDOR" << std::endl;

        std::cout << std::endl << std::endl;

        std::cout << "8. VOLVER" << std::endl;
        std::cout << "9. SALIR" << std::endl;
        std::cout << "\nOpcion: ";
        std::cin >> opt;
        system("cls");
        switch(opt){
            case 1:
                mgVendedores.listarVendedores();
                break;
            case 2:
                mgVendedores.registrarVendedor();
                break;
            case 3:
                std::cout << "========= BAJA VENDEDOR =========" << std::endl;
                std::cout << "Ingrese el ID del VENDEDOR: ";
                std::cin >> id;
                mgVendedores.setEstadoVendedor(id, false);
                break;
            case 4:
                std::cout << "========= ALTA VENDEDOR =========" << std::endl;
                std::cout << "Ingrese el ID del VENDEDOR: ";
                std::cin >> id;
                mgVendedores.setEstadoVendedor(id, true);
                break;
            case 8:
                volver = true;
                break;
            case 9:
                salir = true;
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida" << std::endl;
                system("pause");
                break;
        }

        if(salir){
            exit(1);
        }
    } while(!volver);
}

// MENU CLIENTES
void Menu::administrarClientes()
{
    bool salir = false;
    bool volver = false;
    int id;
    int opt;

    do {
        system("cls");
        std::cout << "=====================================================" << std::endl;
        std::cout << std::string(20, ' ') << "CLIENTES" << std::endl;
        std::cout << "=====================================================" << std::endl;
        std::cout << "1. LISTAR CLIENTES" << std::endl;
        std::cout << "2. FILTRAR CLIENTES" << std::endl;
        std::cout << "3. CARGAR NUEVO CLIENTE" << std::endl;
        std::cout << "4. BAJA CLIENTE" << std::endl;
        std::cout << "5. ALTA CLIENTE" << std::endl;
        std::cout << std::endl << std::endl;

        std::cout << "8. VOLVER" << std::endl;
        std::cout << "9. SALIR" << std::endl;
        std::cout << "\nOpcion: ";
        std::cin >> opt;
        system("cls");
        switch(opt){
            case 1:
                mgClientes.listarClientes();
                break;
            case 2:
                menuFiltrarClientes();
                break;
            case 3:
                mgClientes.registrarCliente();
                break;
            case 4:
                std::cout << "========= BAJA CLIENTE =========" << std::endl;
                std::cout << "Ingrese el ID del CLIENTE: ";
                std::cin >> id;
                mgClientes.setEstadoCliente(id, false);
                break;
            case 5:
                std::cout << "========= ALTA CLIENTE =========" << std::endl;
                std::cout << "Ingrese el ID del CLIENTE: ";
                std::cin >> id;
                mgClientes.setEstadoCliente(id, true);
                break;
            case 8:
                volver = true;
                break;
            case 9:
                salir = true;
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida" << std::endl;
                system("pause");
                break;
        }

        if(salir){
            exit(1);
        }
    } while(!volver);
}

// MENU VENTAS
void Menu::administrarVentas()
{
    bool salir = false;
    bool volver = false;

    int opt;

    do {
        system("cls");
        std::cout << "=====================================================" << std::endl;
        std::cout << std::string(20, ' ') << "VENTAS" << std::endl;
        std::cout << "=====================================================" << std::endl;
        std::cout << "1. LISTAR" << std::endl;
        std::cout << "2. FILTRAR" << std::endl;
        std::cout << "3. REGISTRAR NUEVA VENTA" << std::endl;
        std::cout << std::endl << std::endl;

        std::cout << "8. VOLVER" << std::endl;
        std::cout << "9. SALIR" << std::endl;
        std::cout << "\nOpcion: ";
        std::cin >> opt;
        system("cls");
        switch(opt){
            case 1:
                // llamar funcion para listar todas las ventas
                break;
            case 2:
                menuFiltrarVentas();
                break;
            case 3:
                // llamar funcion para registrar una nueva venta
                break;
            case 8:
                volver = true;
                break;
            case 9:
                salir = true;
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida" << std::endl;
                system("pause");
                break;
        }

        if(salir){
            exit(1);
        }
    } while(!volver);
}

// SUB MENU FILTRO DE VENTAS
void Menu::menuFiltrarLibros(){
    bool salir = false;
    bool volver = false;
    bool volver2 = false;

    std::string nombreGenero;
    std::string nombreAutor;

    int opt;
    int opt2;

    do {
        system("cls");
        std::cout << "================== FILTRAR LIBROS ===================" << std::endl;
        std::cout << "1. POR GENERO" << std::endl;
        std::cout << "2. POR AUTOR" << std::endl;
        std::cout << "3. POR RANGO DE PRECIO" << std::endl;
        std::cout << std::endl << std::endl;

        std::cout << "8. VOLVER" << std::endl;
        std::cout << "9. SALIR" << std::endl;
        std::cout << "\nOpcion: ";
        std::cin >> opt;
        system("cls");
        switch(opt){
            case 1:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nIngrese el nombre del GENERO: ";
                getline(std::cin, nombreGenero);
                // llamar funcion que busca por genero pasando `nombreGenero`
                std::cout << nombreGenero;
                system("pause");
                break;
            case 2:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nIngrese el nombre del AUTOR: ";
                getline(std::cin, nombreAutor);
                // llamar funcion que busca por genero pasando `nombreAutor`
                std::cout << nombreAutor;
                system("pause");
                break;
            case 3:
                while(!volver2){
                    system("cls");
                    std::cout << "================== RANGO DE PRECIOS ===================" << std::endl;
                    std::cout << "1. $0 - $100" << std::endl;
                    std::cout << "2. $101 - $200" << std::endl;
                    std::cout << "3. $201 - $500" << std::endl;
                    std::cout << "4. $501 - $1000" << std::endl;
                    std::cout << "5. $1000+" << std::endl;
                    std::cout << std::endl << std::endl;

                    std::cout << "8. VOLVER" << std::endl;
                    std::cout << "9. SALIR" << std::endl;
                    std::cout << "\nOpcion: ";
                    std::cin >> opt2;
                    switch(opt2){
                        case 1:
                            // llamar funcion pasando como parametro (0, 100)
                            break;
                        case 2:
                            // llamar funcion pasando como parametro (101, 200)
                            break;
                        case 3:
                            // llamar funcion pasando como parametro (201, 500)
                            break;
                        case 4:
                            // llamar funcion pasando como parametro (501, 1000)
                            break;
                        case 5:
                            // llamar funcion pasando como parametro (1000, )
                            break;
                        case 8:
                            volver2 = true;
                            break;
                        case 9:
                            salir = true;
                            std::cout << "Saliendo..." << std::endl;
                            break;
                        default:
                            std::cout << "Opcion invalida" << std::endl;
                            system("pause");
                            break;
                    }

                    if(salir){
                        exit(1);
                    }
                }
                volver2 = false;
                break;
            case 8:
                volver = true;
                break;
            case 9:
                salir = true;
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida" << std::endl;
                system("pause");
                break;
        }

        if(salir){
            exit(1);
        }
    } while(!volver);
}

// SUB MENU FILTRO DE CLIENTES
void Menu::menuFiltrarClientes(){
    bool salir = false;
    bool volver = false;
    bool volver2 = false;

    std::string dniCliente;

    int opt;
    int opt2;

    do {
        system("cls");
        std::cout << "================== FILTRAR CLIENTES ===================" << std::endl;
        std::cout << "1. POR DNI" << std::endl;
        std::cout << "2. POR RANGO DE EDAD" << std::endl;
        std::cout << std::endl << std::endl;

        std::cout << "8. VOLVER" << std::endl;
        std::cout << "9. SALIR" << std::endl;
        std::cout << "\nOpcion: ";
        std::cin >> opt;
        system("cls");
        switch(opt){
            case 1:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nIngrese el DNI del CLIENTE: ";
                getline(std::cin, dniCliente);
                // llamar funcion que busca por DNI pasando `dniCliente`
                //managerClientes.buscarDNI(dniCliente);
                break;
            case 2:
                while(!volver2){
                    system("cls");
                    std::cout << "================== RANGO DE EDAD ===================" << std::endl;
                    std::cout << "1. 10 - 15" << std::endl;
                    std::cout << "2. 15 - 20" << std::endl;
                    std::cout << "3. 20 - 30" << std::endl;
                    std::cout << "4. 30 - 45" << std::endl;
                    std::cout << "5. 45+" << std::endl;
                    std::cout << std::endl << std::endl;

                    std::cout << "8. VOLVER" << std::endl;
                    std::cout << "9. SALIR" << std::endl;
                    std::cout << "\nOpcion: ";
                    std::cin >> opt2;
                    switch(opt2){
                        case 1:
                            // llamar funcion pasando como parametro (10, 15)
                            break;
                        case 2:
                            // llamar funcion pasando como parametro (15, 20)
                            break;
                        case 3:
                            // llamar funcion pasando como parametro (20, 30)
                            break;
                        case 4:
                            // llamar funcion pasando como parametro (30, 45)
                            break;
                        case 5:
                            // llamar funcion pasando como parametro (45, 100)
                            break;
                        case 8:
                            volver2 = true;
                            break;
                        case 9:
                            salir = true;
                            std::cout << "Saliendo..." << std::endl;
                            break;
                        default:
                            std::cout << "Opcion invalida" << std::endl;
                            system("pause");
                            break;
                    }

                    if(salir){
                        exit(1);
                    }
                }
                volver2 = false;
                break;
            case 8:
                volver = true;
                break;
            case 9:
                salir = true;
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida" << std::endl;
                system("pause");
                break;
        }

        if(salir){
            exit(1);
        }
    } while(!volver);
}


// SUB MENU FILTRO DE VENTAS
void Menu::menuFiltrarVentas(){
    bool salir = false;
    bool volver = false;

    std::string nombreLibro;
    std::string nombreCliente;
    std::string nombreAutor;


    int opt;

    do {
        system("cls");
        std::cout << "================== FILTRAR VENTAS ===================" << std::endl;
        std::cout << "1. POR LIBRO" << std::endl;
        std::cout << "2. POR CLIENTE" << std::endl;
        std::cout << "3. POR AUTOR" << std::endl;
        std::cout << std::endl << std::endl;

        std::cout << "8. VOLVER" << std::endl;
        std::cout << "9. SALIR" << std::endl;
        std::cout << "\nOpcion: ";
        std::cin >> opt;
        system("cls");
        switch(opt){
            case 1:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nIngrese el nombre del LIBRO: ";
                getline(std::cin, nombreLibro);
                // llamar funcion que filtra por nombre de libro pasando `nombreLibro`
                break;
            case 2:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nIngrese el nombre del CLIENTE: ";
                getline(std::cin, nombreCliente);
                // llamar funcion que filtra por nombre de cliente pasando `nombreCliente`
                break;
             case 3:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nIngrese el nombre del CLIENTE: ";
                getline(std::cin, nombreAutor);
                // llamar funcion que filtra por nombre de autor pasando `nombreAutor`
                break;
            case 8:
                volver = true;
                break;
            case 9:
                salir = true;
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida" << std::endl;
                system("pause");
                break;
        }

        if(salir){
            exit(1);
        }
    } while(!volver);
}
