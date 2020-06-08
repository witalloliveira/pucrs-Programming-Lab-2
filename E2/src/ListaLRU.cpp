#include "../header/ListaLRU.hpp"

#include <iostream>
#include <sstream>

ListaLRU::Nodo::Nodo(int e)
{
    elemento = e;
    prox = nullptr;
}

ListaLRU::ListaLRU()
{
    inicio = nullptr;
    fim = nullptr;
}

ListaLRU::~ListaLRU()
{
    Nodo *aux;
    aux = inicio;
    while (aux != nullptr)
    {
        Nodo *n = aux;
        aux = aux->prox;
        delete n;
    }
}

bool ListaLRU::insere(int valor)
{
    Nodo *novoNodo = new Nodo(valor);

    novoNodo->ant = nullptr;

    if (this->inicio != nullptr)
    {
        novoNodo->prox = this->inicio;
        this->inicio->ant = novoNodo;
        this->inicio = novoNodo;
    }
    else
    {
        this->inicio = novoNodo;
        this->fim = novoNodo;
    }

    return true;
}

bool ListaLRU::remove(int *valor)
{
    if (this->inicio == nullptr)
    {
        return false;
    }
    else
    {
        Nodo *aux = this->inicio;

        if (aux->prox != nullptr)
        {
            Nodo *penultimo;

            while (aux->prox != nullptr)
            {
                penultimo = aux;
                aux = aux->prox;
            }

            penultimo->prox = nullptr;
            *valor = aux->elemento;
            delete aux;
        }
        else
        {
            *valor = this->inicio->elemento;
            delete this->inicio;
            this->inicio = nullptr;
        }
        return true;
    }
}

bool ListaLRU::acessa(int valor)
{
    if (this->inicio == nullptr)
    {
        return false;
    }
    else
    {
        if (this->inicio->elemento == valor)
        {
            return true;
        }
        else
        {
            Nodo *aux = this->inicio->prox;

            while ((aux != nullptr) &&
                   (aux->elemento != valor))
            {
                aux = aux->prox;
            }

            if (aux == nullptr)
            {

                return false;
            }
            else
            {

                if (aux->prox != nullptr)
                {
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                    aux->prox = this->inicio;
                    aux->ant = nullptr;
                    this->inicio->ant = aux;
                    this->inicio = aux;
                }
                else
                {
                    aux->ant->prox = nullptr;
                    this->fim = aux->ant;
                    aux->ant = nullptr;
                    aux->prox = this->inicio;
                    this->inicio->ant = aux;
                    this->inicio = aux;
                }
                return true;
            }
        }
    }
}

bool ListaLRU::possui(int valor)
{
    if (this->inicio == nullptr)
    {
        return false;
    }
    else
    {
        Nodo *aux = this->inicio;

        while ((aux != nullptr) &&
               (aux->elemento != valor))
        {
            aux = aux->prox;
        }

        if (aux == nullptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

string ListaLRU::toString()
{
    stringstream ss;

    if (this->inicio != nullptr)
    {
        Nodo *aux = this->inicio;

        while (aux != nullptr)
        {
            ss << aux->elemento << " ";
            aux = aux->prox;
        }
    }

    return ss.str();
}