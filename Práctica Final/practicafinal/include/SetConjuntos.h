//Fichero de cabecera de la clase SetConjuntos
#ifndef SETCONJUNTOS_H
#define SETCONJUNTOS_H

#include <iostream>
#include <sstream>
#include "Conjunto.h"
using namespace std;

class SetConjuntos{
private:
    Conjunto *conjuntos;
    int util, tam;

    //Metodo para modificar el tamaño del SetConjuntos
    void resize( int n );
    //Metodo para copiar un SetConjuntos
    void copy(const SetConjuntos &sc);
public:

    //Constructor por defecto
    SetConjuntos();

    //Constructor de copia
    SetConjuntos(const SetConjuntos &s);

    //Destructor
    ~SetConjuntos();

    //Devuelve el cardinal de la interseccion de los conjunto almacenados en la el Set
    int cardinal_set();

    //Añade un conjunto
    void push_back(Conjunto c);

    //Elimina el conjunto de la posicion pos
    void erase(int pos);

    //Posicion del ocnjunto con mayor cardinalidad
    int mayor_cardinalidad();

    //Develve el numero de conjuntos almacenadoa
    int size();

    //Devuelve el elemento en la posicion "indice"
    Conjunto& operator[] (const int indice) const;

    //Operador de asignacion
    SetConjuntos &operator=(const SetConjuntos &sc) ;

    //Operadores de entrada y salida.
    friend istream& operator >>(istream &is , SetConjuntos &conj );
    friend ostream& operator <<(ostream &os , SetConjuntos &conj );
};

#endif
