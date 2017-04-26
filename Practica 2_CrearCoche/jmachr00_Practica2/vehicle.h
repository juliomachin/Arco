#ifndef VEHICLE_H
#define VEHICLE_H
#include <QString>

class Vehicle
{
private:
    QString nombre;
    int nRuedas;
    int potenciaMotor;
    QString tipoComb;
    QString color;
    bool kit;
    bool ruedaRepuesto;
    bool burbuja;
    int multiplesBocinas;
    bool portavasos;
    QString matricula;
    bool alas;
    bool trenAterrizaje;
    bool reactor;
public:
    Vehicle(QString nombre, int nRuedas, int potenciaMotor, QString tipoComb, QString color, bool kit, bool ruedaRepuesto, bool burbuja, int multiplesBocinas, bool portavasos, QString matricula, bool reactor, bool trenAterrizaje, bool alas);

    QString getNombre()
    {
        return nombre;
    }

    int getRuedas()
    {
        return nRuedas;
    }

    int getPotencia()
    {
        return potenciaMotor;
    }

    QString getCombustible()
    {
        return tipoComb;
    }

    QString getColor()
    {
        return color;
    }

    bool getKit()
    {
        return kit;
    }

    bool getRueda_Repuesto()
    {
        return ruedaRepuesto;
    }

    bool getBurbuja()
    {
        return burbuja;
    }

    int getBocinas()
    {
        return multiplesBocinas;
    }

    bool getPortavasos()
    {
        return portavasos;
    }

    bool getReactor()
    {
        return reactor;
    }

    bool getAterrizaje()
    {
        return trenAterrizaje;
    }

    bool getAlas()
    {
        return alas;
    }

    QString getMatricula()
    {
        return matricula;
    }
};

#endif
