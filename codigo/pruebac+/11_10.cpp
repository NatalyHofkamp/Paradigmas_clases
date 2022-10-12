#include <iostream>
/*
int main(void){
    int num_inc;
    srand(time(NULL));
    num_inc= rand()%100;
    int num_us;
    do{
        std::cout<<"ingresa un numero :";
        std::cin>>num_us;
        if (num_us== num_inc){
            std::cout<<"acertaste!"<<std::endl;
            break;
        }
        else if (num_us> num_inc){
            std::cout<<"es muy grande!"<<std::endl;
            continue;
        }
        else{
            std::cout <<"es muy chico"<<std::endl;
            continue;
        }
    }while(num_us);
}

*/

void juego (int num_us,int num_m,int range,int init){
    num_m=init+((range-init)/2);
    std::cout<<num_m<<std::endl;
    if(num_m > num_us){
        std::cout<<"es muy grande"<<std::endl;
        range=num_m;
        juego(num_us,num_m,range,init);
    }
    else if(num_m < num_us){
        std::cout<<"es muy chico"<<std::endl;
        init=num_m;
        juego(num_us,num_m,range,init);
    }
    else{
        std::cout<< "adivinaste, el numero es "<<num_m<<"!"<<std::endl;
    }
}

int main(void){
    int num_us;
    int init;
    int num_m;
    init =0;
    int range= 100;
    std::string answ;
    std::cout<< "ingrese un numero:"<<std::endl;
    std::cin>>num_us;
    srand(time(NULL));
    juego(num_us,num_m,range,init);

}