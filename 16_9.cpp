#include <iostream>
#include <cstring>
#include <string>
#include <map>
/*auto numero=3;
auto i=3.24f;
auto num=3.24;
auto x=i;
int& ref_numero=numero;/*referencia-> es como un puntero-> no puede ser NULL*/
/* ejemplo-> void printf_num(const int& ref) {
                std::cout<< ref;
                }-> te paso la referencia, pero no la podes cambiar*/
/*int main (void){
    int an_int=42;
    float a_float=3.24f;
    std::cout<<"Hola mundo! "<<an_int<<"a_float:"<<a_float <<"\n";
    std::cout<<"ingresar un int:";
    std::cin >> an_int;
    std::cout <<"ingresar un float";
    std::cin>> a_float;
    std::cout<<"an_int:"<<an_int<< ",a_float:"<<a_float<<std::endl;

    std::cerr<< "No hubo error pero probbamos std::cerr"<<std::endl;
    return 0;


}
namespace mi_namespace{
    const int variable= 3;

}
int main(void){
    const char source[]="hello world!";
    char dest[5];

    std::cout<<"source:"<<source<<std::endl;
    std::strcpy(dest,source);
    std::cout<<"dest:"<<dest<<std::endl;
    std::cout<<"source:"<<source<<std::endl;
    std::cout<<::mi_namespace::variable<<std::endl;/*-> lugar para guardar cosas
    return 0;
*/
#if 0
int main(void){
    const std::string source="hello";
    std::string dest;

    std::cout<<"source:"<<source <<std::endl;

    dest =source;
    std::cout<<"dest:"<<dest<<std::endl;

    std::cout<< "source:"<<source+"aaaaaa"<std::endl;
    return 0;

}
#endif

int main(void){
    
}
