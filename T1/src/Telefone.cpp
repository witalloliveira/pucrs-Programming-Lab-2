#include <iostream>
#include <string>

#include "Telefone.hpp"

using namespace std;

Telefone::Telefone() {
    ddi = 0;
    ddd = 0;
    numero = 0;
}

Telefone::Telefone(int ddi, int ddd, int numero) {
    setDDI(int ddi);
    setDDI(int ddd);
    setDDI(long numero);
}

int Telefone::getDDI() { return ddi; }
void Telefone::setDDI(int ddi) { this->ddi = ddi; }

int Telefone::getDDD() { return ddd; }
void Telefone::setDDD(int ddd) { this->ddd = ddd; }

long Telefone::getNumero() { return numero; }
void Telefone::setNumero(long numero) { this->numero = numero; }

string Telefone::toString() {
    string strDDI = to_string(getDDI());
    string strDDD = to_string(getDDD());
    string strNumero = to_string(getNumero());
    string strTelefone = strDDI + strDDD + strNumero;
    return strTelefone;
}

string Telefone::toCSV(char separador=';') {
    string strDDI = to_string(getDDI());
    string strDDD = to_string(getDDD());
    string strNumero = to_string(getNumero());
    string strTelefone = 
        strDDI + 
        separador + 
        strDDD + 
        separador +
        strNumero;
    return strTelefone;
}