#ifndef VENTA_H
#define VENTA_H
#include "fecha.h"

class Venta
{
    private:
        int _id;
        Fecha _fecha;
        int _idCliente;
        int _idVendedor;
        char _formaPago[50];
        bool _envio;

    public:
        Venta();
        virtual ~Venta();

        // getters
        int getId();
        Fecha getFecha();
        int getIdCliente();
        int getIdVendedor();
        const char* getFormaPago();
        bool getEnvio();

        // setters
        void setId(int id);
        void setFecha(Fecha fecha);
        void setIdCliente(int idCliente);
        void setIdVendedor(int idVendedor);
        void setFormaPago(const char* formaPago);
        void setEnvio(bool envio);

        // file
        bool grabarEnDisco();
        bool leerDeDisco(int pos);
        bool modificarEnDisco(int pos);

};

#endif // VENTA_H
