#include <iostream>
#include <tuple>
#include <chrono>
#include <ctime>
#include <vector>
class Medicion{
    protected:
      std::chrono::system_clock::time_point fecha;
      virtual void stamp(void) {//se actualiza y establece la fecha
        this->fecha = std::chrono::system_clock::now();
    }
    public:
        Medicion(){
            stamp();//siempre que se instancia una medición-> se llama al método
        }
        ~Medicion(){}
        virtual void getMed()=0;
};


class GpsMed:public Medicion{
    int x,y,z;
    public:
    GpsMed(int x,int y, int z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
    ~GpsMed(){}
    void getMed ()override{
        std::cout<<"GPS"<<std::endl;
        std::time_t stamp = std::chrono::system_clock::to_time_t(fecha);
        std::cout << std::ctime(&stamp) << "\t";
        std::cout<< "coordenadas-> ("<<x<<","<<y<<","<<z<<")"<<std::endl;
    }
};

class LidarMed: public Medicion{
    std::vector<double> distancias;
    public:
    LidarMed(std::vector<double> dist){
       this-> distancias=dist;
    }
    ~LidarMed(){}
     void getMed() override{
        int i=0;
        std::cout<<"LIDAR"<<std::endl;
        std::time_t stamp = std::chrono::system_clock::to_time_t(fecha);
        std::cout << std::ctime(&stamp) << "\t";
        for(const auto& dist:distancias){
            std::cout<< "distancia "<<i<<"-> "<<dist<<std::endl;
            i++;
        }
    }
};


class CamaraMed:public Medicion{
    std::vector<std::vector<int>> img;
    int row;
    int col;
    public:
    CamaraMed(int row,int col,std::vector<std::vector<int>> img){
        this->row=row;
        this->col=col;
        this->img=img;
    }
    ~CamaraMed(){}
    void getMed () override{
        std::cout<<"CAMARA"<<std::endl;
        std::time_t stamp = std::chrono::system_clock::to_time_t(fecha);
        std::cout << std::ctime(&stamp) << "\t";
        for(const auto& row:img){
            for(const auto&col :row){
                std::cout<< "col";
            }
        }
    }
};

class Sensores{
    public:
    ~Sensores(){}
    virtual Medicion* Medir()=0;
    virtual void getMed(){};
};


class Lidar : public Sensores{
    double anguloApertura;
    double resolucion;
    public:
    Lidar(double anguloApertura, double resolucion){
        this->anguloApertura=anguloApertura;
        this->resolucion=resolucion;
    }
    Lidar(const Lidar& copy){
        this->anguloApertura=copy.anguloApertura;
        this->resolucion=copy.resolucion;
    }
    ~Lidar(){}
    Medicion* Medir()override{
        std::cout<<"Lidar midiendo...";
        std::vector<double> dist(anguloApertura/resolucion);
        LidarMed* medi= new LidarMed(dist);
        return medi;
    };
    bool operator ==(const Lidar& other){
        if(this->anguloApertura ==other.anguloApertura &&this->resolucion==other.resolucion){
            return true;
        }
        else{
            return false;
        }
    }
    Lidar& operator= (const Lidar& other){
        this->anguloApertura=other.anguloApertura;
        this->resolucion=other.resolucion;
        return *this;
    }
    
};
class Camara:public Sensores{
    int fil;
    int col;
    public:
        Camara(int fil, int col){
            this->fil=fil;
            this->col=col;
        }
        ~Camara(){}
        Medicion* Medir()override{
            std::cout<<"CAmara midiendo...";
            std::vector<std::vector<int>> img(fil);
            for(size_t i=0;i<fil;i++){
                img[i].reserve(col);
                for(size_t j=0;j<col;j++){
                    img[i][j]='f';
                }
            }
            CamaraMed* medi= new CamaraMed(this->fil,this->col,img);
            return medi;
        }
        
        void operator= (const Camara& copy){
            this-> fil=copy.fil;
            this->col=copy.col;
        }
        bool operator == (const Camara& copy){
            if (this->fil==copy.fil && this->col==copy.col){
                return true;
            }
            else{
                return false;
            }
        } 
};


class GPS:public Sensores{
    std:: tuple<int,int,int> posicion;
    double precision;
    public:
        GPS(int x,int y,int z, double precision){
            posicion=std::make_tuple(x,y,z);
            this->precision=precision;
        }
        GPS(const GPS& copy){
            posicion=copy.posicion;
            this->precision=copy.precision;
        }
        ~GPS(){}
        Medicion* Medir()override{
            std::cout<<"GPs midiendo...";
            GpsMed* medi= new GpsMed(std::get<0>(posicion),std::get<1>(posicion),std::get<2>(posicion));
            return medi;
        }
        void operator=(const GPS& copy){
            this-> posicion=copy.posicion;
            this->precision=copy.precision;
        }
        bool operator == (const GPS& copy){
            if (posicion ==copy.posicion &&precision==copy.precision){
                return true;
            }
            else{
                return false;
            }
        }


};

class AutoAutonomo{
    std::vector<Sensores*> sensores;
    public:
    AutoAutonomo(){}
    ~AutoAutonomo(){}
    void registro(void){
        for(const auto& sensor: this->sensores){
            std::cout<<"MIDIENDO,,,"<<std::endl;
            Medicion* med= sensor->Medir();
            med->getMed();
            delete med;
        }
    }
    void add(Sensores* sens){
        sensores.emplace_back(sens);
    }
};

int main(void){
    Camara* camara =new Camara(10,10);
    GPS* gps =new GPS(3,5,6,18.90);
    Lidar* lidar= new Lidar (23.45,22.98);
    AutoAutonomo* autito= new AutoAutonomo();
    autito->add(camara);
    autito->add(gps);
    autito->add(lidar);
    autito->registro();
    
}