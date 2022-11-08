#include <cstdlib>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Report {
  protected:
    vector<string>  report;
  public:
    virtual void addDeposit( Deposit* aDeposit ) {};
    virtual void addWithdraw( Withdraw* aWithdraw ) {};
    virtual void addPortfolio( Portfolio* anAccountable ) {};
    virtual void addAccount( Account* anAccountable ) {};

    vector<string> reportFor( Accountable &); 
};
class DetailedReport : public Report {
  public:
    void addDeposit( Deposit* aDeposit );
    void addWithdraw( Withdraw* aWithdraw );
    void addPortfolio( Portfolio* anAccountable );
    void addAccount( Account* anAccountable );
};
class HeadersReport : public Report {
  public:
    void addPortfolio( Portfolio* anAccountable );
    void addAccount( Account* anAccountable );
};
// headers
class Transaction {/*no existe en la vida real, es conceptual-> abstracto 
                    (no tiene sentido instanciarlo)*/
  protected:
    int amount;
    Transaction( int amount ): amount( amount ) {}
  public:
    ~Transaction();
    int value() {  return amount; }
    virtual int affectBalance() = 0;
    virtual string affectReport() = 0;
};
class Deposit: public Transaction {
  public:
    Deposit( int amount ) : Transaction( amount ) {}
    int affectBalance() {   return value(); }
    string affectReport() { return "deposito de " + to_string( value() ); }
};
class Withdraw: public Transaction {
  public:
    Withdraw( int amount ) : Transaction( amount ) {}
    int affectBalance() {   return -value(); }
    string affectReport() { return "retiro de " + to_string( value() ); }
};
class Accountable {
  public:
    virtual int balance() = 0;
    virtual vector<string> affectReport( vector<string> & ) = 0;
    vector<string> report();
};
class Account: public Accountable {
  private:
    vector<Transaction*> transactions;
  public:
    Account();
    ~Account();
int balance();
    void deposit( int amount );
    void withdraw( int amount );
    vector<string> affectReport(); 
};
class Portfolio : public Accountable {
  private:
    vector<Accountable*> accounts;
  public:
    void add( Accountable* anAccount );
    int balance();  
    vector<string> affectReport( vector<string> & ); 
};

// cpp
vector<string> Accountable::report(){ 
    vector<string>  report;
    return affectReport( report );
}
Account::Account() {}
Account::~Account() {}
int Account::balance(){ 
    int total = 0;
    for (auto *each : transactions) {
        total += each->affectBalance();
    }
    return total;
}
void Account::deposit( int amount ){ 
    transactions.emplace_back( new Deposit( amount ) );
}
void Account::withdraw( int amount ){ 
    if( ( balance() - amount ) >= 0 ) {
        transactions.emplace_back( new Withdraw( amount ) );
    } 
}

vector<string> Account::affectReport( vector<string> &report ) { 
    report.emplace_back( "Cuenta: (" + to_string( balance() ) + ")" );
    for (auto *each : transactions) { 
        report.emplace_back( each->affectReport() );
    }
    return report;
}
int Portfolio::balance(){ 
    int total = 0;
    for (auto *each : accounts) {
        total += each->balance();
    }
    return total;
}
void Portfolio::add( Accountable* anAccount ){ 
    accounts.emplace_back( anAccount );
}
vector<string> Portfolio::affectReport( vector<string> &report ) { 
    report.emplace_back( "Portfolio: (" + to_string( balance() ) + ")" );
    for (auto *each : accounts) { 
        each->affectReport( report );
    }
    return report;
}
ostream& operator<<(ostream& stream, Portfolio& p) {
    for (string line : p.report()) { 
        stream << line << endl;
    }
    return stream;
}
// main
void testAccount() {
    Account *cuenta = new Account();
    assert( cuenta->balance() == 0 );
    
    cuenta->deposit( 10 );
    assert( cuenta->balance() == 10 );
    assert( cuenta->report().front() == "Cuenta: (10)" );
    assert( cuenta->report().back() == "deposito de 10" );
    assert( cuenta->report().size() == 2 );

    cuenta->withdraw( 10 );
    assert( cuenta->balance() == 0 );
    assert( cuenta->report().front() == "Cuenta: (0)" );
    assert( cuenta->report().back() == "retiro de 10" );
    assert( cuenta->report().size() == 3 );
    cuenta->withdraw( 10 );
    assert( cuenta->balance() == 0 );
    assert( cuenta->report().front() == "Cuenta: (0)" );
    assert( cuenta->report().back() == "retiro de 10" );
    assert( cuenta->report().size() == 3 );

    cout << "Account ok " << endl;
    delete cuenta;
}

int main(void) {
    testAccount();
    Portfolio *portfolio = new Portfolio();
    assert( portfolio->balance() == 0 );
    assert( portfolio->report().front() == "Portfolio: (0)" );

    Account *cuenta = new Account();
    cuenta->deposit( 10 );
    portfolio->add( cuenta );
    assert( portfolio->balance() == 10 );
    assert( portfolio->report().front() == "Portfolio: (10)" );
    assert( portfolio->report().back() == "deposito de 10" );

    Portfolio *inner = new Portfolio();
    Account *other = new Account();
    other->deposit( 5 );
    inner->add( other );
    portfolio->add( inner );
    assert( portfolio->balance() == 15 );
    assert( portfolio->report().front() == "Portfolio: (15)" );
    assert( portfolio->report().back() == "deposito de 5" );

    other->withdraw(3);
    assert( portfolio->balance() == 12 );
    assert( portfolio->report().front() == "Portfolio: (12)" );
    assert( portfolio->report().back() == "retiro de 3" );

    Portfolio *sub = new Portfolio();
    Account *subOther = new Account();
    subOther->deposit( 15 );
    sub->add( subOther );
    inner->add( sub );

    cout << endl << *portfolio << endl;

    cout << "Portfolio ok " << endl;

    delete cuenta;
    delete portfolio;
    delete inner;
    delete other;
    delete sub;
    delete subOther;

    return 0;
}