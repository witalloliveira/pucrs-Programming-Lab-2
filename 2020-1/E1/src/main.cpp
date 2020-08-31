#include "../header/Banco.hpp"
#include "../header/Conta.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Criando banco1 com construtor padrão..." << endl;

    Banco *b = new Banco("Superbanco");
    cout << endl;

    cout << "Testando registro do nome do banco..." << endl;
    cout << "Nome esperado: Superbanco" << endl;
    cout << "Nome: " << b->getNome() << endl;
    cout << endl;

    cout << "Testando adição de contas..." << endl;
    Conta *c = new Conta(1001);
    b->adicionaConta(*c);
    c = new Conta(1002);
    b->adicionaConta(*c);
    c = new Conta(1003, 100.0);
    b->adicionaConta(*c);

    cout << "Numero de contas esperado: 3" << endl;
    cout << "Numero de contas inserido: " << b->getNumContas() << endl;
    cout << endl;

    cout << "Testando obtem contas..." << endl;
    Conta *c1002 = b->getConta(1002);
    Conta *c1001 = b->getConta(1001);
    Conta *c1003 = b->getConta(1003);

    cout << "Testando depósito..." << endl;
    c1002->depositar(10000.0);
    c1001->depositar(1000.0);
    c1003->depositar(100.0);

    cout << fixed << setprecision(1);
    cout << "Saldo esperado na conta 1002: 10000.0" << endl;
    cout << "Saldo na conta 1002: : " << c1002->getSaldo() << endl;
    cout << "Saldo esperado na conta 1001: 1000.0" << endl;
    cout << "Saldo na conta 1001: : " << c1001->getSaldo() << endl;
    cout << "Saldo esperado na conta 1003: 200.0" << endl;
    cout << "Saldo na conta 1003: : " << c1003->getSaldo() << endl;
    cout << endl;

    cout << "Testando retirada..." << endl;
    double retirado1 = c1002->retirar();
    double retirado2 = c1001->retirar(200);

    cout << "Saldo esperado na conta 1002: 0.0" << endl;
    cout << "Saldo na conta 1002: : " << c1002->getSaldo() << endl;
    cout << "Saldo RETIRADO esperado da conta 1002: 10000.0" << endl;
    cout << "Saldo RETIRADO da conta 1002: " << retirado1 << endl;
    cout << "Saldo esperado na conta 1001: 800.0" << endl;
    cout << "Saldo na conta 1001: : " << c1001->getSaldo() << endl;
    cout << "Saldo RETIRADO esperado da conta 1001: 200.0" << endl;
    cout << "Saldo RETIRADO da conta 1001: " << retirado2 << endl;
    cout << endl;

    cout << "Testando transferência..." << endl;
    bool transferido = b->transferir(*c1001, *c1002, 500);

    cout << "Transeferido? Esperado: true; Resultado: " << transferido << endl;
    if (transferido)
    {
        cout << "Saldo esperado na conta 1002: 500.0" << endl;
        cout << "Saldo na conta 1002: : " << c1002->getSaldo() << endl;
        cout << "Saldo esperado na conta 1001: 300.0" << endl;
        cout << "Saldo na conta 1001: : " << c1001->getSaldo() << endl;
    }
    cout << endl;

    cout << "Testando saldo total..." << endl;
    cout << "Saldo total esperado: 1000.0" << endl;
    cout << "Saldo total: " << b->getSaldoTotal() << endl;

    return 0;
}