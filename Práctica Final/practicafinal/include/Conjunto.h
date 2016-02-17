//Fichero de cabecera para la clase Conjunto
#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <iostream>
#include "VectorDinamico.h"

typedef int TBase;

using namespace std;

class Conjunto {
private:
	VectorDinamico datos;

public:

	//Constructor por defecto
	Conjunto();

	//Constructor con parametros:
	//Crea un conjunto con un elemento
	Conjunto( TBase n);

	//Constructor de copia
	Conjunto( const Conjunto &c);

	//Destructor: Esta vacio por que se usa el destructor de vector dinamico
	~Conjunto();

	//True si esta vacio, false en caso contrario
	bool vacio();

	//Devuelve el numero de elementos (cardinal) de un conjunto
	int size();

	//Inserta un elemento en el conjunto (no inserta repetidos)
	void insertar( TBase n);

	//True si el elemento pertenece, false en caso contrario
	bool pertenece( TBase n );

	//Elimina un elmento de un conjunto.
	//Como los elementos no se repiten basta con elminiar la primera ocurrencia
	void eliminar( TBase n );

	//Imprime el conjunto
	void imprimir();

	//Vacia el conjunto
	void clear();


	//Devuelve el elemento en la posicion "indice"
	TBase& operator[] (const int indice) const;

	//Operador de asignacion
	Conjunto& operator=( const Conjunto &c);

	//True si son iguales
	bool operator==( const Conjunto &c);

	//True si son distintos
	bool operator!=( const Conjunto &c);

	//Sobrecarga operador + (union)
	friend Conjunto operator+(Conjunto& c1, Conjunto& c2);
	friend Conjunto operator+(Conjunto& c, const TBase& i);
	friend Conjunto operator+(const TBase& i, Conjunto& c);

	//Sobrecarga operador - (resta)
	friend Conjunto operator-(Conjunto& c1, Conjunto& c2);
	friend Conjunto operator-(Conjunto& c, const TBase& i);

	//Sobrecarga operador * (interseccion)
	friend Conjunto operator*(Conjunto& c1, Conjunto& c2);
	friend Conjunto operator*(Conjunto& c, const TBase& i);
	friend Conjunto operator*(const TBase& i, Conjunto& c);

};

#endif
