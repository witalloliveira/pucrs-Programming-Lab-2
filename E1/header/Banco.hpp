#ifndef __BANCO_H__
#define __BANCO_H__

#include "../header/Conta.hpp"

#include <iostream>
#include <vector>

using namespace std;

class Banco
{
private:
    string nome;
    int numContas;
    vector<Conta> contas;

public:
    Banco();
    Banco(string nome);
    Banco(string nome, int numContas, vector<Conta> contas);
    Banco(Banco &banco);

    string getNome();
    void setNome(string nome);

    int getNumContas();
    void setNumContas(int numContas);

    vector<Conta> getContas();
    void setContas(vector<Conta> contas);

    bool adicionaConta(const Conta &conta);

    Conta *getConta(int numero);

    bool transferir(Conta &deCC, Conta &paraCC, double valor);

    double getSaldoTotal();
};
#endif // __BANCO_H__