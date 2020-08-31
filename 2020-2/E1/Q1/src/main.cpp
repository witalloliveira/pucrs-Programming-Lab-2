#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int matricula;
  double n1, n2, n3;
  double mediaExercicios, mediaAluno;
  string conceito;

  cout << "Informe a matricula do aluno: ";
  cin >> matricula;

  cout << "Informe a nota N1: ";
  cin >> n1;

  cout << "Informe a nota N2: ";
  cin >> n2;

  cout << "Informe a nota N3: ";
  cin >> n3;

  cout << "Informe a media dos Exercicios: ";
  cin >> mediaExercicios;

  mediaAluno = ((n1 + (2 * n2) + (3 * n3) + mediaExercicios) / 7);

  if (mediaAluno >= 9.0) {
    conceito = "A";
  } else if (mediaAluno < 9.0 && mediaAluno >= 7.5) {
    conceito = "B";
  } else if (mediaAluno < 7.5 && mediaAluno >= 6.0) {
    conceito = "C";
  } else if (mediaAluno < 6.0 && mediaAluno >= 4.0) {
    conceito = "D";
  } else {
    conceito = "E";
  }

  cout << setfill('0') << setw(10) << matricula;
  cout << " ";
  cout << fixed << setprecision(4) << mediaAluno;
  cout << " ";
  cout << conceito << endl;

  return 0;
}