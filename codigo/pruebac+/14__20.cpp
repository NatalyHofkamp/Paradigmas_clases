#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>
using namespace std;
//header//

class Operador{
  private:
    int valor;
    int type;
  public:
    Operador();
    ~Operador();
    int setVal(int amount);
    int setType(int val);
    int showVal();
    int showType();
    bool isDebt();
};


class Account {
  private:
    vector<Operador*>transactions;
    vector<string>reporte;
  public:
    Account();
    ~Account();
    int balance();
    int deposit (int amount);
    int withdraw(int amount);
    vector<string> report();
};
//cpp//

int Operador::showType(){
    return type;
}

int Operador::setType(int val){
    type=val;
}
int Operador::setVal(int amount){
    valor=amount;
}
int Operador::showVal(){
    return valor;
}
Operador::Operador(){};
Operador::~Operador(){};
Account::Account(){}
Account::~Account(){}


int Account ::balance(){
    int total=0;
    for(auto each =transactions.begin();each !=transactions.end();each++){
        if((*each)->showType()!=0){
             total+=(*each)->showVal();
         }
        else{
        total-=(*each)->showVal();
          }
    
    return total;
}
}

int Account::deposit(int amount){
    Operador *operacion =new Operador();
    operacion->setVal(amount);
    operacion->setType(1);
    cout<<"ingresaste "<<amount<<endl;
    transactions.emplace_back(operacion);
}

int Account::withdraw(int amount){
    Operador *operacion =new Operador();
    operacion->setVal(amount);
    operacion->setType(1);
    cout<<"queres sacar "<<amount<<endl;
    if(balance()>=amount){
        transactions.emplace_back(operacion);
        cout<<"sacaste "<<amount<<endl;
    }
    else{
        cout<<"no te alcanza "<<endl;
    }
}

vector<string> Account::report(void){
    string val;
    string oracion;
    for(auto each =transactions.begin();each !=transactions.end();each++){
            val=to_string((*each)->showVal());
            if((*each)->showVal()>0){
                oracion="deposito de "+val;
                reporte.emplace_back(oracion);
            }
            else{
                oracion="retiro de" +val;
                reporte.emplace_back(oracion);
            }
        
    }
    return reporte;

}

int main(void){
    Account *cuenta =new Account ();
    cuenta->deposit(10);
    assert (cuenta -> balance()==10);//lo que quiero obtener del objeto
    cout<<"hay "<<cuenta->balance()<<endl;
    cuenta->withdraw(5);
    cout<<"hay "<<cuenta->balance()<<endl;
    cuenta->withdraw(7);
    cout<<cuenta->report().front()<<endl;
    cout <<"ok"<<endl;
    delete cuenta;
    return 0;
    }