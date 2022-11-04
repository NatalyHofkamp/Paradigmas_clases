#include <iostream>
#include <cstdlib>
#include <vector>

class A
{
    int id_;
    std::string msj_;
  public:
    A(int id, std::string msj):id_{id},msj_{msj}{};
    ~A(){};
    int GetId()const{return id_;}
    std::string GetMsj()const{return msj_;}
};

class ListaDeObjetos
{
    std::vector<A*> lista; 
  public:
    ListaDeObjetos(){};
    ~ListaDeObjetos(){};
    void Almacenar(A*);
    int Retirar(int index);
    void Info();
    int check(int id);
};

void ListaDeObjetos:: Info(void)
{
    for (int i=0;i<lista.size();i++){
        std::cout<<"-------------------------"<<std::endl;
        std::cout<<"    id: "<< lista[i]->GetId()<<std::endl;
        std::cout<<"    msj:"<< lista[i]->GetMsj()<<std::endl;
    }
}

int ListaDeObjetos::check (int id)
{
    for (int i=0;i<lista.size();i++){
        if(lista[i]->GetId()==id){
            return i;
        }
    }
    return -1;
}
void ListaDeObjetos:: Almacenar(A* obj)
{
    if(lista.size()<=3){
        if(check(obj->GetId())==-1){
            lista.emplace_back(obj);
            std::cout<<"se almacenó ->"<<obj->GetId()<<std::endl;
        }
        else{
            std::cout<<"ya está ese id"<<std::endl;
        }
    }
    else{
        std::cout<<"no hay espacio\n";
    }
}

int ListaDeObjetos::Retirar(int id)
{
    lista.erase(lista.begin()+check(id));
}

void Menu(void)
{
    int opt;
    int id;
    std::string msj;
    ListaDeObjetos* lista=new ListaDeObjetos();
    do{
        std::cout<<"elija una opción"<<std::endl;
        std::cout<<"1)Almacenar\n2)Eliminar\n3)Informe\n4)Salir\n";
        std::cin>>opt;
        if(opt==1)
        {
            std::cout<<"-> ingrese id:"<<std::endl;
            std::cin>>id;
            std::cout<<"-> ingrese msj:"<<std::endl;
            std::cin>>msj;
            A* objeto =new A(id,msj);
            lista->Almacenar(objeto);
        }
        else if (opt==2)
        {
            std::cout<<"ingrese el id que quiere eliminar:\n";
            std::cin>>id;
            lista->Retirar(id);
        }
        else if(opt==3)
        {
            lista->Info();
        }
    }while(opt!=4);
}


int main (void)
{
    Menu();
}

/**********************************************************************************************/


class Vehicle
{
  public:
    std::string brand;
    void bocina();
};

class Transporte
{
    protected:
        int asientos;

};

void Vehicle::bocina(void){
    std::cout<<"pip pip"<<std::endl;
}

class Car:public Vehicle
{
  public:
    std::string mod_;

};

class Mcqueen:public Car,public Transporte{
  public:
    std::string color="rojo";
    void setAss(int num){
        asientos=num;
    }
    int getAss(){
        return asientos;
    }
};


int main(void){
    Mcqueen car1;
    car1.brand="fiat";
    car1.mod_="palio";
    car1.bocina();
    car1.setAss(4);
    std::cout<<car1.color<<std::endl<<car1.getAss()<<std::endl;
}

/****************************************************************************************/

/*Escribir una función que dado un vector de enteros, devuelva un nuevo vector
 duplicando cada elemento. El programa debe imprimir lo que se ve en el ejemplo.*/
#include <iostream>
#include<vector>

using namespace std;

vector<int> duplicate(vector<int> vector1)
{
    vector<int> vector2;
    for(size_t i=0;i<vector1.size();i++){
        vector2.emplace_back(vector1[i]);
        vector2.emplace_back(vector1[i]);
    }
    return vector2;
}

int main (void)
{
    vector<int> vector1{1,2,4,5,7};
    vector<int> vector2 = duplicate(vector1);
    for(size_t i=0; i<vector2.size();i++){
        cout<<vector2[i];
    }

    return 0;
}

/*****************************************************************************/
/*Escribir una función que dado un vector de enteros, devuelva el vector sin
 los números primos (suponer números mayores a cero; 1 no es primo). La función 
 debe modificar el vector, no crear uno nuevo. */
#include <iostream>
#include <vector>

using namespace std; 

vector<int> sinprimos(vector<int> vector1)
{
    for (size_t i=0;i<vector1.size();i++){
        int x=2;
        while((vector1[i])%x !=0){
            x++;
        }
        cout<<i<<"  x -> "<< x<<endl;
        if(vector1[i]==x){
                vector1.erase(i+vector1.begin());
            }

    }
    return vector1;
}


int main(void)
{
    vector<int> vector1{2,15,83,1,25,13,303,8,7,9};
    vector1=sinprimos(vector1);

    for(size_t i=0;i<vector1.size();i++){
        cout<<vector1[i]<<endl;
    }
    return 0;

}

/*******************************************************************************************/
/*Escribir una función que dado un vector ordenado y uno desordenado 
devuelva un vector ordenado con los elementos de ambos.*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> ordenar(vector<int> ord, vector<int> desord)
{
        vector<int> result(ord);
        for(size_t i =0; i<desord.size();i++){
            result.emplace_back(desord[i]);
        }
        for(size_t i=0; i<result.size()-1;i++){
            for(size_t x=i+1;x<result.size();x++){
                int aux= result[i];
                if(result[i]>result[x]){
                    result[i]=result[x];
                    result[x]=aux;
                }
                if(result[i]==result[x]){
                    result.erase(result.begin()+x);
                }
                
            }
        }
        return result;
}

int main (void)
{
    vector<int> ordenado{1,2,3,4,5,6,7,8};
    vector<int> desordenado {93,7,67,1,2,61};
    vector <int> result;

    result=ordenar(ordenado,desordenado);
    for(size_t i =0; i<result.size();i++)
    {
        cout<< result[i]<<" - ";
    }
}
/*****************************************************************************************/
/*Escribir una función que dado un vector de enteros y un número 
entero devuelva true solamente si en el vector hay al menos 3 de 
sus primeros 5 múltiplos (un número es múltiplo de si mismo).*/

#include <iostream>
#include <vector>

using namespace std;

bool multiplos(vector<int> vec, int n)
{
    int counter=0;
    for (size_t i=0; i<vec.size();i++){
        if(vec[1]%n==0){
            counter++;
        }
    }
    if (counter >=3){
        return true;
    }
    else{
        return false;
    }
}

int main(void)
{
    vector<int> vec1{2,3,4,5,6,7,8,9};
    vector<int> vec2 {3,6,7,5};
    cout<< multiplos(vec1,2)<<endl;
    cout<<multiplos(vec2,2)<<endl;
    cout<<multiplos(vec1,3)<<endl; 
}

