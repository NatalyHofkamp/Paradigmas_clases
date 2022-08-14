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