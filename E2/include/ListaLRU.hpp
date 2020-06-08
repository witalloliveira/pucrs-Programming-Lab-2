#ifndef __LISTA_LRU_H__
#define __LISTA_LRU_H__

#include <string>

using namespace std;

class ListaLRU
{
private:
    class Nodo
    {
    public:
        int elemento;
        Nodo *ant;
        Nodo *prox;
        Nodo(int e);
    };
    Nodo *inicio;
    Nodo *fim;

public:
    ListaLRU();
    ~ListaLRU();
    bool insere(int valor);
    bool remove(int *valor);
    bool acessa(int valor);
    bool possui(int valor);
    string toString();
};

#endif // __LISTA_LRU_H__