/***********************************************************************************/
/*Escribir una función que dado el código de una materia retorne 
una tupla con el nombre de la materia y el nombre del docente a cargo.
Por ejemplo, para el código “I102” la función devuelve 
la tupla (“Paradigmas de Programación”, “Patricio Moreno”).
*/
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

tuple<string,string> codigo (string cod)
{
    tuple<string,tuple<string,string>> materias = make_tuple("I102",make_tuple("paradigmas","patito"));
    if(cod.compare(get<0>(materias))==0){
        return get<1>(materias);
    }

}
int main(void)
{
    tuple<string,string> a= codigo("I102");
    cout<<"("<<get<0>(a)<<","<<get<1>(a)<<")"<<endl;
    return 0;
}


/********************************************************************************************/

/*Escribir una función reciba un vector de triplas donde cada tripla
(tupla con 3 elementos) tiene la forma (string, string, int) representando 
que una persona le debe a otra un monto de dinero (ej: <”Juan”, “Ilaria”, 200>
indica que Juan le debe a Ilaria 200 pesos). La función debe devolver un vector
con los nombres de las personas que deben mas de lo que les deben.*/

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

auto deben (vector<tuple<string,string,int>> vec)
{
    vector<string> nombres;
    for(auto tuple:vec){
        bool check=false;
        int debe=0;
        int ledeben=0;
        for(auto tuple2:vec){
            if( get<0>(tuple)==get<0>(tuple2)){
                debe+=get<2>(tuple2);
            }
            else if( get<0>(tuple)==get<1>(tuple2)){
                ledeben+=get<2>(tuple2);
            }
        }
        if(debe>ledeben){
            for(auto nombrecito :nombres){
                if (nombrecito==get<0>(tuple)){
                    check=true;
                }
            }
            if(!check){
                    nombres.emplace_back(get<0>(tuple));
                }
            }
        }
    

    for(auto nom:nombres){
        cout<<nom<<endl;
    }    
    return nombres;

        
    }


int main(void)
{
    vector<tuple<string,string,int>> vec;
    vec.emplace_back(make_tuple("juan","maria",200));
    vec.emplace_back(make_tuple("cristian","juan",150));
    vec.emplace_back(make_tuple("cristian","marta",150));
    vec.emplace_back(make_tuple("marta","juan",200));
    vec.emplace_back(make_tuple("marta","maria",350));
    vec.emplace_back(make_tuple("maria","marta",350));
    deben(vec);
    
}

/**************************************************************************************/
/*Escribir una función que dado un vector de nombres (strings)
devuelva un mapa con los nombres como claves y como valores,
para cada clave, la cantidad de veces que aparece en el vector.*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string,int> cantidad( vector<string> nombres){
    map<string,int> canti;
    for(auto nom: nombres){
    if (canti.find(nom) == canti.end()) {
        for(auto nom2:nombres){
            if(nom==nom2){
                if (canti.find(nom) != canti.end()) {
                     canti[nom]++;
                 }
                 else{
                    canti.insert(make_pair(nom,1));
                 }
            }
       }
    }
    }
    for (auto& punt: canti) {
    std::cout << punt.first<< " has value " << punt.second << std::endl;
}
    return canti;
}


int main(void){
    vector<string> nombres;
    nombres.emplace_back("carlos");
    nombres.emplace_back("carlos");
    nombres.emplace_back("maria");
    nombres.emplace_back("maria");
    nombres.emplace_back("maria");
    nombres.emplace_back("maria");
    nombres.emplace_back("carlos");
    nombres.emplace_back("carlos");
    nombres.emplace_back("julia");
    nombres.emplace_back("julia");
    nombres.emplace_back("julia");

    cantidad(nombres);
}

/*******************************************************************************************/
/*Dada una clase Empleado, con atributos como nombre, apellido y sueldo,
 escribir una función que permita leer de std::cin el nombre, el apellido
 65 y el sueldo de un empleado, la empresa en la que trabaja, y los cargue en un mapa.*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Empleado{
  private:
    string nombre;
    string apellido;
    int sueldo;
  public:
    Empleado(string nombre,string apellido, int sueldo){
        this->nombre=nombre;
        this->apellido=apellido;
        this->sueldo=sueldo;
    }
    string get_nom (){return nombre;}
    string get_apell(){return apellido;}
    int get_sueldo(){return sueldo;}
    ~Empleado(){}
};


int main(void){
    map<string,vector<Empleado*>> empresas;
    string empresa;
    string nombre;
    string apellido;
    int sueldo;
    int opt;
    do{
        vector<Empleado*> empleados;
        cout<<"elija una opción:"<<endl<<"1)cargar"<<endl<<"2)terminar"<<endl;
        cin>>opt;
        if(opt==2){
            break;
        }
        cout<<"Empresa:"<<endl;
        cin.ignore();
        getline(cin,empresa);
        cout<<"EMPLEADO DATA:"<<endl;
        cout<<"Nombre:"<<endl;
        cin.ignore();
        getline(cin,nombre);
        cout<<"apellido"<<endl;
        cin.ignore();
        getline(cin,apellido);
        cout<<"sueldo"<<endl;
        cin.ignore();
        cin>>sueldo;
        Empleado* empleado= new Empleado(nombre,apellido,sueldo);
        if (empresas.find(empresa) != empresas.end()) {
                     empresas[empresa].emplace_back(empleado);
                 }
        else{
                empleados.emplace_back(empleado);
                empresas.insert(make_pair(empresa,empleados));
            }
    }while(opt!=2);
    
    for(auto punt: empresas){
        cout<<punt.first<<":"<<endl;
        for(auto empleado :punt.second){
            cout<<"->"<<empleado->get_nom()<<endl<<empleado->get_apell()<<endl<<empleado->get_sueldo()<<endl;
        }
    }

}

/****************************************************************************************************************************/
/*Para el mapa del ejercicio anterior, escribir una función que devuelva, 
para cada empresa, un mapa que contenga como clave el nombre de cada empresa
y como valor una tupla de 2 Empleados, el de mayor sueldo y el de menor sueldo.*/


#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Empleado{
  private:
    string nombre;
    string apellido;
    int sueldo;
  public:
    Empleado(string nombre,string apellido, int sueldo){
        this->nombre=nombre;
        this->apellido=apellido;
        this->sueldo=sueldo;
    }
    string get_nom (){return nombre;}
    string get_apell(){return apellido;}
    int get_sueldo(){return sueldo;}
    ~Empleado(){}
};

