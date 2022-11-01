#include <iostream>
#include <cstdlib>
#include <vector>

class A
{
    int id_;
    std::string msj_;
  public:
    A(int id, std::string msj):id_{id},msj_{msj}{};
    ~A(){};
    int GetId()const{return id_;}
    std::string GetMsj()const{return msj_;}
};

class ListaDeObjetos
{
    std::vector<A*> lista; 
  public:
    ListaDeObjetos(){};
    ~ListaDeObjetos(){};
    void Almacenar(A*);
    int Retirar(int index);
    void Info();
    int check(int id);
};

void ListaDeObjetos:: Info(void)
{
    for (int i=0;i<lista.size();i++){
        std::cout<<"-------------------------"<<std::endl;
        std::cout<<"    id: "<< lista[i]->GetId()<<std::endl;
        std::cout<<"    msj:"<< lista[i]->GetMsj()<<std::endl;
    }
}

int ListaDeObjetos::check (int id)
{
    for (int i=0;i<lista.size();i++){
        if(lista[i]->GetId()==id){
            return i;
        }
    }
    return -1;
}
void ListaDeObjetos:: Almacenar(A* obj)
{
    if(lista.size()<=3){
        if(check(obj->GetId())==-1){
            lista.emplace_back(obj);
            std::cout<<"se almacenó ->"<<obj->GetId()<<std::endl;
        }
        else{
            std::cout<<"ya está ese id"<<std::endl;
        }
    }
    else{
        std::cout<<"no hay espacio\n";
    }
}

int ListaDeObjetos::Retirar(int id)
{
    lista.erase(lista.begin()+check(id));
}

void Menu(void)
{
    int opt;
    int id;
    std::string msj;
    ListaDeObjetos* lista=new ListaDeObjetos();
    do{
        std::cout<<"elija una opción"<<std::endl;
        std::cout<<"1)Almacenar\n2)Eliminar\n3)Informe\n4)Salir\n";
        std::cin>>opt;
        if(opt==1)
        {
            std::cout<<"-> ingrese id:"<<std::endl;
            std::cin>>id;
            std::cout<<"-> ingrese msj:"<<std::endl;
            std::cin>>msj;
            A* objeto =new A(id,msj);
            lista->Almacenar(objeto);
        }
        else if (opt==2)
        {
            std::cout<<"ingrese el id que quiere eliminar:\n";
            std::cin>>id;
            lista->Retirar(id);
        }
        else if(opt==3)
        {
            lista->Info();
        }
    }while(opt!=4);
}


int main (void)
{
    Menu();
}

/**********************************************************************************************/


class Vehicle
{
  public:
    std::string brand;
    void bocina();
};

class Transporte
{
    protected:
        int asientos;

};

void Vehicle::bocina(void){
    std::cout<<"pip pip"<<std::endl;
}

class Car:public Vehicle
{
  public:
    std::string mod_;

};

class Mcqueen:public Car,public Transporte{
  public:
    std::string color="rojo";
    void setAss(int num){
        asientos=num;
    }
    int getAss(){
        return asientos;
    }
};


int main(void){
    Mcqueen car1;
    car1.brand="fiat";
    car1.mod_="palio";
    car1.bocina();
    car1.setAss(4);
    std::cout<<car1.color<<std::endl<<car1.getAss()<<std::endl;
}

/****************************************************************************************/

/*Escribir una función que dado un vector de enteros, devuelva un nuevo vector
 duplicando cada elemento. El programa debe imprimir lo que se ve en el ejemplo.*/
#include <iostream>
#include<vector>

using namespace std;

vector<int> duplicate(vector<int> vector1)
{
    vector<int> vector2;
    for(size_t i=0;i<vector1.size();i++){
        vector2.emplace_back(vector1[i]);
        vector2.emplace_back(vector1[i]);
    }
    return vector2;
}

int main (void)
{
    vector<int> vector1{1,2,4,5,7};
    vector<int> vector2 = duplicate(vector1);
    for(size_t i=0; i<vector2.size();i++){
        cout<<vector2[i];
    }

    return 0;
}

/*****************************************************************************/
/*Escribir una función que dado un vector de enteros, devuelva el vector sin
 los números primos (suponer números mayores a cero; 1 no es primo). La función 
 debe modificar el vector, no crear uno nuevo. */
#include <iostream>
#include <vector>

using namespace std; 

vector<int> sinprimos(vector<int> vector1)
{
    for (size_t i=0;i<vector1.size();i++){
        int x=2;
        while((vector1[i])%x !=0){
            x++;
        }
        cout<<i<<"  x -> "<< x<<endl;
        if(vector1[i]==x){
                vector1.erase(i+vector1.begin());
            }

    }
    return vector1;
}


int main(void)
{
    vector<int> vector1{2,15,83,1,25,13,303,8,7,9};
    vector1=sinprimos(vector1);

    for(size_t i=0;i<vector1.size();i++){
        cout<<vector1[i]<<endl;
    }
    return 0;

}

/*******************************************************************************************/
/*Escribir una función que dado un vector ordenado y uno desordenado 
devuelva un vector ordenado con los elementos de ambos.*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> ordenar(vector<int> ord, vector<int> desord)
{
        vector<int> result(ord);
        for(size_t i =0; i<desord.size();i++){
            result.emplace_back(desord[i]);
        }
        for(size_t i=0; i<result.size()-1;i++){
            for(size_t x=i+1;x<result.size();x++){
                int aux= result[i];
                if(result[i]>result[x]){
                    result[i]=result[x];
                    result[x]=aux;
                }
                if(result[i]==result[x]){
                    result.erase(result.begin()+x);
                }
                
            }
        }
        return result;
}

int main (void)
{
    vector<int> ordenado{1,2,3,4,5,6,7,8};
    vector<int> desordenado {93,7,67,1,2,61};
    vector <int> result;

    result=ordenar(ordenado,desordenado);
    for(size_t i =0; i<result.size();i++)
    {
        cout<< result[i]<<" - ";
    }
}
/*****************************************************************************************/
/*Escribir una función que dado un vector de enteros y un número 
entero devuelva true solamente si en el vector hay al menos 3 de 
sus primeros 5 múltiplos (un número es múltiplo de si mismo).*/

#include <iostream>
#include <vector>

using namespace std;

bool multiplos(vector<int> vec, int n)
{
    int counter=0;
    for (size_t i=0; i<vec.size();i++){
        if(vec[1]%n==0){
            counter++;
        }
    }
    if (counter >=3){
        return true;
    }
    else{
        return false;
    }
}

int main(void)
{
    vector<int> vec1{2,3,4,5,6,7,8,9};
    vector<int> vec2 {3,6,7,5};
    cout<< multiplos(vec1,2)<<endl;
    cout<<multiplos(vec2,2)<<endl;
    cout<<multiplos(vec1,3)<<endl; 
}


