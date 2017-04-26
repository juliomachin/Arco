#include "persona.h"

Persona::Persona(string Nombre, string Apellidos ,string DNI)
{

  this->Nombre=Nombre;
  this->Apellidos=Apellidos;
  this->DNI=DNI;
}

Persona::Persona()
{

}

Persona::~Persona()
{

}

string Persona::getNombre()
{
    return Nombre;
}

void Persona::setNombre(string value)
{
    Nombre=value;
}

string Persona::getApellidos()
{
    return Apellidos;
}

void Persona::setApellidos(string value)
{
    Apellidos=value;
}

string Persona::getDNI()
{
    return DNI;
}

void Persona::setDNI(string value)
{
    DNI=value;
}