map<string,tuple<Empleado*,Empleado*>> mayormenor(map<string,vector<Empleado*>> empresas){
    map<string,tuple<Empleado*,Empleado*>> empleado;
    for( auto puntero:empresas){
        int a;
        int mayor=puntero.second[0]->get_sueldo();
        int may_index, min_index;
        int menor=puntero.second[0]->get_sueldo();;
        for(size_t i=0; i<puntero.second.size();i++){
            a = puntero.second[i]->get_sueldo();
            if(a>mayor){
                mayor=a;
                may_index=i;
            }
            else{
               menor=a; 
               min_index=i;
            }
        }
        empleado.insert(make_pair(puntero.first,make_tuple(puntero.second[may_index],puntero.second[min_index])));
    }

      for(auto pt: empleado){
        cout<<pt.first<<":"<<endl;
        cout<<get<0>(pt.second)->get_nom()<<endl;
        cout<<get<1>(pt.second)->get_nom()<<endl;
    }

    return empleado;
}

int main(void){
    map<string,vector<Empleado*>> empresas;
    string empresa;
    string nombre;
    string apellido;
    int sueldo;
    int opt;
    do{
        vector<Empleado*> empleados;
        cout<<"elija una opción:"<<endl<<"1)cargar"<<endl<<"2)terminar"<<endl;
        cin>>opt;
        if(opt==2){
            break;
        }
        cout<<"Empresa:"<<endl;
        cin.ignore();
        getline(cin,empresa);
        cout<<"EMPLEADO DATA:"<<endl;
        cout<<"Nombre:"<<endl;
        getline(cin,nombre);
        cout<<"apellido"<<endl;
        getline(cin,apellido);
        cout<<"sueldo"<<endl;
        cin>>sueldo;
        Empleado* empleado= new Empleado(nombre,apellido,sueldo);
        if (empresas.find(empresa) != empresas.end()) {
                     empresas[empresa].emplace_back(empleado);
                 }
        else{
                empleados.emplace_back(empleado);
                empresas.insert(make_pair(empresa,empleados));
            }
    }while(opt!=2);

    mayormenor(empresas);
  

}
/*************************************************************************************************/
/*Escribir un programa que defina una clase llamada MiClase,
la cual tenga una función miembro que imprima por pantalla “Hola Mundo!”.
Crear una instancia de esa clase y utilice el objecto para llamar a la
función miembro. */
#include <iostream>
using namespace std;
class MiClase{
    public:
    MiClase(){
        cout<<"new MiClase"<<endl;
    }
    ~MiClase(){
        cout<<"~MiClase"<<endl;
    }
    void print (){
        cout<<"Hola mundo!"<<endl;
    }
};

int main (void){
    MiClase* ob1=new MiClase();
    ob1->print();
    delete ob1;
}

/********************************************************************************************/
/*Escribir un programa que defina una clase llamada MiClase
con un miembro de datos privado de tipo int llamado x y dos
funciones miembro. La primera función miembro llamada setx(int mivalor) 
establecerá el valor de x a su parámetro mivalor. La segunda función
miembro se llama getx(), es de tipo int y devuelve el valor de x. 
Crear una instancia de la clase y utilizar el objeto para acceder 
a ambas funciones miembro.*/
#include <iostream>
using namespace std;
class MiClase{
  private:
    int x;
  public:
  MiClase(){}
  ~MiClase(){}
  void setx(int x){this->x=x;}
  int getx (){return x;}
};

int main(void){
    MiClase* ob1=new MiClase();
    ob1->setx(12);
    cout<< ob1->getx();
    delete ob1;


}
/********************************************************************************************/
/*Desarrollar una clase vector que contenga lo siguiente:

Sus coordenadas (, ), como fin del vector, suponiendo que siempre el inicio está en el par (0, 0).
Un constructor que recibe estos dos valores y los almacena en los miembros correspondientes.
Una función que imprime por pantalla el valor de las coordenadas del vector.
Una función que devuelve la norma del vector.
Una función que devuelve el cuadrante donde se encuentra el vector.
Escribir un programa que permita tomar coordenadas introducidas 
por el usuario, y que imprima por pantalla la norma del vector*/

#include <iostream>
#include <math.h>
using namespace std;

class Vector{
  private:
    int x;
    int y;
  public:
    Vector(int x,int y){
        this->x=x;
        this->y=y;
    }
    ~Vector(){}
    void print_cord(){
        cout<<"("<<this->x<<","<<this->y<<")"<<endl;
    }
    double norma (){
        return sqrt(pow(this->x,2)+ pow(this->y,2));
    }
    double cuadrante(){
        if(this->x>0){
            if(this->y>0){
                cout<<"primer cuadrante"<<endl;
            }
            else{
                cout<<"cuarto cuadrante"<<endl;
            }
        }
        else{
            if(this->y>0){
                cout<<"segundo cuadrante"<<endl;
            }
            else{
                cout<<"tercer cuadrante"<<endl;
            }
        }
    }
};

int main(void){
    Vector* cord1= new Vector(3,-4);
    Vector* cord2= new Vector(-4,3);
    Vector* cord3= new Vector(2,5);

    cout<<cord1->norma()<<endl<<cord2->norma()<<endl<<cord3->norma()<<endl;

    cord1->cuadrante();
    cord2->cuadrante();
    cord3->cuadrante();

    delete cord1;
    delete cord2
    delete cord3;
}

/***************************************************************************************************/
/*Tomar la clase vector desarrollada en el ejercicio anterior, y agregar una función 
constructora de copia que copie todos sus miembros.
En un programa de prueba, generar un objeto de clase llamado v1, inicializándolo
con algun par de coordenadas cualquiera. Luego, generar otro objeto llamado v2,
e inicializarlo con el objeto v1. Imprimir por pantalla los datos de ambos vectores.*/

#include <iostream>
#include <math.h>
using namespace std;

class Vector{
  private:
    int x;
    int y;
  public:
    Vector(int x,int y){
        this->x=x;
        this->y=y;
    }
    Vector(Vector* vec2){
        this->x=vec2->x;
        this->y=vec2->y;
    }
    ~Vector(){}
    void print_cord(){
        cout<<"("<<this->x<<","<<this->y<<")"<<endl;
    }
    double norma (){
        return sqrt(pow(this->x,2)+ pow(this->y,2));
    }
    double cuadrante(){
        if(this->x>0){
            if(this->y>0){
                cout<<"primer cuadrante"<<endl;
            }
            else{
                cout<<"cuarto cuadrante"<<endl;
            }
        }
        else{
            if(this->y>0){
                cout<<"segundo cuadrante"<<endl;
            }
            else{
                cout<<"tercer cuadrante"<<endl;
            }
        }
    }
};

int main(void){
    Vector* v1= new Vector(4,3);
    Vector* v2= new Vector(v1);

    v1->print_cord();
    v2->print_cord();
    delete v1;
    delete v2;
}
/***********************************************************************************************/
/*Escribir un programa que sobrecargue el operador aritmético - 
para poder restar vectores (clase definida en el ejercicio 7). 
Implementar el siguiente código para comprobar la correcta implementación del ejercicio:*/

#include <iostream>
#include <math.h>

using namespace std;

class Vector{
  private:
    double x;
    double y;
  public:
    Vector(double x,double y){
        this->x=x;
        this->y=y;
    }
    Vector(Vector* vec2){
        this->x=vec2->x;
        this->y=vec2->y;
    }
    ~Vector(){}
    double getx(){return x;}
    double gety(){return y;}

