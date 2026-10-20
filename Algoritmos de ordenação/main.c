#include <stdio.h>
#define N 10

void bubble(int v[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1]) { int t = v[j]; v[j] = v[j + 1]; v[j + 1] = t; }
}

void insertion(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i], j = i - 1;
        while (j >= 0 && v[j] > chave) { v[j + 1] = v[j]; j--; }
        v[j + 1] = chave;
    }
}

void selection(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[min]) min = j;
        int t = v[i]; v[i] = v[min]; v[min] = t;
    }
}

void merge(int v[], int ini, int fim) {
    if (ini >= fim) return;
    int meio = (ini + fim) / 2;
    merge(v, ini, meio);
    merge(v, meio + 1, fim);
    int aux[N], i = ini, j = meio + 1, k = 0;
    while (i <= meio && j <= fim) aux[k++] = (v[i] <= v[j]) ? v[i++] : v[j++];
    while (i <= meio) aux[k++] = v[i++];
    while (j <= fim)  aux[k++] = v[j++];
    for (i = ini, k = 0; i <= fim; i++, k++) v[i] = aux[k];
}

void quick(int v[], int ini, int fim) {
    int i = ini, j = fim, pivo = v[(ini + fim) / 2];
    while (i <= j) {
        while (v[i] < pivo) i++;
        while (v[j] > pivo) j--;
        if (i <= j) { int t = v[i]; v[i] = v[j]; v[j] = t; i++; j--; }
    }
    if (ini < j) quick(v, ini, j);
    if (i < fim) quick(v, i, fim);
}

void gravar(const char *nome, int v[], int n) {
    FILE *f = fopen(nome, "w");
    for (int i = 0; i < n; i++) fprintf(f, "%d\n", v[i]);
    fclose(f);
}

int ler(const char *nome, int v[]) {
    FILE *f = fopen(nome, "r");
    int n = 0;
    while (n < N && fscanf(f, "%d", &v[n]) == 1) n++;
    fclose(f);
    return n;
}

void mostrar(const char *titulo, int v[], int n) {
    printf("%s: ", titulo);
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");
}

void ordenar() {
    int v[N], op, n = ler("dados.txt", v);
    mostrar("Original", v, n);

    printf("1-Bubble 2-Insertion 3-Selection 4-Merge 5-Quick: ");
    scanf("%d", &op);

    switch (op) {
        case 1: bubble(v, n); break;
        case 2: insertion(v, n); break;
        case 3: selection(v, n); break;
        case 4: merge(v, 0, n - 1); break;
        case 5: quick(v, 0, n - 1); break;
        default: printf("Opcao invalida!\n"); return;
    }
    gravar("ordenado.txt", v, n);
    mostrar("Ordenado", v, n);
}

void alterar() {
    int v[N], pos, novo, n = ler("dados.txt", v);
    mostrar("Dados atuais", v, n);

    printf("Posicao (1 a %d) e novo valor: ", n);
    scanf("%d %d", &pos, &novo);

    if (pos < 1 || pos > n) { printf("Posicao invalida!\n"); return; }

    v[pos - 1] = novo;
    gravar("dados.txt", v, n);
    ordenar();
}

int main() {
    int inicial[N] = {9, 3, 7, 1, 8, 2, 6, 4, 10, 5};
    int op;

    gravar("dados.txt", inicial, N);

    do {
        printf("\n1-Ordenar  2-Alterar valor  0-Sair\nOpcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1: ordenar(); break;
            case 2: alterar(); break;
            case 0: printf("Ate logo!\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (op != 0);

    return 0;
}