#ifndef VEHICULO_H
#define VEHICULO_H

#include <QMainWindow>

namespace Ui {
class vehiculo;
}

class vehiculo : public QMainWindow
{
    Q_OBJECT

public:
    explicit vehiculo(QWidget *parent = 0);
    ~vehiculo();

private slots:
    void on_guardarVehiculo_clicked();

    void on_mostrarVehiculo_clicked();

    void on_caballosPotencia_rangeChanged(int min, int max);

    void on_borrarDatos_clicked();

private:
    Ui::vehiculo *ui;
};

#endif // VEHICULO_H
