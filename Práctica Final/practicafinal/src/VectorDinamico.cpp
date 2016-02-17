#include "VectorDinamico.h"


VectorDinamico::VectorDinamico() {
	util = 0;
	tam = 10;
	vect = new TBase[10];
}

/*-----------------------------------------------*/

VectorDinamico::VectorDinamico(const VectorDinamico &v){
	copy(v);
}

/*-----------------------------------------------*/

VectorDinamico::~VectorDinamico() {
	delete []vect;
}

/*-----------------------------------------------*/

void VectorDinamico::resize(int n) {
	TBase *aux = new TBase [n];

	for (int i = 0 ; i < n && i < util; i++) {
		aux[i] = vect[i];
	}

	delete []vect;

	vect = aux;
	tam = n;
}

/*-----------------------------------------------*/

void VectorDinamico::copy(const VectorDinamico &v){
	vect = new TBase[v.tam];

	for (int i = 0 ; i < v.util; i++) {
		vect[i] = v.vect[i];
	}
	util = v.util;
	tam = v.tam;
}
/*-----------------------------------------------*/

void VectorDinamico::clear(){
	resize(10);
	util=0;
}

/*-----------------------------------------------*/

int VectorDinamico::size() const {
	return util;
}

/*-----------------------------------------------*/

bool VectorDinamico::vacio() {
	return util == 0;
}

/*-----------------------------------------------*/

void VectorDinamico::push_back(TBase n) {
	if (util + 1 > tam)
		resize(tam * 2);

	vect[util] = n;
	util ++;
}

/*-----------------------------------------------*/

void VectorDinamico::sort() {
	for (int i = 0 ; i < util ; i++) {
		for (int j = 0 ; j < util; j++) {
			if (vect[i] < vect[j]) {
				TBase aux = vect[i];
				vect[i] = vect[j];
				vect[j] = aux;
			}
		}
	}
	
}

/*-----------------------------------------------*/

bool VectorDinamico::pertenece(TBase n) const {

	bool pertenece = false;

	for ( int i = 0 ; i < util && !pertenece  ; i++ ) {
		if (vect[i] == n )
			pertenece = true;
	}
	return pertenece;
}

/*-----------------------------------------------*/

//Elimina la primera ocurrencia de n
void VectorDinamico::eliminar_primera_ocurrencia( TBase n) {

	if (pertenece(n)) {
		int i;
		//Busca la posicion donde aparece n por primera vez
		for (i = 0 ; i < util ; i++) {
			if (vect[i] == n)
			break;
		}

		//Mueve todos los elementos por delante de n una posicion hacia atras ( el elmento queda eliminado)
		for (int j = i ; j < util ; j++) {
			vect[j] = vect[j + 1];
		}

		//Se reduce el numero de utilizados en 1
		util--;
	}

	//Si mas de la mitad del vector esta vacio se modifica el tamaño a la mitad
	if (util < tam/2) {
		resize(tam/2);
	}
}

/*-----------------------------------------------*/

void VectorDinamico::insertar_ordenadamente( TBase n) {

	//Busco la posicion del pirmer elemento mayor que n
	int i;
	for (i = 0 ; i < util ; i++ ) {
		if (vect[i] >= n)
			break;	//Salgo de for, ya he encontrado la posicion
	}

	//Compruebo que hay espacio para un elemento mas
	if (util + 1 > tam) {
		resize(tam * 2);
	}

	//Desplazo las componente una posicion.
	for (int j = util ; j > i ; j--) {
		vect[j] = vect[j - 1];
	}

	//Inserto el elmento
	vect[i] = n;
	util++;
}

/*-----------------------------------------------*/

void VectorDinamico::imprimir() {
	for (int i = 0 ; i < util ; i++)
	cout << vect[i] << " ";
}

/*-----------------------------------------------*/

VectorDinamico& VectorDinamico::operator= (const VectorDinamico &v) {
	if (this != &v) {
		delete []vect;
		copy(v);
	}
	return *this;
}

/*-----------------------------------------------*/

bool VectorDinamico::operator==(const VectorDinamico &v) {
	bool iguales = true;

	if (util == v.util) {

		for (int i = 0 ; i < util && iguales; i++) {
			if (vect[i] != v.vect[i])
				iguales = false;
		}
	}
	return iguales;

}

/*-----------------------------------------------*/

TBase& VectorDinamico::operator[] (const int indice) const {
	return vect[indice];
}
