#ifndef MANAGERVENDEDORES_H
#define MANAGERVENDEDORES_H
#include "fecha.h"
#include "vendedor.h"

class ManagerVendedores
{
    private:
        int cantidad;
        int capacidad;
        Vendedor* vendedores;

        void redimensionar(int nuevaCap);
        bool buscarId(int id);
    public:
        ManagerVendedores();
        virtual ~ManagerVendedores();

        void cargarVendedores();
        void listarVendedores();
        void registrarVendedor();
        void agregarVendedor(const Vendedor& vendedor);
        void setEstadoVendedor(int id, bool estado);

};

#endif // MANAGERVENDEDORES_H
