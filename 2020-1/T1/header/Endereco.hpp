#ifndef __ENDERECO_H__
#define __ENDERECO_H__

#include <string>

using namespace std;

class Endereco
{
private:
    string logradouro;
    string numero;
    string complemento;
    string bairro;
    string cidade;
    string uf;
    string cep;

public:
    Endereco();
    Endereco(string logradouro,
             string numero,
             string complemento,
             string bairro,
             string cidade,
             string uf,
             string cep);
    Endereco(Endereco &endereco);

    string getLogradouro();
    void setLogradouro(string logradouro);

    string getNumero();
    void setNumero(string numero);

    string getComplemento();
    void setComplemento(string complemento);

    string getBairro();
    void setBairro(string bairro);

    string getCidade();
    void setCidade(string cidade);

    string getUF();
    void setUF(string uf);

    string getCEP();
    void setCEP(string cep);

    string toString();
    string toCSV(char separador = ';');

    bool operator==(Endereco &endereco);
};

#endif // __ENDERECO_H__