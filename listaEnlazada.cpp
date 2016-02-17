#include <iostream>
#include <cassert>

using namespace std;

struct Celda {
	int dato;
	Celda *sig;
};


class Lista{

private:
	int n_elementos;
	Celda *datos;

public:
	Lista(){
		n_elementos=0;
		datos = NULL;
	}

	~Lista(){
		liberar();
	}

	void liberar(){
		while(datos != NULL){
			Celda *aux = datos;
			datos = aux -> sig;
			delete aux;

			n_elementos=0;
		}
	}

	void push_front( int n ){

		Celda *aux = new Celda;
		aux->dato = n;
		aux->sig = datos;
		datos = aux;

		n_elementos++;


	}

	void push_back  ( int n ) {

		Celda *aux = new Celda;
		aux->dato = n;
		aux->sig = NULL;

		if(datos == NULL){
			datos = aux;

			n_elementos++;
		}

		else {
			Celda *aux2 = datos;

			while(aux2->sig != NULL)
			aux2 = aux2->sig;

			aux2->sig = aux;

			n_elementos++;
		}
	}

	void pop_back(){
		Celda *aux = datos;

		while(aux->sig->sig != NULL)
		aux = aux->sig;

		delete aux->sig;
		aux->sig = NULL;

		n_elementos--;
	}

	void pop_front(){
		Celda *aux = datos;

		datos = datos->sig;

		delete aux;

		n_elementos--;
	}

	void insert( int pos, int n){
		assert ( pos <= n_elementos );

		if(pos == n_elementos)
		push_back(n);

		else if(pos == 0)
		push_front(n);

		else{
			Celda *aux = datos;

			int i = 0;
			while( i < pos-1){
				aux = aux->sig;
				i++;
			}

			Celda *nueva = new Celda;
			nueva->dato = n;

			nueva-> sig = aux->sig;
			aux -> sig = nueva;
		}
	}

	//Elimina elemento en una posicion
	void erase( int pos ){
		assert ( pos < n_elementos );

		int n = 0;
		Celda *aux = datos;

		while( n < pos-1){
			aux = aux->sig;
			n++;
		}

		Celda *aux2 = aux -> sig;
		aux->sig = aux->sig->sig;

		delete aux2;
	}

	//Ordena haciendo uso de un vector
	void sort(){
		int *v_aux = new int[n_elementos];

		Celda *aux = datos;

		int i = 0;
		while(aux != NULL){
			v_aux[i] = aux->dato;
			aux = aux -> sig;
			i++;
		}

		for(int i = 0 ; i < n_elementos; i++){
			for(int j = 0 ; j < n_elementos ; j++){
				if(v_aux[i] < v_aux[j]){
					int z = v_aux[i];
					v_aux[i]=v_aux[j];
					v_aux[j] = z;
				}
			}
		}

		int tam = n_elementos;

		liberar();

		for(int i = 0 ; i < tam ; i++){
			push_back(v_aux[i]);
		}
	}

	//Mezcla this con l y lo guarda en mezcla
	void merge( Lista &l , Lista &mezcla){

		Celda *aux = datos;
		Celda *aux2 = l.datos;

		while(aux != NULL && aux2 != NULL){
			mezcla.push_back(aux->dato);
			mezcla.push_back(aux2->dato);

			aux=aux->sig;
			aux2=aux2->sig;
		}

		while(aux != NULL ){
			mezcla.push_back(aux->dato);

			aux=aux->sig;

		}

		while( aux2 != NULL){
			mezcla.push_back(aux2->dato);

			aux2=aux2->sig;
		}

	}


	friend ostream& operator << (ostream &o, const Lista &l);

	friend istream& operator >> (istream &is, Lista &l);

};

ostream& operator << (ostream &o,const Lista &l){

	Celda *aux =l.datos;
	while(aux != NULL){
		o << aux->dato << " -> ";
		aux = aux->sig;
	}
	return o;
}

istream& operator >> (istream &is, Lista &l){

	int n;
	is >> n;

	while(n != -1){
		l.push_back(n);
		is>>n;
	}

}

int main(int argc, char const *argv[]){

	Lista l1,l2,l3;

	cout << "Lista 1: ";
	cin >> l1;
	cout << endl;

	cout << "Lista 2: ";
	cin >> l2;
	cout << endl;

	l1.merge(l2 ,l3);
	cout << l3;
	cout << endl;

	l3.sort();

	cout << l3;
	cout << endl;

	return 0;
}