    void print_cord(){
        cout<<"("<<this->x<<","<<this->y<<")"<<endl;
    }
    double norma (){
        return sqrt(pow(this->x,2)+ pow(this->y,2));
    }
    
};
Vector operator - (Vector &v1,Vector &v2 ){
    double x= v1.getx()-v2.getx();
    double y=v1.gety()-v2.gety();

    return Vector {x,y};
}

int main() {
  Vector v1{3.0, 2.0};
  Vector v2{1.0, 5.0};
  Vector v3 = v1 - v2;

  v3.print_cord(); 
}

/*************** **************************************************************************/
/*Implementar una clase arreglo con las operaciones necesarias para poder ejecutar el siguiente programa*/
#include <iostream>
#include <vector>
using namespace std;

class arreglo{
  private:
    vector<int> vec;
    int size;
  public:
    arreglo(int _size){
        this->size=_size;
        vec.reserve(_size);
        for(size_t i=0; i<_size;i++){
            vec.emplace_back(0);
        }
    }
    
    int &operator [](int index){
        return vec[index];
    }
};

int main() {
  arreglo a(7);

  a[0] = 3;
  a[1] = 6;
  a[2] = a[0] + a[1];
  arreglo b = a;
  std::cout << b[2] << std::endl;
}

/***************************************************************************************************************************/
/*Escribir una clase que implemente el TDA Racional (número racional). 
Esta debe manejar los números racionales de modo tal de poder realizar 
las siguientes operaciones:

*creación en base al numerador y denominador,
*igualdad,
*suma,
*resta,
*producto,
*cociente,
*conversión a real, y
*simplificación (4 / 16 se puede simplificar a 1 / 4).*/
#include <iostream>
using namespace std;

class Numero {
  private:
    int num;
    int deno;
  public:
    Numero (int num, int deno){
        this->num=num;
        this->deno=deno;
    }
    void suma(Numero* n2){
        num= this->num*n2->deno + n2->num*this->deno,
        deno= this->deno * n2->deno;
        this->simpl();
    }
    bool igualdad(Numero*n2){
        if((num==n2->num) && (deno==n2->deno)){
            cout<<"truee"<<endl;
            return true;
        }
        else{
            cout<<"falsee";
            return false;
        }
    }
    void resta(Numero* n2){
        num = this->num*n2->deno - n2->num*this->deno;
        deno = this->deno * n2->deno;
        this->simpl();
    }
    Numero* producto( Numero*n2){
        num= this->num*n2->num;
        deno= this->deno * n2->deno;
        this->simpl();
    }
    Numero* cociente( Numero*n2){
        num= this->num*n2->deno;
        deno= this->deno * n2->num;
        this->simpl();
    }
    int conv_real(){
        return this->num/this->deno;
    }
    void simpl(){
        int i=2;
        do{
            if((num %i==0)&&(i>=num)&&(deno %i==0)){
                break;
            }
            i++;
        }while(i<=deno);
        if(num%i==0 && deno%i==0){
            this->num = this->num/i;
            this->deno = this->deno/i; 
        }
    }

    void print(){
        this->simpl();
        cout<<this->num<<"/"<<this->deno<<endl;
    }

    ~Numero(){}
};

int main(void){
     Numero* a1=new Numero(4 ,16);
     Numero* a2=new Numero(2 ,6);
     Numero* a3=new Numero(5 ,15);
     Numero* a4=new Numero(2,8);
    a1->print();
    a2->print();
    a3->print();
    a4->print();
    a1->suma(a2);
    a1->print();
    a2->igualdad(a3);

}

/**************************************************************************************************/
/*Implemente la clase Matriz, utilizando memoria dinámica. Este debe proveer los siguientes métodos:

ProductoEscalar,
Transpuesta,
EsNula (sólo chequea si es nula),
Elemento (devuelve el elemento i, j).
Además debe poder utilizar los operadores: ==, !=, +, - y *.

Piense en una implementación que permita sobrecargar el operador[]
de forma tal que se pueda obtener un elemento de la matriz mediante la operación m[i][j], 
donde m es una instancia de la clase.*/
#include <iostream>
#include <vector>

using namespace std;
class Matriz{
  private:
    vector<vector<int>> mat;
    int row,col;
  public:
    Matriz(int _row,int _col){
        this->row=_row;
        this-> col=_col;
        for(size_t i=0;i<_row;i++){
            vector<int> vec;
            for(size_t j=0;j<_col;j++){
                if(i>=j){
                    vec.emplace_back(1);
                }
                else{
                    vec.emplace_back(2);
                }
                
            }
            mat.emplace_back(vec);
        }
    }
    void ProductoEscalar(int);
    void Print();
    void Transpuesta();
    bool EsNula ();
    int Elemento (int, int);
    bool operator ==(Matriz*);
    bool operator != (Matriz*);
    Matriz* operator +(Matriz*);
    Matriz* operator - (Matriz*);
    Matriz* operator * (Matriz*);    
};

Matriz* Matriz:: operator *(Matriz* other){
    if (this->col == other->row){
        Matriz* m3= this;
        for(size_t i=0;i<row;i++){
            for(size_t j=0;j<col;j++){
                for(size_t k=0;k<col;k++){
                  m3->mat[i][j]=m3->mat[i][j]+(mat[i][k]*other->mat[k][j]);
          }
            }
        }
        return m3;
    }
    
}

Matriz* Matriz:: operator -(Matriz* other){
    Matriz* m3= this;
    for(size_t i=0; i<row;i++){
        for(size_t j=0;j<col;j++){
            m3->mat[i][j]-= other->mat[i][j];
        }
    }  
    return m3;
}

Matriz* Matriz:: operator +(Matriz* other){
    Matriz* m3= this;
    for(size_t i=0; i<row;i++){
        for(size_t j=0;j<col;j++){
            m3->mat[i][j]+= other->mat[i][j];
        }
    }  
    return m3;

}

bool Matriz:: operator !=(Matriz*other)
{
    int total=row*col;
    int si=0;
    for(size_t i=0; i<row;i++){
        for(size_t j=0;j<col;j++){
            if(this->mat[i][j]== other->mat[i][j]){
                si++;
            }
        }
    }
    if(si!=total){
        return true;
    }
    return false;
}

bool Matriz:: operator ==(Matriz* other){
    int total=row*col;
    int si=0;
    for(size_t i=0; i<row;i++){
        for(size_t j=0;j<col;j++){
            if(this->mat[i][j]== other->mat[i][j]){
                si++;
            }
        }
    }
    if(si==total){
        return true;
    }
    return false;
}

int Matriz:: Elemento (int x, int y){
    if(x<=col&& y<=row){
        return mat[x][y];   
    }
}

