#include "vehiculo.h"
#include "ui_vehiculo.h"
#include "vehicle.h"
#include <time.h>
//#include <iostream>

//using namespace std;

std:: vector <Vehicle> vehiculos;
int contadorVehiculos=0;

vehiculo::vehiculo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vehiculo)
{
    ui->setupUi(this);

}

vehiculo::~vehiculo()
{
    delete ui;
}

void vehiculo::on_guardarVehiculo_clicked()
{
    QString nombre = "";
    int nRuedas = 0;
    int potenciaMotor = 0;
    QString tipoComb = "";
    QString color = "";
    bool kit = false;
    bool ruedaRepuesto = false;
    bool burbuja = false;
    int multiplesBocinas = 0;
    bool portavasos = false;
    QString matricula = "";
    bool trenAterrizaje = false;
    bool reactor = false;
    bool alas = false;

    nombre = ui->nombreVehiculo->text();

    if(ui->otroRuedas->isChecked()){
        nRuedas = ui->textoOtrosRuedas->text().toInt();
    }else if(ui->dosRuedas->isChecked()){
        nRuedas = 2;
    }else if(ui->cuatroRuedas->isChecked()){
        nRuedas = 4;
    }else if(ui->doceRuedas->isChecked()){
        nRuedas = 12;
    }

    potenciaMotor = ui->caballosPotencia->value();

    if(ui->diesel->isChecked()){
        tipoComb = "Diesel";
    }else if(ui->gasolina->isChecked()){
        tipoComb = "Gasolina";
    }else if(ui->queroseno->isChecked()){
        tipoComb = "Queroseno";
    }

    if(ui->colorVerde->isChecked()){
        color = "verde";
    }else if(ui->colorAmarillo->isChecked()){
        color = "amarillo";
    }else if(ui->colorAzul->isChecked()){
        color = "azul";
    }else if(ui->colorRojo->isChecked()){
        color = "rojo";
    }

    burbuja = ui->burbuja->isChecked();
    portavasos = ui->portavasos->isChecked();
    reactor = ui->reactor->isChecked();
    trenAterrizaje = ui->trenAterrizaje->isChecked();

    if(ui->kitReparacion->isChecked()){
        kit = true;
        ruedaRepuesto = false;
        alas = false;
    }else{
        if(ui->ruedaRespuesto->isChecked()){
            ruedaRepuesto = true;
            kit = false;
            alas = false;
        }else{
            if(ui->alas->isChecked()){
                ruedaRepuesto = false;
                kit = false;
                alas = true;
            }
        }

        multiplesBocinas = ui->numeroBocinas->value();

        QString numeros="0123456789";
        QString letrasma="BCDFGHJKLMNPQRSTVWXYZ";
        QChar nmatricula[8];
        srand ( time(NULL) );

        for(int i=0;i<4;i++) //generamos los 4 numeros
        {
            nmatricula[i]=numeros[rand()%10];
        }

        for(int i=4;i<7;i++) //generamos las 3 letras
        {
            nmatricula[i]=letrasma[rand()%20];
        }
        nmatricula[7] = '\0';

        matricula = QString(nmatricula);

        ui->matricula->setText(matricula);

        contadorVehiculos++;
        ui->contCoches->setNum(contadorVehiculos);
        vehiculos.push_back(Vehicle(nombre,nRuedas,potenciaMotor,tipoComb,color,kit,ruedaRepuesto,burbuja,multiplesBocinas,portavasos,matricula,reactor,trenAterrizaje,alas));
        ui->vehiculosCreados->addItem(nombre);

    }
}//error
    void vehiculo::on_mostrarVehiculo_clicked()
    {
        if(!vehiculos.empty()){
            int posicion = ui->vehiculosCreados->currentIndex();
            ui->nombreVehiculo->setText(vehiculos[posicion].getNombre());
            ui->matricula->setText(vehiculos[posicion].getMatricula());

            //Burbuja para el coche
            if(vehiculos[posicion].getBurbuja()){
                ui->burbuja->setChecked(true);
            }else{
                ui->burbuja->setChecked(false);
            }

            //Portavasos Gigantes
            if(vehiculos[posicion].getPortavasos()){
                ui->portavasos->setChecked(true);
            }else{
                ui->portavasos->setChecked(false);
            }

            //Reactor
            if(vehiculos[posicion].getReactor()){
                ui->reactor->setChecked(true);
            }else{
                ui->reactor->setChecked(false);
            }

            //Tren de Aterrizaje
            if(vehiculos[posicion].getAterrizaje()){
                ui->trenAterrizaje->setChecked(true);
            }else{
                ui->trenAterrizaje->setChecked(false);
            }

            //Color
            if(vehiculos[posicion].getColor()=="amarillo"){
                ui->colorAmarillo->setChecked(true);
            }else{
                ui->colorAmarillo->setChecked(false);
            }

            if(vehiculos[posicion].getColor()=="azul"){
                ui->colorAzul->setChecked(true);
            }else{
                ui->colorAzul->setChecked(false);
            }

            if(vehiculos[posicion].getColor()=="rojo"){
                ui->colorRojo->setChecked(true);
            }else{
                ui->colorRojo->setChecked(false);
            }

            if(vehiculos[posicion].getColor()=="verde"){
                ui->colorVerde->setChecked(true);
            }else{
                ui->colorVerde->setChecked(false);
            }

            //Ruedas
            if(vehiculos[posicion].getRuedas()==2){
                ui->dosRuedas->setChecked(true);
                ui->textoOtrosRuedas->setText("");
            }else{
                ui->dosRuedas->setChecked(false);
            }

            if(vehiculos[posicion].getRuedas()==4){
                ui->cuatroRuedas->setChecked(true);
                ui->textoOtrosRuedas->setText("");
            }else{
                ui->cuatroRuedas->setChecked(false);
            }

            if(vehiculos[posicion].getRuedas()==12){
                ui->doceRuedas->setChecked(true);
                ui->textoOtrosRuedas->setText("");
            }else{
                ui->doceRuedas->setChecked(false);
            }

            if(vehiculos[posicion].getRuedas()!=4 && vehiculos[posicion].getRuedas()!=2 && vehiculos[posicion].getRuedas()!=12){
                ui->otroRuedas->setChecked(true);
                ui->textoOtrosRuedas->setText( QString::number(vehiculos[posicion].getRuedas(), 'd', 0)  ); //QString::number( NUMERO, TIPO DE NUMERO (int,float..) , numero de decimales detras de la coma );
            }else{
                ui->otroRuedas->setChecked(false);
                ui->textoOtrosRuedas->setText("");
            }

            //Combustible
            if(vehiculos[posicion].getCombustible()=="Gasolina"){
                ui->gasolina->setChecked(true);
            }else{
                ui->gasolina->setChecked(false);
            }

            if(vehiculos[posicion].getCombustible()=="Queroseno"){
                ui->queroseno->setChecked(true);
            }else{
                ui->queroseno->setChecked(false);
            }

            if(vehiculos[posicion].getCombustible()=="Diesel"){
                ui->diesel->setChecked(true);
            }else{
                ui->diesel->setChecked(false);
            }

            //Rueda o Kit
            if(vehiculos[posicion].getRueda_Repuesto()){
                ui->ruedaRespuesto->setChecked(true);
            }else{
                ui->ruedaRespuesto->setChecked(false);
            }

            if(vehiculos[posicion].getKit()){
                ui->kitReparacion->setChecked(true);
            }else{
                ui->kitReparacion->setChecked(false);
            }

            if(vehiculos[posicion].getAlas()){
                ui->alas->setChecked(true);
            }else{
                ui->alas->setChecked(false);
            }

            //Potencia
            ui->caballosPotencia->setValue(vehiculos[posicion].getPotencia());

            //Bocinas
            ui->numeroBocinas->setValue(vehiculos[posicion].getBocinas());

            //Tipo de Vehiculo
            if(vehiculos[posicion].getRuedas() >= 12 && vehiculos[posicion].getBocinas() > 0 && vehiculos[posicion].getBurbuja() == true || vehiculos[posicion].getPortavasos() == true || vehiculos[posicion].getKit() == true) {
                ui->tipoVehiculo->setText("Error de Ejecucion");
            }
            // Condicion Coche de Homer
            else if(vehiculos[posicion].getRuedas() >= 4 && vehiculos[posicion].getBocinas() > 0 && vehiculos[posicion].getBurbuja() == true || vehiculos[posicion].getPortavasos() == true) {
                ui->tipoVehiculo->setText("COCHE DE HOMER");
            }
            // Condición Coche
            else if(vehiculos[posicion].getRuedas() == 4 && vehiculos[posicion].getBocinas() == 1) {
                ui->tipoVehiculo->setText("Coche");
            }
            // Condición Moto
            else if(vehiculos[posicion].getRuedas() == 2 && vehiculos[posicion].getBocinas() == 1) {
                ui->tipoVehiculo->setText("Moto");
            }
            // Condición Avión
            else if(vehiculos[posicion].getRuedas() == 12 && vehiculos[posicion].getAlas() == true && vehiculos[posicion].getReactor() == true && vehiculos[posicion].getAterrizaje() == true && vehiculos[posicion].getCombustible()== "Queroseno" ) {
                ui->tipoVehiculo->setText("Avión");
            }


        }
    } //Cierre Mostar

    void vehiculo::on_borrarDatos_clicked()
    {
        ui->nombreVehiculo->setText("");
        ui->dosRuedas->setChecked(true);
        ui->textoOtrosRuedas->setText("");
        ui->burbuja->setChecked(false);
        ui->portavasos->setChecked(false);
        ui->ruedaRespuesto->setChecked(true);
        ui->numeroBocinas->setValue(0);
        ui->colorVerde->setChecked(true);
        ui->caballosPotencia->setValue(0);
        ui->matricula->setText("");
    }


