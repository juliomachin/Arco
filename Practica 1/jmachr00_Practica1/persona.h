#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;


// Definición de la clase Animal
class Persona
{
public:
    // Constructor de la clase
    Persona();

    // Constructor sobrecargado
    Persona(string Nombre, string Apellidos, string DNI);

    // Destructor de la clase
    ~Persona(void);

    // Relaciona el valor enumerado con el texto equivalente (string)
    //string escribeClasificacion(clasificacion suClasificacion);

    //
    // "Getters" & "Setters" (Devuelven & Establecen valores a los atributos)
    //

    string getNombre();
    void setNombre(string value);

    string getApellidos();
    void setApellidos(string value);


    string getDNI();
    void setDNI(string value);


private:

    string Nombre;
    string Apellidos;
    string DNI;
};

#endif // Persona_H

