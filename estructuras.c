#include <stdio.h>
typedef struct inventario{
    char* nombre;
    int edad;
    float altura;
}inven_t;

inven_t main(void){
    inven_t inven1;
    inven1.nombre="nombre";
    inven1.edad=14;
    inven1.altura =1.72;
    inven_t *puntero =&inven1;
    printf("%s %i %.1f",puntero->nombre,puntero->edad,puntero->altura);


}

/*Una estructura para manejar inventarios que contenga un campo para la descripción del
 producto (máximo 30 caracteres), un número para el número de parte en el inventario, 
 un punto flotante para el precio, un entero
 para la cantidad que hay en el almacén y un entero para el lugar donde se almacena.*/
typedef struct invent{
  char desc[30];
  int parte_num;
  float precio;
  int cant;
  int lugar;
}invent_t;

int main (void){
  invent_t inven1;
  strcpy(inven1.desc,"es una taza muy linda.");
  inven1.parte_num= 1234231;
  inven1.precio= 123.56;
  inven1.cant=3;
  inven1.lugar=8594;
  invent_t* puntero= &inven1;
  printf("desc: %s\nparte_num:%i \nprecio:%.1f\ncant:%i\nlugar:%i\n",puntero->desc,
        puntero->parte_num,puntero->precio,puntero->cant,puntero->lugar);


}

/*Una para manejar una dirección física que contiene arreglos para el país (máximo 40 caracteres), 
la provincia  (máximo 30 caracteres), la ciudad (máx. 20), la dirección (máx. 30) y el código postal
 (10).Una persona, con un arreglo para el nombre, otro para el apellido y una estructura como la del 
 inciso anterior.*/
 typedef struct direccion {
  char pais[40];
  char provincia [30];
  char ciudad[20];
  char direc [30];
  char cod_pos [10];
  }direc_t;

typedef struct persona{
  direc_t* direccion;
  char* nombre;
  char* apellido;
}personita_t;

int main (void){
  direc_t dire1;
  strcpy(dire1.pais,"argentina");
  strcpy(dire1.provincia,"cordooba");
  strcpy(dire1.ciudad,"villa maría");
  strcpy(dire1.direc,"azcuenaga 187");
  strcpy(dire1.cod_pos,"1948");
  personita_t per1;
  per1.direccion=&dire1;
  per1.nombre="marta";
  per1.apellido="minujin";
  personita_t * puntero= &per1;
  printf("%s",puntero->direccion->cod_pos);
}

/*Una estructura, registro, que nos sirva para mantener un registro de los consumos de un vehículo, 
como en el último ejercicio de la guía 1. Para ello, debe contener un número para almacenar una
 cantidad de kilómetros, un número real para almacenar el costo del combustible, un número real 
 para almacenar el dinero utilizado en una recarga, un time_t para almacenar la fecha,
 un booleano para indicar si se llenó el tanque y un arreglo para almacenar algún comentario.*/
 #include <string.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct {
  int dia;
  int mes;
  int anio;
}time_t;
typedef struct {
  float kilom;
  int costo;
  int dine;
  time_t* fecha;
  bool lleno;
  char* coment;
}registro_t;

int main(void){
  time_t fecha={12,3,2022};
  registro_t reg1;
  reg1.kilom=203920;
  reg1.costo=20934200;
  reg1.dine= 569530;
  reg1.fecha=&fecha;
  reg1.lleno = true;
  reg1.coment= "hay que cargar de nuevo el sabado.";
  registro_t*puntero =&reg1;
  printf("se cargó el %i/%i/%i ",puntero->fecha->dia,puntero->fecha->mes,puntero->fecha->anio);
}

/* 2) Definir una estructura punto que contenga las coordenadas de un punto en R2*/
typedef struct punto {
  int x;
  int y;
}punto_t;

int main(void){
  punto_t vec1 ={2,4};
  punto_t vec2 ={10,8};
  int puntx=vec2.x - vec1.x;
  int punty =vec2.y - vec1.y;
  float distancia  = sqrt(pow(puntx,2)+pow(punty,2));
  printf("%.1f",distancia);
}

/*Estamos armando nuestra propia plaforma social y decidimos que vamos a permitir que 
las personas se envíen mensajes que a lo sumo tengan 143 caracteres. Para ello, vamos 
a utilizar una estructura. La misma tiene que tener un número no signado que identifica 
al mensaje dentro de los millones y millones de mensajes que nos van a mandar, un time_t
 para la fecha, un arreglo para almacenar el mensaje y un arreglo para almacenar el nombre
  de usuario de quien lo publica.*/

/*Implementar una función que tome un mensaje y lo publique en la terminal, con el siguiente
 formato:
*/
typedef struct {
  int dia;
  int mes;
  int anio;
}timeTT;

typedef struct {
  char mensaje [143];
  int identificador;
  timeTT* fecha;
  char * usuario;
}mensaje_t;

int mensaje(char * mensaje,char* user){
  srand(time(NULL));
  mensaje_t mensaje1;
  timeTT fecha1={22,4,2018};
  strcpy(mensaje1.mensaje,mensaje);
  mensaje1.identificador=rand();
  mensaje1.fecha=&fecha1;
  mensaje1.usuario=user;
  mensaje_t * puntero =&mensaje1;
  printf("%i-%i-%i \n",puntero->fecha->dia, puntero->fecha->mes,puntero->fecha->anio);
  printf("<mensaje>");
  printf("%s",puntero->mensaje);
  printf("<%s>",puntero->usuario);



}
int main(void){
  mensaje("hola mirta,cómo estás?.","Carlos");
}


