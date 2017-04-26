#include "vehicle.h"

Vehicle::Vehicle(QString nombre, int nRuedas, int potenciaMotor, QString tipoComb, QString color, bool kit, bool ruedaRepuesto, bool burbuja, int multiplesBocinas, bool portavasos, QString matricula, bool reactor, bool trenAterrizaje, bool alas)
{
    this->nombre = nombre;
    this->nRuedas = nRuedas;
    this->potenciaMotor = potenciaMotor;
    this->tipoComb = tipoComb;
    this->color = color;
    this->kit = kit;
    this->ruedaRepuesto = ruedaRepuesto;
    this->burbuja = burbuja;
    this->multiplesBocinas = multiplesBocinas;
    this->portavasos = portavasos;
    this->matricula = matricula;
    this->reactor = reactor;
    this->trenAterrizaje = trenAterrizaje;
    this->alas = alas;
}
