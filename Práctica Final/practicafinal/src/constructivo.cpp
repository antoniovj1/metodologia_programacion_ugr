#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "SetConjuntos.h"
#include "Conjunto.h"

using namespace std;

//Devuelve un SetConjuntos con la solución.
SetConjuntos alg_k_mic( int k , SetConjuntos conjuntos){
    SetConjuntos sol;

    int pos_mc = conjuntos.mayor_cardinalidad();

    //Añado a la solucion el conjunto con mayor cardinalidad
    sol.push_back(conjuntos[pos_mc]);
    //Elimino ese conjunto de los disponibles
    conjuntos.erase(pos_mc);


    int mic;
    //Mientras no este la solucion y queden conjuntos
    while (sol.size() != k && conjuntos.size()>0) {

        //Creo un conjunto con la interseccion de los componentes de sol,
        //para luego hacer la interseccion con los demas conjuntos con mas facilidad y mirar la
        //interseccion con cardinalidad maxima.
        Conjunto aux=sol[0];
        for(int i = 0 ; i < sol.size(); i++)
            aux = aux*sol[i];


        //Busco la interseccion con cardinalidad maxima.
        Conjunto aux2;
        int pos=0;
        mic = 0; //Sirve para buscar el maximo
        for(int i = 0 ; i <conjuntos.size(); i++){
            aux2 = aux*conjuntos[i];

            if(aux2.size() > mic){
                mic = aux2.size();
                pos = i;
            }
        }

        //Añadimos el conjunto a la solucion y lo eliminamos
        sol.push_back(conjuntos[pos]);
        conjuntos.erase(pos);
    }
    return sol;
}

int main(int argc, char const *argv[]) {

    if(argc != 4){
        cerr << " Se necesitan 3 argumentos: k , fichero entrada , fichero salida" << endl;
        return -1;
    }

    SetConjuntos conjuntos,k_mic;

    int k = atoi(argv[1]);

    //Abrimos fichero de entrada y salida
    ifstream entrada(argv[2]);
    ofstream salida(argv[3]);

    //Cargamos los datos del fichero de entrada en un SetConjuntos
    entrada>>conjuntos;

    //Ejecutamos el algoritmo k_mic y guardamos su resultado en un SetConjuntos
    if(conjuntos.size() > 0)
        k_mic = alg_k_mic(k,conjuntos);

    //Sacamos por pantalla infomacion de la solución
    cout << setw(38);
    cout << left;
    cout << setfill('.');
    cout << "Número total de conjuntos" ;
    cout << conjuntos.size() << endl;

    cout << setw(39);
    cout << "Número conjuntos en la solución" ;
    cout << k_mic.size() << endl;

    cout << setw(38);
    cout << "Cardinal de la solución" ;
    cout << k_mic.cardinal_set() << endl;

    //Guardamos el resultado en el fichero salida, manteniendo el formato original.
    salida << k_mic;

    //Cerramos los ficheros.
    entrada.close();
    salida.close();

}
