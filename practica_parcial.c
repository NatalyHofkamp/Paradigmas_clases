#include <stdio.h>
#include <string.h>

/*Ejercicio 1
1. Implementar dos versiones de una función que dado un arreglo de punteros a double (una matriz), y sus dimen-
siones, inicialice la matriz con la identidad.
1. Una versión debe cumplir con el prototipo:
void identidad(double **, size_t filas, size_t columnas);
*/


typedef enum {
  ST_OK, 
  ERR_NULL,
  ERR_INV_VAL,
}status_t;

void identidad (double** mat, size_t filas, size_t columnas){
    if((mat==NULL)|| (filas<=0)||(filas!=columnas)){
        return exit(-1);
    }
    else{
      for(size_t x=0 ; x<filas ; x++){
        for(size_t y=0 ; y<columnas ; y++ ){
          if(x==y){
            mat[x][y]=1;
          }
          else{
            mat[x][y]=0;
          }
        }
      }
    }
    return;
}

double ** crear (size_t fil, size_t col){
  double **m;
  m= (double**)malloc(sizeof(double*)*fil);
  if (NULL==m){
    return NULL;
  }
  for(int i=0; i<fil;i++){
    m[i]=(double*)malloc(sizeof(double)*col);
    if(NULL ==m[i]){
        free(m[i]);
        return NULL;
    }
  }
  return m;
}


int main(int argc, char*argv[]){
  size_t filas;
  size_t  columnas;

  filas= atoi(argv[1]);
  columnas =atoi(argv[2]);
  double ** mat;
  mat=crear(filas,columnas);
  if (NULL==mat){
    return -1;
  }

  identidad(mat,filas,columnas);
  for(size_t x=0 ; x<filas ; x++){
      for(size_t y=0 ; y<columnas ; y++ ){
        printf("%.1f ",mat[x][y]);
      }
      puts("\n");
    }
}

/*2. Otra versión debe cumplir con el prototipo:
status_t identidad(double **, size_t filas, size_ columnas);
*/
typedef enum {
  ST_OK, 
  ERR_NULL,
  ERR_INV_VAL,
}status_t;

status_t identidad(double **mat, size_t filas, size_t columnas){
    if(mat==NULL){
      return ERR_NULL;
    }
    if ((filas!=columnas)||(filas<=0)){
      return ERR_INV_VAL;
    }

    for(int x=0;x<filas;x++){
      for(int y=0;y<columnas;y++){
        if(x==y){
          mat[x][y]=1;
        }
        else{
          mat[x][y]=0;
        }
      }
    }
    return ST_OK;
}


double** crear(size_t filas, size_t columnas){
  double** m;
  m=(double**) malloc(sizeof(double*)*filas);
  if(NULL==m){
    return NULL;
  }
  for(int i=0;i<filas;i++){
    m[i]=(double*)malloc(sizeof(double)*columnas);
    if (NULL== m[i]){
      free(m[i]);
      return NULL;
    }
  }
  return m;

}


int main(int argc, char*argv[]){
  size_t filas;
  size_t  columnas;
  filas= atoi(argv[1]);
  columnas =atoi(argv[2]);
  double ** mat;
  mat=crear(filas,columnas);
  if (NULL==mat){
    return NULL;
  }
  identidad(mat,filas,columnas);
    for(size_t x=0 ; x<filas ; x++){
        for(size_t y=0 ; y<columnas ; y++ ){
          printf("%.1f ",mat[x][y]);
        }
        puts("\n");
      }
}


/*2. Implementar una función que reciba Una matriz de doubles y retome el indice de la fila cuyos elementos suman
el valor más grande.*/

int mas_grande(double** mat, size_t filas, size_t columnas){
  if((mat==NULL)||(columnas<=0)||(filas<=0)){
    return 1;
  }
  else{
    int index;
    double max=0;
    double suma;
    for(int i=0;i<columnas;i++){
        max+= mat[0][i];
        index=0;
    }
    for(int i=0;i<filas;i++){
      suma=0;
      for(int j=0;j<columnas;j++){
        suma+=mat[i][j];
      }
      if(suma>max){
        index=i;
        max=suma;
      }
    }
    return index;
   }
  }

double** cargar(size_t filas, size_t columnas){
  if((filas>0)&&(columnas>0)){
    double** mat;
    mat= (double**) malloc (sizeof(double*)*filas);
    if(mat==NULL){
      return NULL;
    }
    for(int i=0; i<filas;i++){
      mat[i]= (double*)malloc(sizeof(double)*columnas);
      if(mat[i]==NULL){
        free(mat[i]);
        return NULL;
      }
    }
    return mat;
  }
}


