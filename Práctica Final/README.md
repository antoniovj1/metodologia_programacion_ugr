# Descripción del Programa
Considerar el siguiente problema de optimización, denominado problema de la máxima intersección
de k conjuntos (k-MIC). Dada una colección de m conjuntos C={S 1 , ..., S m } sobre un conjunto finito
de enteros ({1,...,n}), y un entero positivo k, el objetivo de este problema es seleccionar exactamente k
conjuntos de C cuya intersección tiene el máximo cardinal. La práctica consiste en desarrollar un
programa que realice las siguientes acciones:

1. Leer m conjuntos de un fichero de entrada, donde cada línea (terminada en '\n') contiene los
enteros asociados a cada conjunto.

2. Resolver el problema k-MIC utilizando una técnica constructiva (método greedy) que consiste
en los siguientes pasos:
 ```
Partir de una solución vacía, Sol.
Sea S' el conjunto con mayor cardinal de C.
Incluir S' en Sol y eliminarlo de C.
Mientras |Sol| ≠ k hacer
        Buscar el conjunto S'' en C cuya intersección con todos los conjuntos en Sol tiene el mayor cardinal.
        Incluir S'' en Sol y eliminarlo de C.
Devolver Sol.
```
3. Guardar los conjuntos de la solución encontrada, Sol, en un fichero de salida (que tenga el
mismo formato que el fichero de entrada).
NOTA: El ejecutable se deberá llamar constructivo y se invocará de la siguiente forma:
```
$ constructivo k fichero_entrada fichero_salida
```
