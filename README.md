# Algoritmos de ordenacao com rand() (C++17)

Arquivos independentes: BubbleSort.cpp, MergeSort.cpp, QuickSort.cpp,
HeapSort.cpp, ShellSort.cpp e StraightSelection.cpp.

Cada programa pergunta o tamanho do vetor, gera 10 vetores diferentes com rand(),
ordena cada um, mede o tempo da ordenacao em milissegundos, verifica se estao
ordenados e calcula a media das 10 execucoes.

A semente srand(12345) e fixa para os seis algoritmos receberem os mesmos
valores em cada execucao, desde que o tamanho do vetor seja o mesmo.
So a ordenacao e cronometrada. A geracao e a verificacao ficam fora do tempo.

Compilar no terminal do VS Code (MinGW/G++):
    g++ -std=c++17 -O2 BubbleSort.cpp -o BubbleSort.exe
Executar no Windows PowerShell:
    .\BubbleSort.exe

Ao executar, informe 10, 100, 1000, 10000, 100000 ou 1000000.
Os resultados aparecem no terminal e sao salvos em NomeDoAlgoritmo_resultados.csv.
O CSV utiliza ponto como separador decimal e ponto-e-virgula como separador de campo.
Ao importar no Google Planilhas em portugues, configure o separador decimal se necessario.

ATENCAO: Bubble Sort e Straight Selection sao O(n^2), e 10 execucoes
com 100 mil/1 milhao de itens podem ser impraticavelmente demoradas.
