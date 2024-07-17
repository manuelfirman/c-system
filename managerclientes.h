#ifndef MANAGERCLIENTES_H
#define MANAGERCLIENTES_H
#include "cliente.h"

class ManagerClientes
{
    private:
        int cantidad;
        int capacidad;
        Cliente* clientes;

        void redimensionar(int nuevaCap);
    public:
        ManagerClientes();
        virtual ~ManagerClientes();

        bool buscarId(int id);
        void cargarClientes();
        void listarClientes();
        void registrarCliente();
        void agregarCliente(const Cliente& cliente);
        void setEstadoCliente(int id, bool estado);
        Cliente obtenerCliente(int id);
};

#endif // MANAGERCLIENTES_H
