/*delete [s] -> borrar un arreglo
delete -> borrar un objeto
composicion-> uno no existe sin el otro
agregacion -> tan bien por separado*/

#include <iostream>
#include <vector>
#include <array>
#include <map>
using namespace std;
/*
int main(void){
    array<float,5> data {1.0f,20.0,4.3,5.7,3.0}/*no es dinámico, tiene un tamaño fijo;

    for(const auto& elem:data)/*ponemos la referencia para evitar copiar una estructura grande, en este caso son floats
                                /* const-> no queres modificar los datos
    {
        cout<<elem<<endl;
    }

    cout<<"array at(0) ->"<<data.at(0)<<endl;
    cout<< "array operator [0] ->"<<data[-1]<<endl;/*basurita
    data[0]=15.0;
    cout<< "array operator[0] after set  ->"<<data[0]<<endl;

}
*/

/**********V E C T O R E S *******************

int main(void){
    vector<string>data;
    data.reserve(10);/*no vas a saber cuánto crece  cuando le agregas algo - la capacidad que tiene
    cout<<"capacity"<<data.capacity()<<endl;
    for(size_t i=0; i<data.capacity();i++){
        string input;
        cin>>input;
        data.emplace_back(input);
    }
    data.emplace_back("11");
    data.emplace_back("12");

     cout<<"capacity"<<data.capacity()<<endl;
    for( const auto & elem:data){
        cout<<elem<<endl;
    }
}


*************************** M A P A S **********************************

*/

int main (void){
    map <int, string> alumnos;

    alumnos.emplace(209,"nicolas");
    alumnos.emplace(983,"joaquin");
    alumnos.emplace(298029,"Lolo");

    for(const auto& [legajo,nombre]:alumnos){
        cout<<nombre<<"("<<legajo<<")"<<endl;
    }

    for(const auto& pt: alumnos){
        const auto& legajo =pt.first;
        const auto& nombre =pt.second;
        cout<<nombre<<"("<<legajo<<")"<<endl;
    }
    cout<<boolalpha


}