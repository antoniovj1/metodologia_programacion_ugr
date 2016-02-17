#include "SetConjuntos.h"


SetConjuntos::SetConjuntos(){
    util = 0;
    tam = 10;
    conjuntos = new Conjunto[10];
}

/*-----------------------------------------------*/

SetConjuntos::SetConjuntos(const SetConjuntos &sc){
    copy(sc);
}

/*-----------------------------------------------*/

SetConjuntos::~SetConjuntos(){
    delete []conjuntos;
}

/*-----------------------------------------------*/

void SetConjuntos::copy(const SetConjuntos &sc){
    util = sc.util;
    tam = sc.tam;
    conjuntos = new Conjunto[tam];

    for(int i = 0 ; i < util ; i++)
        conjuntos[i]=sc.conjuntos[i];
}

/*-----------------------------------------------*/

void SetConjuntos::resize( int n){
    Conjunto *aux = new Conjunto [n];

    for (int i = 0 ; i < util ; i++) {
        aux[i] = conjuntos[i];
    }

    delete []conjuntos;

    conjuntos = aux;
    tam = n;
}

/*-----------------------------------------------*/

int SetConjuntos::cardinal_set(){
    Conjunto aux = conjuntos[0];

    //Realiza la interseccion de todos los conjuntos almacenados
    for(int i = 0 ; i< util; i++)
        aux=aux*conjuntos[i];

    return aux.size();
}

/*-----------------------------------------------*/

void SetConjuntos::push_back(Conjunto n) {
    if (util + 1 > tam)
        resize(tam * 2);

    conjuntos[util] = n;
    util ++;
}

/*-----------------------------------------------*/

void SetConjuntos::erase(int n){
    if(n < util){
        //Mueve todos los elementos por delante de n una posicion hacia atras
        for (int j = n ; j < util-1 ; j++) {
            conjuntos[j] = conjuntos[j + 1];
        }
        util--;
    }

    //Compruebo si esta muy vacio, si es asi reduzco el tamaño
    if(util < tam/2)
        resize(tam/2);
}

/*-----------------------------------------------*/

int SetConjuntos::mayor_cardinalidad(){
    int pos = 0;
    int cardinal = 0;

    //Recorro los conjuntos y guardo la posicion del que tiene mayor cardinalidad
    for(int i = 0 ;  i < util ; i++){
        if(conjuntos[i].size() > cardinal){
            cardinal = conjuntos[i].size();
            pos = i;
        }
    }
    return pos;
}

/*-----------------------------------------------*/

int SetConjuntos::size(){
    return util;
}

/*-----------------------------------------------*/

Conjunto& SetConjuntos::operator[] (const int indice) const {
	return conjuntos[indice];
}

/*-----------------------------------------------*/
SetConjuntos& SetConjuntos::operator=(const SetConjuntos &sc){
    if(this != &sc){
        delete[] conjuntos;
        copy(sc);
    }
    return *this;
}
/*-----------------------------------------------*/
//La funcion lee el fichero linea por linea
//Cada linea la alamacena en un conjunto y lo añade a conj
istream& operator >>(istream &is , SetConjuntos &conj ){
    Conjunto c;
    int n;
    string s;

    while(getline(is,s)){
        istringstream ss(s); //Convierte un string en un stream

        while (ss >> n){
            c.insertar(n);
        }

        conj.push_back(c);
        c.clear();
    }

    return is;
}

/*-----------------------------------------------*/
//Imprime los datos con el formato:
//1 linea = 1 conjunto
//Los elementos estan separados por una tabulacion
ostream& operator <<(ostream &os , SetConjuntos &conj ){
    Conjunto aux;

    for(int i = 0;i <conj.size(); i++){
        aux = conj[i];
        for(int j = 0 ; j < aux.size(); j++){
            os << aux[j];
            os << '\t';
        }
        os << '\n';
    }

    return os;
}
