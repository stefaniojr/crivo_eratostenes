#include "api.h"

typedef struct cel TCelula;

struct numero
{
    int numero;
    int marcado;
};

struct cel
{
    Numero *numeroItem;
    TCelula *prox;
};

struct listanumeros
{
    TCelula *ini;
    TCelula *fim;
};

ListaNumeros *inicializaLista()
{
    ListaNumeros *lista = (ListaNumeros *)malloc(sizeof(ListaNumeros));

    lista->ini = NULL;
    lista->fim = NULL;

    return lista;
}

Numero *inicializaNumero(int numero, int marcado)
{
    Numero *numeroItem = (Numero *)malloc(sizeof(Numero));
    numeroItem->numero = numero;
    numeroItem->marcado = marcado;

    return numeroItem;
}

void insereNumero(Numero *num, ListaNumeros *lista)
{
    TCelula *novoNum = (TCelula *)malloc(sizeof(TCelula));

    novoNum->prox = lista->ini;
    novoNum->numeroItem = num;
    lista->ini = novoNum;

    if (lista->fim == NULL)
        lista->fim = novoNum;
}

void imprime(ListaNumeros *lista)
{
    TCelula *numeroCelula;

    for (numeroCelula = lista->ini; numeroCelula != NULL; numeroCelula = numeroCelula->prox)
        printf("%d ", numeroCelula->numeroItem->numero);
    printf("\n");
}

void imprimePrimos(ListaNumeros *lista)
{
    TCelula *numeroCelula;

    for (numeroCelula = lista->ini; numeroCelula != NULL; numeroCelula = numeroCelula->prox)
        if (numeroCelula->numeroItem->marcado == 0)
            printf("%d ", numeroCelula->numeroItem->numero);
    printf("\n");
}

void marcarMultiplos(ListaNumeros *lista)
{
    TCelula *numeroCelula = lista->ini;
    for (numeroCelula = lista->ini; numeroCelula != NULL; numeroCelula = numeroCelula->prox)
    {
        //Checa se não está marcado para continuar.
        if (numeroCelula->numeroItem->marcado == 0)
        {

            int primidor = 0;

            if (numeroCelula->numeroItem->marcado == 1)
                continue;

            for (int i = 2; i <= numeroCelula->numeroItem->numero / 2; i++)
            {

                if (numeroCelula->numeroItem->numero % i == 0)
                {
                    primidor++;
                    break;
                }
            }

            if (primidor == 0)
            {
                TCelula *numeroCelulaAtual = numeroCelula->prox;
                while (numeroCelulaAtual != NULL)
                {
                    if (numeroCelulaAtual->numeroItem->numero % numeroCelula->numeroItem->numero == 0)
                        numeroCelulaAtual->numeroItem->marcado = 1; // Marca o número.

                    numeroCelulaAtual = numeroCelulaAtual->prox;
                }
            }
            else
            {
                numeroCelula->numeroItem->marcado = 1; // Marcar o número, pois ele não é primo.
            }
        }
    }
}

ListaNumeros *liberaLista(ListaNumeros *lista)
{
    TCelula *numeroCelula = lista->ini;

    while (numeroCelula != NULL)
    {
        TCelula *numeroCelulaAtual = numeroCelula->prox;
        liberaNumero(numeroCelula->numeroItem);
        free(numeroCelula);
        numeroCelula = numeroCelulaAtual;
    }

    free(lista);
}

void liberaNumero(Numero *numeroItem)
{
    if (numeroItem != NULL)
        free(numeroItem);
}