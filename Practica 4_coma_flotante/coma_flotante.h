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
    bool comparar(bitset<8> exp1, bitset<8> exp2);

    int sumaBinaria(int sum1, int sum2, int len);
    int restaBinaria(int sum1, int sum2);
    int toDecimal(int x);
    int multBinaria(int mult1, int mult2);
    long long sumaBinariaMult(long long sum1, long long sum2);
    int divisionBinaria(int D, int d);


private slots:
    void on_pushButton_clicked();

    void on_suma_clicked();

    void on_prod_clicked();

    void on_division_clicked();

private:
    Ui::coma_flotante *ui;
    bitset<32> n1;
    bitset <32> n2;
    bool carry;

};

#endif // COMA_FLOTANTE_H
