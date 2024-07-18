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

        int getCantidad();
        void cargarVentas();
        void actualizarVentas();
        void listarVentas();
        void listarDetalleVentas();
        void registrarVenta();
        void agregarVenta(const DetalleVenta& venta);
        void setEstadoVenta(int id, bool estado);
        void filtrarPorLibro(const char* titulo);
        void filtrarPorCliente(const char* nombre);
        void filtrarPorVendedor(const char* nombre);
};

#endif // MANAGERVENTAS_H