bool Matriz:: EsNula(){
    int total= row*col;
    int counter=0;
    for(const auto row: mat){
        for(const auto col: row){
            if(col==0){
                counter++;
            }
        }
    }
    if (counter==total){
        return true;
    }
    else{
        return false;
    }
}
void Matriz:: Transpuesta (){
    auto aux= mat;
    for(size_t i=0;i<row;i++){for(size_t j=0;j<col;j++){
        mat[i][j]=aux[j][i];
    }}
    }


void Matriz:: Print(){
    for(const auto row: mat){
        for(const auto col:row){
            cout<<col<< " ";
        }
        cout<<endl;
    }
}
void  Matriz:: ProductoEscalar(int esc){
    for(auto &row: mat){
        for(auto &col:row){
           col*=esc;
        }
    }
}

int main(void){
    Matriz* mat= new Matriz(3,3);
    Matriz* mat2= new Matriz(3,3);
    mat->Print();
    mat->ProductoEscalar(2);
    mat->Print();
    cout<< "TRANSPUESTA"<<endl;
    mat->Transpuesta();
    mat->Print();
    cout<< "es nula?->"<<mat->EsNula()<<endl;
    cout<<mat->Elemento(2,2)<<endl;
    cout<<"son iguales?->"<<(mat==mat2)<<endl;
    cout<<"son distintas?->"<<(mat!=mat2)<<endl;
    mat =mat->operator+(mat2);
    mat->Print();
    mat=mat->operator-(mat2);
    mat->Print();
    mat2->Print();
    mat =mat->operator*(mat2);
     mat->Print();
     /* agregar operador [][], hacerlo con malloc*/
}

/***********************************************************************************************/
/*Implementar la clase Persona. Implementar las clases Estudiante, Profesor y Staff.

Todas las personas tienen nombre y apellido como atributos y un método que devuelve su
nombre como string (se puede sobrecargar el operador << —friend ostream& operator<<(ostream& os,
const Persona& p);—para enviar una persona a stdout).
Todos los estudiantes tienen una carrera asociada y un año de ingreso a dicha carrera.
Todos los profesores tienen al menos departamento asociado y al menos una materia que dictar.*/

#include <iostream>
#include <vector>
using namespace std;

class Persona{
  private:
    string name,surname;
  public:
    Persona(string _name,string _surname){
        this->name=_name;
        this->surname =_surname;
    }

    ~Persona(){}
    string get_name(){return name;}
};

class Estudiante: public Persona{
  private:
    string carrera,anio;
  public:
    Estudiante(string name,string surname,string carrera,string anio): Persona(name,surname){
        this->carrera=carrera;
        this->anio=anio;
    }
    ~Estudiante(){}

};

class Profesor : public Persona{
  private:
    string departamento;
    vector<string> materias;
  public:
    Profesor(string nombre, string apellido,string departamento,string materia):
    Persona(nombre,apellido){
        this->departamento=departamento;
        materias.emplace_back(materia);
    }
    ~Profesor(){}
};


/**********************************************************************************************/
/*Implementar la clase Pieza y las clases Peon, Torre, Caballo, Alfil, Reina y Rey.

Todas las piezas tienen una ubicación en un tablero.
Todas las piezas se pueden mover.
Escribir el código necesario para poder crear piezas de ajedrez, ubicarlas en una
 posición del tablero y moverlas.*/

#include <iostream>

using namespace std;

class Pieza{
  public:
  int x,y;
  Pieza(int x,int y){
    this->x=x;
    this->y=y;
  }
  ~Pieza(){}
  void Mover();
  void Print(){
    cout<<"("<<x<<","<<y<<")"<<endl;
  }
};

class Peon: public Pieza{
    public:
    Peon(int x, int y):Pieza(x,y){
    }
    void Mover (int move){
        y+=move;
    }
};

class Caballo :public Pieza{
    public:
        
        Caballo(int x, int y): Pieza(x,y){
        }
        ~Caballo(){}
        void Mover(string direc){
            if (direc =="aw"){
                x-=2;
                y++;
            }
            else if(direc=="as"){
                x-=2;
                y--;
            }
            else if(direc=="wa"){
                y+=2;
                x--;
            }
            else if(direc=="wd"){
                y+=2;
                x++;
            }
            else if(direc=="dw"){
                x+=2;
                y++;
            }
            else if(direc=="ds"){
                x+=2;
                y--;
            }
            else if(direc=="sa"){
                y-=2;
                x--;
            }
            else if(direc== "sd"){
                y-=2;
                x++;
            }
        }
};

class Torre :public Pieza {
    public:
        Torre (int x, int y):Pieza(x,y){}
        ~Torre(){}
        void mover(string direc, int cuanto){
            if(direc=="w"){
                y+=cuanto;
            }
            else if(direc=="a"){
                x-=cuanto;
            }
            else if(direc=="d"){
                x+=cuanto;
            }
            else if(direc=="s"){
                y-=cuanto;
            }
        }
};
class Rey:public Pieza {
    public:
        Rey(int x, int y):Pieza(x,y){}
        ~Rey(){}
        void mover(string direc){
            if(direc=="w"){
                y++;
            }
            else if(direc=="a"){
                x--;
            }
            else if(direc=="d"){
                x++;
            }
            else if(direc=="s"){
                y--;
            }
        }
};

class Alfil :public Pieza{
    public: 
    Alfil(int x,int y):Pieza(x,y){}
    ~Alfil(){}
    void mover(string direc, int cuanto){
        if(direc=="aw"){
            x-=cuanto;
            y+=cuanto;
        }
        else if( direc=="as"){
            x-=cuanto;
            y-= cuanto;
        }
        else if(direc=="dw"){
            x+=cuanto;
            y+=cuanto;
        }
        else if(direc=="ds"){
            x+=cuanto;
            y-=cuanto;
        }
    }
};

class Reina: public Torre, public Alfil{
    public:
    Reina(int x,int y):Torre(x,y),Alfil(x,y){}
    ~Reina(){}
};

int main(void){

    Torre* torre= new Torre(4,5);
    cout<<"torre : ";
    torre->Print();
    torre->mover("w",3);

    Reina* reina =new Reina(6,6);
    cout<<"reina:";
    reina->Torre::Print();
    reina->Alfil::mover("aw",4);
    reina->Alfil::Print();

}
/*************************************************************************************************/

/*Implementar la clase Animalia, de la que heredan las clases Mammalia y Reptilia.
 Implementar las clases PantheraLeo, PantheraPink, VaranusKomodoensis, PseudotrapelusSinaitus.

Todas las clases tienen una forma de obtener su nombre como string.
¿Qué comparten Mammalia y Reptilia?
Todos los reptiles tienen la capacidad de poner huevos, pero sólo el VaranusKomodoensis
 puede cazar para alimentarse.
Todos los mamíferos maman cuando son crías, pero sólo la PantheraLeo ruge, mientras que
 la PantheraPink puede abrir puertas.
Escribir un programa que cree e inicialice objetos de todas las clases desarrolladas, 
ejecute todos sus comportamientos y, en ellos, imprima qué está haciendo el anima
 (por ejemplo, en algún momento un objeto de la clase PantheraLeo debe imprimir “ruge”).*/
