# Atividade 03: Ordenação e Arquivos em C

Este projeto é um programa em C que une dois assuntos vistos nas ultimas aulaa: algoritmos de ordenação e manipulação de arquivos. Ele grava números desordenados em um arquivo, lê esses dados, ordena com o algoritmo escolhido pelo usuário e salva o resultado em um novo arquivo.

## Como funciona

Ao iniciar, o programa cria o arquivo `dados.txt` com dez números desordenados. Em seguida, mostra um menu com as opções de ordenar, alterar um valor ou sair.

Na opção de ordenar, o programa lê os valores do `dados.txt` e pergunta qual algoritmo o usuário quer usar: Bubble Sort, Insertion Sort, Selection Sort, Merge Sort ou Quick Sort. Depois de ordenar, ele salva o resultado no arquivo `ordenado.txt` e mostra os valores na tela.

Na opção de alterar, o usuário informa a posição do valor que quer trocar e o novo valor. O programa atualiza o `dados.txt` e reordena os dados em seguida, gerando um novo `ordenado.txt`.

## Arquivos

O arquivo `main.c` contém todo o código do programa. O arquivo `dados.txt` guarda os valores originais, sem ordem, e é a entrada do programa. O arquivo `ordenado.txt` guarda os valores já ordenados e é criado ou atualizado a cada ordenação. Os dois arquivos de texto são gerados automaticamente na pasta onde o programa foi executado.
