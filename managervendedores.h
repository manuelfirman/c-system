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
    public:
        ManagerVendedores();
        virtual ~ManagerVendedores();

        bool buscarId(int id);
        void cargarVendedores();
        void listarVendedores();
        void registrarVendedor();
        void agregarVendedor(const Vendedor& vendedor);
        void setEstadoVendedor(int id, bool estado);
        Vendedor obtenerVendedor(int id);

};

#endif // MANAGERVENDEDORES_H
