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
        printf("%d %d\n", numeroCelula->numeroItem->numero, numeroCelula->numeroItem->marcado);
}

void marcarMultiplos(ListaNumeros *lista)
{
    TCelula *numeroCelula = lista->ini;
    for (numeroCelula = lista->ini; numeroCelula != NULL; numeroCelula = numeroCelula->prox)
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
            //marcar os multiplos desse numero, exceto ele.
        }
        else
        {
            //marcar esse numero
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