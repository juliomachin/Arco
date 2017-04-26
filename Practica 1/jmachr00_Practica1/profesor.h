#ifndef PROFESOR_H
#define PROFESOR_H
#include "persona.h"
#include "alumno.h"


class Profesor : public Persona
{
public:
    std::vector<Alumno*> listaAlumnos;
    Profesor();
    Profesor(string Nombre, string Apellido, string DNI);
    ~Profesor();

    void anyadirAlumno(Alumno* alu);
    void anyadirNota(Alumno* alu, int nota1);
    void anyadirNota(Alumno* alu, int nota1, int nota2);
    void anyadirNota(Alumno* alu, int nota1, int nota2, int nota3);
    float notaMedia(Alumno* alu);
    void imprimirAlumnos();
    void imprimirBestAlumno();
};

#endif // PROFESOR_H
