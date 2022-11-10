/*juego para almacenar juegos,de terror, de aventura, online*/
#include <iostream>
#include <vector>

class Juego{
  protected:
    int codigo;
    float precio;
    std::string nombre;
  public:
    Juego(int codigo, float precio,std::string nombre){
        this->codigo=codigo;
        this->precio=precio;
        this->nombre=nombre;
        std::cout<<"Juego()"<<std::endl;
    }
    virtual ~Juego(){}
    std::string getNombre(){return this->nombre;}
    virtual void PrintInfo()=0;
};

class Terror: public Juego{
  private:
    std::string categoria;
  public:
    Terror(int codigo, float precio,std::string nombre,std::string categoria):Juego(codigo,precio,nombre){
        this->categoria=categoria;
        std::cout<<"Terror()"<<std::endl;
    }
    ~Terror(){}
    void PrintInfo(){
        std::cout<<this->nombre<<":"<<std::endl;
        std::cout<<"categoría: "<<this->categoria<<std::endl;
        std::cout<<"precio: "<<this->precio<<std::endl;
        std::cout<<"codigo: "<< this->codigo<<std::endl;
    }
};

class Aventura :public Juego{
  private:
    int duracion;
  public:
    Aventura(int codigo, float precio,std::string nombre,int duracion):Juego(codigo,precio,nombre){
        std::cout<<"aventura"<<std::endl;
        this->duracion=duracion;
    }
    ~Aventura(){}
    void PrintInfo(){
         std::cout<<this->nombre<<":"<<std::endl;
        std::cout<<"duracion: "<<this->duracion<<"hs"<<std::endl;
        std::cout<<"precio: "<<this->precio<<std::endl;
        std::cout<<"codigo: "<< this->codigo<<std::endl;
    }
};

class Coleccion{
  private:
    std::vector<Juego*> stock;
  public:
    Coleccion(){}
    Coleccion(Coleccion* other){
        std::cout<<"coleccion()"<<std::endl;
        this->stock=other->stock;
    }
    ~Coleccion(){
        for(auto& juego:stock){
            delete juego;
        }
        std::cout<<"~Coleccion()"<<std::endl;
    }
    void Agregar(Juego* juego){
        stock.emplace_back(juego);
        std::cout<<"comprado"<<std::endl;
    }
    void PrintColec(){
        for(const auto& juego :this->stock){
            juego->PrintInfo();
        }
    }
    void Vender(std::string nombre){
        for(size_t i=0; i<stock.size();i++){
            if((stock[i]->getNombre())==nombre){
                stock.erase(stock.begin()+i);
            }
        }
    }

    bool operator== (Coleccion* other){
        if (this->stock== other->stock){
            return true;
        }
        else return false;
    }
    
};

class Gamer{
    std::string nombre;
    Coleccion* coleccion;
  public:
    Gamer(std::string nombre){
        std::cout<<"Gamer()"<<std::endl;
        this->nombre=nombre;
    }
    Gamer( const Gamer* other){
        this->nombre=other->nombre;
        this->coleccion=other->coleccion;
    }
    ~Gamer(){}
    void ComprarJuego(Juego* juego){
        std::cout<<"comprando..."<<std::endl;
        coleccion->Agregar(juego);
    }
    void venderJuego(std::string nombre){
        coleccion->Vender(nombre);
    }
    void verJuegos(){
        coleccion->PrintColec();
    }
    bool operator == (Gamer* other){
        if (this->coleccion == other->coleccion){
            return true;
        }
        else return false;
    }
    void operator = (Gamer* other){
        this->nombre=other->nombre;
        this->coleccion=other->coleccion;
    }
};

int main (void){
    Gamer* uno= new Gamer("Pablito");
    Gamer* dos= new Gamer("Maria");
    Aventura* Minecraft= new Aventura(23345, 2093.049, "Minecraft",720);
    Terror* Slenderman = new Terror(26545, 2.049, "Slenderman","+16");
    uno->ComprarJuego(Minecraft);
    uno->ComprarJuego(Slenderman);
   // std::cout<<"son iguales?->"<<(uno==dos);
    uno->verJuegos();
    dos=uno;
    dos->verJuegos();
    std::cout<<"son iguales?->"<<(uno==dos);
}
