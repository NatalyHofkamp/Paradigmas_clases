#include <stdio.h>
/*Escriba 3 porciones de código que inicialicen de 3 maneras distintas la 
variable str con la cadena "Winter is coming". Comente las diferencias entre las 3 formas.*/

int cadena(void);

int main()
{
   cadena();
}

int cadena (void){
    char winter [7]={'w','i','n','t','e','r',0};
    char is [3]="is";
    char coming [7]={'c','o','m','i','n','g','\0'};
    
    printf("%s %s %s ",winter,is,coming);
}

/*Para cada inciso, explique las diferencias en las definiciones mostradas:*/
int cadena(void);

int main()
{
   cadena();
}

int cadena (void){
  char manzana[] = "manzana";
  char * naranja = "naranja";
  
  printf("manzana[] es un arreglo de char.");
  printf("hacemos manzana [1]-> %c \n ",manzana [1]);
  manzana[1]='o';
  printf(" se modifica manzana [1]='o' ->%s \n",manzana);
  
  printf("*naranja puntero a char.naranja[1]-> %c\n",naranja[1]);
  printf("no se modifica con naranja[1].");
}

/*Escriba un programa que lea una cadena de caracteres ingresada por el flujo de entrada estándar 
y la imprima por pantalla. almacena la cadena en un arreglo de no más de 100 caracteres. Utilice 
los siguientes métodos:*/
int cadena(void);

int main()
{
   cadena();
}

int cadena (void){
  char nombre [100];
  fgets(nombre,30,stdin);
  printf("tu nombre es: %s",nombre);
    
}

/*Escriba un programa que lea una cadena de caracteres e imprima por pantalla, para cada elemento de la cadena: 
su posición dentro de la cadena, el carácter y su código en representación ASCII. Por ejemplo:*/

int cadena(void);

int main()
{
   cadena();
}

int cadena (void){
  char palabra [100];
  fgets(palabra,30,stdin);
  printf("la palabra ingresada es: %s\n",palabra);
  char letras[30]="abcdefghijklmnopqrstuvwxyz";
  int ascii[30]={65,66,67,68,69,70,71,72,3,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};
  int contador =0;
  while(palabra[++contador]!=0);
  for (int i=0;i< contador-1 ;i++){
      printf("%i ",i);
      printf("%c ",palabra[i]);
      for (int x=0;x<=27;x++){
          if (palabra[i]==letras[x]){
              int asciival = ascii[x];
              printf("%i \n",asciival);
          }
          }
      }
  }

/*(ctype.h) Escriba un programa que lea una cadena de caracteres e imprima una tabla como la siguiente:*/
int cadena(void);

int main()
{
   cadena();
}

int cadena (void){
  char palabra [100];
  fgets(palabra,30,stdin);
  printf("la palabra ingresada es: %s\n",palabra);
  int contador =0;
  while(palabra[++contador]!=0);
  int tabla [contador][11];
   for (int i=0;i<contador;i++){
      for(int x=0;x<11;x++){
          tabla[i][x]=0;
      }
  }
  for (int i =0;i<contador;i++){
      int result = isdigit(palabra[i]);
      if (result!=0){
          tabla[0][i]=1;
      }
      int result1 = isalpha(palabra[i]);
      if (result1!=0){
          tabla[1][i]=1;
      }
      
      int result2 = isalnum(palabra[i]);
      if (result2!=0){
          tabla[2][i]=1;
      }
      
      int result3 = isxdigit(palabra[i]);
      if (result3!=0){
          tabla[3][i]=1;
      }
      
      int result4 = islower(palabra[i]);
      if (result4!=0){
          tabla[4][i]=1;
      }
      
      int result5 = isupper(palabra[i]);
      if (result5!=0){
          tabla[5][i]=1;
      }
      
      int result6 = isspace(palabra[i]);
      if (result6!=0){
          tabla[6][i]=1;
      }
      int result7 = iscntrl(palabra[i]);
      if (result7!=0){
          tabla[7][i]=1;
      }
      int result8 = ispunct(palabra[i]);
      if (result8!=0){
          tabla[8][i]=1;
      }
      int result9 = isprint(palabra[i]);
      if (result9!=0){
          tabla[9][i]=1;
      }
      int result10 = isgraph(palabra[i]);
      if (result10!=0){
          tabla[10][i]=1;
      }   
  }
  
  for (int i=0;i<contador;i++){
      for(int x=0;x<11;x++){
          printf("%i",tabla[i][x]);
      }
      puts("\n");
  }
 
  }

