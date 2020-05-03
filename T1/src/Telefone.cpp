#include <iostream>
#include <string>

#include "../src/Telefone.hpp"

using namespace std;

Telefone::Telefone() {
    ddi = 0;
    ddd = 0;
    numero = 0;
}

Telefone::Telefone(int ddi, int ddd, long numero) {
    setDDI(ddi);
    setDDI(ddd);
    setDDI(numero);
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
    
    string subStrNumeroBegin = strNumero.substr(0,4);
    string subStrNumeroEnd = strNumero.substr(4,4);
    
    string strTelefone = 
        "+" + 
        strDDI + 
        "(" + 
        strDDD + 
        ")" +
        subStrNumeroBegin +
        "-" +
        subStrNumeroEnd;
    
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

bool Telefone::operator== (const Telefone &tEquals) const {
    return (ddi == tEquals.ddi &&
            ddd == tEquals.ddd &&
            numero == tEquals.numero);
}