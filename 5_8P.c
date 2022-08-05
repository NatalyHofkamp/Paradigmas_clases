#include <stdio.h>
/*iterar sobre una matriz 
  definir dos constantes para ancho  alto de la matriz.
  recorrer con dos for anidados y asignar valores a las celdas de la matriz */

const int x=2;
const int y =3;

void recorrer (void);
void matShow (int,int,int [][]);
int main (void){
    recorrer ();
    return 0;
}
/* un arreglo es un puntero de enteros*/
void recorrer (void){
    int mat [x][y];
    int i;
    int j;
    int h = 0;
    for (i=0;i<x;i++){/*sentencia/condicion, se realiza despues de cada vuelta*/
        for(j=0;j<y;i++){
            mat[i][j] == h++;
        }
    }
    
    matShow(mat,x,y);

}

void matShow (int m[x][y],int row,int col){
    
    for (i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("%d" ,mat[i][j]);
            printf("\n");
        }
    }

}

void matSHow ()