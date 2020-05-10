#ifndef __CNPJ_HPP__
#define __CNPJ_HPP__

#include <string>

using namespace std;

class Cnpj
{
private:
	string raiz;
	string filial;
	string dv;

public:
	Cnpj();
	Cnpj(string raiz, string filial, string dv);
	Cnpj(Cnpj& cnpj);

	string getRaiz();
	void setRaiz(string raiz);

	string getFilial();
	void setFilial(string filial);

	string getDV();
	void setDV(string dv);

	bool setCnpj(string cnpj);

	static bool isValid(string cnpj);

	string toString();

	bool operator==(Cnpj &cnpj);
};

#endif // __CNPJ_HPP__
