#ifndef __CONTA_H__
#define __CONTA_H__

#include <iostream>

using namespace std;

class Conta
{
private:
    int numero;
    double saldo;

public:
    Conta();
    Conta(int numero);
    Conta(int numero, double saldo);

    int getNumero();
    void setNumero(int numero);

    double getSaldo();
    void setSaldo(double saldo);

    void depositar(double valor);

    double retirar();
    double retirar(double valor);
};
#endif // __CONTA_H__