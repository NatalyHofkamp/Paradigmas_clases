/*********************pruewba juego*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char*chau;
}despedida;

typedef struct{
    char holis[20];
    despedida* chauchis;
}holi;

int main(){
     holi hola;
     holi* hola_ptr=&hola;
     hola_ptr->chauchis->chau="chauchis";
     strcpy(hola_ptr->holis,"olis");
     printf("%s",hola_ptr->holis);
     printf("%s",hola_ptr->chauchis->chau);
}