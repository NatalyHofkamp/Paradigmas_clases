#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum{
    EXIT_OK,
}status_t;

// caracteristicas del videojuego
typedef struct {
    int cod;
    char titulo[50];
    int plataforma;
    char compania [50];
    int prestado;
    struct videojuego * next;
} videojuego;

//el juego
typedef struct{
    videojuego* primero;
}lista;

//nuestra lista de juegos
lista* mi_lista=NULL;
void consumirLinea(void){
    int c;
    do{
        c=getchar();
    }while(c!= EOF && c!= '\n');
}
void cargar (){
    int cod;
    char titulo[50];
    int plataforma;
    char compania [50];
    int prestado;
    printf("pasame los datos:");
    printf("codigo:");
    scanf("%d",&cod);
    consumirLinea();
    printf("titulo:");
    fgets(titulo,50,stdin);
    printf("plataforma:options: 1)play, 2)xbox \n");
    scanf("%d",&plataforma);
    consumirLinea();
    printf("compañía:");
    fgets(compania,50,stdin);
    printf("prestado?");
    scanf("%d",&prestado);
    videojuego* nuevo= (videojuego*) malloc( sizeof(videojuego));
    nuevo->cod=cod;
    strcpy(nuevo->titulo,titulo);
    nuevo->plataforma=plataforma;
    strcpy(nuevo->compania,compania);
    nuevo->prestado=prestado;
    nuevo->next=NULL;
    if (mi_lista->primero ==NULL){
        mi_lista->primero=nuevo;
    }
    else{
        //para recorrer hasta llegar al último
        videojuego * aux;
        aux=mi_lista->primero;
        while(aux->next !=NULL){
            aux=aux->next;
        }
        aux->next=nuevo;
    }

}


void print_menu (void){
    printf("----gestion de videojuegos -----\n");
    printf("1. añadir juegos \n");
    puts("2. listar videojuegos");
    puts("3. eliminar videojuego");
    puts("4.prestar videojuego");
    puts("5.listar videojuegos por plataforma");
    puts("6.salir");
    puts("ingresa una opcion: \n");
}
void menu(void){
    /*mostrar un menu, para que la persona elija*/
    int opt;
    do{
    print_menu();
    scanf("%i",&opt);
    switch(opt){
        case 1: cargar();
        puts("juego cargado ! ");
        break;
        case 2:
        break;
        case 3:
        break;
        case 4: break;
        case 5:break;
        case 6: puts("bye bitches");return EXIT_OK;
        default: puts("ingresaste una opción inválida.");
        break;
    }
        }while(opt!=6);
}


int main (void){
    menu();
}

