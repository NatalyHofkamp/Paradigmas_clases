#include <iostream>

class Printable{
    public:
     virtual void Print() const =0;
     /*la clase que hereda de aca, puede sobreeescribir 
     este elemento-> con el cero está obligado a cambairlo*/
     /*te da la posibilidad de cambiar el comportamiento*/
};

class A:public Printable
{
  public: 
  /*se pone el override cuando pisas algo virtual*/
    void Print()const override {
        std::cout <<"Print from A"<<std::endl;
    }

};

class B: public Printable{
    public: 
    void Print() const override{
        std::cout << "Print from B"<<std::endl;
    }
};

int main(void){
    Printable *a= new A ();
    Printable *b= newB();
    Printable *b= new B();
    Print(A());
}