int main(int argc, char*argv[]){
    size_t filas;
    size_t columnas;
    int k=3;
    filas=atoi(argv[1]);
    columnas=atoi(argv[2]);
    double **mat;
    mat=cargar(filas,columnas);
    for(int i=0;i<filas;i++){
      for(int j=0;j<columnas;j++){
           mat[i][j]=atoi(argv[k++]);
           printf("%.1f  ",mat[i][j]);
      }
      puts("\n");
    }
    
   printf("%i", mas_grande(mat,filas,columnas));
}

/*3. Implementar una función que reciba una matriz de floats y retome status_t el nombre y la traza de lamatriz
por la interfaz.

Justifique las validaciones llevadas á cabo y aquellas no realizadas.*/

typedef enum{
  ST_OK,
  ERR_INV_VAL,
  ERR_NULL,
} status_t;

status_t mat_traza  (float** mat,  size_t filas, size_t columnas, float* traza){
    if((mat==NULL)||(traza==NULL)){
      return ERR_NULL;
    }
    if((filas!=columnas)||(filas<=0)){
      return ERR_INV_VAL;
    }
    *traza=mat[0][0];
    for(int i=1;i<filas;i++){
     *traza+=mat[i][i];
    }
    return ST_OK;
}

float** cargar (size_t filas, size_t columnas){
  float** mat;
  mat=(float**)malloc(sizeof(float)*filas);
  if(mat==NULL){
    return NULL;
  }
  for(int i=0; i<filas;i++){
    mat[i]=(float*)malloc(sizeof(float)*columnas);
    if(mat[i]==NULL){
      free(mat[i]);
      return NULL;
    }
  }
  return mat;
}

int main(int argc, char*argv[]){
  size_t filas;
  size_t columnas;
  float traza;
  int k=3;
  float ** mat;
  filas= atoi(argv[1]);
  columnas=atoi(argv[2]);
  mat= cargar (filas,columnas);
  for(int x=0;x<filas;x++){
    for(int y=0;y<columnas;y++){
      mat[x][y]=atoi(argv[k++]);
    }
  }
  mat_traza(mat,filas,columnas,&traza);
  printf("%.1f",traza);
}

/*
4. Escriba un programa que reciba como argumentos una serie de cadenas e imprima aquella que se ordenaría
rimera en un diccionario. No es necesario ordenar ningún vector. Lo siguiente es un ejemplo de ejecución del
programa solicitado
9 ./eja "cadenal” "aazz" "ozA" taza" "azza azzza" "ana 222! "Última cadena"
anzz*/

int main(int argc,char*argv[]){
if (argc<=1){
    puts("no ingresaste ninguna oración \n");
    return 1;
  }
  char* max=argv[1];
  int index=1;
  for(int i=2;i<argc;i++){
    int a= strcmp(max,argv[i]);
    if(a>0){
      max=argv[i];
      index=i;
    }
  }
  printf("%s",argv[index]);
  return 0;
}

/*
5. Implementar una función que cree dinámicamente un vector iniciallzado con ceros Dar ejemplos de invocación
de dicha función.*/

int*cargar (int len){
  if((len<=0)){
    return NULL;
  }
  int *vec;
  vec=(int*)malloc(sizeof(int)*len);
  if(vec==NULL){
    return NULL;
  }
  for(int x=0; x<len;x++){
      vec[x]=0;
    }
  return vec;
}

int main(void){
    int len;
    len=5;
    int* vector;
    vector= cargar (len);
    for(int x=0; x<len;x++){
      printf("%i",vector[x]);
    }
}
/*
1) Implementar dos versiones de una función que dado un número entero, positivo, devuelva el resultado, r, de la
siguiente ecuación:

1. Una versión debe cumplir con el prototipo: long gauss_sum(int n); */



long gauss_sum(int n){
  if(n<0){
    return 0;
  }
  long r=0;
  for(int i=1; i<n;i++){
      r+=i;
  }
  return r;
}

int main(int argc, char*argv[]){
  int n= atoi(argv[1]);
  long r;
  r=gauss_sum(n);
  printf("%ld",r);
  return 0;
}
/*
2. Otra versión debe cumplir con el prototipo: 'status_t gauss_sum(long *r, int n); .
- ¿Cuáles son las ventajas y desventajas de usar la versión 2. en lugar de la 1.2
*/
typedef enum{
  ST_OK,
  ERR_INV_VAL,
  ERR_NULL,
}status_t;

status_t gauss_sum (long*r, int n){
  if(n<0){
    return ERR_INV_VAL; 
  }
  if (r==NULL){
    return ERR_NULL;
  }
  for(int i=1;i<n;i++){
    *r+=i;
  }
}

int main(int argc, char*argv[]){
  long r=0;
  int n=atoi(argv[1]);
  gauss_sum(&r,n);
  printf("%ld",r);
}