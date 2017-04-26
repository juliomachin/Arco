#ifndef ALUMNO_H
#define ALUMNO_H
#include "persona.h"

class Alumno: public Persona
{
public:

     std::vector<int> notas;

     Alumno();
     Alumno(string Nombre, string Apellido, string DNI);
     ~Alumno();


     void anyadirNota(int nota);
     void imprimirNotas();
     int numeroNotas();


 };


#endif // ALUMNO_H
