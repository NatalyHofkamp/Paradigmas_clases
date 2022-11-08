#include <cstdlib>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

/* portfolios-> puede tener varias cuentas u otros portfolios

tengo que poder consultar el balance del portofolio y hacer report*/
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

// header
class Accountable {
    public: 
        Accountable(){}
        ~Accountable(){}
        virtual int balance()=0;
        
};


class Transaction {
  protected:
    int amount;
        Transaction( int amount ): amount( amount ) {}
  public:
    ~Transaction();
    int value() {  return amount; }
    virtual bool isDeposit() = 0;
    virtual int affectBalance() = 0;
    virtual string affectReport() = 0;
};
class Deposit: public Transaction {
  public:
    Deposit( int amount ) : Transaction( amount ) {}
    bool isDeposit() {      return true; };
    int affectBalance() {   return value(); }
    string affectReport() { return "deposito de " + to_string( value() ); }
};
class Withdraw: public Transaction {
  public:
    Withdraw( int amount ) : Transaction( amount ) {}
    bool isDeposit() {      return false; };
    int affectBalance() {   return -value(); }
    string affectReport() { return "retiro de " + to_string( value() ); }
};

class Account : public Accountable {
  private:
    vector<Transaction*> transactions;
  public:
    Account(){};
    ~Account(){};
    int balance();
    void deposit( int amount );
    void withdraw( int amount );
    vector<string> report();
};

class Portfolio: public Accountable{
  public:
    vector <Accountable*>cuentas;
  private:
    Portfolio(){};
    ~Portfolio(){}
    void Add(Accountable* account){
        cuentas.emplace_back(account);
    }
    int balance(){
        int total = 0;
        for (auto *each : cuentas) {
            total += each->balance();
        }
        return total;
        }
    };



// cpp

int Account::balance(){
    /*devuelve el total de dinero en a cuenta*/
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
vector<string> Account::report(){ 
    /*devuelve los mivimientos que se hicieron*/
    vector<string>  report;
    for (auto *each : transactions) { 
        report.emplace_back( each->affectReport() );
    }
    return report;
}
void testAccount() {
    Account *cuenta = new Account();
    assert( cuenta->balance() == 0 );
    
    cuenta->deposit( 10 );
    assert( cuenta->balance() == 10 );
    assert( ((new DetailedReport())->reportFor(*cuenta)).front() == "Cuenta: (10)" );
    assert( ((new DetailedReport())->reportFor(*cuenta)).back() == "deposito de 10" );
    assert( ((new DetailedReport())->reportFor(*cuenta)).size() == 2 );

    cuenta->withdraw( 10 );
    assert( cuenta->balance() == 0 );
    assert( ((new DetailedReport())->reportFor(*cuenta)).front() == "Cuenta: (0)" );
    assert( ((new DetailedReport())->reportFor(*cuenta)).back() == "retiro de 10" );
    assert( ((new DetailedReport())->reportFor(*cuenta)).size() == 3 );
    cuenta->withdraw( 10 );
    assert( cuenta->balance() == 0 );
    assert( ((new DetailedReport())->reportFor(*cuenta)).front() == "Cuenta: (0)" );
    assert( ((new DetailedReport())->reportFor(*cuenta)).back() == "retiro de 10" );
    assert( ((new DetailedReport())->reportFor(*cuenta)).size() == 3 );

    cout << "Account ok " << endl;
    delete cuenta;
}

int main(void) {
    testAccount();
    Portfolio *portfolio = new Portfolio();
    assert( portfolio->balance() == 0 );
    assert( ((new DetailedReport())->reportFor(*portfolio)).front() == "Portfolio: (0)" );

    Account *cuenta = new Account();
    cuenta->deposit( 10 );
    portfolio->add( cuenta );
    assert( portfolio->balance() == 10 );
    assert( ((new DetailedReport())->reportFor(*portfolio)).front() == "Portfolio: (10)" );
    assert( ((new DetailedReport())->reportFor(*portfolio)).back() == "deposito de 10" );

    Portfolio *inner = new Portfolio();
    Account *other = new Account();
    other->deposit( 5 );
    inner->add( other );
    portfolio->add( inner );
    assert( portfolio->balance() == 15 );
    assert( ((new DetailedReport())->reportFor(*portfolio)).front() == "Portfolio: (15)" );
    assert( ((new DetailedReport())->reportFor(*portfolio)).back() == "deposito de 5" );

    other->withdraw(3);
    assert( portfolio->balance() == 12 );
    assert( ((new DetailedReport())->reportFor(*portfolio)).front() == "Portfolio: (12)" );
    assert( ((new DetailedReport())->reportFor(*portfolio)).back() == "retiro de 3" );

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