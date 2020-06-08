#include "../header/ListaLRU.hpp"

#include <iostream>

using namespace std;

int main()
{
    ListaLRU *lru = new ListaLRU;

    // Teste para ListaLRU::insere(int valor) e ListaLRU::toString()
    cout << lru->toString() << endl;
    for (int i = 0; i < 5; ++i)
    {
        lru->insere((i + 1) * 10);
        cout << lru->toString() << endl;
    }

    // Teste para ListaLRU::possui(int valor)
    for (int i = 0; i < 11; ++i)
    {
        int valor = (i + 1) * 5;
        cout << "possui " << valor << "? ";
        if (lru->possui(valor))
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }

    // Teste para ListaLRU::acessa(int valor) e ListaLRU::toString()
    for (int i = 0; i < 11; ++i)
    {
        int valor = (i + 1) * 5;
        if (i % 2 == 0)
        {
            if (lru->acessa(valor))
                return 1;
        }
        else
        {
            if (!lru->acessa(valor))
                return 1;
        }
        cout << lru->toString() << endl;
    }
    for (int i = 4; i >= 0; --i)
    {
        int valor = (i + 1) * 10;
        if (!lru->acessa(valor))
            return 1;
        cout << lru->toString() << endl;
    }

    // Teste para ListaLRU::remove(int valor) e ListaLRU::toString()
    for (int i = 0; i < 5; ++i)
    {
        int valor;
        if (!lru->remove(&valor))
            return 1;
        cout << valor << endl;
        cout << lru->toString() << endl;
    }

    // Teste para ListaLRU::insere(int valor) e ListaLRU::toString()
    cout << lru->toString() << endl;
    for (int i = 0; i < 8; ++i)
    {
        lru->insere((i + 1) * 10);
        cout << lru->toString() << endl;
    }

    // Teste para ListaLRU::remove(int valor) e ListaLRU::toString()
    for (int i = 0; i < 4; ++i)
    {
        int valor;
        if (!lru->remove(&valor))
            return 1;
        cout << valor << endl;
        cout << lru->toString() << endl;
    }

    // Teste para ListaLRU::~ListaLRU()
    delete lru;

    return 0;
}