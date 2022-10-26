#include <iostream>

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