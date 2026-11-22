#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // rand() e srand()
#include <chrono>  // medicao de tempo
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void mesclar(vector<int> &v, vector<int> &aux, int ini, int meio, int fim)
{
    int i = ini, j = meio + 1, k = ini;
    while (i <= meio && j <= fim)
        aux[k++] = (v[i] <= v[j]) ? v[i++] : v[j++];
    while (i <= meio)
        aux[k++] = v[i++];
    while (j <= fim)
        aux[k++] = v[j++];
    for (int p = ini; p <= fim; p++)
        v[p] = aux[p];
}

void mergeSort(vector<int> &v, vector<int> &aux, int ini, int fim)
{
    if (ini >= fim)
        return;
    int meio = ini + (fim - ini) / 2;
    mergeSort(v, aux, ini, meio);
    mergeSort(v, aux, meio + 1, fim);
    mesclar(v, aux, ini, meio, fim);
}

void ordenar(vector<int> &v)
{
    if (v.empty())
        return;
    vector<int> aux(v.size());
    mergeSort(v, aux, 0, static_cast<int>(v.size()) - 1);
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
    string nomeArquivo = "MergeSort_" + to_string(tamanho) + ".csv";
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
        csv << "MergeSort;" << tamanho << ";" << execucao << ";"
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
    cout << "Resultados salvos em: " + nomeArquivo + ".csv\n";
    return 0;
}
