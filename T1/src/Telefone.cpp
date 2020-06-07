#include "../header/Telefone.hpp"

#include <string>

using namespace std;

Telefone::Telefone()
{
    setDDI(0);
    setDDD(0);
    setNumero(0);
}

Telefone::Telefone(int ddi, int ddd, long numero)
{
    setDDI(ddi);
    setDDD(ddd);
    setNumero(numero);
}

Telefone::Telefone(Telefone &telefone)
{
    setDDI(telefone.getDDI());
    setDDD(telefone.getDDD());
    setNumero(telefone.getNumero());
}

int Telefone::getDDI() { return this->ddi; }
void Telefone::setDDI(int ddi) { this->ddi = ddi; }

int Telefone::getDDD() { return this->ddd; }
void Telefone::setDDD(int ddd) { this->ddd = ddd; }

long Telefone::getNumero() { return this->numero; }
void Telefone::setNumero(long numero) { this->numero = numero; }

string Telefone::toString()
{
    string strDDI = to_string(this->getDDI());
    string strDDD = to_string(this->getDDD());
    string strNumero = to_string(this->getNumero());

    string subStrNumeroBegin = strNumero.substr(0, 4);
    string subStrNumeroEnd = strNumero.substr(4, 4);

    return ("+" +
            strDDI +
            "(" +
            strDDD +
            ")" +
            subStrNumeroBegin +
            "-" +
            subStrNumeroEnd);
}

string Telefone::toCSV(char separador)
{
    string strDDI = to_string(this->getDDI());
    string strDDD = to_string(this->getDDD());
    string strNumero = to_string(this->getNumero());

    return (strDDI +
            separador +
            strDDD +
            separador +
            strNumero);
}

bool Telefone::operator==(Telefone &telefone)
{
    return (this->getDDI() == telefone.getDDI() &&
            this->getDDD() == telefone.getDDD() &&
            this->getNumero() == telefone.getNumero());
}