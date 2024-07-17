#include "venta.h"
#include <string.h>

Venta::Venta()
{
    //ctor
}

Venta::~Venta()
{
    //dtor
}

int Venta::getId()
{
    return _id;
}

Fecha Venta::getFecha()
{
    return _fecha;
}

int Venta::getIdCliente()
{
    return _idCliente;
}

int Venta::getIdVendedor()
{
    return _idVendedor;
}

const char* Venta::getFormaPago()
{
    return _formaPago;
}

bool Venta::getEnvio()
{
    return _envio;
}

// setters
void Venta::setId(int id)
{
    _id = id;
}

void Venta::setFecha(Fecha fecha)
{
    _fecha = fecha;
}

void Venta::setIdCliente(int idCliente)
{
    _idCliente = idCliente;
}

void Venta::setIdVendedor(int idVendedor)
{
    _idVendedor = idVendedor;
}

void Venta::setFormaPago(const char* formaPago)
{
    strcpy(_formaPago, formaPago);
}

void Venta::setEnvio(bool envio)
{
    _envio = envio;
}

bool Venta::grabarEnDisco()
{
    FILE* pFile = fopen("ventas.dat", "ab");
    if(pFile == NULL) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return false;
    }

    if(fwrite(&_id, sizeof(_id), 1, pFile) != 1) return false;
    if(fwrite(&_idCliente, sizeof(_idCliente), 1, pFile) != 1) return false;
    if(fwrite(&_idVendedor, sizeof(_idVendedor), 1, pFile) != 1) return false;
    if(fwrite(&_envio, sizeof(_envio), 1, pFile) != 1) return false;
    if(fwrite(_formaPago, sizeof(_formaPago), 1, pFile) != 1) return false;
    if(!_fecha.grabarEnDisco(pFile)) return false;

    fclose(pFile);
    return true;
}

bool Venta::leerDeDisco(int pos)
{
    FILE* pFile = fopen("ventas.dat", "rb");
    if(pFile == NULL) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return false;
    }

    fseek(pFile, pos * (sizeof(Fecha) + 3 * sizeof(int) + 50 * sizeof(char) + sizeof(bool)), SEEK_SET);

    if(fread(&_id, sizeof(_id), 1, pFile) != 1) return false;
    if(fread(&_idCliente, sizeof(_idCliente), 1, pFile) != 1) return false;
    if(fread(&_idVendedor, sizeof(_idVendedor), 1, pFile) != 1) return false;
    if(fread(&_envio, sizeof(_envio), 1, pFile) != 1) return false;
    if(fread(_formaPago, sizeof(_formaPago), 1, pFile) != 1) return false;
    if(!_fecha.grabarEnDisco(pFile)) return false;

    fclose(pFile);
    return true;
}

bool Venta::modificarEnDisco(int pos)
{
    FILE* pFile = fopen("ventas.dat", "rb+");
    if(pFile == NULL) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return false;
    }
    fseek(pFile, pos * (sizeof(Fecha) + 3 * sizeof(int) + 50 * sizeof(char) + sizeof(bool)), SEEK_SET);
    if(fwrite(&_id, sizeof(_id), 1, pFile) != 1) return false;
    if(fwrite(&_idCliente, sizeof(_idCliente), 1, pFile) != 1) return false;
    if(fwrite(&_idVendedor, sizeof(_idVendedor), 1, pFile) != 1) return false;
    if(fwrite(&_envio, sizeof(_envio), 1, pFile) != 1) return false;
    if(fwrite(_formaPago, sizeof(_formaPago), 1, pFile) != 1) return false;
    if(!_fecha.grabarEnDisco(pFile)) return false;

    fclose(pFile);
    return true;
}
