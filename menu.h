#ifndef MENU_H
#define MENU_H
#include "managervendedores.h"
#include "managerclientes.h"


class Menu
{
    private:
        ManagerVendedores mgVendedores;
        ManagerClientes mgClientes;

        void administrarLibros();
        void administrarClientes();
        void administrarVendedores();
        void administrarVentas();

        void menuFiltrarClientes();
        void menuFiltrarLibros();
        void menuFiltrarVentas();
    public:
        Menu();
        virtual ~Menu();

        void iniciar();

    protected:


};

#endif // MENU_H