/*) Volvamos sobre nuestros pasos y rehagamos los menúes.

Definir una estructura que contenga un valor que el usuario 
tenga que ingresar (puede ser entero, enum, char, cadena) y 
una cadena con lo que se debe mostrar como mensaje para la opción.*/
typedef struct opciones{
    int option;
    char * mensaje;
}optiones_t;

int main(void){
  optiones_t matriz_opciones[5];
  char mensaje[20];
  char *new_msj;
  for (int i=0;i<5;i++){
    sprintf(mensaje,"mensaje n°%i",i);/*se cambia el valor del mensaje*/
    new_msj=(char*)malloc(sizeof(char)*strlen(mensaje));
    for(int x=0;x<=strlen(mensaje);x++){
      new_msj[x]=mensaje[x];
    }
    matriz_opciones[i].option=i;
    matriz_opciones[i].mensaje=new_msj;
  }
  int opt;
  printf("ingresa una opcion .");
  scanf("%i",&opt);
  for (int x=0;x<5;x++){
    if(matriz_opciones[x].option==opt){
      printf("%s",matriz_opciones[x].mensaje);
    }
  }
}


/*Implementar una función que reciba un vector con estructuras e imprima un menú.*/

/*Como variante del inciso anterior, la función puede imprimir el menú, leer lo que
 se ingresa y retornar la opción seleccionada.*/
 
typedef struct menu{
  int opt;
  char* mensaje;
}menu;

menu* func_vect(menu* vector ,const int len){
    for (int i=0; i<len;i++){
      printf("%i . %s\n",vector[i].opt,vector[i].mensaje);
    }
    return vector;
}

menu* val_vect (menu*vector, const int len){
   char msj[20];
   char *msj_copy;
   for(int x=0; x<len;x++){
    vector[x].opt=x;
    sprintf(msj,"mensaje n°%i",x);
    msj_copy=(char*)malloc(sizeof(char)*strlen(msj));
    for(int j=0; j<=strlen(msj);j++){
      msj_copy[j]=msj[j];
    }
    vector[x].mensaje=msj_copy;
  }
  return vector;
}

menu* us_select(menu* vector,const int len){
  printf("Elegi una opción:");
  int choice;
  scanf("%i",&choice);
  for (int j=0; j<len;j++){
    if (vector[j].opt==choice){
      printf("%s",vector[j].mensaje);
    }
  }
}

int main(void){
  const int len = 3;
  struct menu vector[len];
  
  val_vect(vector, len);
  func_vect(vector,len);
  us_select(vector,len);
}


/*Para acceder a cada uno de los campos de las estructuras, escribir una expresión.*/

struct header {
    int secuencia;
    time_t stamp;
    char * frame;
};

struct pose {
    struct {
        double x, y, z;
    } posicion;
    struct {
        double qx, qy, qz, qw;
    } orientacion;
};

struct pose_stamped {
    struct header encabezado;
    struct pose pose;
}robot_pose;

struct pose_stamped cargar(struct pose_stamped* robot_pose){
  robot_pose->encabezado.secuencia=4;
  robot_pose->encabezado.stamp=time(NULL);
  robot_pose->encabezado.frame="frame";
  robot_pose->pose.posicion.x=15.983;
  robot_pose->pose.posicion.y=39.2983;
  robot_pose->pose.posicion.z=390.382938;
  robot_pose->pose.orientacion.qx=1.23;
  robot_pose->pose.orientacion.qy=2.34;
  robot_pose->pose.orientacion.qz=3.21;
  robot_pose->pose.orientacion.qw=4.81;
}
int main(void){
  struct pose_stamped  robot;
  struct pose_stamped* robot_ptr=&robot;
  cargar(robot_ptr);
  printf("%s",robot_ptr->encabezado.frame);

}

/*Escribir una porción de código para cargar la estructura robot_pose
 usando las demás estructuras. Luego, para acceder a cada uno de los
  campos de las estructuras, escribir una expresión*/


struct header {
    int secuencia;
    time_t stamp;
    char * frame;
} header;

struct punto {
    double x, y, z;
} point;

struct cuaternion {
    double qx, qy, qz, qw;
} quaternion;

struct pose {
    struct punto * posicion;
    struct cuaternion * orientacion;
} pose;

struct pose_stamped {
    struct header * encabezado;
    struct pose * pose;
} robot_pose, * robot_pose_ptr;

struct pose_stamped* cargar (struct pose_stamped* robot){
  robot-> encabezado->secuencia=4;
  robot-> encabezado->stamp=time(NULL);
  robot-> encabezado->frame="frame";
  robot->pose->posicion->x=3.56;
  robot-> pose-> posicion->y=4.29;
  robot->pose->posicion->z=438.191;
  robot-> pose->orientacion->qx=82.9292;
  robot->pose->orientacion->qy=83.9494;
  robot->pose->orientacion->qz= 8228.7373;
  robot->pose->orientacion->qw=22771.2929;
  return robot;
}
int main(void){
  robot_pose_ptr=&robot_pose;
  cargar (robot_pose_ptr);
  printf("%s y posicion en x:%f",robot_pose.encabezado->frame, robot_pose.pose->posicion->x);
}
