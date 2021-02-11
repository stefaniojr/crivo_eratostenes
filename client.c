#include "api.h"

int main (){
    int N;

    printf("Qual o maior numero?\n");
    scanf("%d", &N);

    ListaNumeros* lista;
    lista = inicializaLista();

    for (int i=N; i>=2; i--)
        insereNumero(inicializaNumero(i, 0), lista);
    
    marcarMultiplos(lista);
    
    imprime(lista);

    lista = liberaLista(lista);

    return 0;
}