#include <iostream>
using namespace std;

class Animalia{
    private:
        string nombre;
    public:
    Animalia(string nom){
        this->nombre= nom;
    }    
    ~Animalia(){}
    string get_nom(){return nombre;}
 };

class Reptilia :public Animalia{
    public:
    Reptilia(string nombre):Animalia(nombre){}
    ~Reptilia(){}
    void huevito (){
        cout<<get_nom()<< "* pone un wevo *"<<endl;
    }
};

class VaranusKomodoensis:public Reptilia{
    public:
    VaranusKomodoensis(string nombre):Reptilia(nombre){}
    ~VaranusKomodoensis(){}
    void cazar(){
        cout<<get_nom()<<"  *caza*"<<endl;
    }
};

class PseudotrapelusSinaitus: public Reptilia {
    public:
    PseudotrapelusSinaitus(string nombre): Reptilia(nombre){}
    ~PseudotrapelusSinaitus(){}
};


 class Mammalia :public Animalia{
    private:
     string estado;
    public:
     Mammalia(string nombre,string estado):Animalia(nombre){
        this->estado=estado;
     }
     void mamar(){
        if(estado =="cria"){
            cout<<get_nom()<<" el cachorrito is mamando"<<endl;
        }
        else{
            cout<<get_nom()<<" como es adulto, no mama"<<endl;
        }
     }
 };

class PantheraLeo : public Mammalia{
    public:
    PantheraLeo(string nombre,string estado):Mammalia(nombre,estado){}
    ~PantheraLeo(){}
    void rugir (){
        cout<<get_nom()<<"** RUGEEE **"<<endl;
    }
 };

class PantheraPink :public Mammalia{
    public:
    PantheraPink(string nombre, string estado): Mammalia(nombre,estado){}
    ~PantheraPink(){}
    void puertas(){
        cout<<get_nom()<<" * abre una puerta *"<<endl;
    }
};

int main(void){
    PantheraLeo* leito= new PantheraLeo("leito","cria");
    PantheraPink* cacho =new PantheraPink ("cachito","adulto");
    VaranusKomodoensis* salamank = new VaranusKomodoensis("salamank");
    PseudotrapelusSinaitus* nose = new PseudotrapelusSinaitus ("nose");

    leito->mamar();
    leito->rugir();
    cacho->mamar();
    cacho->puertas();
    salamank->cazar();
    nose->huevito();
    
}

/********************************************************************************/
/*Escribir las clases para manejar las propiedades en venta de 
una inmobiliaria: casas, departamentos y terrenos baldíos. Debe haber 
funciones que calculen la comisión del vendedor a partir del precio de venta, 
sabiendo que éste tiene fórmulas de cálculo para distintas casas, departamentos
y terrenos. La unidad debe ser autosuficiente y estar correctamente modularizada.*/
#include <iostream>
#include <vector>
using namespace std;

class Inmueble{
    public:
    double val;
    Inmueble(int val){
        this->val=val;
    }
    ~Inmueble(){}
    virtual double comision()=0;
};

class Casa : public Inmueble {
    public:
    Casa(int val):Inmueble (val){};
    ~Casa(){}
    double comision (){
        return 4000;
    }
};
class Departamento : public Inmueble {
    public:
    Departamento(int val):Inmueble (val){};
    ~Departamento(){}
    double comision (){
        return 3400;
    }
};

class baldio : public Inmueble {
    public:
    baldio(int val):Inmueble (val){};
    ~baldio(){}
    double comision (){
        return 1000;
    }
};

int main(void){
    vector<Inmueble*> propiedades;
    propiedades.reserve(3);
    propiedades.emplace_back(new baldio(35000));
    propiedades.emplace_back(new Departamento(58200));
    propiedades.emplace_back(new Casa(45320));
    double total_comi;
    for(const auto prop : propiedades){
        total_comi+=prop->comision();
    }
    cout<<"la comisión va a ser "<< total_comi<<endl;
    return 0;
}

/*****************************************************************************/
/*Escribir un programa que, utilizando la implementación del ejercicio anterior, 
compare dos propiedades (que podrán ser casas, departamentos o terrenos baldíos) 
e imprima los datos de la de mayor precio de venta.*/

#include <iostream>
#include <vector>
using namespace std;

class Inmueble{
    public:
    double val;
    Inmueble(int val){
        this->val=val;
    }
    ~Inmueble(){}
    virtual double comision()=0;
};

class Casa : public Inmueble {
    public:
    Casa(int val):Inmueble (val){};
    ~Casa(){}
    double comision (){
        return 4000;
    }
};
class Departamento : public Inmueble {
    public:
    Departamento(int val):Inmueble (val){};
    ~Departamento(){}
    double comision (){
        return 3400;
    }
};

class baldio : public Inmueble {
    public:
    baldio(int val):Inmueble (val){};
    ~baldio(){}
    double comision (){
        return 1000;
    }
};

int main(void){
    vector<Inmueble*> propiedades;
    propiedades.reserve(3);
    propiedades.emplace_back(new baldio(35000));
    propiedades.emplace_back(new Departamento(58200));
    propiedades.emplace_back(new Casa(45320));
    double max= propiedades[0]->val;
    for(const auto prop : propiedades){
        if((prop->val) > max){
            max=prop->val;
        }
    }
    cout<<"valor máximo"<<max<<endl;
    return 0;
}/*Escribir un programa que, utilizando la implementación del ejercicio anterior, 
compare dos propiedades (que podrán ser casas, departamentos o terrenos baldíos) 
e imprima los datos de la de mayor precio de venta.*/

#include <iostream>
#include <vector>
using namespace std;

class Inmueble{
    public:
    double val;
    Inmueble(int val){
        this->val=val;
    }
    ~Inmueble(){}
    virtual double comision()=0;
};

class Casa : public Inmueble {
    public:
    Casa(int val):Inmueble (val){};
    ~Casa(){}
    double comision (){
        return 4000;
    }
};
class Departamento : public Inmueble {
    public:
    Departamento(int val):Inmueble (val){};
    ~Departamento(){}
    double comision (){
        return 3400;
    }
};

class baldio : public Inmueble {
    public:
    baldio(int val):Inmueble (val){};
    ~baldio(){}
    double comision (){
        return 1000;
    }
};

int main(void){
    vector<Inmueble*> propiedades;
    propiedades.reserve(3);
    propiedades.emplace_back(new baldio(35000));
    propiedades.emplace_back(new Departamento(58200));
    propiedades.emplace_back(new Casa(45320));
    double max= propiedades[0]->val;
    for(const auto prop : propiedades){
        if((prop->val) > max){
            max=prop->val;
        }
    }
    cout<<"valor máximo"<<max<<endl;
    return 0;
}
/*************************************************************************************/
/*construir un programa para una competencia de atletismo, 
el programa debe gestionar uan serie de atletas  caracterizados por su numero de atleta
nombre y tiempo de carrera. Al final el programa debe mostrar los datos del atleta ganador 
de la carrera*/

