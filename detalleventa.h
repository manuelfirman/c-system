#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H
#include <iostream>


class DetalleVenta
{
    private:
        int idLibro;
        char nombreVendedor[50];
        char nombreCliente[50];
        char tituloLibro[50];
        float precioTotal;

    public:
        DetalleVenta();
        virtual ~DetalleVenta();

        int getIdLibro();
        const char* getNombreVendedor();
        const char* getNombreCliente();
        const char* getTituloLibro();
        float getPrecioTotal();

        void setIdLibro(int id);
        void setNombreVendedor(const char* nombre);
        void setNombreCliente(const char* nombre);
        void setTituloLibro(const char* titulo);
        void setPrecioTotal(float precio);

        bool grabarEnDisco();
        bool leerDeDisco(int pos);
        bool modificarEnDisco(int pos);

        void toString();

};

#endif // DETALLEVENTA_H
