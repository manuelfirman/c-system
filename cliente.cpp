#include "cliente.h"
#include "string.h"
Cliente::Cliente()
{
    //ctor
}

Cliente::~Cliente()
{
    //dtor
}

const char* Cliente::getDomicilio() const
{
     return _domicilio;
}

const char* Cliente::getTelefono() const
{
     return _telefono;
}

const char* Cliente::getMail() const
{
    return _mail;
}

int Cliente::getIdGeneroFavorito() const
{
    return _idGeneroFavorito;
}

void Cliente::setDomicilio(const char* domicilio)
{
    strcpy(_domicilio, domicilio);
}

void Cliente::setTelefono(const char* telefono)
{
    strcpy(_telefono, telefono);
}

void Cliente::setMail(const char* mail)
{
    strcpy(_mail, mail);
}

void Cliente::setIdGeneroFavorito(int idGeneroFavorito)
{
    _idGeneroFavorito = idGeneroFavorito;
}

void Cliente::toString()
{
    Persona::toString();
    std::cout << "Domicilio: " << _domicilio << "\n";
    std::cout << "Telefono: " << _telefono << "\n";
    std::cout << "Mail: " << _mail << "\n";
    std::cout << "Genero Favorito: " << _idGeneroFavorito << "\n"; // agregar condicional para mostrar texto en vez de numero

}

bool Cliente::grabarEnDisco(){
    FILE* pFile = fopen("clientes.dat", "ab");
    if(pFile == NULL) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return false;
    }

    if(!Persona::grabarEnDisco(pFile)){
        fclose(pFile);
        return false;
    }

    if(fwrite(&_domicilio, sizeof(_domicilio), 1, pFile) != 1){
        fclose(pFile);
        return false;
    }

    if(fwrite(&_telefono, sizeof(_telefono), 1, pFile) != 1){
        fclose(pFile);
        return false;
    }

    if(fwrite(&_mail, sizeof(_mail), 1, pFile) != 1){
        fclose(pFile);
        return false;
    }

    if(fwrite(&_idGeneroFavorito, sizeof(_idGeneroFavorito), 1, pFile) != 1){
        fclose(pFile);
        return false;
    }


    fclose(pFile);
    return true;
}

bool Cliente::leerDeDisco(int pos){
    FILE* pFile = fopen("clientes.dat", "rb");
    if(pFile == NULL) {
        std::cerr << "Error al abrir el archivo para lectura." << std::endl;
        return false;
    }

    fseek(pFile, pos * (sizeof(int) + 2 * 50 * sizeof(char) + sizeof(Fecha) + sizeof(bool) + 50 * sizeof(char) + 100 * sizeof(char) + 15 * sizeof(char) + sizeof(int)), SEEK_SET);

    if(!Persona::leerDeDisco(pFile)){
        fclose(pFile);
        return false;
    }

    if(fread(&_domicilio, sizeof(_domicilio), 1, pFile) != 1){
        fclose(pFile);
        return false;
    }

    if(fread(&_telefono, sizeof(_telefono), 1, pFile) != 1){
        fclose(pFile);
        return false;
    }

    if(fread(&_mail, sizeof(_mail), 1, pFile) != 1){
        fclose(pFile);
        return false;
    }

    if(fread(&_idGeneroFavorito, sizeof(_idGeneroFavorito), 1, pFile) != 1){
        fclose(pFile);
        return false;
    }


    fclose(pFile);
    return true;
}

bool Cliente::modificarEnDisco(int pos)
{
    FILE* pFile = fopen("clientes.dat", "rb+");
    if(pFile == NULL) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return false;
    }

    fseek(pFile, pos * (sizeof(int) + 2 * 50 * sizeof(char) + sizeof(Fecha) + sizeof(bool) + 50 * sizeof(char) + 100 * sizeof(char) + 15 * sizeof(char) + sizeof(int)), SEEK_SET);

    if(!Persona::grabarEnDisco(pFile)){
        fclose(pFile);
        return false;
    }

    if(fwrite(&_domicilio, sizeof(_domicilio), 1, pFile) != 1){
        fclose(pFile);
        return false;
    }

    if(fwrite(&_telefono, sizeof(_telefono), 1, pFile) != 1){
        fclose(pFile);
        return false;
    }

    if(fwrite(&_mail, sizeof(_mail), 1, pFile) != 1){
        fclose(pFile);
        return false;
    }

    if(fwrite(&_idGeneroFavorito, sizeof(_idGeneroFavorito), 1, pFile) != 1){
        fclose(pFile);
        return false;
    }

    fclose(pFile);
    return true;
}
