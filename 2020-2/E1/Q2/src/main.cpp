#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

#define TAM 5

typedef vector<vector<int>> MatrizBidimensional;

int main()
{

    MatrizBidimensional matriz;
    vector<int> somatorioPorLinha(TAM);

    cout << endl
         << "MATRIZ " << TAM << "x" << TAM << endl;

    for (int i = 0; i < TAM; ++i)
    {
        vector<int> linha(TAM);

        for (int j = 0; j < TAM; ++j)
        {
            cout << "Informe um valor para a posicao ["
                 << i + 1 << "] x [" << j + 1 << "] : ";
            cin >> linha[j];
        }

        matriz.push_back(linha);
    }

    for (int i = 0; i < TAM; ++i)
    {
        int somatorioElementosLinha = 0;

        for (int j = 0; j < TAM; ++j)
        {
            somatorioElementosLinha += matriz[i][j];
            //cout << somatorioElementosLinha << endl;
        }

        somatorioPorLinha[i] = somatorioElementosLinha;
    }

    cout << endl
         << "ENTRADA" << endl;

    for (int i = 0; i < TAM; ++i)
    {
        for (int j = 0; j < TAM; ++j)
        {
            cout << matriz[i][j] << "\t";
        }
        //cout << " =\t" << somatorioPorLinha[i];
        cout << endl;
    }

    cout << endl
         << "SAIDA" << endl;

    for (int i = 0; i < TAM; ++i)
    {
        auto menorSomatorio = min_element(begin(somatorioPorLinha),
                                          end(somatorioPorLinha));

        for (int j = 0; j < TAM; ++j)
        {

            if (somatorioPorLinha[i] == *menorSomatorio && matriz[i][j] < 0.0)
            {
                matriz[i][j] = (matriz[i][j] * (-1));
            }

            cout << matriz[i][j] << "\t";
        }
        //cout << " =\t" << somatorioPorLinha[i];
        cout << endl;
    }

    return 0;
}