#include <iostream>
#include <vector>

using namespace std;

class Atleta{
  private:
    int numero;
    string nombre;
    double tiempo;
  public:
  Atleta(int num_, string _nom, double _tiempo)
  {
    this->numero=num_;
    this-> nombre= _nom;
    this->tiempo= _tiempo;
  }
  ~Atleta(){}
  double get_tiempo(){return tiempo;}
  void get_data (){
    cout<<"nombre: "<< nombre<<endl;
    cout<<"num: "<<numero<<endl;
    cout<<"tiempo:"<< tiempo<<endl;
  }
};

int main(void){
    vector<Atleta*> atletas;
    atletas.emplace_back(new Atleta(12,"pedro",23.56));
    atletas.emplace_back(new Atleta(11,"cata",22.56));
    atletas.emplace_back(new Atleta(10,"alfa",10.56));

    double min= atletas[0]->get_tiempo();
    int index=0;
    for(size_t i=0; i<atletas.size();i++){
        if((atletas[i]->get_tiempo())<=min){
            min=(atletas[i]->get_tiempo());
            index=i;
        }
    }
    cout<<"el ganador es :"<<endl;
    atletas[index]->get_data();
}
/*********************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Alumno{
    private:
        string nombreCarrera;
    public:
        Alumno(string _nombreCarrera){
            this->nombreCarrera=_nombreCarrera;
        }
        ~Alumno(){}
        void MostrarDatos(){
            cout<<"carrera: "<<nombreCarrera<<endl;
        }
        void SetNombreCarrera (string nombre){
            nombreCarrera=nombre;
        }
        string getNombreCarrera(){return nombreCarrera;}
};

class Deportista{
  private:
    string entrenador;
  public:
    Deportista(string nombre){
        this->entrenador=nombre;
    }
    void MostrarDatos(){
        cout<<"entrenador: "<<entrenador<<endl;
    }
    void setNombre(string nombre){
        this->entrenador=nombre;
    }
    string getNombre(){return this->entrenador;}
};

class BecadoDeporte: public Alumno, public Deportista{
  private:
    float montoBeca;
  public:
    BecadoDeporte(string nom,string nom2, float monto): Alumno(nom),Deportista(nom2){
        this->montoBeca=monto;
    }
    void MostrarDatos(){
        cout<<"monto: "<<montoBeca<<endl;
    }
    void setBeca(float monto){
        this->montoBeca=monto;
    }
    float getBeca(){ return montoBeca;}
};

int main (void){
    BecadoDeporte* jorge= new BecadoDeporte("ingenieria","claudia",12000.23);
    jorge->Deportista::MostrarDatos();
    jorge->MostrarDatos();
    jorge->Alumno::MostrarDatos();
}

#include <iostream>
#include <vector>
class Persona{
  public:
    std::string nombre, apellido;
    int edad;
    Persona(std::string name,std::string apellido,int edad){
        this->nombre=name;
        this->apellido=apellido;
        this->edad=edad;
    }
    ~Persona(){}
    virtual void PartidoFutbol()=0;
    virtual void entrenamiento()=0;
};

class Futbolista: public Persona{
  private:
    int dorsal;
    std::string posicion;
  public:
    Futbolista(std::string nombre, std::string apell, int edad, int dorsal,std::string posicion):
    Persona(nombre,apell,edad){
        this->dorsal=dorsal;
        this->posicion=posicion;
    }
    void Entrevista (){
        std::cout<<this->nombre<<" *responde preguntas"<<std::endl;
    }
    void PartidoFutbol(){
        std::cout<< this->nombre<<"*juega"<<std::endl;
    }
    void entrenamiento(){
        std::cout<< this->nombre<<"*entrena*"<<std::endl;
    }
};

class Entrenador: public Persona{
  private:
    std::string estrategia;
  public:
    Entrenador(std::string nombre, std::string apellido, int edad, std::string estrategia):
    Persona(nombre,apellido,edad){
        this->estrategia=estrategia;
    }
    ~Entrenador(){}
    void Planificar (){
        std::cout<< this->nombre<< "*planifica jugada"<<std::endl;
    }
    void PartidoFutbol(){
        std::cout<<this->apellido<< "*piensa*"<<std::endl;
    }
    void entrenamiento(){
        std::cout<< this->apellido<<"*mira*"<<std::endl;
    }

};

int main(void){
    std::vector <Persona*> equipo;
    equipo.emplace_back(new Futbolista("lionel","Messi",35,10,"delantero"));
    equipo.emplace_back(new Entrenador ("lionel","scaloni",45,"4-4-3"));

    for(const auto pers: equipo){
        pers->entrenamiento();
        pers->PartidoFutbol();
    }
}
/**************************************************************************************/

class clase{
    public:
    int val;
    vector<int> vec;
    clase(int v){
        this->val=v;
    }
    clase(){}
    ~clase(){}
    clase operator+(clase &a){
        clase nu(this->val + a.get_val());
        return nu;
    }
    clase operator-(clase&a){
        clase nue (this->val - a.get_val());
        return nue;
    }

    friend ostream& operator << (ostream& os,const clase& este);
    int&  operator [] (int index){
        return vec[index];
    }
    void operator - (int val){
        vec.emplace_back(val);
    }
    int get_val(){return val;}
};
ostream& operator <<(ostream& os, const clase &a){
    os<<a.val<<endl;
    return os;
}

int main(void){
    clase a(2);
    clase b(3);
    clase c= a+b;
    cout<<c.get_val()<<endl;
    clase d= c-a;
    cout<<c;
    c-3;
    cout<<c[0]<<endl;

}

/*************************************************************************************************/
class Empleado{
  private:
    string nombre,apellido;
    float sueldo;
  public:
    Empleado(string nom,string ap, float suel){
        this->  nombre=nom;
        this->apellido=ap;
        this->sueldo=suel;
    }
    ~Empleado(){}
    float get_sueldo(){return sueldo;}
    string get_nombre(){return nombre;}
};

class Empresa{
    vector<Empleado*> empre;
    string nombre;
  public:
    Empresa(string nombre){
        this->nombre=nombre;
    }
    ~Empresa(){}
    void add(Empleado* em){
        empre.emplace_back(em);
    }
    string get_max(){
        int max=empre[0]->get_sueldo();
        int max_ind=0;
        for(size_t i=0; i<empre.size();i++){
            if((empre[i]->get_sueldo())>max){
                max=empre[i]->get_sueldo();
                max_ind=i;
            }
        }
        return empre[max_ind]->get_nombre();
    }
    string get_min(){
        int min=empre[0]->get_sueldo();
        int min_ind=0;
        for(size_t i=0; i<empre.size();i++){
            if((empre[i]->get_sueldo())<min){
                min=empre[i]->get_sueldo();
                min_ind=i;
            }
        }
        return empre[min_ind]->get_nombre();
    }
    string get_nombre(){return nombre;}
    vector<Empleado*> get_emple (){return empre;}
};

