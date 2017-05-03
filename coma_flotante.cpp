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
    /*    cout << "exp1 " << e1 << endl;
        cout << "exp2 " << e2 << endl;

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
          //  ma[22] = 1;
        }

        bitset <23> comp = ~m2;

        int maux = sumaBinaria(comp.to_ulong(),1,23) ;
        bitset<23> ma(maux);
        //Sumamos las mantisas
        carry = false;
        int mant = sumaBinaria(m1.to_ulong(),ma.to_ulong(), 23);
        bitset <23>  m(mant);
        cout << m << endl;

        if(!carry){
            carry = false;
            exp = restaBinaria(exp,1);
            m.operator <<=(1);
        }

        if(dif==0){
            cout << "entro"<< endl;
            int pos =22;
            int diff = 1;
            while(!m[pos]){
                diff = diff+1;
                cout << diff << endl;

                pos--;
            }
            cout << diff << endl;
            exp = restaBinaria(exp,diff);
            m.operator <<=(diff);

        }

        */
         /*
          *SEGUNDO INTENTO
          *
         //Paso 1
         bool g=0; bool r=0; bool st=0;
         int n = m1.size();
         //Paso 3
         int d = restaBinaria((int) e1.to_ulong(),(int) e2.to_ulong());
            cout << "d " << d << endl;
         //Paso 4
         bitset <23> comp = ~m2;
         carry = false;
         int maux = sumaBinaria(comp.to_ulong(),1,23) ;

         //Paso 5
         bitset<23> ma(maux);
           cout << "Mantisa comp 2 " << ma << endl;
         //Paso 6
         int aux = d;
         if(aux>0){
             g = ma[d-1];
             aux--;
         }
         if (aux > 0){
             r = ma [d-2];
             aux--;
         }
         if(aux > 0){
             aux = d;
             //bool a = true;
             int resta = 3;
             while(aux > 0){
                 bool p =ma[d-resta];
                 cout << st << endl;

                 st = st^p;
                 aux--;
                 resta++;
             }
         }
         cout << "g " << g << "r " << r << "st " << st << endl;
         //Paso 7
         aux = d;
         for(int i=0;i<d;i++){
             ma.operator >>=(1);
             ma[22] = 1;
         }
         //Paso 8
         carry = false;
         int sum = sumaBinaria(m1.to_ulong(), ma.to_ulong(), 26);
         bitset <26> maaux(sum);
         ma = maaux;
         cout << "Paso 8" << endl;
         cout << ma << endl;
         //Paso 9
         if(ma[n-1]==1 && !carry){
             cout << "Paso 9" << endl;
             bitset <23> comp = ~ma;
             carry = false;
             int  rescom = sumaBinaria(comp.to_ulong(),1,23) ;
             bitset <23> maaux(rescom);
             ma = maaux;
             cout << ma << endl;
         }

         //Paso 10
         cout << "Paso 10" << endl;

         int pos = 26;
         int k=0;
         while(!ma[pos]){
             k++;
             pos--;
         }
         if(k==0){
             st = r^st;
             r = g;
             cout << g << endl;
         }
         if(k>0){
             r = 0;
             st = 0;
         }
         cout << ma << endl;
         if(carry){
             k= k-1;
         }
         for(int i=0;i<k;i++){
             cout << "entro a desplazar" << endl;
             ma =  ma.operator <<(1);
         }

         int exp = restaBinaria(e1.to_ulong(), k);
          cout << r << endl;
          cout << ma << endl;
         //Paso 11
         if ((r==1 && st==1) || (r==1 && st==0 && ma[0]==1)){
             cout << "paso 11"<< endl;
             carry = false;
             int suma11 = sumaBinaria(ma.to_ulong(), 1, 23);
             bitset <23> aux (suma11);
             ma = aux;
             if(carry){
                 ma =  ma.operator >>(1);
                 carry = false;
                 exp = sumaBinaria(exp, 1, 8);


             }
         }
*/

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

//PRODUCTO
void coma_flotante::on_prod_clicked()
{
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
    //ESTO NO FUNCIONA
    int mant = multBinaria(m1.to_ulong(), m2.to_ulong());
    //mirar cuanto desplazar
    bitset <24> m (mant);
    //exponente
    int e = sumaBinaria(e1.to_ulong(), e2.to_ulong(), 9);
    e = restaBinaria(e, 127);
    bitset <8> exp(e);
    cout << exp << endl;


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
//DIVISION
void coma_flotante::on_division_clicked()
{

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

    bool a, b;
    //  bool carry = false;
    for(int i=0;i<len;i++){
        a=num1[i];
        b=num2[i];
        bool sum = (a ^ b) ^ carry;
        carry = (a && b) || (a && carry) || (b && carry);
        res[i]= sum;

    }

    int resdec = res.to_ulong();

    cout << "resultado "<<carry << endl;
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
    bitset<24> x( mult1 );
    bitset<24> y( mult2 );
    //incluimos "Hidden bit"
    x[23]= 1;
    y[23]= 1;
   // std::bitset tmp = x;
    std::bitset<48> resbit;
    int res =0;
    int tam = y.size();
    cout << tam << endl;

    for(int i=0; i<24;i++){
        if(y[i]==0){
            x = x.operator <<(1);

         //   resbit = resbit.operator <<(1);
            cout << resbit << endl;
        }else{
            cout << "entro" << endl;
           // x = x.operator <<(1);
            int temp = sumaBinaria (resbit.to_ulong(), x.to_ulong(),48);
            std::bitset<48> tmp (temp);
            cout << resbit << endl;

            resbit  = tmp;
        }
    }
    cout << resbit << endl;


}

int  coma_flotante::toDecimal(int x){
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

}
