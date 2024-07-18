#include "vendedor.h"
#include "fecha.h"

Vendedor::Vendedor()
{
    //ctor
}

Vendedor::~Vendedor()
{
    //dtor
}

Fecha Vendedor::getIngreso()
{
    return _ingreso;
}

float Vendedor::getSueldo()
{
    return _sueldo;
}

void Vendedor::setSueldo(float valor)
{
    _sueldo = valor;
}


void Vendedor::setIngreso(Fecha fecha)
{
    _ingreso = fecha;
}

void Vendedor::toString()
{
    Persona::toString();
    std::cout << "Sueldo: $" << _sueldo << "\n";
    std::cout << "Fecha de Ingreso: "; _ingreso.MostrarFecha();std::cout << std::endl;
}

void Vendedor::toStringShort()
{
    std::cout << _id << "\t" << _nombres << "\t" << _apellidos << "\n";
}

bool Vendedor::grabarEnDisco(){
    FILE* pFile = fopen("vendedores.dat", "ab");
    if(pFile == NULL) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return false;
    }

    if(!Persona::grabarEnDisco(pFile)){
        fclose(pFile);
        return false;
    }

    if(fwrite(&_sueldo, sizeof(_sueldo), 1, pFile) != 1){
        fclose(pFile);
        return false;
    }

    if(!_ingreso.grabarEnDisco(pFile)){
        fclose(pFile);
        return false;
    }

    fclose(pFile);
    return true;
}

bool Vendedor::leerDeDisco(int pos){
    FILE* pFile = fopen("vendedores.dat", "rb");
    if(pFile == NULL) {
        std::cerr << "Error al abrir el archivo para lectura." << std::endl;
        return false;
    }

    fseek(pFile, pos * (sizeof(int) + sizeof(float) + 2 * 50 * sizeof(char) + sizeof(Fecha) + sizeof(bool) + sizeof(Fecha)), SEEK_SET);

    if(!Persona::leerDeDisco(pFile)){
        fclose(pFile);
        return false;
    }

    if(fread(&_sueldo, sizeof(_sueldo), 1, pFile) != 1){
        fclose(pFile);
        return false;
    }

    if(!_ingreso.leerDeDisco(pFile)){
        fclose(pFile);
        return false;
    }

    fclose(pFile);
    return true;
}

bool Vendedor::modificarEnDisco(int pos)
{
    FILE* pFile = fopen("vendedores.dat", "rb+");
    if(pFile == NULL) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return false;
    }

    fseek(pFile, pos * (sizeof(int) + sizeof(float) + 2 * 50 * sizeof(char) + sizeof(Fecha) + sizeof(bool) + sizeof(Fecha)), SEEK_SET);

    if(!Persona::grabarEnDisco(pFile)){
        fclose(pFile);
        return false;
    }

    if(fwrite(&_sueldo, sizeof(_sueldo), 1, pFile) != 1){
        fclose(pFile);
        return false;
    }

    if(!_ingreso.grabarEnDisco(pFile)){
        fclose(pFile);
        return false;
    }

    fclose(pFile);
    return true;
}
