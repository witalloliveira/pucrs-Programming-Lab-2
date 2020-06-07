#include "../header/Conta.hpp"

#include <string>

using namespace std;

Conta::Conta()
{
    this->numero = int();
    this->saldo = double();
}

Conta::Conta(int numero)
{
    this->numero = numero;
    this->saldo = double();
}

Conta::Conta(int numero, double saldo)
{
    this->numero = numero;
    this->saldo = saldo;
}

int Conta::getNumero()
{
    return this->numero;
}
void Conta::setNumero(int numero)
{
    this->numero = numero;
}

double Conta::getSaldo()
{
    return this->saldo;
}
void Conta::setSaldo(double saldo)
{
    this->saldo = saldo;
}

void Conta::depositar(double valor)
{
    this->saldo += valor;
}

double Conta::retirar(double valor)
{
    this->saldo -= valor;
    return valor;
}

double Conta::retirar()
{
    double valor = this->saldo;
    this->saldo = double();
    return valor;
}