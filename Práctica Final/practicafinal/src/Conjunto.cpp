#include "Conjunto.h"

//Constructor por defecto
Conjunto::Conjunto() {}

/*-----------------------------------------------*/

//Constructor con parametros:
//Crea un conjunto con un elemento
Conjunto::Conjunto( TBase n) {
    datos.push_back(n);
}

/*-----------------------------------------------*/

//Constructor de copia
Conjunto::Conjunto( const Conjunto &c) {
    datos = c.datos;  // El operador de asignacion esta sobrecargado en VectorDinamico
}

/*-----------------------------------------------*/

//Destructor: Esta vacio por que se usa el destructor de VectorDinamico
Conjunto::~Conjunto() {};

/*-----------------------------------------------*/

//True si esta vacio, false en caso contrario
bool Conjunto::vacio() {
    return datos.vacio();
}

/*-----------------------------------------------*/

//Devuelve el numero de elementos (cardinal) de un conjunto
int Conjunto::size() {
    return datos.size();
}

/*-----------------------------------------------*/

//Inserta un elemento en el conjunto (no inserta repetidos)
void Conjunto::insertar( TBase n) {
    if (!pertenece(n))
        datos.insertar_ordenadamente(n);
}

/*-----------------------------------------------*/

//True si el elemento pertenece, false en caso contrario
bool Conjunto::pertenece( TBase n ) {
    return datos.pertenece(n);
}

/*-----------------------------------------------*/

//Elimina un elmento de un conjunto.
//Como los elementos no se repiten basta con elminiar la primera ocurrencia
void Conjunto::eliminar( TBase n ) {
    datos.eliminar_primera_ocurrencia(n);
}

/*-----------------------------------------------*/

//Imprime los datos del conjunto
void Conjunto::imprimir() {
    datos.imprimir();
}

/*-----------------------------------------------*/

//Elimina los datos alamacenado
void Conjunto::clear(){
    datos.clear();
}

/*-----------------------------------------------*/

TBase& Conjunto::operator[] (const int indice) const {
	return datos[indice];
}

/*-----------------------------------------------*/

//Operador de asignacion
Conjunto& Conjunto::operator=( const Conjunto &c) {
    if (this != &c)
        datos = c.datos;

    return *this;
}

/*-----------------------------------------------*/

//True si son iguales
bool Conjunto::operator==( const Conjunto &c) {
    return datos == c.datos;
}

/*-----------------------------------------------*/

//True si son distintos
bool Conjunto::operator!=( const Conjunto &c) {
    return !(datos == c.datos);
}

/*-----------------INTERSECCION-------------------*/

Conjunto operator*(Conjunto& c1, Conjunto& c2) {
    Conjunto aux;
    for (int i = 0 ; i < c2.datos.size() ; i++) {
        //Si el dato pertenece a los dos conjuntos lo añade a aux
        if (c1.pertenece(c2.datos[i]))
            aux.insertar(c2.datos[i]);
    }
    return aux;
}

/*-----------------------------------------------*/

Conjunto operator*(Conjunto& c, const TBase& i) {
    Conjunto aux;

    //Si i pertenece a c , se guarda i en aux
    if (c.pertenece(i))
        aux.insertar(i);
    return aux;
}

/*-----------------------------------------------*/

Conjunto operator*(const TBase& i, Conjunto& c) {
    Conjunto aux;

    //Si i pertenece a c , se guarda i en aux
    if (c.pertenece(i))
        aux.insertar(i);
    return aux;
}

/*-------------------RESTA------------------------*/

Conjunto operator-(Conjunto& c1, Conjunto& c2) {
    Conjunto aux;
    aux = c1;
    for (int i = 0 ; i < c1.datos.size() ; i++) {
        aux.eliminar(c2.datos[i]); //En caso de que el elmento no este, la funcion no hace nada
    }
    return aux;
}

/*-----------------------------------------------*/

Conjunto operator-(Conjunto& c, const TBase& i) {
    Conjunto aux;

    aux = c;
    aux.eliminar(i);//En caso de que el elmento no este, la funcion no hace nada
    return aux;
}

/*------------------UNION------------------------*/

Conjunto operator+(Conjunto& c1, Conjunto& c2) {
    Conjunto aux;
    aux = c1;

    //Se añaden todos los elementos de c2 a aux ( aux es  igual a c1)
    for (int i = 0 ; i < c2.datos.size() ; i++) {
        aux.insertar(c2.datos[i]);
    }
    return aux;
}

/*-----------------------------------------------*/

Conjunto operator+(Conjunto& c, const TBase& i) {
    Conjunto aux;

    aux = c;
    aux.insertar(i);

    return aux;
}

/*-----------------------------------------------*/

Conjunto operator+(const TBase& i, Conjunto& c) {
    Conjunto aux;

    aux = c;
    aux.insertar(i);

    return aux;
}
