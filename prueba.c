/*Implementar una función que retorne una matriz dinámica, de un tamaño pasado como argumento, 
siendo la misma inicializada con:

-> ceros,
-> unos,
-> la identidad,
-> números aleatorios.

*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char* copyString (char[]);

int main (void){
  char *copy;
  copy =copyString("Holiwis");
  free(copy);
}

char * copyString(char cadena []){
  char * newCadena;
  int len;
  len=strlen(cadena);
  newCadena =(char*) malloc(sizeof(char)*len+1);
  for (int x =0;x<len;x++){
    newCadena[x]=cadena[x];
  }
  int len2= strlen(newCadena);
  for(int i =0;i<=len;i++){
    printf("%c",newCadena[i]);
  }
  printf("%i",len2);
  return newCadena;
}
