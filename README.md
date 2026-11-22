# Algoritmos de ordenação em C++

Projeto para comparar o tempo de seis algoritmos: Bubble Sort, Merge Sort,
Quick Sort, Heap Sort, Shell Sort e Straight Selection (ordenação por seleção).
Cada arquivo `.cpp` é um programa independente.

## Como o código funciona

1. O `main()` solicita a quantidade de números, que deve ser um inteiro positivo.
2. Cria um `vector<int>` preenchido com números gerados por `rand()`.
3. Chama `ordenar()` e mede sua duração com `chrono::steady_clock`, em milissegundos.
4. Confere o resultado com `is_sorted()` e salva o tempo no CSV.
5. Repete o processo 10 vezes, gerando um novo vetor a cada repetição, e mostra a média no terminal.

A geração dos números, a conferência e a gravação do CSV ficam fora da medição.
Na primeira repetição, o vetor ordenado também aparece no terminal se tiver até 20 elementos.

## `rand()` e `srand()`

`rand()` gera números inteiros pseudoaleatórios entre `0` e `RAND_MAX`.
`srand(12345)` define uma semente fixa antes das 10 repetições: ao iniciar o
programa novamente, a sequência se repete. Assim, os seis algoritmos recebem
as mesmas entradas para o mesmo tamanho de vetor, usando a mesma implementação
de `rand()`. A semente não é reiniciada entre as repetições.

## Salvamento dos arquivos CSV

`ofstream csv(nomeArquivo)` cria o arquivo na pasta de onde o programa foi
executado. O nome inclui o algoritmo e o tamanho do vetor, por exemplo:
`BubbleSort_1000.csv`. No programa de seleção, o nome atual é
`StraighSelection_1000.csv`.

O arquivo contém um cabeçalho e 10 linhas de resultados. Exemplo ilustrativo:

```csv
Algoritmo;Tamanho;Execucao;Tempo (ms)
BubbleSort;1000;1;2.345678
```

Os campos são separados por `;` e os tempos usam ponto decimal e seis casas
decimais. O CSV guarda os tempos de cada repetição; a média aparece somente
no terminal. Ao executar novamente o mesmo algoritmo com o mesmo tamanho,
o arquivo anterior é sobrescrito. O arquivo é fechado automaticamente ao sair do `main()`.

## Como compilar e executar

Com G++ instalado, use o terminal PowerShell:

```powershell
g++ -std=c++17 -O2 BubbleSort.cpp -o BubbleSort.exe
.\BubbleSort.exe
```

Informe um tamanho positivo, como `10`, `100` ou `1000`. Para testar outro
algoritmo, troque o nome do arquivo e do executável nos comandos.
