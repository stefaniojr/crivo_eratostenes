#ifndef API_H_
#define API_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <stdbool.h>

typedef struct numero Numero;
typedef struct listanumeros ListaNumeros;

ListaNumeros *inicializaLista();
Numero *inicializaNumero(int numero, int marcador);
void insereNumero(Numero *num, ListaNumeros *lista);
void imprime(ListaNumeros *lista);
void imprimePrimos(ListaNumeros *lista);
void marcarMultiplos(ListaNumeros *lista);
ListaNumeros *liberaLista(ListaNumeros *lista);
void liberaNumero(Numero *numeroItem);

#endif /* API_H_ */