/*
---------------------Diferentes recursos de C++------------------------
    string cadena="john";
    string cadena1="watson";
    int num=15;
    float num1=928.2908;
    cout<< cadena<<endl<<num<<endl<<cadena1<<endl<<num1<<endl;
    int x=2,y=4,z=7;
    cout<<"la suma de x, y z es:"<<x+y+z<<endl;
    cadena.append(cadena1);
    auto len =cadena.length();
    cadena[0]='M';
    cout<<cadena<< " -> len:" << len<< endl;
    string fullName;
    cout << "Type your full name: ";
    getline (cin, fullName);
    cout << "Your name is: " << fullName<<endl;
    cout<<"maxxxxxxx:"<<max(x,y)<<endl<<"Minnnnnn:"<<min(x,y)<<endl;
    x>y?cout<<"x es mayor que y":cout<<"y es mayor que x";
-------------------------------------------------------------------------*/
#include <iostream>
#include <string>

using namespace std;

/*
1)Escribir la siguiente frase por pantalla “She sells sea shells by the seashore.”

Todo en una sola línea.
En siete líneas.*/

string cadenita(string oracion){
    cout<<"en una linea: "<< oracion<<endl;
    cout<<"en 7 lineas: "<<endl;
    for(int i=0;i<oracion.size();i++){
        cout<<oracion[i];
        if(oracion[i]==' '){
            cout<<endl;
        }
    }
    return oracion;
}

int main(){
    string oracion ="She sells sea shells by the seashore";
    cadenita(oracion);
    return 0;
}
/*2) Escribir un programa que reciba tres enteros x,  y ,z y devuelva el resultado de la siguiente fórmula:*/
int sumi (int x, int y,int z){
    int suma;
    suma=(x+y+z)*2+z;
    return suma;

}
int main(){
    int x=2,y=8,z=0;
    int sum;
    sum= sumi(x,y,z);
    cout<<sum<<endl;
}
/*3) corregir código para que se imprima
3 = a + b
c = 3
*/

#include <iostream>

using namespace std;

int main()
{
    int a = 1, b = 2, c = 3;
    cout << c << " = a + b"<<endl;
    cout << "c = " << c <<endl;
}

/*Escribir un programa que reciba la cantidad de distintas monedas ingresadas (de a un tipo de moneda a la vez), a saber:

5 centavos
10 centavos
25 centavos
50 centavos
1 peso
2 pesos
5 pesos
10 pesos
Y devuelva el monto total con un mensaje por pantalla de la forma:

“Su monto total es de $PP.CC” (donde PP es la cantidad de pesos y CC la cantidad de centavos)
“Su monto total es de PP peso(s) y CC centavo(s). Considere que las palabras pesos y centavos
 puede tomar la forma singular o plural, según la cantidad en particular. Resuélvalo.
*/

int main(){
    cout<<"holiwis, ingresa monedas->"<<endl;
    double c_cent=0, d_cent=0, v_cent=0, cin_cent=0;
    int un_peso=0,dos_peso=0,c_p=0,diez_p=0;
    cin>>c_cent>>d_cent>>v_cent>>cin_cent>>un_peso>>dos_peso>>c_p>>diez_p;
    c_cent*=0.05;
    d_cent*=0.10;
    v_cent*=0.25;
    cin_cent*=0.50,
    dos_peso*=2;
    c_p*=5;
    diez_p*=10;
    int pesos=un_peso+dos_peso+c_p+diez_p;
    double cent= c_cent+d_cent+v_cent+cin_cent;
    int pesitos= (int)cent;
    pesos+=pesitos;
    cent-=pesitos;
    cent*=100;
    cout<<"Su monto total es de $"<<pesos<<"."<<cent<<endl;
    if(pesos==1){
        cout<<"Su monto total es de "<<pesos<< " peso y "<<cent<< " centavos"<<endl;
    }
    else{
         cout<<"Su monto total es de "<<pesos<< " pesos y "<<cent<< " centavos"<<endl;
    }
}
/*Escribir un programa que encuentre el valor máximo y mínimo de una serie de 
valores numéricos ingresados por el usuario. El programa debe primero preguntar
 cuantos valores se ingresarán, y luego leerlos.*/

 int main(){
    int i;
    cout<<"cuantos valores vas a ingresar?"<<endl;
    cin>>i;
    int array[i];
    for(int x=0;x<i;x++){
        int val;
        cout<<"dale, ingresa uno:"<<endl;
        cin>>val;
        array[x]=val;
    }
    int m=array[0];
    for(int j=1;j<i;j++){
      m= max(m,array[j]);
    }
    cout<<"max val-> "<<m<<endl;
 }

 /*Escribir un programa que calcule las raíces de un polinomio de segundo grado. Pruebe los tres tipos de soluciones que existen:

Raíz doble.
Raíces reales.
Raíces complejas.*/

