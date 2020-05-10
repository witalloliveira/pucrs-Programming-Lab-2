#ifndef __TELEFONE_H__
#define __TELEFONE_H__

#include <iostream>

using namespace std;

class Telefone
{
private:
    int ddi;
    int ddd;
    long numero;

public:
    Telefone();
    Telefone(int ddi, int ddd, long numero);
    Telefone(Telefone &telefone);

    int getDDI();
    void setDDI(int ddi);

    int getDDD();
    void setDDD(int ddd);

    long getNumero();
    void setNumero(long numero);

    string toString();
    string toCSV(char separador = ';');

    bool operator==(Telefone &telefone);
};
#endif // __TELEFONE_H__