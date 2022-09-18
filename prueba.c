#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*4. La función [strdup recibe una cadena de caracteres y devuelve una copia de la misma utilizando memoria
dinámica. Implemente dicha función, con el siguiente prototipo:

char *strdup(char *);*/

char* strDup(char* cadena){
  if(cadena==NULL){
    return NULL;
  }
  int len;
  len=strlen(cadena)+1;
  char *copia;
  copia=(char*) malloc(sizeof(char)*len);
  for(int i=0;i<len;i++){
    copia[i]=cadena[i];
  }
  return copia;

}

int main (int argc, char* argv[]){
  int len = strlen(argv[1])+1;
  char *cadena;
  char* copia;
  cadena=(char*)malloc(sizeof(char)*len);
  cadena=argv[1];
  copia=strDup(cadena);
  printf("%s",copia);
}