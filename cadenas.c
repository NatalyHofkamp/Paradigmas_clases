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
  