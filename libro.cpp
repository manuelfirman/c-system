#include "libro.h"
#include <string.h>

Libro::Libro()
{
    _id = -1;
}

Libro::~Libro()
{
    //dtor
}

int Libro::getId()
{
    return _id;
}

const char* Libro::getTitulo()
{
    return _titulo;
}

int Libro::getIdGenero()
{
    return _idGenero;
}

int Libro::getStock()
{
    return _stock;
}

float Libro::getPrecio()
{
    return _precio;
}

Fecha Libro::getFechaPublicacion()
{
    return _publicacion;
}

bool Libro::getEstado()
{
    return _estado;
}

// setters
void Libro::setId(int id)
{
    _id = id;
}

void Libro::setTitulo(const char* titulo)
{
    strcpy(_titulo, titulo);
}

void Libro::setIdGenero(int idGenero)
{
    _idGenero = idGenero;
}

void Libro::setStock(int stock)
{
    _stock = stock;
}

void Libro::setPrecio(float precio)
{
    _precio = precio;
}

void Libro::setFechaPublicacion(Fecha fecha)
{
    _publicacion = fecha;
}

void Libro::setEstado(bool estado)
{
    _estado = estado;
}

// file
bool Libro::grabarEnDisco()
{
    FILE* pFile = fopen("libros.dat", "ab");
    if(pFile == NULL) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return false;
    }

    if(fwrite(&_id, sizeof(_id), 1, pFile) != 1) return false;
    if(fwrite(_titulo, sizeof(_titulo), 1, pFile) != 1) return false;
    if(fwrite(&_idGenero, sizeof(_idGenero), 1, pFile) != 1) return false;
    if(fwrite(&_stock, sizeof(_stock), 1, pFile) != 1) return false;
    if(fwrite(&_precio, sizeof(_precio), 1, pFile) != 1) return false;
    if(fwrite(&_estado, sizeof(_estado), 1, pFile) != 1) return false;
    if(!_publicacion.grabarEnDisco(pFile)) return false;

    fclose(pFile);
    return true;
}

bool Libro::leerDeDisco(int pos)
{
    FILE* pFile = fopen("libros.dat", "rb");
    if(pFile == NULL) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return false;
    }

    fseek(pFile, pos * (sizeof(Fecha) + 3 * sizeof(int) + 50 * sizeof(char) + sizeof(bool) + sizeof(float)), SEEK_SET);

    if(fread(&_id, sizeof(_id), 1, pFile) != 1) return false;
    if(fread(_titulo, sizeof(_titulo), 1, pFile) != 1) return false;
    if(fread(&_idGenero, sizeof(_idGenero), 1, pFile) != 1) return false;
    if(fread(&_stock, sizeof(_stock), 1, pFile) != 1) return false;
    if(fread(&_precio, sizeof(_precio), 1, pFile) != 1) return false;
    if(fread(&_estado, sizeof(_estado), 1, pFile) != 1) return false;
    if(!_publicacion.grabarEnDisco(pFile)) return false;

    fclose(pFile);
    return true;
}

bool Libro::modificarEnDisco(int pos)
{
    FILE* pFile = fopen("libros.dat", "rb+");
    if(pFile == NULL) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return false;
    }

    fseek(pFile, pos * (sizeof(Fecha) + 3 * sizeof(int) + 50 * sizeof(char) + sizeof(bool) + sizeof(float)), SEEK_SET);

    if(fwrite(&_id, sizeof(_id), 1, pFile) != 1) return false;
    if(fwrite(&_titulo, sizeof(_titulo), 1, pFile) != 1) return false;
    if(fwrite(&_idGenero, sizeof(_idGenero), 1, pFile) != 1) return false;
    if(fwrite(&_stock, sizeof(_stock), 1, pFile) != 1) return false;
    if(fwrite(&_precio, sizeof(_precio), 1, pFile) != 1) return false;
    if(fwrite(&_estado, sizeof(_estado), 1, pFile) != 1) return false;
    if(!_publicacion.grabarEnDisco(pFile)) return false;

    fclose(pFile);
    return true;
}

void Libro::toStringShort()
{
    std::cout << _id << "\t" << _precio << "\t" << _titulo << std::endl;
}

void Libro::toString()
{
    std::cout << _id << "\t" << _stock << "\t" << _precio << "\t" << _titulo << std::endl;
}

void Libro::toStringExtendido()
{
    std::cout << _id << "\t" <<  _stock << "\t" << (_idGenero == 1 ? "Terror" : _idGenero == 2 ? "Ficcion" : _idGenero == 3 ? "Comedia" : _idGenero == 4 ? "Anime" : "Drama") << "\t" << _precio << "\t"; _publicacion.MostrarFecha(); std::cout << "\t" << _titulo << "\t" << std::endl;
}