tuple<string,string> emple (map<string,Empresa*> emp){
    for(auto punt: emp){
        tuple<string,string> a ((punt.second)->get_max(),(punt.second)->get_min());
        cout<<punt.first<<": max-> "<<get<0> (a)<<endl<<"min-> "<<get<1>(a)<<endl;
        }
   
}

int main(void){
    map<string,Empresa*>empresas;
    string nombre,apellido,empresa;
    float sueldo;
    int opt;
    do{
        cout<<"elija una opción:"<<endl<<"1)cargar"<<endl<<"2)terminar"<<endl;
        cin>>opt;
        if(opt==2){
            break;
        }
        cout<<"empresa:"<<endl;
        cin.ignore();
        getline(cin,empresa);
        cout<<"nombre:"<<endl;
        getline(cin,nombre);
        cout<<"apellido:"<<endl;
        getline(cin,apellido);
        cout<<"sueldo:"<<endl;
        cin>>sueldo;
        if(empresas.find(empresa)!= empresas.end()){
             empresas[empresa]->add(new Empleado(nombre,apellido,sueldo));
        }
        else{
            Empresa* em= new Empresa(empresa);
            em->add(new Empleado(nombre,apellido,sueldo));
            empresas.insert(make_pair(em->get_nombre(),em));
        }
    }while(opt!=2);
    
    emple(empresas);
    }
int main(void){
    vector<int> b{2,3,4,5,2,7};
    tuple<int,vector<int>> a(6,b);
    for (const auto& num:get<1>(a)){
      cout<<num;
    }
    cout<<endl;
    (get<1>(a)).erase(get<1>(a).begin()+2);
     for (const auto& num:get<1>(a)){
      cout<<num;
    }
}
/**********************************************************************************************/

#include <iostream>
#include <vector>
#include <tuple>
#include <map>
 using namespace std;
 /*
class Terreno{
    double precio;
    public:
        Terreno(double precio){
            this->precio=precio;
        }
        ~Terreno(){}
        double get_precio(){return precio;}
        virtual double comision()=0;
};

class Casa: public Terreno {
    public:
        Casa(double precio):Terreno (precio){}
        ~Casa(){}
        double comision(){
            return(this->get_precio()-3000);
        }
};

class Departamentos: public Terreno{
    public:
    Departamentos(double precio):Terreno(precio){}
    ~Departamentos(){}
    double comision(){
        return (this->get_precio()-5000);
    }
};

class Baldio: public Terreno{
    public:
        Baldio(double precio): Terreno(precio){}
        ~Baldio(){}
        double comision(){
            return (this->get_precio()-500);
        }
};

int main(void){
    vector<Terreno*>prop;
    prop.emplace_back(new Casa (10000));
    prop.emplace_back(new Departamentos(7000));
    prop.emplace_back(new Baldio(5000));

    for(const auto& each: prop){
        cout<<each->comision();
    }
}
*************************************************************************************************/
vector<string> deben (vector<tuple<string,string,int>>personas){
    vector<string>nombres;
    for(const auto& each: personas){
        int debe=0;
        int ledeben=0;
        bool check=false;
        for(const auto&other:personas){
            if(get<0>(each) ==get<0>(other)){
                debe+=get<2>(other);
            }
            else if( get<0> (each) == get<1>(other)){
                ledeben+=get<2>(other);
            }
        }
        if(debe>ledeben){
            for(const auto&nom:nombres){
                if(get<0>(each)==nom){
                    check=true;
                }
            }
            if(!check){
                        nombres.emplace_back(get<0>(each));
                        cout<< get<0>(each)<<endl;
                }
        }

    }

}

int main(void){
    vector<tuple<string,string,int>>monto;
    
    monto.emplace_back(make_tuple("juan","carlos",200));
    monto.emplace_back(make_tuple("juan","maria",100));
    monto.emplace_back(make_tuple("carlos","maria",250));
    monto.emplace_back(make_tuple("carlos","juan",500));
    monto.emplace_back(make_tuple("maria","carlos",200));
    monto.emplace_back(make_tuple("maria","juan",500));
    
    deben(monto);

}
//
#include <iostream>
#include <vector>
class estudiante {
    private:
        std::vector<int> notas;
        std::string nombre;
    public:
    estudiante (std::string nombre,float nota1, float nota2){
        notas.emplace_back(nota1);
        notas.emplace_back(nota2);
        this-> nombre=nombre;
    }
    ~estudiante(){std::cout<<"~estudiante()"<<std::endl;}
    float promedio(){
        float total =0;
        for(const auto& nota:notas){
            total+=nota;
        }
        return total/notas.size();
    }
    std::string get_nombre(){return nombre;}
};

class materia {
    private:
        std::vector<estudiante*> estudiantes;
        std::string nombre;
    public:
        materia(std::string nombre){
            this->nombre=nombre;
        }
        ~materia(){
            std::cout<<"~materia()"<<std::endl;
            for(auto each:estudiantes){
                delete each;
            }
        }
        void add_alumno(estudiante* estu){
            estudiantes.emplace_back(estu);
        }
        void ver_alumnos(void){
            for(const auto& alum: estudiantes){
                std::cout<< alum->get_nombre()<<"-> promedio: "<<alum->promedio()<<std::endl;
            }
        }
};
int main(void){
    materia* sanmi = new materia("san miguel");
    sanmi->add_alumno(new estudiante("diego",10,8));
    sanmi->add_alumno(new estudiante("barby",9,5));
    sanmi->add_alumno(new estudiante("jaci",6,9));
    sanmi->add_alumno(new estudiante("naty",8,6));
    sanmi->ver_alumnos();
    delete sanmi;
}
/***************************************************************/

class clase{
    public:
    int val;
    vector<int> vec;
    clase(int v){
        this->val=v;
    }
    clase(){}
    ~clase(){}
    clase operator+(clase &a){
        clase nu(this->val + a.get_val());
        return nu;
    }
    clase operator-(clase&a){
        clase nue (this->val - a.get_val());
        return nue;
    }

    friend ostream& operator << (ostream& os,const clase& este);
    int&  operator [] (int index){
        return vec[index];
    }
    void operator - (int val){
        vec.emplace_back(val);
    }
    int get_val(){return val;}
};
ostream& operator <<(ostream& os, const clase &a){
    os<<a.val<<endl;
    return os;
}

int main(void){
    clase a(2);
    clase b(3);
    clase c= a+b;
    cout<<c.get_val()<<endl;
    clase d= c-a;
    cout<<c;
    c-3;
    cout<<c[0]<<endl;

}