/*Escriba un programa que lea una cadena de caracteres y verifique si la misma se encuentra vacía.*/
int cadena(void);

int main()
{
   cadena();
}

int cadena (void){
  char palabra [100];
  fgets(palabra,30,stdin);
  int contador =0;
  while(palabra[++contador]!=0);
  if (contador==1){
      printf("la cadena esta vacía");
  }
  else{
      printf("la cadena  es :%s",palabra);
  }
  }
/*
Escriba un programa que lea una cadena de caracteres e imprima su longitud. 
Considere los siguientes casos de ejecución:*/
int cadena(void);

int main()
{
   cadena();
}

int cadena (void){
  char palabra [100];
  fgets(palabra,30,stdin);
  int contador =0;
  while(palabra[++contador]!=0);
  printf("%i",contador-1);
  
  }

/*Implemente una función que reciba una cadena y la invierta.*/
char *cadena(char *palabra);

int main()
{
   cadena("hola como estas");
}

char *cadena (char *palabra){
  int contador =0;
  while(palabra[++contador]!=0);
  char new[contador];
  int j=0;
  for (int i=contador-1;i>=0;i--){
          new[j++]=palabra[i];
  }
  puts(palabra);
  puts(new);
  
  }
/*Implemente una función que reciba una cadena y retorne un 
booleano indicando si la misma es palíndroma o no.*/

#include <stdbool.h>
bool es_palindroma( char *palabra);

int main()
{
   es_palindroma("anana");
}

bool es_palindroma(char *palabra){
    int contador=0;
    while (palabra[++contador]!=0);
    int j=0;
    for (j; j<=contador/2;j++){
        if((palabra[--contador]==palabra[j])&&(j==contador/2)){
            printf("la palabra -> %s es palíndroma",palabra);
        }
    }
    puts("no es palíndroma");
  }
  
/*Implemente una función que reciba una cadena y:

la convierta a mayúsculas: char *strupper(char *);*/

char *strupper(char *palabra);

int main()
{
   strupper("anana");
}

char *strupper(char *palabra){
     printf("%s \n",palabra);
     int contador=0;
     while(palabra[++contador]!=0);
      char a[contador];
     for(int i=0;i<contador;i++){
         a[i]= toupper(palabra[i]);
     }
     printf("%s",a);
      
}
  

/*la convierta a minúsculas: char *strlower(char *);*/
char *strupper(char *palabra);

int main()
{
   strupper("AnAnA");
}

char *strupper(char *palabra){
     printf("%s \n",palabra);
     int contador=0;
     while(palabra[++contador]!=0);
      char a[contador];
     for(int i=0;i<contador;i++){
         a[i]= tolower(palabra[i]);
     }
     printf("%s",a);
      
}

/*invierta el casing: char *strinvertcase(char *);

Los caracteres que se encuentren en mayúsculas los convierta
 a minúsculas y los que están en minúsculas a mayúsculas.*/
 char *strinvertcase(char *palabra);

int main()
{
   strinvertcase("AnAnA");
}

char *strinvertcase(char *palabra){
     printf("%s \n",palabra);
     int contador=0;
     while(palabra[++contador]!=0);
      char a[contador];
     for(int i=0;i<contador;i++){
         if(isupper(palabra[i])!=0){
             a[i]= tolower(palabra[i]);
         }
         else{
             a[i]= toupper(palabra[i]);
         }
     }
     printf("%s",a);
      
}
  
/*Implemente una función que reciba una cadena de caracteres, posiblemente representando 
un número entero, y convierta su contenido al número que representa. Similar a strtol().*/

char *cadena(char *palabra);

int main()
{
   cadena("23456");
}

char *cadena(char *palabra){
     
      char *new;
      int numb;
      
      numb = strtol(palabra,&new,10);
      printf("%i",numb);
}
  
/*Implemente una función que reciba un número y lo cargue en un arreglo de caracteres recibido como argumento.
 Sugerencia: utilice la función sprintf() de la biblioteca estándar de entrada y salida.*/
char *cadena(int num);

int main()
{
   cadena(794);
}

char *cadena(int num){
     
      char cadena[20];
      sprintf(cadena,"un numero -> %i",num);
      puts(cadena);
}
 
/*Escriba una función que reciba un número entero positivo y un arreglo de caracteres y cargue en
 este último la representación en binario del primero. Implemente además la función inversa, que recibe 
una representación de un número en binario y carga un número con el valor que ésta representa.*/

char *cadenaBinario(char *palabra,int num);

