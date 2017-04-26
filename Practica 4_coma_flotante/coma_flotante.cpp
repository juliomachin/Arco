#include "coma_flotante.h"
#include "ui_coma_flotante.h"
#include <limits.h>
#include <iostream>
#include <math.h>
#include <bitset>
using namespace std;


coma_flotante::coma_flotante(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::coma_flotante)
{
    ui->setupUi(this);
}

coma_flotante::~coma_flotante()
{
    delete ui;
}



void coma_flotante::on_pushButton_clicked()
{
    ui->numero1bin->clear();
    ui->numero2bin->clear();
    ui->numero1hex->clear();
    ui->numero2hex->clear();

    QString numero1 = ui->numero1->text();
    QString numero2 = ui->numero2->text();

    bool ok;

    float variable1 = numero1.toFloat();
    //OBTENER VALOR EN COMA FLOTANTE
    string str1 = toFloatingPoint( (float)variable1);
   QString qstr1 = QString::fromStdString(str1);
   //GUARDAR NUMERO COMO BITSET ????
   std::bitset<32> set1(str1);
   n1 = set1;
   //GUARDAR NUMERO HEXADECIMAL
    int hex1 = set1.to_ulong();
    QString hexnum1;
    hexnum1=QString::number(hex1,16);


   float variable2 = numero2.toFloat();
   std::string str2 = toFloatingPoint( (float)variable2);
  QString qstr2 = QString::fromStdString(str2);
  std::bitset<32> set(str2);
  n2 = set;

   int hex2 = set.to_ulong();
   QString hexnum2;

      hexnum2=QString::number(hex2,16);

      //IMPRIMIR VALORES
    ui->numero1bin->setText(qstr1);
   ui->numero1hex->setText(hexnum1);
    ui->numero2bin->setText(qstr2);

   ui->numero2hex->setText(hexnum2);



}

string coma_flotante::toFloatingPoint(float variable){
    union
    {
         float input;
         int   output;
    }    data;

    data.input = variable;

   bitset<sizeof(float) * CHAR_BIT> bits(data.output);


   string resultado = bits.to_string<char, std::char_traits<char>, std::allocator<char> >();


    return resultado;
}

//SUMA
void coma_flotante::on_suma_clicked()
{
    bitset<32> res(0);
    bitset <8> e1, e2;
    for(int i=1;i<9;i++){
        e1[i-1]= n1[i];
        e2[i-1]= n2[i];
    }
  /* bool a, b;
    bool carry = false;
    for(int i=0;i<32;i++){
      a=n1[i];
      b=n2[i];
      bool sum = (a ^ b) ^ carry;
      carry = (a && b) || (a && carry) || (b && carry);
      res[i]= sum;
   }
    int resdec = n1.to_ulong();

    cout << res << endl;
    cout <<resdec <<endl;
    */
}

//PRODUCTO
void coma_flotante::on_prod_clicked()
{

}
//DIVISION
void coma_flotante::on_division_clicked()
{

}
