#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // rand() e srand()
#include <chrono>  // medicao de tempo
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void ordenar(vector<int> &v)
{
    int n = static_cast<int>(v.size());
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int valor = v[i];
            int j = i;
            while (j >= gap && v[j - gap] > valor)
            {
                v[j] = v[j - gap];
                j -= gap;
            }
            v[j] = valor;
        }
    }
}

int main()
{
    int tamanho;
    cout << "Quantos numeros no vetor? ";
    cin >> tamanho;
    if (!cin || tamanho <= 0)
    {
        cout << "Tamanho invalido!\n";
        return 1;
    }

    // Mesma semente nos 6 programas = mesmas entradas ao comparar algoritmos.
    srand(12345);

    const int repeticoes = 10;
    double soma = 0.0;
    string nomeArquivo = "ShellSort_" + to_string(tamanho) + ".csv";
    ofstream csv(nomeArquivo);
    if (!csv)
    {
        cerr << "Erro ao criar o CSV.\n";
        return 1;
    }
    csv << "Algoritmo;Tamanho;Execucao;Tempo (ms)\n";

    cout << fixed << setprecision(6);
    for (int execucao = 1; execucao <= repeticoes; execucao++)
    {
        // Geracao aleatoria: FORA da medicao de tempo.
        vector<int> numeros(tamanho);
        for (int i = 0; i < tamanho; i++)
        {
            numeros[i] = rand();
        }

        auto inicio = chrono::steady_clock::now();
        ordenar(numeros);
        auto fim = chrono::steady_clock::now();

        double tempoMs = chrono::duration<double, milli>(fim - inicio).count();
        soma += tempoMs;

        if (!is_sorted(numeros.begin(), numeros.end()))
        {
            cerr << "Erro: vetor nao foi ordenado!\n";
            return 1;
        }

        cout << "Execucao " << execucao << ": " << tempoMs << " ms\n";
        csv << "ShellSort;" << tamanho << ";" << execucao << ";"
            << fixed << setprecision(6) << tempoMs << "\n";

        // Mostra o vetor apenas quando for pequeno.
        if (tamanho <= 20 && execucao == 1)
        {
            cout << "Vetor ordenado: ";
            for (int numero : numeros)
                cout << numero << " ";
            cout << "\n";
        }
    }

    cout << "Media das 10 execucoes: " << soma / repeticoes << " ms\n";
    cout << "Resultados salvos em:" + nomeArquivo + ".csv\n";
    return 0;
}