int main()
{
   cadenaBinario("El numero binario es ", 794);
}

char *cadenaBinario(char *palabra,int num){
      char mensaje [80];
      sprintf(mensaje,"%s %i",palabra,num);
      
      puts(mensaje);
      
}
  
  
/*Escriba una función que recibe dos cadenas y un número e inserta una cadena dentro de
 la otra en la posición dada por el número.*/


char *cadenaBinario(char *palabra,char *corta,int num);

int main()
{
   cadenaBinario("El numero binario es ", "794",6);
}

char *cadenaBinario(char *palabra,char *corta,int num){
    
      char mensaje [80];
      char part2 [80];
      for(int i=0;i<=num;i++){
          mensaje[i]=palabra[i];
          }
      sprintf(mensaje,"%s%s",mensaje,corta);
      int contador=0;
      while(palabra[contador++]!=0);
      int j=0;
      for(int i=num;i<=contador;i++){
          part2[j++]=palabra[i];
          }
      sprintf(mensaje,"%s%s",mensaje,part2);  
      if ((num >0)&&(num <contador)){
        puts(mensaje);
      }
      else{
          puts("no se puede");
      }
      
}

/*                                               ARREGLOS DE CADENAS 

1_Defina un arreglo de cadenas que contenga 10 frutas. Defina un tipo enumerativo fruta_t que contenga las 10 frutas
 mencionadas en el arreglo, en el mismo orden.
 Luego implemente un programa o función que imprima un elemento del arreglo, dado por una variable del tipo fruta_t.*/

 enum fruta_t {manzana,banana,pera,uva,kiwi};
 int cadena (enum fruta_t color);

 int main(void){
    
    enum fruta_t verde= kiwi;
    cadena (verde);
 }

 int cadena (enum fruta_t color){
    char *arreglo[10]={"manzana","banana","pera","uva","kiwi"};
    printf("%s\n",arreglo[color]);
    
 }

/*Defina un tipo enumerativo status_t con los valores:

ST_OK,
ST_ERROR_RADIO_NEGATIVO,
ST_ERROR_ALTURA_NEGATIVA, y
ST_ERROR_PUNTERO_NULO.
Defina un arreglo de cadenas constante que contenga las cadenas:

"0k",
"El radio del cilindro no puede ser negativo",
"La altura del cilindro no puede ser negativa", y
"Se recibio un puntero nulo".
Implemente una función, imprimir_estado(), que reciba una variable de tipo 
status_t e imprima el estado correspondiente por el flujo estándar de errores.*/

 enum status_t {ST_OK,ST_ERROR_RADIO_NEGATIVO,ST_ERROR_ALTURA_NEGATIVA,ST_ERROR_PUNTERO_NULO};

 int imprimir_estado(enum status_t estado);
 int main(void){
    enum status_t estado = ST_OK;
    imprimir_estado(estado);
 }
  int imprimir_estado(enum status_t estado){
    switch(estado){
        case ST_OK: printf("0k\n"); break;
        case ST_ERROR_RADIO_NEGATIVO: printf("El radio del cilindro no puede ser negativo\n");break;
        case ST_ERROR_ALTURA_NEGATIVA: printf("La altura del cilindro no puede ser negativa\n");break;
        case ST_ERROR_PUNTERO_NULO :printf("Se recibio un puntero nulo\n");break;
    }
  }

/*Implemente una función que reciba un arreglo de palabras, un arreglo de definiciones y una palabra e imprima
 la definición de la palabra recibida.*/

 enum pal_def {casa,pera,taza};

