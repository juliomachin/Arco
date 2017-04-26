#include <iostream>
#include "persona.h"
#include "alumno.h"
#include "profesor.h"
#include <string>
void Calificando()
{
    Profesor *Profesor1 = new Profesor("Aldo","Raine","1122A");
    Profesor *Profesor2 = new Profesor("Walter","White", "2233B");
    Profesor *Profesor3 = new Profesor("Michael","Scofield","3344C");
    Profesor *Profesor4 = new Profesor("Annalisse","Keating", "4455D");

    Alumno *Alumno1 = new Alumno("Hans","Landa","1234A");
    Alumno *Alumno5 = new Alumno("Hugo","Stiglitz","7340X");
    Alumno *Alumno2 = new Alumno("Jesse","Pinkman","9012C");
    Alumno *Alumno6 = new Alumno("Saul","Goodman","0794F");
    Alumno *Alumno3 = new Alumno("Fernando","Soucre","7890E");
    Alumno *Alumno7 = new Alumno("Sara","Tancredi","0916Q");
    Alumno *Alumno4 = new Alumno("Laurel","Castillo","6785G");
    Alumno *Alumno8 = new Alumno("Frank","Delfino","9089V");


    //Los profesores añaden los alumnos
    Profesor1->anyadirAlumno(Alumno1);
    Profesor1->anyadirAlumno(Alumno5);
    Profesor2->anyadirAlumno(Alumno2);
    Profesor2->anyadirAlumno(Alumno6);
    Profesor3->anyadirAlumno(Alumno3);
    Profesor3->anyadirAlumno(Alumno7);
    Profesor4->anyadirAlumno(Alumno4);
    Profesor4->anyadirAlumno(Alumno8);



    //Notas Alumno1 y Alumno 5
    Profesor1->anyadirNota(Alumno1,4,5);
    Profesor1->anyadirNota(Alumno5,7,3,5);

    //Notas Alumno2 y Alumno6
    Profesor2->anyadirNota(Alumno2,3,8,4);
    Profesor2->anyadirNota(Alumno6,1);

    //Notas Alumno3 y Alummno 7
    Profesor3->anyadirNota(Alumno3,5,6,4);
    Profesor3->anyadirNota(Alumno7,7,8,5);


    //Notas Alumno4 y Alumno8
    Profesor4->anyadirNota(Alumno4,10,9);
    Profesor4->anyadirNota(Alumno8,3,2);



    //Profesor 1
    cout << "Soy el Profesor: " << Profesor1->getNombre() << endl;
    cout << "Soy el Alumno: " << Alumno1->getNombre() << endl;
    Alumno1->imprimirNotas(); 
    Profesor1->notaMedia(Alumno1);
    cout << "Soy el Alumno : " << Alumno5->getNombre() << endl;
    Alumno5->imprimirNotas();
    Profesor1->notaMedia(Alumno5);

    //Profesor 2
    cout << "Soy el Profesor: " << Profesor2->getNombre() << endl;
    cout << "Soy el Alumno: " << Alumno2->getNombre() << endl;
    Alumno2->imprimirNotas();
    Profesor2->notaMedia(Alumno2);
    cout << "Soy el Alumno: " << Alumno6->getNombre() << endl;
    Alumno6->imprimirNotas();
    Profesor1->notaMedia(Alumno6);

    //Profesor 3
    cout << "Soy el Profesor: " << Profesor3->getNombre() << endl;
    cout << "Soy el Alumno :" << Alumno3->getNombre() << endl;
    Alumno3->imprimirNotas();
    Profesor3->notaMedia(Alumno3);
    cout << "Soy el Alumno :" << Alumno7->getNombre() << endl;
    Alumno7->imprimirNotas();
    Profesor3->notaMedia(Alumno7);

    //Profesor 4
    cout << "Soy el Profesor: " <<  Profesor4->getNombre() << endl;
    cout << "Soy el Alumno: " << Alumno4->getNombre() << endl;
    Alumno4->imprimirNotas();
    Profesor4->notaMedia(Alumno4);
    cout << "Soy el Alumno: " << Alumno8->getNombre() << endl;
    Alumno8->imprimirNotas();
    Profesor4->notaMedia(Alumno8);

    Profesor3->imprimirBestAlumno();
}



int main()
{
   Calificando();
   return 0;
}

