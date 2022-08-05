#include <stdio.h> /*libreria condefiniciones macros y constantes de c */
#include <math.h> /* libreria de matemática */
/*
%s ->strings
%d-> int
%c-> char
%p -> pointer

*/

const int x=1, y=2 ,z=4;
char holi = 't';
int sum = x+y+z;
int div = z%y;
int mult = z*y;

void hola (void){
    printf("Hola mundo. :D \n ");
}
void impr (void){
    printf("numero1: %d, numero2= %d , numero3= %d y una letra :%C \n",x,y,z,holi);
    printf("la suma da : %d\n",sum);
    printf("la división entre el numero2 y el numero3 da :%d\n",div);
    printf("la multiplicación entre el numero2 y el numero3 da : %d\n",mult);
}
void conditions (void){
    if (div == 0){
        printf("la división no tiene resto.\n");
    }
    if (mult>10){
        printf("aaaaaaa");
    }
    else if (mult>5){
        printf("la multiplicación es mayor que 5.\n");
    }
    else {
        printf("la multiplicación es menor que 5\n");
    }

    (x > 1)? printf("es mayor que 1. X vale: %d\n",x) :printf("no es mayor que 1. x vale :%d\n",x);
    (y > 1)? printf("es mayor que 1. Y vale: %d\n",y) :printf("no es mayor que 1. Y vale :%d\n",y);

    switch (y){
        case 1: printf("lunes\n");
        break;
        case 2:printf("martes\n");
        break;
        case 3:printf("miercoles\n");
        break;
        case 4:printf("jueves\n");
        break;
        case 5:printf("viernes\n");
        break;
        case 6:printf("sábado\n");
        break;
        case 7:printf("domingo\n");
        break;
        default : printf("valor default");
    }


}

void loops (void){
    int i =0;
    while (i<3){
        printf("%d\n",i);
        i++;
    }
    do{
        i--;
        printf("%d\n",i);
    }
    while (i>0);

    int h;

    for (h=0;h<3;h+=1){
        printf("el valor de h es: %d\n",h);
    }
}

void arrays(void){
    int first_array[]={7,8,9};
    int f;
    for(f=0;f<3;f++){
    printf("%d\n",first_array[f]);
    }
    char string1 []="Esto es un cadena de texto\n";
    printf("%s",string1);
    char string2 [] = "holis\n";
    int i;
    for (i=0;i<sizeof(string2);i++){
         printf("%c\n",string2[i]);
         }
}

void inputs (void){
    char firstname [30]; /*cant. caracteres que se pueden ingresar*/
    int age; /*la cant de numeros no se aclara */
    printf("ingrese su nombre :\n");
    scanf ("%s",firstname); /*solo recibe la primer palabra*/
    printf("Hellooo %s ,cuántos años tenes?",firstname); /*printf requiere aclarar qué varibale es */
    scanf("%d",&age);
    printf("Nombre :%s \nEdad :%d\n",firstname,age);
}

void pointer(void){
    /* *ptr-> devuelve el valor de la variable con el puntero
        &num-> devuelve el puntero con la variable 
    */
    int num = 40;
    int num2 = 30;
    int * ptr = &num ;/* una variable puntero, nombre:ptr -> guarda la dirección de 'num' */
      printf("La dirección de la variable %d es : %p\n",*ptr,ptr);
      printf("la direccion de la variable %d es %p \n",num2,&num2);
    

}

int param_func (int, int );
void func_x (); /* podemos declarar funciones y llamarlas (si están declaradas) antes de definirlas */


int main (void){
    hola();
    impr();
    conditions();
    loops();
    arrays();
    inputs();
    pointer();
    printf(" 2+12 = %d \n",param_func(2,12));
    func_x();
    
}
void func_x (){
    printf("se puede llamar a una función si está declarada, sin estar definida. \n");
}
int param_func (int x, int y ){
    return x+y ;
}