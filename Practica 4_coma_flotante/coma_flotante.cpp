#include "coma_flotante.h"
#include "ui_coma_flotante.h"
#include <limits.h>
#include <iostream>
#include <math.h>
#include <bitset>
#include <stdexcept>

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


    int var =  (int )bits.to_ulong();
    bitset<32> q (var);


    return resultado;
}

//SUMA
void coma_flotante::on_suma_clicked()
{
    bitset <23> zeros (0);
    if(n1 ==0){
        int hex = n2.to_ulong();
        QString hexnum;
        hexnum=QString::number(hex,16);
        ui->reshex->setText(hexnum);
        //Expresamos resultado en decimal
        int a = toDecimal(hex);
    }else if(n2 ==0){
        int hex = n1.to_ulong();
        QString hexnum;
        hexnum=QString::number(hex,16);
        ui->reshex->setText(hexnum);
        //Expresamos resultado en decimal
        int a = toDecimal(hex);
    }else if(n2 == n1 == 0){
        int hex = n1.to_ulong();
        QString hexnum;
        hexnum=QString::number(hex,16);
        ui->reshex->setText(hexnum);
        //Expresamos resultado en
    }else{
        bitset<32> res(0);
        bitset <8> e1, e2, er;
        bitset <23> m1, m2, mr;
        bool s1, s2, sr;
        s1 = n1.test(31);
        s2 = n2.test(31);
        int j=7;
        for(int i=30;i>22;i--){
            e1[j]= n1[i];
            e2[j]= n2[i];
            j--;
        }
        j=22;
        for(int i=22;i>=0;i--){
            m1[j]= n1[i];
            m2[j]= n2[i];
            j--;
        }
       //MISMO SIGNO
        if(s1 == s2){
            //Comprobamos que e1>e2, si no lo cambiamos
            if(e1.to_ulong()<e2.to_ulong()){
                bitset<8> aux(0);
                aux = e1;
                e1= e2;
                e2 = aux;
                bitset<23> aux1(0);
                aux1 = m1;
                m1= m2;
                m2 = aux1;
            }
            //Hallamos la diferencia
            int d = restaBinaria((int) e1.to_ulong(),(int) e2.to_ulong());
            //Desplazamos d la mantisa y sumamos al exponente hasta igualarlos
            carry = false;
            int exp = sumaBinaria((int) e2.to_ulong(),d, 8);
            int dif = d;
            if(d>0){
                m2.operator >>=(1);
                m2[22] = 1;
                 d--;
            }

            for(int i=0;i<d;i++){
                m2.operator >>=(1);
            }
            //Sumamos las mantisas
            carry = false;
            int mant = sumaBinaria(m1.to_ulong(),m2.to_ulong(), 23);
            bitset <23>  m(mant);
            //Modificamos el resultado
            if(carry || dif==0){
                carry = false;
                exp = sumaBinaria(exp,1, 8);
                m.operator >>=(1);
            }
            //Lo juntamos en el bitset resultado
            bitset <8>  er(exp);
            int j=0;
            for(int i=0;i<23;i++){
                res[i] = m[j];
                j++;
            }
            j=0;
            for(int i=23;i<32;i++){
                res[i] = er[j];
                j++;
            }
            res[31] = s1;
            //Expresamos resultado en hexadecimal
            int hex = res.to_ulong();
            QString hexnum;
            hexnum=QString::number(hex,16);
            ui->reshex->setText(hexnum);
            //Expresamos resultado en decimal
            int a = toDecimal(hex);
        }else{
            //DIFERENTE SIGNO
            //Comprobamos si el negativo es mayor que el positivo en valor absoluto
            if (s1){
            //    abs = n1;
                 n1[31] = s2;
            }
            if(s2){
                cout << "entro " << endl;
                n2[31] = s1;

            }
            bool iguales = false;
            if(n1.operator ==(n2)){
                cout << "iguales" << endl;
                iguales = true;
            }
        /*    if(e1.to_ulong()<e2.to_ulong()){
                cout << "entro" << endl;
                bitset<8> aux(0);
                aux = e1;
                e1= e2;
                e2 = aux;
                bitset<23> aux1(0);
                aux1 = m1;
                m1= m2;
                m2 = aux1;
           }*/
             if(n1.to_ulong()<n2.to_ulong()){
                 bitset<8> aux(0);
                 aux = e1;
                 e1= e2;
                 e2 = aux;
                 bitset<23> aux1(0);
                 aux1 = m1;
                 m1= m2;
                 m2 = aux1;
                 cout <<"ebtro"<<endl;
                bool auxs = s1;
                s1 = s2;
                s2 = auxs;

            }


             //TERCER INTENTO
             //Resta de exponenetes
             int d = restaBinaria((int) e1.to_ulong(),(int) e2.to_ulong());
             cout << "diferencia " << d << endl;

             //Desplazamos la mantisa
             carry = false;
             int exp = sumaBinaria((int) e2.to_ulong(),d, 8);
             int dif = d;
             if(d>0){
                 m2.operator >>=(1);
                 m2[22] = 1;
                  d--;
             }

             for(int i=0;i<d;i++){
                 m2.operator >>=(1);
             }

             //Añadimos los hidden bits para sumar
             bitset <24> sum1(m1.to_ulong());
             bitset <24> sum2(m2.to_ulong());
             cout << "operandos sin el bit" << endl;
             cout << "m1" << sum1 << endl;
             cout << "m2" << sum2 << endl;

             sum1[23] = 1;
             if(dif==0) sum2[23] = 1;
             cout << "operandos con el bit" << endl;
             cout << "m1" << sum1 << endl;
             cout << "m2" << sum2 << endl;

             //Restamos las mantisas

             int mant = restaBinaria(sum1.to_ulong(), sum2.to_ulong());
             bitset <24> maux (mant);
             cout << "resultado de la resta " << maux << endl;

             //Normalizamos
             exp=0;
             if(maux[23] == 1){
                 cout << "Esta normalizado" << endl;
                 bitset <8> er (e1.to_ulong());
                 exp = e1.to_ulong();

             }else{
                 if(!iguales){
                     //buscamos el primer 1
                     cout << "no esta normalizado" << endl;
                     int pos = 23;
                     int k=0;
                     cout << maux[pos] << endl;
                     while(!maux[pos]){
                         cout << maux[pos] << endl;

                         pos--;
                         k++;
                     }
                     cout << "posiciones a desplazar " << k << endl;
                     for(int i=0;i<k;i++){

                         maux = maux.operator <<(1);
                     }
                     cout << "mantisa desplazada " << maux << endl;

                    exp = restaBinaria(e1.to_ulong(),k);
                 }
             }

             maux[23] = 0;
             bitset <23> ma(maux.to_ulong());

            bitset <8>  er(exp);
            cout << er << endl;
            cout << ma << endl;
            int j=0;
            for(int i=0;i<23;i++){
                res[i] = ma[j];
                j++;
            }
            j=0;
            for(int i=23;i<32;i++){
                res[i] = er[j];
                j++;
            }
            res[31] = s1;
            //Expresamos resultado en hexadecimal
            int hex = res.to_ulong();
            QString hexnum;
            hexnum=QString::number(hex,16);
            ui->reshex->setText(hexnum);
            //Expresamos resultado en decimal
            int a = toDecimal(hex);


        }
    }
}

