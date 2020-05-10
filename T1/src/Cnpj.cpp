#include "../header/Cnpj.hpp"

#include <iostream>
#include <cctype>
#include <array>

using namespace std;

Cnpj::Cnpj()
{
	setRaiz("00000000");
	setFilial("0000");
	setDV("00");
}

Cnpj::Cnpj(string raiz, string filial, string dv)
{
	setRaiz(raiz);
	setFilial(filial);
	setDV(dv);
}

Cnpj::Cnpj(Cnpj& cnpj)
{
	setRaiz(cnpj.getRaiz());
	setFilial(cnpj.getFilial());
	setDV(cnpj.getDV());	
}

string Cnpj::getRaiz() { return raiz; }
void Cnpj::setRaiz(string raiz) { this->raiz = raiz; }

string Cnpj::getFilial() { return filial; }
void Cnpj::setFilial(string filial) { this->filial = filial; }

string Cnpj::getDV() { return dv; }
void Cnpj::setDV(string dv) { this->dv = dv; }

bool Cnpj::setCnpj(string cnpj)
{
	if (!isValid(cnpj))
		return false;

	array<string, 3> ss;
	string subStrRaiz;
	string subStrFilial;
	string subStrDV;

	if (cnpj.size() == 18)
	{
		ss[0] = cnpj.substr(0, 2);
		ss[1] = cnpj.substr(3, 3);
		ss[2] = cnpj.substr(7, 3);
		subStrRaiz = ss[0] + ss[1] + ss[2];
		subStrFilial = cnpj.substr(11, 4);
		subStrDV = cnpj.substr(16, 2);
	}
	else
	{
		subStrRaiz = cnpj.substr(0, 8);
		subStrFilial = cnpj.substr(8, 4);
		subStrDV = cnpj.substr(12, 2);
	}

	setRaiz(subStrRaiz);
	setFilial(subStrFilial);
	setDV(subStrDV);

	return true;
}

bool Cnpj::isValid(string cnpj) {
	if	(cnpj.size()==18) { // 00.000.000/0000-00
		if	(cnpj.at(2)!='.' || cnpj.at(6)!='.' || cnpj.at(10)!='/' || cnpj.at(15)!='-')
			return false;
		cnpj = cnpj.substr(0,2) + cnpj.substr(3,3) + cnpj.substr(7,3) +
		       cnpj.substr(11,4) + cnpj.substr(16,2);
	}
	if (cnpj.size()==14) {
		for	(int i=0; i<14; ++i)
			if	(!isdigit(cnpj.at(i)))
				return false;
		int peso1[] = {5,4,3,2,9,8,7,6,5,4,3,2};
		int soma = 0;
		for	(int i=0; i<12; ++i)
			soma += (cnpj.at(i)-'0') * peso1[i];
		int div = soma / 11;
		int resto = soma % 11;
		char dv1;
		if	(resto < 2)
			dv1 = '0';
		else
			dv1 = 11 - resto + '0';
		if	(dv1 != cnpj.at(12))
			return false;
		int peso2[] = {6,5,4,3,2,9,8,7,6,5,4,3,2};
		soma = 0;
		for	(int i=0; i<13; ++i)
			soma += (cnpj.at(i)-'0') * peso2[i];
		div = soma / 11;
		resto = soma % 11;
		char dv2;
		if	(resto < 2)
			dv2 = '0';
		else
			dv2 = 11 - resto + '0';
		if	(dv2 != cnpj.at(13))
			return false;
		return true;
	}
	else
		return false;
}

string Cnpj::toString()
{
	return this->getRaiz().substr(0, 2) +
		   "." +
		   this->getRaiz().substr(2, 3) +
		   "." +
		   this->getRaiz().substr(5, 3) +
		   "/" +
		   this->getFilial() +
		   "-" +
		   this->getDV();
}

bool Cnpj::operator==(Cnpj &cnpj)
{
	return (this->getRaiz() == cnpj.getRaiz() &&
			this->getFilial() == cnpj.getFilial() &&
			this->getDV() == cnpj.getDV());
}
