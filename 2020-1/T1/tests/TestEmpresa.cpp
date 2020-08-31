#include "../header/Empresa.hpp"

#include <iostream>
#include <string>

using namespace std;

int testaEmpresa() {
    // Não testa toString(), pois o formato de saída não é rigoroso neste caso
    string csv="Supermercado Boa Praça;40.160.083/0001-09;1020306789;Rua da Esperança;1234;;Jardim Velho;Porto Alegre;RS;90123-456;55;51;34215678";
    
    cout << "PASSOU AQUI 1" << endl;

    Endereco end1;
    end1.setLogradouro("1");
    end1.setNumero("2");
    end1.setComplemento("3");
    end1.setBairro("4");
    end1.setCidade("5");
    end1.setUF("6");
    end1.setCEP("7");
    
    cout << "PASSOU AQUI 2" << endl;
    
    Endereco end2;
    end2.setLogradouro("Rua da Esperança");
    end2.setNumero("1234");
    end2.setComplemento("");
    end2.setBairro("Jardim Velho");
    end2.setCidade("Porto Alegre");
    end2.setUF("RS");
    end2.setCEP("90123-456");
    
    cout << "PASSOU AQUI 3" << endl;
    
    cout << end2.toCSV() << endl;

    Endereco end3 = end2;
    
    cout << end3.toCSV() << endl;

    cout << "PASSOU AQUI 4" << endl;

    Telefone tel1;
    tel1.setDDI(1);
    tel1.setDDD(2);
    tel1.setNumero(3);
    
    cout << "PASSOU AQUI 5" << endl;
    
    Telefone tel2;
    tel2.setDDI(55);
    tel2.setDDD(51);
    tel2.setNumero(34215678);
    
    cout << "PASSOU AQUI 6" << endl;
    
    cout << tel2.toCSV() << endl;

    //Telefone tel3;
    //tel3 = tel2;
    
    Telefone tel3 = tel2;

    cout << tel3.toCSV() << endl;
    cout << tel3.getDDI() << endl;
    cout << tel3.getDDD() << endl;
    cout << tel3.getNumero() << endl;
    
    cout << "PASSOU AQUI 7" << endl;

    Empresa emp;
    emp.setNome("Supermercado Boa ");
    emp.setCNPJ("15305817000145");
    emp.setInscEst("102030");
    emp.setEndereco(&end1);
    emp.setTelefone(&tel1);

    cout << "PASSOU AQUI 8" << endl;

    string s;
    s = emp.getNome();
    cout << "PASSOU AQUI 9" << endl;
    emp.setNome(s+"Praça");
    s = emp.getCNPJ();
    cout << "PASSOU AQUI 10" << endl;
    if (s != "15.305.817/0001-45")
        return 0;
    cout << "PASSOU AQUI 11" << endl;
    emp.setCNPJ("40.160.083/0001-09");
    cout << "PASSOU AQUI 12" << endl;
    s = emp.getInscEst();
    cout << "PASSOU AQUI 13" << endl;
    emp.setInscEst(s+"6789");
    cout << "PASSOU AQUI 14" << endl;
    Endereco *pEnd = emp.getEndereco();
    cout << "PASSOU AQUI 15" << endl;
    if (pEnd->toCSV() != "1;2;3;4;5;6;7")
        return 0;
    cout << "PASSOU AQUI 16" << endl;
    emp.setEndereco(&end2);
    cout << "PASSOU AQUI 17" << endl;
    Telefone *pTel = emp.getTelefone();
    if (pTel->toCSV() != "1;2;3")
        return 0;
    cout << "PASSOU AQUI 18" << endl;
    emp.setTelefone(&tel2);

    cout << "PASSOU AQUI 19v1" << endl;

    string xyz = emp.toCSV();
    cout << "PASSOU AQUI 19v2" << endl;
    cout << xyz << endl;
    cout << "PASSOU AQUI 19v3" << endl;
    if (emp.toCSV() != csv)
        return 0;

    cout << "PASSOU AQUI 20" << endl;

    Empresa emp3;
    cout << "PASSOU AQUI 21" << endl;
    emp3.setNome("Supermercado Boa Praça");
    cout << "PASSOU AQUI 22" << endl;
    emp3.setCNPJ("40160083000109");
    cout << "PASSOU AQUI 23" << endl;
    emp3.setInscEst("1020306789");
    cout << "PASSOU AQUI 24" << endl;
    emp3.setEndereco(&end3);
    cout << "PASSOU AQUI 25" << endl;
    emp3.setTelefone(&tel3);
    cout << "PASSOU AQUI 26" << endl;

    cout << emp.toString() << endl;
    cout << emp3.toString() << endl;
    cout << emp.toCSV() << endl;
    cout << emp3.toCSV() << endl;

    cout << "PASSOU AQUI 26.1" << endl;

    cout << emp.getTelefone()->toString() << endl;
    cout << emp3.getTelefone()->toString() << endl;

    if (emp == emp3) {
        cout << "IGUAL" << endl;
    }

	if	(!(emp == emp3)) {
        cout << "PASSOU AQUI 26.2" << endl;
		return 0;
    }
    
    cout << "PASSOU AQUI 27" << endl;
    emp3.setInscEst("1020306788");
    cout << "PASSOU AQUI 28" << endl;
	if	(emp == emp3)
		return 0;

    
    cout << "PASSOU AQUI 29" << endl;

    return 1;
}

int main()
{
    cout << "Empresa:\t\t" << (testaEmpresa()?"OK":"FALHOU") << endl;
    return 0;
}