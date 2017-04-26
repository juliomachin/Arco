#ifndef COMA_FLOTANTE_H
#define COMA_FLOTANTE_H
#include <bitset>
#include <QMainWindow>
using namespace std;

namespace Ui {
class coma_flotante;
}

class coma_flotante : public QMainWindow
{
    Q_OBJECT

public:
    explicit coma_flotante(QWidget *parent = 0);
    ~coma_flotante();
    string toFloatingPoint( float variable );


private slots:
    void on_pushButton_clicked();

    void on_suma_clicked();

    void on_prod_clicked();

    void on_division_clicked();

private:
    Ui::coma_flotante *ui;
    bitset<32> n1;
    bitset <32> n2;
};

#endif // COMA_FLOTANTE_H
