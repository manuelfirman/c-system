#include "Menu.h"
#include <iostream>
#include <limits>
#include "detalleventa.h"

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
        std::cout << "1. COMPRAR LIBROS" << std::endl;
        std::cout << std::endl << std::endl;
        std::cout << "2. ADMINISTRAR LIBROS" << std::endl;
        std::cout << "3. ADMINISTRAR VENDEDORES" << std::endl;
        std::cout << "4. ADMINISTRAR CLIENTES" << std::endl;
        std::cout << "5. ADMINISTRAR VENTAS" << std::endl;
        std::cout << std::endl << std::endl;


        std::cout << "9. SALIR" << std::endl;
        std::cout << "\nOpcion: ";
        std::cin >> opt;
        system("cls");
        switch(opt){
            case 1:
                menuCompra();
                break;
            case 2:
                administrarLibros();
                break;
            case 3:
                administrarVendedores();
                break;
            case 4:
                administrarClientes();
                break;
            case 5:
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
                mgLibros.listarLibros();
                break;
            case 2:
                menuFiltrarLibros();
                break;
            case 3:
                mgLibros.registrarLibro();
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
        std::cout << std::endl << std::endl;

        std::cout << "8. VOLVER" << std::endl;
        std::cout << "9. SALIR" << std::endl;
        std::cout << "\nOpcion: ";
        std::cin >> opt;
        system("cls");
        switch(opt){
            case 1:
                mgVentas.listarDetalleVentas();
                break;
            case 2:
                menuFiltrarVentas();
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
        std::cout << "1. POR RANGO DE EDAD" << std::endl;
        std::cout << "2. POR GENERO FAVORITO" << std::endl;

        std::cout << std::endl << std::endl;

        std::cout << "8. VOLVER" << std::endl;
        std::cout << "9. SALIR" << std::endl;
        std::cout << "\nOpcion: ";
        std::cin >> opt;
        system("cls");
        switch(opt){
            case 1:
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
            case 2:
                while(!volver2){
                    system("cls");
                    std::cout << "================== RANGO DE EDAD ===================" << std::endl;
                    std::cout << "1. Terror" << std::endl;
                    std::cout << "2. Ciencia Ficcion" << std::endl;
                    std::cout << "3. Comedia" << std::endl;
                    std::cout << "4. Anime" << std::endl;
                    std::cout << "5. Drama" << std::endl;
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

void Menu::menuCompra()
{
    bool salir = false;
    int opt;

    do {
        int id;
        int indice;
        Libro libro;
        bool salir2 = false;
        int opt2;
        int idCliente;
        int idVendedor;

        system("cls");
        std::cout << "=====================================================" << std::endl;
        std::cout << std::string(20, ' ') << "MENU COMPRA" << std::endl;
        std::cout << "=====================================================" << std::endl;

        mgLibros.listarLibrosVenta();

        std::cout << std::endl << std::endl;
        std::cout << "1. AGREGAR LIBRO" << std::endl;
        std::cout << "2. VER CARRITO" << std::endl;
        std::cout << "3. QUITAR LIBRO" << std::endl;
        std::cout << "4. FINALIZAR COMPRA" << std::endl;
        std::cout << std::endl;
        std::cout << "9. SALIR" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opt;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(opt){
            case 1:
                std::cout << "Ingrese ID del libro a agregar:";
                std::cin >> id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                libro = mgLibros.getLibro(id);
                if(libro.getId() == -1){
                    std::cout << "Error: ID Incorrecto. Intente con uno de los Id's listados" << std::endl;
                    system("pause");
                    break;
                }
                std::cout << libro.getTitulo();
                carrito.agregarLibro(libro);
                std::cout << "Libro agregado" << std::endl;
                system("pause");
                break;
            case 2:
                system("cls");
                carrito.listarItems();
                system("pause");
                break;
            case 3:
                while(!salir2){
                    system("cls");

                    carrito.listarItems();
                    std::cout << std::endl << std::endl;
                    std::cout << "1. ELIMINAR LIBRO" << std::endl;
                    std::cout << "9. VOLVER" << std::endl;
                    std::cout << std::endl;

                    std::cout << "Opcion: ";                    std::cin >> opt2;
                    switch(opt2){
                        case 1:
                            std::cout << "Ingrese el N de item a eliminar: ";
                            std::cin >> indice;
                            if(carrito.eliminarLibro(indice)) std::cout << "Libro eliminado del carrito" << std::endl;
                            else std::cout << "Error. Indice incorrecto." << std::endl;
                            system("pause");
                            break;
                        case 9:
                            salir2 = true;
                            break;
                        default:
                            std::cout << "Opcion invalida" << std::endl;
                            system("pause");
                            break;
                    }
                }
                break;
            case 4:
                system("cls");
                std::cout << "Ingrese ID Vendedor: ";
                std::cin >> idVendedor;
                while(!mgVendedores.buscarId(idVendedor)){
                    std::cout << "ID Invalido" << std::endl;
                    std::cout << "Ingrese ID Vendedor: ";
                    std::cin >> idVendedor;
                }

                std::cout << "Ingrese ID Cliente: ";
                std::cin >> idCliente;
                while(!mgClientes.buscarId(idCliente)){
                    std::cout << "ID Invalido" << std::endl;
                    std::cout << "Ingrese ID Cliente: ";
                    std::cin >> idCliente;
                }

                finalizarCompra(idCliente, idVendedor);
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


void Menu::finalizarCompra(int idCliente, int idVendedor)
{
    float total;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::string(20, ' ') << "INFORME DE VENTA" << std::endl;
    std::cout << "=====================================================" << std::endl;

    std::cout << "ID\tTITULO\t\t\tSTOCK\t\tPRECIO" << std::endl;
    for(int i=0; i < carrito.obtenerCantidad(); i++){
        Libro libro = carrito.obtenerLibro(i);
        libro.toString();
        total += libro.getPrecio();
    }
    Vendedor vendedor = mgVendedores.obtenerVendedor(idVendedor);
    Cliente cliente = mgClientes.obtenerCliente(idCliente);
    Libro libro = carrito.obtenerLibro(0);

    std::cout << std::endl << std::endl;
    std::cout << "VENDEDOR: " << vendedor.getNombres() << std::endl;
    std::cout << "CLIENTE: " << cliente.getNombres() << std::endl;
    std::cout << "TOTAL: $" << total << std::endl;

    DetalleVenta detalleVenta;

    detalleVenta.setIdLibro(libro.getId());
    detalleVenta.setTituloLibro(libro.getTitulo());
    detalleVenta.setNombreCliente(cliente.getNombres());
    detalleVenta.setNombreVendedor(vendedor.getNombres());
    detalleVenta.setPrecioTotal(total);

    if(!detalleVenta.grabarEnDisco()) std::cout << "Error. No se pudo generar la compra." << std::endl;

    std::cout << "COMPRA REALIZADA" << std::endl;
    std::cout << "INFORME GUARDADO" << std::endl;
    mgVentas.agregarVenta(detalleVenta);
    carrito.resetCarrito();
    system("pause");
}

