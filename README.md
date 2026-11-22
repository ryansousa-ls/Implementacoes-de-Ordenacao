# Algoritmos de ordenação em C++

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
executado. 