int defi (char*palabras[],char *definiciones[],enum pal_def word);
 int main(void){
    char *palabras[]={"casa","pera","taza"};
    char *definiciones[]={"lugar para vivir","fruta","objeto para beber"};
    enum pal_def word ={pera};
    enum pal_def word2 ={casa};
    enum pal_def word3 ={taza};
    defi(palabras,definiciones,word);
    defi(palabras,definiciones,word3);
    defi(palabras,definiciones,word2);
 }
  int defi (char*palabras[],char *definiciones[],enum pal_def word){
  printf("la palabra %s es -> %s\n",palabras[word], definiciones[word]);
  }

  /*Implemente una función que reciba un arreglo de cadenas constantes,
 y una cadena, y retorne la posición de la cadena recibida dentro del arreglo.*/

 int defi (char oracion[],char palabra[]);
 int main(void){
    char oracion[]="hay muchas palabras en esta cadena";
    char palabra[] ="cadena";
    char palabra1[]="muchas";
    char palabra2[]="casa";
    defi(oracion,palabra);
    defi(oracion,palabra1);
    defi(oracion,palabra2);
 }
  int defi (char oracion[],char palabra[]){
    char *puntero;
    puntero = strstr(oracion,palabra);
    if (puntero!=NULL){
      int index= puntero - oracion;
      printf("La palabra '%s' está en el index -> %i\n",palabra,index);
    }
    else{
      printf("la palabra '%s' no está en '%s'\n",palabra,oracion);
    }
  }
  /*Implemente una función que reciba un arreglo de números y
 un número, y retorne la posición del número recibido dentro del arreglo.*/

 int defi (int numeritos[],int num,int longi);
 int main(void){
    int numeritos[6]= {2,6,1,7,8,10};
    int longi = (sizeof numeritos) / (sizeof numeritos[0]);
    int num =1;
    int num2= 5;
    defi(numeritos,num,longi);
    defi(numeritos,num2,longi);
 }
  int defi (int numeritos[6],int num,int longi){
    for(int i=0;i<longi;i++){
      if (numeritos[i]==num){
        printf("el num ->%i está en la posición -> %i\n",num,i);
        return 0;
      }
    }
      printf("el num no está en el arreglo\n");
  }
  /*Escriba un programa que reciba una cadena de caracteres e imprima su longitud, à la strlen().*/

 int defi (char cadena[],int longi);
 int main(int argc,char *argv[]){
    for (int i =1; i<argc;i++){
      int longi = strlen(argv[i]);
      defi(argv[i],longi);
    }
 }
  int defi (char cadena [],int longi){
      printf("len de la cadena -> %i\n",longi);
  }

/*Escriba un programa que reciba como argumentos dos números e imprima el 
resultado de la operación módulo entre ambos.*/

 int defi (int num1,int num2);
 int main(int argc,char *argv[]){
      int num1 =atoi(argv[1]);
      int num2 = atoi(argv[2]);
      defi(num1,num2);
 }
  int defi (int num1,int num2){
    float modulo = num2%num1;
    float modulo2 = num1%num2;
    printf("el modulo entre %i y %i es  -> %.1f\n",num2,num1,modulo);
    printf("el modulo entre %i y %i es  -> %.1f\n",num1,num2,modulo2);
  }

/*                            MEMORIA DINAMICA 

Implementar una función que reciba una cadena y retorne una copia de la misma, 
utilizando memoria dinámica, por el nombre. Si por algún motivo no se puede, retornar NULL.*/
#/*include <stdio.h>
#include <string.h>
#include <stdlib.h>*/

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
  newCadena =(char*) malloc(sizeof(char)*len);
  for (int x =0;x<len;x++){
    newCadena[x]=cadena[x];
  }
  puts(newCadena);
  return newCadena;
}


/*Implementar 2 funciones equivalentes a las 2 funciones del punto anterior,
 pero en lugar de copiar una cadena, copian un arreglo de números.*/
#include <stdio.h>
#include <stdlib.h>
int* copyNum (int*,int);

int main(void){
  int numArr [4]={2,3,4,5};
  int len;
  len =(sizeof numArr)/(sizeof numArr[0]);
  copyNum(numArr,len);
}
 int* copyNum(int* numArr,int len){
  int*  newArr;
  newArr= (int*)malloc(sizeof(int)*len);
  if (newArr ==NULL){
    return NULL;
  }
  for (int x=0;x<len;x++){
    newArr[x]= numArr[x];
    printf("%i",newArr[x]);
  }
  return newArr;
 }
