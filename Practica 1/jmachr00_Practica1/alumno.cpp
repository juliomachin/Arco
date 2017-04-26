#include "alumno.h"
#include "persona.h"
Alumno::Alumno()
{

}

Alumno::Alumno(string Nombre, string Apellidos, string DNI)
{

    this->setNombre(Nombre);
    this->setApellidos(Apellidos);
    this->setDNI(DNI);
}

Alumno::~Alumno()
{

}

void Alumno::anyadirNota(int nota)
{
    if(notas.size()<3){
        notas.push_back(nota);
    }
}

void Alumno::imprimirNotas()
{
    for(int i=0;i<(int)notas.size();i++)
    {
    cout<< "Nota:"<< notas[i] << endl;
    }
}


int Alumno:: numeroNotas()
{
    return notas.size();
}
