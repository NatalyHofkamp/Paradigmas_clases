#include <cstdlib>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

// header
class Transaction {
  private:
    char kind;
    int amount;
    Transaction( char kind, int amount );
  public:
    static Transaction* Deposit( int amount ) { return new Transaction( 'D', amount ); }
    static Transaction* Withdraw( int amount ) { return new Transaction( 'W', amount ); }
    ~Transaction();
    int value();
    bool isDeposit();
};
class Account {
  private:
    vector<Transaction*> transactions;
  public:
    Account();
    ~Account();
    int balance();
    void deposit( int amount );
    void withdraw( int amount );
    vector<string> report();
};

// cpp
Transaction::Transaction( char k, int a ):kind(k),amount(a){}
int Transaction::value(){
    return amount;
}
bool Transaction::isDeposit(){
    return kind == 'D';
}

Account::Account() {}
Account::~Account() {}
void Transaction::affectBalance (){
    if(isDeposit()){
        return value();
    }
    else{
        return -1*value();
    }
}

int Account::balance(){ 
    int total = 0;
    for (auto each = transactions.begin(); each != transactions.end(); each++) {
        total+=(*each)->affectBalance();
    }
    return total;
}


void Account::deposit( int amount ){ 
    transactions.emplace_back( Transaction::Deposit( amount ) );
}
void Account::withdraw( int amount ){ 
    if( (balance() - amount ) >= 0 ) {
        transactions.emplace_back( Transaction::Withdraw( amount ) );
    } 
}
vector<string> Account::report(){ 
    vector<string>  report;

    for (auto each = transactions.begin(); each != transactions.end(); each++) { 
        if( (*each)->isDeposit() ) {
            report.emplace_back( "deposito de " + to_string( (*each)->value() ) );
        } else {
            report.emplace_back( "retiro de " + to_string( (*each)->value() ) );
        }
    }
    return report;
}

int main(void) {
    Account *cuenta = new Account();
    assert( cuenta->balance() == 0 );
    
    cuenta->deposit( 10 );
    assert( cuenta->balance() == 10 );
    assert( cuenta->report().front() == "deposito de 10" );
    assert( cuenta->report().size() == 1 );

    cuenta->withdraw( 10 );
    assert( cuenta->balance() == 0 );
    assert( cuenta->report().front() == "deposito de 10" );
    assert( cuenta->report().back() == "retiro de 10" );
    assert( cuenta->report().size() == 2 );
    cuenta->withdraw( 10 );
    assert( cuenta->balance() == 0 );
    assert( cuenta->report().front() == "deposito de 10" );
    assert( cuenta->report().back() == "retiro de 10" );
    assert( cuenta->report().size() == 2 );

    cout << "ok " << std::endl;

    delete cuenta;

    return 0;
}