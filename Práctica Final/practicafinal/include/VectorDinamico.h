//Fichero de cabecera de la clase VectorDinamico
#ifndef VECTORDINAMICO_H
#define VECTORDINAMICO_H

#include <iostream>

using namespace std;

typedef int TBase;

class VectorDinamico {

private:
	int util, tam;
	TBase *vect;

	//Metodo para aumentar o disminuir  el tamaño del vector;
	void resize(int n);
	//Metodo para copiar un VectorDinamico
	void copy( const VectorDinamico &v );

public:
	//Constructor por defecto
	VectorDinamico();

	//Constructor de copia
	VectorDinamico( const VectorDinamico &v );

	//Destructor
	~VectorDinamico();

	void clear();

	//Devulve el numero de elemtos del vector
	int size() const;

	//True si esta vacion, false en caso contrario
	bool vacio() ;

	//Añade un elemento al final de vector
	void push_back(TBase n);

	//Ordena el vector
	void sort();

	//True si n se encuentra en el vector, false en caso contrario
	bool pertenece(TBase n) const ;

	//Elimina la primera ocurrencia de n
	void eliminar_primera_ocurrencia( TBase n) ;

	//Si el vector esta ordenado, inserta guardando el orden
	void insertar_ordenadamente( TBase n);

	//Muestra por pantalla el contenido del vector
	void imprimir() ;

	//Operador de asignacion
	VectorDinamico& operator= (const VectorDinamico &v);

	//True si son iguales,false en caso contrario
	bool operator==(const VectorDinamico &v) ;

	//Devuelve el elemento en la posicion "indice"
	TBase& operator[] (const int indice) const;
};

#endif
