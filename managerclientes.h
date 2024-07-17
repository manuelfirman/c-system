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
        bool buscarId(int id);
    public:
        ManagerClientes();
        virtual ~ManagerClientes();

        void cargarClientes();
        void listarClientes();
        void registrarCliente();
        void agregarCliente(const Cliente& cliente);
        void setEstadoCliente(int id, bool estado);
};

#endif // MANAGERCLIENTES_H
