#include <stdio.h>
#include <math.h>
int main (void){
    int entero =1234;
    float var_float= 0.8;
    int a = 1; /*las variables no se redefinen */
    printf("%i and %i \n",a,entero); /* dos enteros */
    printf("%1.2f and %i \n",var_float,a);/* un float y un entero */
    printf("%c \n",97);/* el caracter que tiene ese valor en ASCII */
    printf("%i\n",'b'-97); /* si pedimos un numeros de la resta entre n caracter y un int, nos da el resultado 
                             porque hace la operacion con el valor de ASCII */
    printf("un  int ocupa %lu bytes \n ",sizeof(int)); /* cant. bytes que ocupa cada tipo de variable */ 
    
    int x,y,z;
    x=1;
    y=2;
    z=x+y;
    /* la division entre enteros da un entero, entre floats nos da un float*/
    printf("la suma de %i y %i da = %i \n",x,y,z);

    printf("%f \n",(float) 32);/*interpretar un numero como un float*/

    printf("%f\n",pow(x,y)); 
/* Para las condiciones
   && and
   || or 
   == igual 
   != distinto
   !(x<20) para decir que una condición no se cumple 
*/
    if (x> 20){
        puts("x es mayor a 20\n");
    }
    else{
        puts("x es menor a 20\n");
    }
    return 0; 
}

/* tipos de variables
int
short
chart
int
long int
float
double
void

*/

/*
1 bit -> 8 bytes 
*/