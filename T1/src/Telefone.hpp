#ifndef __TELEFONE_H__
#define __TELEFONE_H__

#include <iostream>

using namespace std;

class Telefone {
    int ddi;
    int ddd;
    long numero;

public:
    Telefone();
    Telefone(int ddi, int ddd, int numero);

    int getDDI();
    void setDDI(int ddi);
    
    int getDDD();
    void setDDD(int ddd);

    long getNumero();
    void setNumero(long numero);

    string toString();
    string toCSV(char separador);
};
#endif // __TELEFONE_H__