/*Implementar una función que reciba una cadena de caracteres y un carácter. La función retorna una copia de la cadena,
 pero elimina todo lo que esté después del carácter recibido. Utilizar memoria dinámica.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* strip_comment(char*,char);

int main(void){
  strip_comment("esto va ; esto no va",';');
}

char* strip_comment(char* cadena,char corte){
  char* restoCadena;
  int len;
  len= strlen(cadena);
  int newLen=0;
  int i=0;
  while (cadena[i++]!=corte){
    newLen+=1;
  }
  restoCadena =(char*)malloc(sizeof(char)*newLen);
  if(restoCadena == NULL){
    return NULL;
  }
  for(int x=0;x<newLen;x++){
    restoCadena[x] =cadena[x];
  }
  puts(restoCadena);
}

/*Implementar una función que reciba una cadena de caracteres que comienza con espacios y retorna,
 por la interfaz, una copia de la cadena sin los espacios del comienzo. Realizar las validaciones necesarias.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* left_trim(char*);

int main(void){
   left_trim("     frase a la izquierda");
}

char* left_trim (char* cadena){
  char* restoCadena;
  int len;
  int nullCounter=0;
  int i=0;
  int j=0;
  len= strlen(cadena);
  while(cadena[i++]==' '){
    nullCounter++;
  }
  int newLen = len-nullCounter;
  restoCadena = (char*)malloc(sizeof(char)*newLen);
  if (restoCadena == NULL){
    return NULL;
  }
  for (i--;i<len;i++){
    restoCadena[j++]=cadena[i];
    printf("%c",cadena[i]);
  }
}
/*Implementar una que borre los espacios a izquierda y a derecha.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* left_trim(char*);

int main(void){
   left_trim("     frase en el centro     ");
}

char* left_trim (char* cadena){
  char* newCadena;
  int len = strlen(cadena);
  int leftBlank=0;
  int rightBlank=0;
  int newLen;
  int i=0;
  int j=0;
  while(cadena[i++]==' '){
    leftBlank++;
  }
  while(cadena[len--]==' '){
    rightBlank++;
  }
  newLen= len-leftBlank;
  newCadena = (char*)malloc(sizeof(char)*newLen);
  if(newCadena == NULL){
    return NULL;
  }
  for(i--;i<len;i++){
    newCadena[j++]=cadena[i];
  }
  puts(cadena);
  puts("\n");
  puts(newCadena);
}

/*Implementar una función que reciba una cadena de caracteres, un carácter y una longitud. 
La misma retorna una copia dinámica de la cadena original,
 centrada en la longitud especificada y rellenando con el carácter pedido.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* centrar (char*,char,int);

int main(void){
  char * a;
  a= centrar(" hola ",'*',12);
  free(a);
}

char* centrar(char* cadena, char icon, int longi){
  char* newcadena;
  char * rightcad;
  char* cadenita;
  int x=0;
  int len = strlen(cadena);
  newcadena = (char*)malloc(sizeof(char)*longi);
  if (newcadena==NULL){
    return NULL;
  }
  int sideslongi= (longi -len)/2;
  for(int j=0;j<longi;j++){
    if((j<sideslongi)|| (j>=(longi-sideslongi))){
        newcadena[j]=icon;
    }
    else{
        newcadena[j]=cadena[x++];
      }
    }
      puts(newcadena);
  }


  /*Implementar una función que reciba dos vectores de números
 y retorne un nuevo vector con los números de ambos vectores concatenados.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* newVect (int*,int*,int,int);

int main(void){
  int vect1[]={2,3,4,5};
  int len1 = (sizeof vect1 / sizeof vect1[0]);
  int vect2[]={8,10,3};
  int len2 = (sizeof vect2 / sizeof vect2[0]);
  newVect(vect1,vect2,len1,len2);
}

int* newVect(int* vect1, int*vect2,int len1,int len2){
  int final_len =len1+len2;
  int* newvect;
  int x=0;
  int i=0;
  newvect=(int*)malloc(sizeof(int)*final_len);
  for(int j=0;j<final_len;j++){
    if(j<len1){
      newvect[j]=vect1[x++];
    }
    else{
      newvect[j]=vect2[i++];
    }
  }
  for (int j=0;j<final_len;j++){
    printf("%i",newvect[j]);
  }
}

/*Implementar una función similar a la del ejercicio anterior, 
pero en lugar de retornar un nuevo vector, modifica el primero pegándole el segundo.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* newVect (int*,int*,int,int);

int main(void){
  int vect1[]={2,3,4,5};
  int len1 = (sizeof vect1 / sizeof vect1[0]);
  int vect2[]={8,10,3};
  int len2 = (sizeof vect2 / sizeof vect2[0]);
  newVect(vect1,vect2,len1,len2);
}

int* newVect(int* vect1, int*vect2,int len1,int len2){
  int final_len =len1+len2;
  int i=0;
  int h=0;
  int *copy;
  copy =(int*)malloc(sizeof(int)*len1);
  for (int x=0; x<len1;x++){
    copy[x]=vect1[x];
  }
  vect1=(int*)malloc(sizeof(int)*final_len);
  for(int j=0;j<=final_len;j++){
    if (j<len1){    
        vect1[j]=copy[i++];
        }
    else{
      vect1[j]=vect2[h++];
    }
    }
  for (int j=0;j<final_len;j++){
    printf("%i",vect1[j]);
  }
}

