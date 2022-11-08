/* patron-> singleton*/
#include <chrono>
#include <iostream>
#include <thread>
/* PATRON */
using namespace std;
class Singleton {
    protected:
    Singleton (const string value): value_(value){}
    static Singleton * singleton_;/* todas las variables comparten ESTA variable(valor se mantiene)*/
    string value_;
    public:
    Singleton (Singleton&other) = delete;
    void operator =(const Singleton&)=delete;
    static Singleton * GetInstance (const string &value){
        if (singleton_ == nullptr){
            singleton_=new Singleton(value);
        }
        return singleton_;
    }
    void SomeBussinessLogic (){}

    static void print_algo() {/* metodo estático->no necesita una instancia para ser ejecutado*/
        cout<< "imprime desde la clase:"<<value_<<endl;
    }

    string value ()const {return value_;}
};
Singleton* Singleton:: singleton_= nullptr; /*se puede definir por fuera porque es estático*/

int main(){
    Singleton *m= Singleton::GetInstance("rella");
    Singleton *p= Singleton::GetInstance("vera");
    Singleton ::print_algo();
    cout<< "muzza"<<m->value()<<endl;
    cout<<"prima"<<p->value()<<endl;

    return 0;

}


