/*                                                  GUIA 1
1) Escribir una función que reciba el capital inicial, una tasa de interés y un número de años 
y devuelva el monto final a cobrar.*/

#include <stdio.h>
#include <math.h>

int capital (int,float,int);

int main(void){
    capital(1000,10,2);
}

int capital (int cap_in,float t_int,int anio){
    int final;
    int final_exp;
    float _exp;
    float a;
    a = 1+(t_int/100);
    _exp = pow(a,2);
    final_exp= cap_in*_exp;
    printf("%i\n",final_exp);
}

/* 2) Escribir una función que convierta un valor en grados Fahrenheit a grados Celsius.
   3)Escribir una función que convierta un valor en grados Celsius a grados Fahrenheit.*/
int fahrenheit (float);
int celcius (float);
int main(void){
    fahrenheit(32);
    celcius(10);
}
int fahrenheit (float gr){
    float conv;
    conv= (1.8*gr)+32;
    printf("%f\n",conv);
}
int celcius (float gra){
    float conv2;
    conv2 = (gra - 32) * 0.55;
    printf("%f\n",conv2);
}

/* 4)Escribir una función que dadas la hora, minutos y segundos devuelva el tiempo en segundos.*/
int segundos (float,float,float);

int main (void){
    segundos(2,45,19);
}

int segundos (float hora,float minuto,float seg){
    float hrs;
    float min;
    float total_seg;
    hrs= hora*3600;
    min = minuto *60;
    total_seg = hrs + min +seg;
    printf("%f\n",total_seg);
}

/* 5) Escribir una función que dadas las coordenadas de un 
vector en R^3 ,  devuelva la norma del mismo */
int norma (float,float,float);

int main (void){
    norma(3,5,2);
}

int norma (float r1,float r2,float r3){
    float norma;
    float r1_e , r2_e , r3_e;
    float sum;
    r1_e= pow(r1,2);
    r2_e= pow(r2,2);
    r3_e= pow (r3,2);
    sum= r1_e + r2_e + r3_e;
    norma = sqrt(sum);
    printf("%f\n",norma);
}

/* 6) Teniendo el radio de un cilindro y su altura escribir funciones que calculen:
        a_El diámetro del cilindro.
        b_La circunferencia.
        c_El área de la base.
        d_El volumen del cilindro.
        e_El área del cilindro.
*/
int cilindro (float,float);

int main (void){
    cilindro(3,5);
}

int cilindro (float radio,float altura){
    float diametro;
    float circunferencia;
    float area_base;
    float volumen;
    float area;
    diametro = 2*radio;
    printf("%f\n",diametro);
    circunferencia = PI *diametro;
    printf("%f\n",circunferencia);
    area_base = PI * pow(radio,2);
    printf("%f\n",area_base);
    volumen = altura * area_base;
    printf("%f\n",volumen);
    area = (circunferencia*altura) + (2* area_base);
    printf("%f\n",area);
}



/* 7) Escribir una función que dado un número entero devuelva 1
 si el mismo es impar y 0 si fuera par. */
 int par_impar (int);
int main (void){
    par_impar(3);
}
int par_impar (int entero){
    int a = entero %2;
    if (a== 0) {
        printf("1\n");
    }
    else{
        puts("0\n");
    }
}

/* 8) Escribir una función que dado un número devuelva el primer número múltiplo de 10 inferior a él.
 Por ejemplo, para 153 debe devolver 150.*/
int mult_10 (int);
int main (void){
    mult_10(153);
}
int mult_10 (int num){
    
    if (num%10 ==0){
        printf("%i",num);
    }
    else{
        mult_10(num-1);
    }
}

/* 9) Escribir una función que compare (reciba) 2 números enteros a y b. 
La función debe retornar un número menor, igual o mayor que cero si
 a es, respectivamente, menor que, igual a, o mayor que b.*/ 

int comp (float,float);
int main (void){
    comp(3,3);
}
int comp(float a, float b){
    if (a>b){
        printf("1\n");
    }
    else if (a==b){
        printf("0\n");
    }
    else{
        printf("-1\n");
    }
}

