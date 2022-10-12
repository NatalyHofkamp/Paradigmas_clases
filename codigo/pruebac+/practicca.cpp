#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

/*pasar una cadena y cambiarla en otra función*/

typedef enum{
    st_ok,
    err_inv_val,
    err_null,
}status_t;

namespace mi_espacio{
    char* cadenita;
    int numerito;
}

status_t cambiar(std::string &cadena){
    int len= cadena.size();
    srand(time(NULL));
    int x=std::rand();
    std::string cambio=std::to_string(x);
    cadena=cambio;
    return status_t::st_ok;
}


int main(){
    std::string cadena ="hola";
    mi_espacio::numerito=12;
    mi_espacio::cadenita="mmi cadeNiTa";
    std::cout<<mi_espacio::cadenita<< std::endl<<"numero:"<<mi_espacio::numerito<<std::endl;
    std::cout<<"cadena en main:"<<cadena<<std::endl;
    cambiar(cadena);
    std::cout<<"cadena desp de la función"<<cadena<<std::endl;
    std::cout<<"te gustó el juego?"<<std::endl;
    std::string resp;
    std::cin>>resp;
    if((resp=="NO")||(resp=="no")){
        std::cout<<"bueno, tu problema"<<std::endl;
        return status_t::err_inv_val;
    }
    else{
        std::cout<<"me alegro :)"<<std::endl;
        return status_t::st_ok;
         }


}