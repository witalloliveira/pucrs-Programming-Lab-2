#include "../header/Banco.hpp"
#include "../header/Conta.hpp"

#include <algorithm> // find_if
#include <numeric> // accumulate

Banco::Banco()
{
    this->nome = string();
    this->numContas = int();
    this->contas = vector<Conta>();
}

Banco::Banco(string nome)
{
    this->nome = nome;
    this->numContas = int();
    this->contas = vector<Conta>();
}

Banco::Banco(string nome, int numContas, vector<Conta> contas)
{
    this->nome = nome;
    this->numContas = numContas;
    this->contas = contas;
}

Banco::Banco(Banco &banco)
{
    this->nome = banco.nome;
    this->numContas = banco.numContas;
    this->contas = banco.contas;
}

string Banco::getNome()
{
    return this->nome;
}
void Banco::setNome(string nome)
{
    this->nome = nome;
}

int Banco::getNumContas()
{
    return this->numContas;
}
void Banco::setNumContas(int numContas)
{
    this->numContas = numContas;
}

vector<Conta> Banco::getContas()
{
    return this->contas;
}
void Banco::setContas(vector<Conta> contas)
{
    this->contas = contas;
}

bool Banco::adicionaConta(const Conta &conta)
{
    this->contas.push_back(conta);
    this->numContas++;       
    return true;
}

Conta *Banco::getConta(int numero)
{
    auto query = (find_if(this->contas.begin(),
                          this->contas.end(),
                          [&](Conta &lConta) {
                              return (lConta.getNumero() == numero);
                          }));
    return &(*query);
    /*
    for (auto itConta = this->contas.begin(); itConta != this->contas.end(); itConta++)
    {
        if (itConta->getNumero() == numero)
        {
            return &(*itConta);
        }
    }*/
}

bool Banco::transferir(Conta &deCC, Conta &paraCC, double valor)
{
    if (deCC.getSaldo() > valor)
    {   
        deCC.setSaldo(deCC.getSaldo() - valor);
        paraCC.setSaldo(paraCC.getSaldo() + valor);
        return true;
    }
    else
    {
        cerr << "WARNING! SALDO INSUFUCIENTE" << endl;
        cout << "TRANSFERENCIA NAO REALIZADA" << endl;
        return false;
    }
}

double Banco::getSaldoTotal()
{
    return accumulate(this->contas.begin(), this->contas.end(), 0,
                      [](double saldoTotalContas, Conta lConta) {
                          return (saldoTotalContas + lConta.getSaldo());
                      });
    /*
    double saldoTotalContas;
    //for (auto itConta = this->contas.begin(); itConta != this->contas.end(); itConta++)
    for (auto &itConta : this->contas)
    {
        saldoTotalContas += itConta.getSaldo();
    }
    return saldoTotalContas;
    */
}