#include "profesor.h"
#include "alumno.h"


Profesor::Profesor()
{

}

Profesor::Profesor(string Nombre, string Apellidos, string DNI)
{
    this->setNombre(Nombre);
    this->setApellidos(Apellidos);
    this->setDNI(DNI);
}

Profesor::~Profesor()
{

}


void Profesor::anyadirAlumno(Alumno* alumno)
{
   listaAlumnos.push_back(alumno);

}

void Profesor::anyadirNota(Alumno* alumno, int nota1)
{
    for(int i=0;i<(int)listaAlumnos.size();i++){
        if(listaAlumnos[i]->getDNI()==alumno->getDNI()){
            listaAlumnos[i]->anyadirNota(nota1);
        }
    }

}

void Profesor::anyadirNota(Alumno* alumno, int nota1, int nota2)
{
    for(int i=0;i<listaAlumnos.size();i++){
        if(listaAlumnos[i]==alumno){
            listaAlumnos[i]->anyadirNota(nota1);
            listaAlumnos[i]->anyadirNota(nota2);
        }
    }
}

void Profesor::anyadirNota(Alumno* alumno, int nota1, int nota2, int nota3)
{
    for(int i=0;i<listaAlumnos.size();i++){
        if(listaAlumnos[i]==alumno){
            listaAlumnos[i]->anyadirNota(nota1);
            listaAlumnos[i]->anyadirNota(nota2);
            listaAlumnos[i]->anyadirNota(nota3);
        }
    }
}

float Profesor::notaMedia(Alumno* alumno)
{
   float nota_media = 0;
   float nota_total = 0;
   for(int i=0; i<alumno->notas.size();i++){
       nota_total = nota_total + alumno->notas[i];
   }
   nota_media = nota_total /(alumno->notas.size());
   cout << "Su nota media es:" << nota_media << endl;

}

void Profesor::imprimirAlumnos()
{
    for(int i=0; i<listaAlumnos.size();i++){
        cout << "El alumno : " << listaAlumnos[i]->getNombre()<< endl ;
    }

}

void Profesor::imprimirBestAlumno()
{
    int mejorNota = -1;
    for(int i=0; i< listaAlumnos.size();i++){
        if (listaAlumnos[i]->notas.size() == 3){
            if((mejorNota == -1) || (this->notaMedia(listaAlumnos[i]) > mejorNota)){
                    mejorNota = this->notaMedia(listaAlumnos[i]);
                    cout << "El mejor alumno es: "<< listaAlumnos[i] << endl; //Imprimir Alumno
            }
        }
    }
    if(mejorNota == -1){
        cout << "Ningun Alumno del Profesor tiene 3 notas." << endl;
    }
}
