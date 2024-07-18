#include "persona.h"
#include <string.h>

Persona::Persona() : _id(0), _estado(false)
{
    memset(_apellidos, 0, sizeof(_apellidos));
    memset(_nombres, 0, sizeof(_nombres));
}

Persona::~Persona()
{
    //dtor
}

int Persona::getId()
{
    return _id;
}

const char* Persona::getApellidos()
{
    return _apellidos;
}

const char* Persona::getNombres()
{
    return _nombres;
}

Fecha Persona::getNacimiento()
{
    return _nacimiento;
}

bool Persona::getEstado()
{
    return _estado;
}

void Persona::setId(int id)
{
    _id = id;
}

void Persona::setNombres(const char* nombres)
{
    strcpy(_nombres, nombres);
}

void Persona::setApellidos(const char* apellidos)
{
    strcpy(_apellidos, apellidos);
}

void Persona::setNacimiento(Fecha fechaNac)
{
    _nacimiento = fechaNac;
}

void Persona::setEstado(bool estado)
{
    _estado = estado;
}

bool Persona::leerDeDisco(FILE* file) {
return  fread(&_id, sizeof(_id), 1, file) == 1 &&
        fread(_apellidos, sizeof(_apellidos), 1, file) == 1 &&
        fread(_nombres, sizeof(_nombres), 1, file) == 1 &&
        fread(&_estado, sizeof(_estado), 1, file) == 1 &&
        _nacimiento.leerDeDisco(file);
}

bool Persona::grabarEnDisco(FILE* file) const {
return  fwrite(&_id, sizeof(_id), 1, file) == 1 &&
        fwrite(_apellidos, sizeof(_apellidos), 1, file) == 1 &&
        fwrite(_nombres, sizeof(_nombres), 1, file) == 1 &&
        fwrite(&_estado, sizeof(_estado), 1, file) == 1 &&
        _nacimiento.grabarEnDisco(file);
}

void Persona::toString()
{
    std::cout << "ID: " << _id << "\t" << "Estado: " << (_estado ? "Activo" : "Inactivo") << "\n";
    std::cout << "Nombres: " << _nombres << "\t" << "Apellidos: " << _apellidos << "\n";
    std::cout << "Fecha de Nacimiento: "; _nacimiento.MostrarFecha(); std::cout << std::endl;
}