/* 10) Escribir una función que reciba un número entero 
y devuelva 1 si el número es positivo y -1 si el número es negativo.*/
int comp (float);
int main (void){
    comp(0);
}
int comp(float a){
    if (a>=0){
        printf("1\n");
    }
    else{
        printf("-1\n");
    }
}

/* 12)Escribir un programa que imprima, en 3 líneas separadas,
 su nombre, apellido y legajo. */
 
int comp (char const *nombre,char const *apellido ,int);
int main (void){
    char nombre[30] = "Nataly";
    char apellido[30] = "Hofkamp";
    comp(nombre,apellido,34596);
}
int comp(char const *nombre,char const *apellido ,int leg){
    printf("Nombre :%s\n Apellido :%s\n Legajo :%i\n",nombre,apellido,leg);
}

/*                                          CICLOS

1) Escribir un programa que imprima la tabla de multiplicar del número 7.*/
int tabla7 (void);
int main (void){
    tabla7 ();
    
}
int tabla7(void){
    int i;
    for ( i=0;i<=70;i+=7){
        printf("%i\n",i);
    }

}

/* 2)Escribir un programa que imprima la tabla de multiplicar para los números del 1 al 10. */
int tablas (void);
int main (void){
    tablas ();
    
}
int tablas(void){
    int i;
    int n;
    for ( i=0;i<=10;++i){
        for (n=0;n<=10;++n){
            int a = n*i;
            printf("%i.",a);
        }
        puts("\n");
    }

}


/*3)Escribir un programa que imprima la tabla de conversión de Celsius a 
Fahrenheit para los valores de 0ºC a 100ºC de 10 en 10 con 2 decimales.*/


int conver (void);
int celcius (float);

int main(void){
    conver();
}

int celcius (float gra){
    float conv;
    conv= (1.8 * gra) + 32;
    return (conv);
}

int conver(void){
    float i;
    for (i=0; i<=100;i+=10){
        printf("%.1f grados celcius son %i grados farenheit\n",i,celcius(i));
    }
}

/*Los coeficientes binomiales. escribir una función que los calcule.*/
int coef_bi (int,int);
int factorial(int);
int main(void){
    coef_bi(3,2);
}

int coef_bi(int n, int k){
    float a;
    float b;
    float c;
    float res;
    a= factorial(n);
    b=factorial (k);
    c= factorial (n-k);
    res = a/(b*c);
    printf("%.4f",res);
}

int factorial(int num){
    if (num > 1){
        return num*factorial(num-1);
    }
    else {
        return num;
    }
}

/*La potencia de un binomio se computa como 
. Escribir una función void desarrollar_binomio(int n); 
que imprima los términos a calcular.*/

int coef_bi (int,int);
int factorial(int);
int potencia(int);
int main(void){
    potencia(3);
}

int potencia(int pot){
    int a;
    int k;
    float r;
    printf("el polinomio de (x+y)^%i =",pot);
    for (k=0;k<=pot;++k){
        a=coef_bi(pot,k);
        r=pot-k;
        if (a<=1){
            printf("+ 1 x^%.1f y^%i ",r,k);
        }
        else{
        printf("+%i x^%.1f y^%i ",a,r,k);
        }
    }
    
}


int coef_bi(int n, int k){
    float a;
    float b;
    float c;
    float res;
    a= factorial(n);
    b=factorial (k);
    c= factorial (n-k);
    res = a/(b*c);
    return res;
}

int factorial(int num){
    if (num > 1){
        return num*factorial(num-1);
    }
    else {
        return num;
    }
}

/* 9)Escribir una función que dado un número
 entero lo imprima espejado. Por ejemplo: 123456 se imprime como 654321.*/

 int espejo(int);

int main(void){
    espejo(456);
}

