#ifndef MANAGERVENTAS_H
#define MANAGERVENTAS_H
#include "detalleventa.h"
#include "venta.h"

class ManagerVentas
{
    private:
        int cantidad;
        int capacidad;
        DetalleVenta* ventas;

        void redimensionar(int nuevaCap);
        bool buscarId(int id);
    public:
        ManagerVentas();
        virtual ~ManagerVentas();

        void cargarVentas();
        void actualizarVentas();
        void listarVentas();
        void listarDetalleVentas();
        void registrarVenta();
        void agregarVenta(const DetalleVenta& venta);
        void setEstadoVenta(int id, bool estado);
};

#endif // MANAGERVENTAS_H
