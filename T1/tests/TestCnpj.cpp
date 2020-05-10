#include "../header/Cnpj.hpp"

#include <iostream>
#include <string>

using namespace std;

int testaCnpj() {
	// Teste para a classe Cnpj (return 0 significa que o teste falhou)s
	string s1 = "40.160.083/0001-09"; // CNPJ Valido
	if	(!Cnpj::isValid(s1))
	       	return 0;
	string s2 = "15305817000145"; // CNPJ Valido
	if	(!Cnpj::isValid(s2))
	       	return 0;
	if	(!Cnpj::isValid("11.444.777/0001-61")) // CNPJ Valido
		return 0;
	if	(Cnpj::isValid("11.444.777/0001-60")) // CNPJ Invalido
	       	return 0;
	if	(Cnpj::isValid("11.444.777/0001-62")) // CNPJ Invalido
	       	return 0;
	if	(Cnpj::isValid("0123456789abcd")) // CNPJ Invalido
		return 0;
	Cnpj cnpj1;
	cnpj1.setCnpj(s1);
	if	(cnpj1.toString() != s1)
		return 0;
	Cnpj cnpj2;
	cnpj2.setCnpj(s2);
	if	(cnpj2.getRaiz() != s2.substr(0,8) ||
		 cnpj2.getFilial() != s2.substr(8,4) ||
		 cnpj2.getDV() != s2.substr(12,2) )
		return 0;
	if	(cnpj1 == cnpj2)
		return 0;
	Cnpj cnpj3 = cnpj1;
	if	(!(cnpj1 == cnpj3))
		return 0;
	return 1;
}

int main()
{
    cout << "Cnpj:\t\t\t" << (testaCnpj()?"OK":"FALHOU") << endl;
    return 0;
}