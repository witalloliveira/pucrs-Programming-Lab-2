#include "../header/Empresa.hpp"

Empresa::Empresa()
{
    setNome("");
    setCNPJ(Cnpj().toString()); // DUVIDA
    setInscEst("");
    setEndereco(nullptr);
    setTelefone(nullptr);
}

Empresa::Empresa(string nome,
                 Cnpj cnpj,
                 string inscEst,
                 Endereco *endereco,
                 Telefone *telefone)
{
    setNome(nome);
    setCNPJ(cnpj.toString()); //DUVIDA
    setInscEst(inscEst);
    setEndereco(endereco);
    setTelefone(telefone);
}

Empresa::Empresa(Empresa &empresa)
{
    setNome(empresa.getNome());
    setCNPJ(empresa.getCNPJ()); // DUVIDA
    setInscEst(empresa.getInscEst());
    setEndereco(empresa.getEndereco());
    setTelefone(empresa.getTelefone());
}

string Empresa::getNome()
{
    return this->nome;
}
void Empresa::setNome(string nome)
{
    this->nome = nome;
}

string Empresa::getCNPJ()
{
    return this->cnpj.toString();
}
bool Empresa::setCNPJ(string cnpj)
{
    this->cnpj.setCNPJ(cnpj); // DUVIDA
}

string Empresa::getInscEst()
{
    return this->inscEst;
}
void Empresa::setInscEst(string inscEst)
{
    this->inscEst = inscEst;
}

Endereco *Empresa::getEndereco()
{
    return this->endereco;
}
void Empresa::setEndereco(Endereco *endereco)
{
    this->endereco = endereco;
}

Telefone *Empresa::getTelefone()
{
    return this->telefone;
}
void Empresa::setTelefone(Telefone *telefone)
{
    this->telefone = telefone;
}

string Empresa::toString()
{
    return (this->getNome() +
            this->getCNPJ() +
            this->getInscEst() + 
            this->getEndereco()->toString() + // DUVIDA
            this->getTelefone()->toString()); // DUVIDA
}

string Empresa::toCSV(char separador)
{
    return (this->getNome() +
            separador +
            this->getCNPJ() +
            separador +
            this->getInscEst() + // DUVIDA
            separador +
            this->getEndereco()->toString() + // DUVIDA
            separador +
            this->getTelefone()->toString()); // DUVIDA
}

bool Empresa::operator==(Empresa &empresa)
{
    return (this->getNome() == empresa.getNome() &&
            this->getCNPJ() == empresa.getCNPJ() &&
            this->getInscEst() == empresa.getInscEst() &&
            this->getEndereco() == empresa.getEndereco() &&
            this->getTelefone() == empresa.getTelefone());
}