/* void sumar(duble** a, double b,double c)-> no puede tener un return 0;
                                                                return NULL;
                                           -> puede tener un return;


    double sumar (a,b,c)-> NO puede tener un return 0;
                                             return NULL;
                        -> puede tener return NAN;
                                       return 1.0;

    void SumarVector( double*a, size_t la, const double*b,size_t lb)
    -> funciones cortas
    -> archivos cortos

    auto sumar  (const auto & a, auto& b );-> mejor pasar por referencia para no copiar y 
                                              ahorrar espacio, total recibis los valores.


*/
#include <iostream>

/* #### ERRRORR#########*/
/*
int& RetRef (int number){
    int value=0;
    value=number*10;
    return value;
    devuelve una referencia a una variable dentro de una función -> inválido
}

int main(void){
    int value;
    value= RetRef(10);
    std::cout<<value;
    return 0;
    }

#### ERROR #####
-> Indicar que una variable es estática. 

int increment (void){
    int counter=0;
    std::cout<<counter++<<std::endl;

}

int static_increment (void){
    static int counter=0;/-> se guarda el valor que tiene hasta el próximo 
                            llamado(mantiene su valor)
    std::cout<<counter++<<std::endl;

}

int main(void){
    increment();
    increment();
    static_increment();
    static_increment();

}

-> se pueden poner valores por omisión.

std::string Greet (const std::string &whom ="wold"){
    return "helloo"+ whom +"!";


-> diccionarios en c++

std::map <std::string,int> NonAutoFunction (void){
    std::map<std::string,int> var ={{"a",1},{"b",2},{"c",3}};
    return var;
}
auto AutoFunction (void){
    std::map<std::string,int> var ={{"a",1},{"b",2},{"c",3}};
    return var;
}
}