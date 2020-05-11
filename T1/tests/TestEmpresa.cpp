#include "../header/Empresa.hpp"

#include <iostream>
#include <string>

using namespace std;

int testaEmpresa() {
    // Não testa toString(), pois o formato de saída não é rigoroso neste caso
    string csv="Supermercado Boa Praça;40.160.083/0001-09;1020306789;Rua da Esperança;1234;;Jardim Velho;Porto Alegre;RS;90123-456;55;51;34215678";
    
    Endereco end1;
    end1.setLogradouro("1");
    end1.setNumero("2");
    end1.setComplemento("3");
    end1.setBairro("4");
    end1.setCidade("5");
    end1.setUF("6");
    end1.setCEP("7");
    Endereco end2;
    end2.setLogradouro("Rua da Esperança");
    end2.setNumero("1234");
    end2.setComplemento("");
    end2.setBairro("Jardim Velho");
    end2.setCidade("Porto Alegre");
    end2.setUF("RS");
    end2.setCEP("90123-456");
    Endereco end3 = end2;
    
    Telefone tel1;
    tel1.setDDI(1);
    tel1.setDDD(2);
    tel1.setNumero(3);
    Telefone tel2;
    tel2.setDDI(55);
    tel2.setDDD(51);
    tel2.setNumero(34215678);
    Telefone tel3 = tel2;
    
    Empresa emp;
    emp.setNome("Supermercado Boa ");
    emp.setCNPJ("15305817000145");
    emp.setInscEst("102030");
    emp.setEndereco(&end1);
    emp.setTelefone(&tel1);

    string s;
    s = emp.getNome();
    emp.setNome(s+"Praça");
    s = emp.getCNPJ();
    if (s != "15.305.817/0001-45")
        return 0;
    emp.setCNPJ("40.160.083/0001-09");
    s = emp.getInscEst();
    emp.setInscEst(s+"6789");
    Endereco *pEnd = emp.getEndereco();
    if (pEnd->toCSV() != "1;2;3;4;5;6;7")
        return 0;
    emp.setEndereco(&end2);
    Telefone *pTel = emp.getTelefone();
    if (pTel->toCSV() != "1;2;3")
        return 0;
    emp.setTelefone(&tel2);

    if (emp.toCSV() != csv)
        return 0;

    Empresa emp3;
    emp3.setNome("Supermercado Boa Praça");
    emp3.setCNPJ("40160083000109");
    emp3.setInscEst("1020306789");
    emp3.setEndereco(&end3);
    emp3.setTelefone(&tel3);

	if	(!(emp == emp3))
		return 0;
    emp3.setInscEst("1020306788");
	if	(emp == emp3)
		return 0;

    return 1;
}

int main()
{
    cout << "Empresa:\t\t" << (testaEmpresa()?"OK":"FALHOU") << endl;
    return 0;
}