#ifndef MENU_H
#define MENU_H
#include "managervendedores.h"
#include "managerclientes.h"
#include "managerventas.h"
#include "managerlibros.h"
#include "carrito.h"

class Menu
{
    private:
        Carrito carrito;
        ManagerVendedores mgVendedores;
        ManagerClientes mgClientes;
        ManagerLibros mgLibros;
        ManagerVentas mgVentas;

        void administrarLibros();
        void administrarClientes();
        void administrarVendedores();
        void administrarVentas();

        void menuFiltrarClientes();
        void menuFiltrarLibros();
        void menuFiltrarVentas();
        void menuCompra();
        void finalizarCompra(int idCliente, int idVendedor);
    public:
        Menu();
        virtual ~Menu();

        void iniciar();

    protected:


};

#endif // MENU_H
