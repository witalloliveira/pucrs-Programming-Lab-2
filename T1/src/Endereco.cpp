#include "../header/Endereco.hpp"

#include <string>

using namespace std;

Endereco::Endereco()
{
    setLogradouro("");
    setNumero("");
    setComplemento("");
    setBairro("");
    setCidade("");
    setUF("");
    setCEP("");
}

Endereco::Endereco(string logradouro,
                   string numero,
                   string complemento,
                   string bairro,
                   string cidade,
                   string uf,
                   string cep)
{
    setLogradouro(logradouro);
    setNumero(numero);
    setComplemento(complemento);
    setBairro(bairro);
    setCidade(cidade);
    setUF(uf);
    setCEP(cep);
}

Endereco::Endereco(Endereco &endereco)
{
    setLogradouro(endereco.getLogradouro());
    setNumero(endereco.getNumero());
    setComplemento(endereco.getComplemento());
    setBairro(endereco.getBairro());
    setCidade(endereco.getCidade());
    setUF(endereco.getUF());
    setCEP(endereco.getCEP());
}

string Endereco::getLogradouro() { return this->logradouro; }
void Endereco::setLogradouro(string logradouro)
{
    this->logradouro = logradouro;
}

string Endereco::getNumero() { return this->numero; }
void Endereco::setNumero(string numero)
{
    this->numero = numero;
}

string Endereco::getComplemento() { return this->complemento; }
void Endereco::setComplemento(string complemento)
{
    this->complemento = complemento;
}

string Endereco::getBairro() { return this->bairro; }
void Endereco::setBairro(string bairro)
{
    this->bairro = bairro;
}

string Endereco::getCidade() { return this->cidade; }
void Endereco::setCidade(string cidade)
{
    this->cidade = cidade;
}

string Endereco::getUF() { return this->uf; }
void Endereco::setUF(string uf)
{
    this->uf = uf;
}

string Endereco::getCEP() { return this->cep; }
void Endereco::setCEP(string cep)
{
    this->cep = cep;
}

string Endereco::toString()
{
    return (this->getLogradouro() +
            " " +
            this->getNumero() +
            ", " +
            this->getComplemento() +
            ", " +
            this->getBairro() +
            ", " +
            this->getCidade() +
            "/" +
            this->getUF() +
            ", " +
            this->getCEP());
}

string Endereco::toCSV(char separador)
{
    return (this->getLogradouro() +
            separador +
            this->getNumero() +
            separador +
            this->getComplemento() +
            separador +
            this->getBairro() +
            separador +
            this->getCidade() +
            separador +
            this->getUF() +
            separador +
            this->getCEP());
}

bool Endereco::operator==(Endereco &endereco)
{
    return (this->getLogradouro() == endereco.getLogradouro() &&
            this->getNumero() == endereco.getNumero() &&
            this->getComplemento() == endereco.getComplemento() &&
            this->getBairro() == endereco.getBairro() &&
            this->getCidade() == endereco.getCidade() &&
            this->getUF() == endereco.getUF() &&
            this->getCEP() == endereco.getCEP());
}