#include "../header/Telefone.hpp"

#include <iostream>
#include <string>

using namespace std;

bool testTelefone() {
    string h1 = "==========================================";
    string h2 = "------------------------------------------";
        
    cout << h1 << endl;
    cout << "=== INICIANDO TESTES FUNCIONAIS ==========" << endl;
    cout << h1 << endl;
    cout << "CLASSE: TELEFONE" << endl;
    cout << h2 << endl;
    cout << "INSTANCIANDO OBJETOS..." << endl;
    cout << h2 << endl;

    Telefone tX;
    tX.setDDI(55);
    tX.setDDD(51);
    tX.setNumero(34215678);
    Telefone tY;
    tY.setDDI(55);
    tY.setDDD(68);
    tY.setNumero(33445566);
    Telefone tZ;
    
    cout << "OBJETOS tX, tY, tZ INSTANCIADOS" << endl;
    cout << h2 << endl;
    
    cout << "VALIDANDO tX..." << endl;
    cout << h2 << endl;

    if (tX.getDDI() != 55)
        return false;
    if (tX.getDDD() != 51)
        return false;
    if (tX.getNumero() != 34215678)
        return false;
    if (tX.toString() != "+55(51)3421-5678")
        return false;
    if (tX.toCSV(';') != "55;51;34215678")
        return false;

    cout << "tX.getDDI()\t\t OK" << endl;
    cout << "tX.getDDD()\t\t OK" << endl;
    cout << "tX.getNumero()\t\t OK" << endl;
    cout << "tX.toString()\t\t OK" << endl;
    cout << "tX.toCSV(';')\t\t OK" << endl;
    cout << h2 << endl;
    cout << "OBJETO tX VALIDADO COM SUCESSO" << endl;
    cout << h2 << endl;

    cout << "VALIDANDO tY..." << endl;
    cout << h2 << endl;

    if (tY.getDDI() != 55)
        return false;
    if (tY.getDDD() != 68)
        return false;
    if (tY.getNumero() != 33445566)
        return false;
    if (tY.toString() != "+55(68)3344-5566")
        return false;
    if (tY.toCSV(';') != "55;68;33445566")
        return false;
    
    cout << "tY.getDDI()\t\t OK" << endl;
    cout << "tY.getDDD()\t\t OK" << endl;
    cout << "tY.getNumero()\t\t OK" << endl;
    cout << "tY.toString()\t\t OK" << endl;
    cout << "tY.toCSV(';')\t\t OK" << endl;
    cout << h2 << endl;
    cout << "OBJETO tY VALIDADO COM SUCESSO" << endl;
    cout << h2 << endl;

    tZ = tX;

    cout << "VALIDANDO SOBRECARGA DE OPERADOR..." << endl;
    cout << h2 << endl;

    if (!(tZ == tX))
        return false;
    if (tZ == tY)
        return false;

    cout << "(!(tZ == tX))\t\t OK" << endl;
    cout << "(tZ == tY)\t\t OK" << endl;
    cout << h2 << endl;
    cout << "SOBRECARGA OPERADOR VALIDADA COM SUCESSO" << endl;
    cout << h2 << endl;

    cout << "ENCERRANDO TESTES..." << endl;
    cout << h1 << endl;
    cout << "=== TESTES FINALIZADOS COM SUCESSO =======" << endl;
    cout << h1 << endl;

    return true;
}

void runTestTelefone() {
    bool statusTestTelefone = testTelefone();
    cout << "Telefone:\t\t" << (statusTestTelefone?"OK":"FALHOU") << endl;
}

int main () {
    runTestTelefone();
    return 0;
}