/*Escribir una función reciba un vector de triplas donde cada tripla
(tupla con 3 elementos) tiene la forma (string, string, int) representando 
que una persona le debe a otra un monto de dinero (ej: <”Juan”, “Ilaria”, 200>
indica que Juan le debe a Ilaria 200 pesos). La función debe devolver un vector
con los nombres de las personas que deben mas de lo que les deben.*/

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

auto deben (vector<tuple<string,string,int>> vec)
{
    vector<string> nombres;
    for(size_t i=0; i<vec.size(); i++){
        if (find(nombres.begin(), nombres.end(), get<0>(vec[i])) == nombres.end()) {
            nombres.emplace_back(get<0>(vec[i]));
            cout<<get<0>(vec[i])<<endl;
            }
    }
}

int main(void)
{
    vector<tuple<string,string,int>> vec;
    vec.emplace_back(make_tuple("juan","maria",200));
    vec.emplace_back(make_tuple("cristian","juan",150));
    vec.emplace_back(make_tuple("cristian","marta",150));
    vec.emplace_back(make_tuple("marta","juan",200));
    vec.emplace_back(make_tuple("marta","maria",350));
    vec.emplace_back(make_tuple("maria","marta",350));
    deben(vec);
    
}