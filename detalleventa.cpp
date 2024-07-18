#include "detalleventa.h"
#include <string.h>

DetalleVenta::DetalleVenta()
{

}

DetalleVenta::~DetalleVenta()
{
    //dtor
}

int DetalleVenta::getId() {
    return id;
}

const char* DetalleVenta::getNombreVendedor() {
    return nombreVendedor;
}

const char* DetalleVenta::getNombreCliente() {
    return nombreCliente;
}

const char* DetalleVenta::getTituloLibro() {
    return tituloLibro;
}

float DetalleVenta::getPrecioTotal() {
    return precioTotal;
}

// Setters
void DetalleVenta::setId(int newIdLibro) {
    id = newIdLibro;
}

void DetalleVenta::setPrecioTotal(float precio)
{
    precioTotal = precio;
}

void DetalleVenta::setNombreVendedor(const char* newNombreVendedor) {
    strcpy(nombreVendedor, newNombreVendedor);
}

void DetalleVenta::setNombreCliente(const char* newNombreCliente) {
    strcpy(nombreCliente, newNombreCliente);
}

void DetalleVenta::setTituloLibro(const char* titulo)
{
    strcpy(tituloLibro, titulo);
}

bool DetalleVenta::grabarEnDisco()
{
   FILE* pFile = fopen("detalleventa.dat", "ab");
    if(pFile == NULL) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return false;
    }

    int grabo = fwrite(this, sizeof(DetalleVenta), 1, pFile);
    fclose(pFile);
    return grabo == 1;
}

bool DetalleVenta::leerDeDisco(int pos)
{
    FILE* pFile = fopen("detalleventa.dat", "rb");
    if(pFile == NULL) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return false;
    }

    fseek(pFile, pos * sizeof(DetalleVenta), SEEK_SET);
    int leyo = fread(this, sizeof(DetalleVenta), 1, pFile);

    fclose(pFile);
    return leyo == 1;
}

bool DetalleVenta::modificarEnDisco(int pos)
{

}

void DetalleVenta::toString()
{
    std::cout << "ID: " << id << std::endl;
    std::cout << "Cliente: " << nombreCliente << std::endl;
    std::cout << "Vendedor: " << nombreVendedor << std::endl;
    std::cout << "Titulo: " << tituloLibro << std::endl;
    std::cout << "Precio Total: $" << precioTotal << std::endl;
}