int espejo(int num){
    int a;
    int x;
    int b;
    float res;
    int divv;
    b=10;
    if (num !=0){
        res= num % b ;
        printf("%.0f",res);
        divv = num/b;
        espejo(divv);
    }
    else{
        return 1;
    }
}

/*                                      DECISIONES   

1) Escribir una función que dada una dimensión imprima la matriz identidad de esa dimensión.*/
int matriz(size_t);

int main(void){
    matriz(6);
}

int matriz(size_t dim)/*size_t unsigned integer*/
{
    size_t col;
    size_t fil;
    
    for (col=0;col<dim;col++){
        for (fil=0;fil<dim;fil++){
            if(fil == col){
                putchar('1');
            }
            else{
                putchar ('0');
            }
        }
        putchar('\n');
    }
}

/* 5) Escribir un programa que calcule las 2 raíces de un polinomio de segundo grado */

int raices(int,int,int);

int main(void){
    raices(1,4,0);
}

int raices(int a, int b,int c){
    int dis;
    float res;
    float r1, r2;
    dis= pow(b,2) - (4*a*c);
    if (dis >0){
        r1= (- b + sqrt(dis))/ (2*a);
        r2= (- b - sqrt(dis))/ (2*a);
        printf("x1 = %.1f y x2= %.1f",r1,r2);
    }
    else if (dis ==0){
        r1= (- b/ (2*a));
        printf("x1 = %.1f ",r1);
    }
    
    else{
        printf("No tiene raices reales.");
    }
}

/* 6)Escribir una función que dadas dos rectas definidas por su pendiente y
 su ordenada al origen devuelva la abcisa en la que se intersectan. Validar
  lo que considere necesario.*/

int interseccion(float,float,float,float);

int main(void){
    interseccion(2,1,5,6);
}

int interseccion(float x1, float y1,float x2,float y2){
    float x;
    float y;
    x= (y2 - y1)/(x2 - x1);
    y= (x1*x) + y1;
    printf("las rectas F(X)= %.1fX + %.1f y G(X)= %.1fX + %.1f \n se intersecan en el punto : (%.2f,%.2f)",x1,y1,x2,y2,x,y);
}

/* 8) Escribir un programa que calcule la mínima cantidad de billetes
 (moneda peso argentino) con los que se puede obtener un monto.*/
int interseccion(int);

int main(void){
    interseccion(2563);
}

int interseccion(int plata){
  int mil = 0;
  int quin = 0;
  int dosc = 0;
  int cien = 0;
  int cinc = 0;
  int veinte = 0;
  int diez = 0;
  int cinco = 0;
  int dos = 0;
  int uno = 0;
  
  do {
  if ((plata - 1000)>=0){
      mil+=1;
      plata-=1000;
  }
  else if ((plata - 500)>=0){
      quin+=1;
      plata-=500;
  }
  else if ((plata - 200)>=0){
      dosc+=1;
      plata-=200;
  }
  else if ((plata - 100)>=0){
      cien+=1;
      plata-=100;
  }else if ((plata - 50)>=0){
      cinc+=1;
      plata-=50;
  }else if ((plata - 20)>=0){
      veinte+=1;
      plata-=20;
  }else if ((plata - 10)>=0){
      diez+=1;
      plata-=10;
  }else if ((plata - 5)>=0){
      cinco+=1;
      plata-=5;
  }else if ((plata - 2)>=0){
      dos+=1;
      plata-=2;
  }else if ((plata - 1)>=0){
      uno+=1;
      plata-=1;
  }
  }while (plata >0);
  
 if (mil > 0){
      printf("%i X 1000 ARS \n",mil);
  }
 if (quin > 0){
      printf("%i X 500ARS\n",quin);
  }if (dosc > 0){
      printf("%i X 200 ARS\n",dosc);
  }if (cien > 0){
      printf("%i X 100ARS\n",cien);
  }if (cinc > 0){
      printf("%i X 50 ARS\n",cinc);
  }if (veinte > 0){
      printf("%i X 20 ARS\n",veinte);
  }if (diez > 0){
      printf("%i X 10 ARS\n",diez);
  }if (cinco > 0){
      printf("%i X 5 ARS\n",cinco);
  }if (dos > 0){
      printf("%i X 2 ARS\n",dos);
  }if (uno > 0){
      printf("%i X 1 ARS\n",uno);
  }
  
}




