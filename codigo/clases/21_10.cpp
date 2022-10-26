#include <iostream>
/*
class Motor{
  private:
    vector<Oxigeno*>O_; -> esto no es polimorfismo, porque tenes que saber de qué tipo es
    vector<Hidracina*>H_;
}
class Motor {
  private:
    Combustible  C_;/*-> no necesitas saber de qué tipo es lo que tiene adentro (polimorfismo)
  public:
    Motor(COmbustible &c_) :c_(c);
}

*/
struct left{
    virtual void print() const{
        std::cout <<"left"<< std::endl;
    }
};
struct right {
    virtual void print() const{
        std::cout <<"right"<< std::endl;
    }
};

struct center : public left, public right {
    void print()const{/* hay que poner dos distintos si ambos tienen el mismo método*/
        center::left::print();
        this->right::print();
    }
};

class Rectangle
{
    public:
        Rectangle (int w,int h) :width_{w},height_{h}{}
        int width()const{return width_;}
        int height()const{return height_;}
        void Print();
        virtual void Print() const{/*el virtual se pone en la madre*/
            std::cout<<"rectangulo"<<std::endl;
        }
    protected:/*lo que heredaste de otra clase pasa a ser virtual*/
    int width_=0;
    int height_=0;
};

class Square : public Rectangle{
    public:
        Square (int size): Rectangle {size,size}{}
        void Print()const override{/*sobreescribiendo un método*/
           /* this->Rectangle::Print(); -> si pongo esto, me imprime tambien el rectangulo*/
            std::cout <<"square:"<<std::endl;
        }
};

void PrintShape(const Rectangle & r)/*Esto es polimorfismo porque no necesita saber qué clase es para usarla*/
{
    r.Print();
}

int main (void)
{
    Rectangle rec(10,15);
    Square sq(10);
    PrintShape(rec);
    PrintShape (sq);
    center c{};

}