#ifndef __EMPRESA_H__
#define __EMPRESA_H__

#include "../header/Cnpj.hpp"
#include "../header/Endereco.hpp"
#include "../header/Telefone.hpp"

#include <string>

using namespace std;

class Empresa
{
private:
    string nome;
    Cnpj cnpj;
    string inscEst;
    Endereco *endereco;
    Telefone *telefone;

public:
    Empresa();
    Empresa(string nome,
            Cnpj cnpj,
            string inscEst,
            Endereco *endereco,
            Telefone *telefone);
    Empresa(Empresa &empresa);

    string getNome();
    void setNome(string nome);

    string getCNPJ();
    bool setCNPJ(string cnpj);

    string getInscEst();
    void setInscEst(string inscEst);

    Endereco *getEndereco();
    void setEndereco(Endereco *endereco);

    Telefone *getTelefone();
    void setTelefone(Telefone *telefone);

    string toString();
    string toCSV(char separador = ';');

    bool operator==(Empresa &empresa);
};

#endif // __EMPRESA_H__