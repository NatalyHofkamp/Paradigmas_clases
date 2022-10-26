/* WORKSHOP MARTES 25/10 16.00hs*/
/*parcialito en dos semanas*/
#include <iostream>


/*las cosas se tienen que deshacer en orden inverso al que se crearon*/

class Point{
    /*se le pone _ (guion bajo) a las variables privadas*/
    double x_,y_;
  public:
  /*lista de inicializadores*/
    Point(double x,double y):x_(x),y_(y){std::cout<<"Point()"<<std::endl;}
    /*se crea un objeto y automaticamente se le asigna el valor que pasaron*/
    ~Point(){std::cout <<"~Point()"<<std::endl;}
    void Print() const{
        std::cout<<"("<<x_<<","<<y_<<")"<<std::endl;
    }
  
    /*getters*/
    double x() const {return x_;}
    double y() const {return y_;}
};

class Vector
{
    Point start;
    Point end;
  public:
    Vector(double x1, double y1, double x2, double y2):
    /*constructores*/
        start{x1,y1}, end{x2,y2}{
            std::cout<<"vector()"<<std::endl;
        }
    ~Vector (){std::cout<<"~vector()"<<std::endl;}
    void Print()const{
        std::cout<<"("<<start.x()<<","<<start.y()<<")->"<<"("<< end.x()<<","<<end.y()<<")"<<std::endl;
    }
    
};


int main(void){
    Vector vec{-1,-2,2,2};
    Point p1 (1,2);
    Vector *v= new Vector (0,0,10,10);
    vec.Print();
    v->Print();
    delete v;
}