#include <iostream>
using namespace std;

class Complejo{
    private:
        double x,y;

    public:
        Complejo();
        Complejo(double,double);
        Complejo(const Complejo &);/*por si pasamos un complejo por copia,(en función de otra) */
        ~Complejo(){cout<<"Adios mundo cruel"<<endl;}
        
        void emitir(){cout<<x<<" "<<y<<endl;}

        const Complejo operator-();
        Complejo& operator=(const Complejo&);
        const Complejo operator+(const Complejo&);


        Complejo& operator++();
        Complejo operator++(int);   // El argumento int se utiliza para indicar que la funcion se debe invocar
                                    // para un incremento postfix. El int nunca se usa, es un elemento ficticio para poder
                                    // sobrecargar el operador y distinguir su uso prefix/postfix

        Complejo& operator+=(const Complejo&);
        Complejo& operator-=(const Complejo&);
        
        const Complejo operator+(double);
        bool operator ==(const Complejo &);
        bool operator !=(const Complejo &);
    
};


//Constructores
Complejo::Complejo():x(0.0),y(0.0){}
Complejo::Complejo(const Complejo &c):x(c.x),y(c.y){}
Complejo::Complejo(double a, double b):x(a),y(b){}

//Operadores
const Complejo Complejo::operator-(){ //este operador invierte el complejo. ej: -c;
    Complejo s;
    s.x = -x;
    s.y = -y;
    return s;
}

Complejo& Complejo::operator++(){ //el operador pre-incremento puede devolver una referencia a si mismo
    x++; y++; 
    return *this;
}

Complejo Complejo::operator++(int){ //el operador post-incremento debe devolver un nuevo objeto
    Complejo anterior(x,y);
    x++; y++;
    return anterior;
}

Complejo& Complejo::operator=(const Complejo& b){ //actualizo las variables, pero tambien devuelvo un referencia al mismo objeto
    x=b.x;                                        //por si la operacion esta encadenada con otras operaciones  
    y=b.y;
    return *this;
}

Complejo& Complejo:: operator+=(const Complejo& b){
    x+= b.x;
    y+= b.y;
    return *this;
    
}

Complejo& Complejo:: operator-=(const Complejo& b){
    x-= b.x;
    y-= b.y;
    return *this;
}

const Complejo Complejo:: operator+(const Complejo &b){
    return Complejo(x+b.x,y+b.y);
}

const Complejo Complejo:: operator+(double a){
    return Complejo(x+a,y);
}

bool Complejo:: operator ==(const Complejo & b){
    return (b.x == x) && (b.y == y);
}

bool Complejo:: operator !=(const Complejo & b){
    return !((*this) == b);
}

int main(){

    Complejo a,b(1,2.2),c(b);

    if(b==b) cout<<"Es igual"<<endl;
    if(b!=a) cout<<"Son distintos"<<endl;

    cout<<"Probemos los distintos incrementadores"<<endl;
    a.emitir();
    (++a).emitir();

    a.emitir();
    (a++).emitir(); //este operador tiene que crear un nuevo complejo temporal que luego se destruye (pero sus valores son devueltos)
    a.emitir();

    return EXIT_SUCCESS;
}