#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int arreglitoCeros (int *a, int);
int arreglitoUnos(int *a, int longi);
int sumaArreglito(int *a,int longi);
int mediaArreglito(int *a, int longi,int sum);
int varianza(int sum, int media, int *a, int longi);
int maxNum (int *a,int longi);
bool veccpy(int *dest, const int ldest, int *orig, const int lorig);
bool iguales (int *dest, const int  ldest, int *orig, const int lorig);
const int * busqueda_lineal(int *v, const int leng, int objetivo);
int main()
{
    int longi =3;
    int a[longi];
    arreglitoCeros(a,longi);
    printf("otro punto \n");
    #define len 4 
    int m1[len]={1,2,3,4};
    int m2[len]={3,4,5,6};
    veccpy(m1,len,m2,len);
    iguales(m1,len,m2,len);
    iguales(m1,len,m1,len);
    puts("\n");
    int v[len]={2,4,5,6};
    int objetivo =2;
    busqueda_lineal(v, len, objetivo);
}
const int * busqueda_lineal(int *v, const int leng, int objetivo){

  for(int i =0; i<leng;i++){
    if (*(v+i)== objetivo){
      printf("el valor %i se encuentra en la posición : %d",objetivo, i);
      return (v+i);
    }
  }
  return v;

}
bool iguales (int *dest, const int  ldest, int *orig, const int lorig){
  if (ldest==lorig){
    for(int i=0;i<ldest;i++){
      if ((dest+i) == (orig+i)){
        continue;
      }
      else{
        printf("False");
        puts("\n");
        return false;
      }
    }
    printf("True");
    puts("\n");
      return true;
  }
}
bool veccpy(int *dest, const int  ldest, int *orig, const int lorig){
 printf("m1 =");
   for (int i=0;i<ldest;i++){
    printf("%i",*(dest+i));
  }
  puts("\n");
   printf("m2 =");
   for (int i=0;i<lorig;i++){
    printf("%i",*(orig+i));
  }
  puts("\n");
if (ldest==lorig){
  for (int i=0;i<ldest;i++){
    *(orig +i)=*(dest+i);
  }
  printf("m1 =");
   for (int i=0;i<ldest;i++){
    printf("%i",*(dest+i));
  }
  puts("\n");
   printf("m2 =");
   for (int i =0;i<ldest;i++){
    printf("%i",*(orig+i));
  }
  puts("\n");
}


}
int maxNum (int *a,int longi){
  int max ,min = a[0];
  for(int i=0;i<longi;i++){
    if (*(a+i)>max){
      max=*(a+i);
    }
    if (*(a+i)<=min ){
      min=*(a+i);
    }
  }
  printf("max : %i, min =%i \n",max,min);
} 
int main (void){
  int a[5]= {5,1,6,4,8};
  int longi =sizeof(a) /sizeof(a[0]);
  maxNum(a,longi);

}
int varianza(int sum, int media, int *a, int longi){
  int nose=0;
  for (int i=0;i<longi;i++){
    nose+=pow((*(a+i)-media),2);
  }
  int vari= (nose/(longi-1));
  printf("varianza: %i\n",vari);
  maxNum(a,longi);

}
int mediaArreglito(int *a, int longi,int sum){
  int media = sum/longi;
  printf("media : %i\n",media);
  varianza(sum,media,a,longi);
}

int sumaArreglito(int *a,int longi){
  int sum=0;
  for (int i=0;i<longi;i++){
    sum+=*(a+i);
  }
  printf("suma :%i\n",sum);
  mediaArreglito(a,longi,sum);
}


int arreglitoUnos(int *a, int longi){
  for (int j=0;j<longi;j++){
    *(a+j)+=1;
    printf( "%d ", *(a+j) );
        }
        printf( "\n" );
  sumaArreglito(a,longi);
  }

int arreglitoCeros(int *a, int longi){
  printf("%p\n",a);
  for ( size_t i = 0; i < longi; i++ ) {
            *(a+i)= i;
            printf( "%d ", *(a+i) );
        }
        printf( "\n" );

  arreglitoUnos(a,longi);
    
}
