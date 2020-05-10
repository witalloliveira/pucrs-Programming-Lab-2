#include "../header/Endereco.hpp"

#include <iostream>
#include <string>

int testaEndereco()
{
    // Não testa toString(), pois o formato de saída não é rigoroso neste caso
    string csv = "Rua da Esperança;1234;s/c;Jardim Velho;Porto Alegre;RS;90123-456";
    Endereco e1;
    e1.setLogradouro("Rua da ");
    e1.setNumero("123");
    e1.setComplemento("s/");
    e1.setBairro("Jardim ");
    e1.setCidade("Porto ");
    e1.setUF("R");
    e1.setCEP("90123-");
    string s;
    s = e1.getLogradouro();
    e1.setLogradouro(s + "Esperança");
    s = e1.getNumero();
    e1.setNumero(s + "4");
    s = e1.getComplemento();
    e1.setComplemento(s + "c");
    s = e1.getBairro();
    e1.setBairro(s + "Velho");
    s = e1.getCidade();
    e1.setCidade(s + "Alegre");
    s = e1.getUF();
    e1.setUF(s + "S");
    s = e1.getCEP();
    e1.setCEP(s + "456");
    Endereco e2 = e1;
    if (!(e1 == e2))
        return 0;
    e2.setComplemento("");
    if (e1 == e2)
        return 0;
    if (e1.toCSV() != csv)
        return 0;
    return 1;
}

int main()
{
    cout << "Endereco:\t\t" << (testaEndereco() ? "OK" : "FALHOU") << endl;
    return 0;
}