//PRODUCTO
void coma_flotante::on_prod_clicked()
{
    bitset <23> zeros (0);
    if(n1 ==0 || n2==0){
        int hex = 0;
        QString hexnum;
        hexnum=QString::number(hex,16);
        ui->reshex->setText(hexnum);
        //Expresamos resultado en decimal
        int a = toDecimal(hex);
    }else{

        bitset<32> res(0);
        bitset <8> e1, e2;
        bitset <23> m1, m2, mr;
        bool s1, s2, sr;
        s1 = n1.test(31);
        s2 = n2.test(31);
        int j=7;
        for(int i=30;i>22;i--){
            e1[j]= n1[i];
            e2[j]= n2[i];
            j--;
        }
        j=22;
        for(int i=22;i>=0;i--){
            m1[j]= n1[i];
            m2[j]= n2[i];
            j--;
        }
        sr =  s1^s2;
        carry = false;
        int e = sumaBinaria(e1.to_ulong(), e2.to_ulong(), 9);
        e = restaBinaria(e, 127);
        //mantisa
        int mant = multBinaria(m1.to_ulong(), m2.to_ulong());
        //mirar cuanto desplazar
        bitset <25> maux (mant);
        cout << "mantisa sin normlizar" <<maux << endl;
        if(maux[24]==1){
            cout << "ebtro" << endl;
            maux[24] =0;
            carry = false;
            e = sumaBinaria(e,1,8);
            maux = maux.operator >>(1);
        }else if(maux[23] == 1){
            maux[23] =0;
        }
        cout << "mantisa norn " <<maux << endl;

        bitset <23> m (maux.to_ulong());
        cout << "mantisa normlizada" << m << endl;

        bitset <8> exp(e);
        cout << "exponenete " <<exp << endl;


        j=0;
        for(int i=0;i<23;i++){
            res[i] = m[j];
            j++;
        }
        j=0;
        for(int i=23;i<32;i++){
            res[i] = exp[j];
            j++;
        }
        res[31] = sr;
        //Expresamos resultado en hexadecimal
        int hex = res.to_ulong();
        QString hexnum;
        hexnum=QString::number(hex,16);
        ui->reshex->setText(hexnum);
        //Expresamos resultado en decimal
        int a = toDecimal(hex);

    }



}
int coma_flotante::mult(int num1, int num2){
    bitset <23> zeros (0);
    bitset<32> n1(num1);
    bitset<32> n2(num2);
    int resfinal=0;
    if(n1 ==0 || n2==0){
        int hex = 0;
        QString hexnum;
        hexnum=QString::number(hex,16);
        ui->reshex->setText(hexnum);
        //Expresamos resultado en decimal
       resfinal = hex;
    }else{

        bitset<32> res(0);
        bitset <8> e1, e2;
        bitset <23> m1, m2, mr;
        bool s1, s2, sr;
        s1 = n1.test(31);
        s2 = n2.test(31);
        int j=7;
        for(int i=30;i>22;i--){
            e1[j]= n1[i];
            e2[j]= n2[i];
            j--;
        }
        j=22;
        for(int i=22;i>=0;i--){
            m1[j]= n1[i];
            m2[j]= n2[i];
            j--;
        }
        sr =  s1^s2;
        carry = false;
        int e = sumaBinaria(e1.to_ulong(), e2.to_ulong(), 9);
        e = restaBinaria(e, 127);
        //mantisa
        int mant = multBinaria(m1.to_ulong(), m2.to_ulong());
        //mirar cuanto desplazar
        bitset <25> maux (mant);
        cout << "mantisa sin normlizar" <<maux << endl;
        if(maux[24]==1){
            cout << "ebtro" << endl;
            maux[24] =0;
            carry = false;
            e = sumaBinaria(e,1,8);
            maux = maux.operator >>(1);
        }else if(maux[23] == 1){
            maux[23] =0;
        }
        cout << "mantisa norn " <<maux << endl;

        bitset <23> m (maux.to_ulong());
        cout << "mantisa normlizada" << m << endl;

        bitset <8> exp(e);
        cout << "exponenete " <<exp << endl;


        j=0;
        for(int i=0;i<23;i++){
            res[i] = m[j];
            j++;
        }
        j=0;
        for(int i=23;i<32;i++){
            res[i] = exp[j];
            j++;
        }
        res[31] = sr;
        //Expresamos resultado en hexadecimal
        int hex = res.to_ulong();
        QString hexnum;
        hexnum=QString::number(hex,16);
        //Expresamos resultado en decimal
        resfinal = res.to_ulong();
}
        return resfinal;
}
int coma_flotante::sum(int num1, int num2){
    int resfinal = 0;
    bitset <23> zeros (0);
    bitset <32> n1(num1);
    bitset <32> n2(num2);

    if(n1 ==0){
        int hex = n2.to_ulong();
        QString hexnum;
        hexnum=QString::number(hex,16);
        //ui->reshex->setText(hexnum);
        //Expresamos resultado en decimal
        resfinal =hex;
    }else if(n2 ==0){
        int hex = n1.to_ulong();
        QString hexnum;
        hexnum=QString::number(hex,16);
        ui->reshex->setText(hexnum);
        //Expresamos resultado en decimal
        resfinal = hex;
    }else if(n2 == n1 == 0){
        int hex = n1.to_ulong();
        QString hexnum;
        hexnum=QString::number(hex,16);
        ui->reshex->setText(hexnum);
        resfinal = n1.to_ulong();

        //Expresamos resultado en
    }else{
        bitset<32> res(0);
        bitset <8> e1, e2, er;
        bitset <23> m1, m2, mr;
        bool s1, s2, sr;
        s1 = n1.test(31);
        s2 = n2.test(31);
        int j=7;
        for(int i=30;i>22;i--){
            e1[j]= n1[i];
            e2[j]= n2[i];
            j--;
        }
        j=22;
        for(int i=22;i>=0;i--){
            m1[j]= n1[i];
            m2[j]= n2[i];
            j--;
        }
       //MISMO SIGNO
        if(s1 == s2){
            //Comprobamos que e1>e2, si no lo cambiamos
            if(e1.to_ulong()<e2.to_ulong()){
                bitset<8> aux(0);
                aux = e1;
                e1= e2;
                e2 = aux;
                bitset<23> aux1(0);
                aux1 = m1;
                m1= m2;
                m2 = aux1;
            }
            //Hallamos la diferencia
            int d = restaBinaria((int) e1.to_ulong(),(int) e2.to_ulong());
            //Desplazamos d la mantisa y sumamos al exponente hasta igualarlos
            carry = false;
            int exp = sumaBinaria((int) e2.to_ulong(),d, 8);
            int dif = d;
            if(d>0){
                m2.operator >>=(1);
                m2[22] = 1;
                 d--;
            }

            for(int i=0;i<d;i++){
                m2.operator >>=(1);
            }
            //Sumamos las mantisas
            carry = false;
            int mant = sumaBinaria(m1.to_ulong(),m2.to_ulong(), 23);
            bitset <23>  m(mant);
            //Modificamos el resultado
            if(carry || dif==0){
                carry = false;
                exp = sumaBinaria(exp,1, 8);
                m.operator >>=(1);
            }
            //Lo juntamos en el bitset resultado
            bitset <8>  er(exp);
            int j=0;
            for(int i=0;i<23;i++){
                res[i] = m[j];
                j++;
            }
            j=0;
            for(int i=23;i<32;i++){
                res[i] = er[j];
                j++;
            }
            res[31] = s1;
            //Expresamos resultado en hexadecimal
            int hex = res.to_ulong();
            QString hexnum;
            hexnum=QString::number(hex,16);
            ui->reshex->setText(hexnum);
            //Expresamos resultado en decimal
            resfinal = res.to_ulong();
        }else{
            //DIFERENTE SIGNO
            //Comprobamos si el negativo es mayor que el positivo en valor absoluto
            if (s1){
            //    abs = n1;
                 n1[31] = s2;
            }
            if(s2){
                n2[31] = s1;

            }
            bool iguales = false;
            if(n1.operator ==(n2)){
                iguales = true;
            }
        /*    if(e1.to_ulong()<e2.to_ulong()){
                cout << "entro" << endl;
                bitset<8> aux(0);
                aux = e1;
                e1= e2;
                e2 = aux;
                bitset<23> aux1(0);
                aux1 = m1;
                m1= m2;
                m2 = aux1;
           }*/
             if(n1.to_ulong()<n2.to_ulong()){
                 bitset<8> aux(0);
                 aux = e1;
                 e1= e2;
                 e2 = aux;
                 bitset<23> aux1(0);
                 aux1 = m1;
                 m1= m2;
                 m2 = aux1;
                bool auxs = s1;
                s1 = s2;
                s2 = auxs;

            }


             //TERCER INTENTO
             //Resta de exponenetes
             int d = restaBinaria((int) e1.to_ulong(),(int) e2.to_ulong());

             //Desplazamos la mantisa
             carry = false;
             int exp = sumaBinaria((int) e2.to_ulong(),d, 8);
             int dif = d;
             if(d>0){
                 m2.operator >>=(1);
                 m2[22] = 1;
                  d--;
             }

             for(int i=0;i<d;i++){
                 m2.operator >>=(1);
             }

             //Añadimos los hidden bits para sumar
             bitset <24> sum1(m1.to_ulong());
             bitset <24> sum2(m2.to_ulong());

             sum1[23] = 1;
             if(dif==0) sum2[23] = 1;

             //Restamos las mantisas

             int mant = restaBinaria(sum1.to_ulong(), sum2.to_ulong());
             bitset <24> maux (mant);

             //Normalizamos
             exp=0;
             if(maux[23] == 1){
                 bitset <8> er (e1.to_ulong());
                 exp = e1.to_ulong();

             }else{
                 if(!iguales){
                     //buscamos el primer 1
                     int pos = 23;
                     int k=0;
                     while(!maux[pos]){

                         pos--;
                         k++;
                     }
                     for(int i=0;i<k;i++){

                         maux = maux.operator <<(1);
                     }

                    exp = restaBinaria(e1.to_ulong(),k);
                 }
             }

             maux[23] = 0;
             bitset <23> ma(maux.to_ulong());

            bitset <8>  er(exp);

            int j=0;
            for(int i=0;i<23;i++){
                res[i] = ma[j];
                j++;
            }
            j=0;
            for(int i=23;i<32;i++){
                res[i] = er[j];
                j++;
            }
            res[31] = s1;
            //Expresamos resultado en hexadecimal
            int hex = res.to_ulong();
            QString hexnum;
            hexnum=QString::number(hex,16);
            //Expresamos resultado en decimal
            resfinal = res.to_ulong();

        }
    }
    return resfinal;

}
//DIVISION
void coma_flotante::on_division_clicked()
{
    //Dividimos los numeros en mantisa, signo y exponente
        bitset<32> res(0);
        bitset <8> e1, e2;
        bitset <23> m1, m2, mr;
        bitset<23> me(0);
        bool s1, s2, sr;
        s1 = n1.test(31);
        s2 = n2.test(31);
        int j=7;
        for(int i=30;i>22;i--){
            e1[j]= n1[i];
            e2[j]= n2[i];
            j--;
        }
        j=22;
        for(int i=22;i>=0;i--){
            m1[j]= n1[i];
            m2[j]= n2[i];
            j--;
        }
        int p = 0;
        for(int i=0;i<23;i++){
            if(m2[i]==1){
                p = 23 -i;
                break;
            }
        }
        int mas=p;
        cout << p << endl;
        for(int i=22;p>0;i--){
            me[p] = m2[i];
            p--;
        }
        cout << me << endl;
        float bnum=1;
        int x = 1;
        for(int i=0;i<23;i++){
            if(me[i]==1){
                 bnum = bnum + pow(2,-x);
            }
            x++;
        }
        float bnew =0;
        if(bnum<1.25){
            bnew = 1.0;
        }else{
            bnew = 0.8;
        }
        string  xs = toFloatingPoint(bnew);
        bitset <32> x0b (xs);
        int x0 = x0b.to_ulong();
        cout << x0 << endl;
        int multi =0;

        int rest = 0;
        int ress =0;
        int aux = x0;
        for(int i=0;i<4;i++){
            multi = mult(n2.to_ulong(),x0);
            rest = sum(2, -multi);
            ress =mult(x0,rest);
            aux = x0;
            x0 = ress;
      //  int resaux = mult(x0.to_ulong(),sum(2,-(mult(n2.to_ulong(),x0.to_ulong()))));
        cout << "x0  "<< x0 << endl;

        }
        int div = divisionBinaria(1,m2.to_ulong());
        int auxmant = mult(n1.to_ulong(), ress);
        bitset <32> x1 (auxmant);

        cout << "x1  "<< x1 << endl;
       // m2[23] = 1;
        //m1[23] = 1;


        //Sacamos el signo del resultado
        sr =  s1^s2;
        //Hallamos el exponenete
        int er = restaBinaria(e1.to_ulong(), e2.to_ulong());
        carry = false;
        er = sumaBinaria(er, 127, 8);



 /*   //Dividimos los numeros en mantisa, signo y exponente
    bitset<32> res(0);
    bitset <8> e1, e2;
    bitset <23> m1, m2, mr;
    bool s1, s2, sr;
    s1 = n1.test(31);
    s2 = n2.test(31);
    int j=7;
    for(int i=30;i>22;i--){
        e1[j]= n1[i];
        e2[j]= n2[i];
        j--;
    }
    j=22;
    for(int i=22;i>=0;i--){
        m1[j]= n1[i];
        m2[j]= n2[i];
        j--;
    }
    //Comprobamos los tamaños

    //Sacamos el signo del resultado
    sr =  s1^s2;
    //Hallamos el exponenete
    int er = restaBinaria(e1.to_ulong(), e2.to_ulong());
    carry = false;
    er = sumaBinaria(er, 127, 8);



    int div = divisionBinaria(m1.to_ulong(),m2.to_ulong());
    //Dividimos las mantisas

    bitset <25> maux(div);
    cout << maux << endl;
    if(maux[24]==1){
        cout << "ebtro" << endl;
        maux[24] =0;
        er = restaBinaria(er,1);
        maux = maux.operator >>(1);
    }else if(maux[23] == 1){
        maux[23] =0;
    }else if(maux[23]==0){
        cout << "entro"<< endl;
        er = restaBinaria(er,1);
        maux = maux.operator <<(1);

    }
    bitset <23> m (maux.to_ulong());

    bitset<8> exp (er);
    cout << "exponente "<< exp << endl;
    cout <<"mantisa " << m << endl;
    j=0;
    for(int i=0;i<23;i++){
        res[i] = m[j];
        j++;
    }
    j=0;
    for(int i=23;i<32;i++){
        res[i] = exp[j];
        j++;
    }
    res[31] = sr;
    //Expresamos resultado en hexadecimal
    int hex = res.to_ulong();
    QString hexnum;
    hexnum=QString::number(hex,16);
    ui->reshex->setText(hexnum);
    //Expresamos resultado en decimal
    int a = toDecimal(hex);

*/
}
bool coma_flotante:: comparar(bitset<8> exp1, bitset<8> exp2){

    int valor1 = 0;
    int valor2 =0;
    int j=7;
    int var = (int) exp1.to_ulong();
    //int final = toDecimal(var, (int)exp1.size());
    for(int i=0;i<8;i++){
        if(exp1.test(i)){
            valor1 = valor1 + (int) pow(2,j);
        }
        if(exp2.test(i)){
            valor2 = valor2 +(int) pow(2,j);
        }
        j--;
    }

    if(valor1>valor2)
        return true;
    else
        return false;
}
int coma_flotante:: sumaBinaria(int sum1, int sum2, int len){
    bitset<sizeof(len)*CHAR_BIT> num1( sum1 );
    bitset<sizeof(len)*CHAR_BIT> num2( sum2 );
    unsigned int tam = len;
    bitset<sizeof(len)*CHAR_BIT> res;

    if(len==22){
        bitset<22> res;
    }
    else if(len==8){
        bitset<8> res;
    }
    if(len== 48){
        bitset<48> res;
        bitset<48> n1( sum1 );
        bitset<48> n2( sum2 );
        cout << n1 << endl;
        cout << n2 << endl;
        bool a, b;
        //  bool carry = false;
        for(int i=0;i<len;i++){
            a=n1[i];
            b=n2[i];
            bool sum = (a ^ b) ^ carry;
            carry = (a && b) || (a && carry) || (b && carry);
            res[i]= sum;

        }
        cout << "resultado suma " << res << endl;
        int resdec = res.to_ulong();
        return resdec;

   }
    bool a, b;
    //  bool carry = false;
    for(int i=0;i<len;i++){
        a=num1[i];
        b=num2[i];
        bool sum = (a ^ b) ^ carry;
        carry = (a && b) || (a && carry) || (b && carry);
        res[i]= sum;

    }
    cout << res << endl;
    int resdec = res.to_ulong();
    return resdec;


}