/* 10) Escribir una función que dado un carácter imprima: */
void impr (char);

int main(void)
{
    impr('a');
}

void impr(char letra)
{
    switch (letra){
        case 'A': printf("Ada Lovelace\n");
        break;
        case 'a':printf("Alan Turing\n");
        break;
        case 'B':printf("Brian Kernighan\n");
        break;
        case 'b':printf("Bjarne Stroustrup\n");
        break;
        case 'D':printf("Dennis Ritchie\n");
        break;
        case 'G':printf("Grace Hopper\n");
        break;
        case 'H':printf("Hedy Lammar\n");
        break;
        case 'I':printf("Ida Rhodes\n");
        break;
        case 'm':printf("Margaret Hamilton\n");
        break;
        case 'M':printf("Maddog Hall\n");
        break;
        default : printf("No lo conozco");
        
    }
    
}

/*                          ENTENDIENDO C 

1)Dados los siguientes tipos

char
unsigned char
short
int
unsigned int
unsigned long
float
double

¿Cuál es el tamaño, en bytes, de cada uno y cuáles son sus valores máximos y mínimos?

¿Cuáles, si alguno, pueden tener un tamaño diferente? ¿De qué depende el cambio? todavía no llegamos a esto :p/*


/*                                          ARREGLOS

1)Un arreglo de enteros con 15 elementos, todos ellos de valor 0.*/
int arreglito (int);

void main(void){
    arreglito(5);
    arreglito(15);
}

int arreglito(int len){

    int arreglo[len];
    int i;
    for (i=0;i<len;++i){
        arreglo[i]=0;
        printf("%i",arreglo[i]);
    }
    
}

/* 2)Un arreglo de 7 doubles, todos ellos de valor 3.0. */

int arreglito (int);

void main(void){
    arreglito(7);
}

int arreglito(int len){
    double arreglo[len];
    int i;
    for (i=0;i<len;++i){
        arreglo[i]=0.3;
        printf("%.1f\n",arreglo[i]);
    }
    
}

/* 3)Un arreglo con SIZE elementos de 
algún tipo (bool, int, float, double, etc) y lo inicialice con valores aleatorios.*/
int arreglito (int);

void main(void){
    arreglito(7);
}

int arreglito(int len){
    srand(time(NULL));
    double arreglo[len];
    int i;
    int b;
    
    for (i=0;i<len;++i){
        b = rand() % 11;
        arreglo[i]=b;
        printf("%.1f\n",arreglo[i]);
    }
    
}
/* 2) Escribir ciclos que realicen cada una de las siguientes operaciones:

a)Inicializar un vector de 10 elementos con ceros.*/
int arreglito (int);

void main(void){
    arreglito(10);
}

int arreglito(int len){
    int arreglo [] = {0,0,0,0,0,0,0,0,0,0};
    int i;
    for (i=0;i<len;++i){
        printf("%i",arreglo[i]);
    }
    
}

/* Sumar 1 a cada uno de los 15 elementos del arreglo vector.*/
int arreglito (int);

void main(void){
    arreglito(10);
}

int arreglito(int len){
    int arreglo [] = {0,0,0,0,0,0,0,0,0,0};
    int i;
    for (i=0;i<len;++i){
        arreglo[i]+=1;
        printf("%i",arreglo[i]);
    }
    
}

/*Leer del teclado y almacenar 12 valores de punto flotante en el arreglo temp_mensuales.*/


int arreglito (int);

void main(void){
    arreglito(10);
}

int arreglito(int size){
    float temp_mensuales [size];
    int i;
    for (i=0;i<size;i+=1){
        temp_mensuales[i]=0.5;
        printf("%.1f",temp_mensuales[i]);
    }
    
}