int raices (int a,int b,int c){
    int discriminante = (b*b)-4*a*c;
    int raiz1= (-b+sqrt(discriminante))/(2*a);
    int raiz2= (-b-sqrt(discriminante))/(2*a);
    if(discriminante<0){
        cout<<"tiene raices imaginarias, imposible";
    }
    else if (discriminante ==0){
        cout<<"raiz doble-> "<<raiz1<<endl;}
    else{
        cout<<"raiz 1-> "<<raiz1<<endl<<"raiz 2->"<<raiz2<<endl;
    }

    return 0;
}


int main(){
    int a,b,c;
    cin>>a>>b>>c;
    raices(a,b,c);
}
using namespace std;

enum class Status {kOk, kError}; 


Status Minimum (double &min, const double vector[], size_t length){
    if ((vector ==NULL)||(length<=0)){
        return Status::kError;
    }
    double j=vector[0];

    for(int c=0;c<length;c++){
        if (vector[c]>j){
            j=vector[c];
        }
    }
    min=j;
    return Status::kOk;

}

int main(){
    double min;
    size_t length=10;
    const double vector [length]={1,2,3,4,5,6,7,8,9,0};
    Minimum(min,vector,length);
    cout<<min;
}
/*****************************************************************************************************/
using namespace std;

enum class Status {kOk, kError}; 


Status Minimum (double &min, const double vector[], size_t length){
    if ((vector ==NULL)||(length<=0)){
        return Status::kError;
    }
    double j=vector[0];

    for(int c=0;c<length;c++){
        if (vector[c]>j){
            j=vector[c];
        }
    }
    min=j;
    return Status::kOk;

}

int main(){
    double min;
    size_t length=10;
    const double vector [length]={1,2,3,4,5,6,7,8,9,0};
    Minimum(min,vector,length);
    cout<<min;
}

/*****************************************************************************/
using namespace std;

enum class Status {kOk, kError}; 


Status Minimum (double *min, const double vector[], size_t length){
    if ((vector ==NULL)||(length<=0)){
        return Status::kError;
    }
    double j=vector[0];

    for(int c=0;c<length;c++){
        if (vector[c]>j){
            j=vector[c];
        }
    }
    *min=j;
    return Status::kOk;

}

int main(){
    double min;
    size_t length=10;
    const double vector [length]={1,2,3,4,5,6,7,8,9,0};
    Minimum(&min,vector,length);
    cout<<min;
}

/***********************************************************************************/
using namespace std;

enum class Status {kOk, kError}; 


Status Minimum (const double& min, const double vector[], size_t length){
    if ((vector ==NULL)||(length<=0)){
        return Status::kError;
    }
    double j=vector[0];

    for(int c=0;c<length;c++){
        if (vector[c]>j){
            j=vector[c];
        }
    }
    min=j; /*no se puede modificar, pq es const double*/
    return Status::kOk;

}

int main(){
    double min;
    size_t length=10;
    const double vector [length]={1,2,3,4,5,6,7,8,9,0};
    Minimum(min,vector,length);
    cout<<min;
}