int coma_flotante:: restaBinaria(int sum1, int sum2){
    bitset<sizeof(sum1)*CHAR_BIT> x( sum1 );
    bitset<sizeof(sum2)*CHAR_BIT> y( sum2 );
    bitset<sizeof(sum1)*CHAR_BIT> res;
    bool a, b;
    bool borrow = false;
    for (int i = 0; i < (int)x.size(); i++){
        if (borrow){
            if (x[i]){
                res[i] = y[i];
                borrow = y[i];
            }else{
                res[i] = !y[i];
                borrow = true;
            }
        }else{
            if (x[i]){
                res[i] = !y[i];
                borrow = false;
            }else{
                res[i] = y[i];
                borrow = y[i];
            }
        }
    }

    return (int) res.to_ulong();

}
int coma_flotante::multBinaria(int mult1, int mult2){
    bitset<25> x( mult1 );
    bitset<25> y( mult2 );
    //incluimos "Hidden bit"
    x[23]= 1;
    y[23]= 1;
   // std::bitset tmp = x;
    std::bitset<48> resbit(0);
    std::bitset<48> zeros(0);
    std::bitset<48> aux (x.to_ulong());
    cout << x << endl;
    cout << y << endl;

    cout << "auxuliar " << aux << endl;
    int tam = y.size();

    for(int i=0; i<25;i++){
        if(y[i]==0){
        }else{
            cout << "i " <<i << endl;
           // x = x.operator <<(1);
            long long temp = sumaBinariaMult(resbit.to_ullong(), aux.to_ullong());
            cout << "llego"<< endl;

            std::bitset<48> tmp (temp);
            resbit  = tmp;
            cout << "suma entero " <<temp << endl;

        }

        aux = aux.operator <<=(1);

    }
    cout << resbit << endl;
    resbit = resbit.operator >>(23);
    cout << resbit << endl;

    bitset <25> mant (resbit.to_ullong());
    cout << mant << endl;

    return resbit.to_ulong();

}

float  coma_flotante::toDecimal(int x){
    cout << " valor " << x << endl;
    bitset<32> res(x);
    cout << res << endl;
    string binary = res.to_string<char, std::char_traits<char>, std::allocator<char> >();
    bool negative  = !!(x & 0x80000000);
    int  exponent  =   (x & 0x7f800000) >> 23;
    int sign = negative ? -1 : 1;

    // Subtract 127 from the exponent
    exponent -= 127;

    // Convert the mantissa into decimal using the
    // last 23 bits
    int power = -1;
    float total = 0.0;

    for ( int i = 0; i < 23; i++ )
    {
        int c = binary[i + 9 ] - '0';
        total += (float) c * (float) pow( 2.0, power );
        power--;
    }
    total += 1.0;

    float value = sign * (float) pow( 2.0, exponent ) * total;

    QString resdec = QString::number(value);
    if(x == 0){
        resdec = QString::number(x);

    }
    ui->resdec->setText(resdec);
    cout << "RESULTADO "<< value << endl;
    return value;

}
long long coma_flotante:: sumaBinariaMult(long long sum1, long long sum2){
    bitset<48> num1( sum1 );
    bitset<48> num2( sum2 );
    bitset<48> res (0);
    cout << num1 << endl;
    cout << num2 << endl;

    bool a, b;
    //  bool carry = false;
    for(int i=0;i<48;i++){
        a=num1[i];
        b=num2[i];
        bool sum = (a ^ b) ^ carry;
        carry = (a && b) || (a && carry) || (b && carry);
        res[i]= sum;

    }
    cout << res << endl;
    long long resdec = res.to_ullong();
    return resdec;


}
int coma_flotante:: divisionBinaria(int D, int d){
    bitset <24> div1 (D);
    bitset <24> div1aux (D);

    bitset <24> div2 (d);
    div1[23]= 1;
    div2[23]= 1;
    bitset <24> aux(0);
    bitset <24> res(0);

    int k=0;
    //Calculamos los bits efectivos
    for(int i=0;i<24;i++){
        if(div2[i]==1){
            k = 24 -i;
            break;
        }
    }
    cout <<"K: "<< k<< endl;

    int p=0;
    //Calculamos los bits efectivos
    for(int i=0;i<24;i++){
        if(div1[i]==1){
            p = 24 -i;
            break;
        }
    }
    cout <<"P: "<< p<< endl;
    int kaux = k;

    int resta = 0;
    int bits = 0;
    int bitsres = 23;
    int primera =0;
    for(int i=23;i>=0;i--){
         if(kaux>0){
             aux[i]= div1[i];
             kaux--;
             bits++;
         }
     }
    int posdesp=0;
    bool des = false;
    while(bits <= p){
        //bajamos k bit
        if(primera!=0){
            aux[23-bits] = div1[23-bits];
            bits++;
        }
        cout << "1 PASO"<< aux << endl;

        //desplazamos
        posdesp = 0;
        for(int i=23;i>=0;i--){
            if(aux[i]==0){

                aux = aux.operator <<(1);
                posdesp++;
               // cout << aux << endl;
                if(posdesp==23){
                    posdesp=0;
                    break;
                }i++;
            }else{
                break;
            }
        }
        cout << "2 PASO"<< aux << endl;

        //comprobamos tamaño
        int desp  = 0;
        cout << "desplazamientoo "<<posdesp << endl;
        des = false;
        int cifras = k;
        while(aux.to_ulong()<div2.to_ulong()){
            aux = aux.operator >>(posdesp);
            cout << bits << endl;
            cout <<"Volvemos a desplazar" << aux << endl;
            aux[23-bits] =div1[23-bits];
            cout << "con nuevo bit: "<<aux << endl;
            bits++;
            cifras =bits -posdesp;

            if(bits==24)
                break;
            desp++;
            res[bitsres] = 0;
            bitsres--;
            aux = aux.operator <<(posdesp);
            if(posdesp==0&&aux[23]==0){
                 //div2 = div2.operator >>(1);
                 //des = true;
                aux = aux.operator <<(bits-1);

            }
            cout << cifras << endl;
            if(k>1&&cifras>k){
                div2 = div2.operator >>(1);
                des = true;
            }
             cout <<"Recolocamos para comparar" << aux << endl;


        }


        cout << "3 PASO"<< aux << endl;
        //div2 = div2.operator <<(1);

       //restamos
        res[bitsres] = 1;
        bitsres--;
        resta = restaBinaria(aux.to_ulong(),div2.to_ulong());
        bitset <24> nuevo (resta);
        aux = resta;
        if(des)
            div2 = div2.operator <<(desp);
        cout << "resultado de la resta "<< aux << endl;
        cout << "resultado "<< res << endl;
        primera++;



        }
        //
       /* aux.reset();
        kaux = k;
        for(int i=23;i>=0;i--){
            if(kaux>0){
                 aux[i]= div1[i-bits];
                 kaux--;
                 bits++;

            }
        }
        cout << aux << endl;
        if(aux.to_ulong()>=div2.to_ulong()){
            res[bitsres] = 1;
            bitsres--;
            resta =
        }else{
            aux[23-k] =div1[23-bits];
            bits++;

        }
    }*/
    return res.to_ulong();

}


