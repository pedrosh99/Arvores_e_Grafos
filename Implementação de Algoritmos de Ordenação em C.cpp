// Acadêmico: Pedro Henrique Garcia Dos Santos
// Matrícula: 2412276
// Matéria: Árvores e Grafos
// Professor: Vinícius Siqueira
// Período: 5°
// Objetivo: Atividade Avaliativa - Implementação de Algoritmos de Ordenação em C

// ==> BIBLIOTECAS
#include <stdio.h> // Entrada e saída padrão (printf, scanf)
#include <stdlib.h> // Funções gerais (rand, srand, EXIT_SUCCESS)
#include <time.h> // Funções para medir tempo (clock, time)
#include <locale.h> // Configuração de idioma/localização
#include <string.h> // Manipulação de strings (não usada diretamente)
#include <math.h> // Funções matemáticas (não usada diretamente)
#include <limits.h> // Limites de tipos (não usada diretamente)

// ==> FUNÇÃO AUXILIAR: printArray
// ==> Imprime os elementos do array na tela
void printArray(int arr[], int size){
    // Percorre o vetor do índice 0 até size-1
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]); // Imprime cada elemento
    }
    printf("\n"); // Quebra de linha ao final
}

// ==> BUBBLE SORT
// ==> Algoritmo simples que compara elementos adjacentes
// ==> Complexidade: O(n²)
void bubbleSort(int arr[], int size){
    // Laço externo controla número de passadas
    for(int i = 0; i < size - 1; i++){
        // Laço interno faz as comparações
        for(int j = 0; j < size - i - 1; j++){
            // Se o elemento atual for maior que o próximo
            if(arr[j] > arr[j+1]){
                // Troca os elementos
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


// ==> SELECTION SORT
// ==> Seleciona o menor elemento e coloca na posição correta
// ==> Complexidade: O(n²)
void selectionSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        // Assume que o menor elemento está na posição atual
        int minIndex = i;
        // Procura o menor elemento restante
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        // Troca o menor encontrado com a posição atual
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}


// ==> INSERTION SORT
// ==> Insere cada elemento na posição correta
// ==> Complexidade: O(n²)
void insertionSort(int arr[], int size){
    // Começa do segundo elemento
    for(int i = 1; i < size; i++){
        int key = arr[i]; // Elemento a ser inserido
        int j = i - 1;

        // Move os elementos maiores para a direita
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        // Insere o elemento na posição correta
        arr[j + 1] = key;
    }
}


// ==> QUICK SORT
// ==> Algoritmo recursivo baseado em divisão e conquista
// ==> Complexidade média: O(n log n)
// Função que organiza o vetor em torno de um pivô
int partition(int arr[], int low, int high){
    int pivot = arr[high]; // Escolhe o último elemento como pivô
    int i = low - 1;

    for(int j = low; j < high; j++){
        // Se elemento atual for menor que o pivô
        if(arr[j] < pivot){
            i++;
            // Troca elementos
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Coloca o pivô na posição correta
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i + 1; // Retorna índice do pivô
}

// Função recursiva do QuickSort
void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


// ==> MERGE SORT
// ==> Algoritmo recursivo baseado em divisão e conquista
// ==> Complexidade: O(n log n)
// Função que une duas partes ordenadas
void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1; // Tamanho da parte esquerda
    int n2 = right - mid; // Tamanho da parte direita

    int L[n1], R[n2]; // Vetores temporários

    // Copia dados para vetores auxiliares
    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Junta os vetores de forma ordenada
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copia elementos restantes
    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

// Função recursiva do MergeSort
void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


// ==> SHELL SORT
// ==> Versão otimizada do Insertion Sort
// ==> Complexidade média: ~ O(n^1.5)
void shellSort(int arr[], int size){
    for(int gap = size/2; gap > 0; gap /= 2){
        for(int i = gap; i < size; i++){
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// ==> FUNÇÃO copyArray
// ==> Copia o vetor original para outro vetor
// ==> (garante comparação justa entre algoritmos)
void copyArray(int source[], int dest[], int size){
    for(int i = 0; i < size; i++){
        dest[i] = source[i];
    }
}

// ==> MAIN
int main(int argc, char *argv[]){

    setlocale(LC_ALL, "Portuguese"); // Define idioma

    int size;
    printf("Digite o tamanho do array: ");
    scanf("%d", &size);

    // Validação do tamanho
    if(size <= 0){
        printf("Tamanho inválido!\n");
        return EXIT_FAILURE;
    }

    int original[size]; // Vetor original
    int arr[size]; // Vetor auxiliar para ordenação

    srand(time(NULL)); // Inicializa gerador aleatório

    // Preenche vetor com números aleatórios
    for(int i = 0; i < size; i++){
        original[i] = rand() % 1000;
    }

    int option;
    clock_t start, end; // Variáveis para medir tempo

    // Menu interativo
    do{
        puts("\n===== MENU =====");
        puts("1 - Bubble Sort");
        puts("2 - Selection Sort");
        puts("3 - Insertion Sort");
        puts("4 - Quick Sort");
        puts("5 - Merge Sort");
        puts("6 - Shell Sort");
        puts("7 - Executar TODOS");
        puts("0 - Sair");
        printf("Escolha: ");
        scanf("%d", &option);

        switch(option){

            case 1:
                copyArray(original, arr, size);
                start = clock();
                bubbleSort(arr, size);
                end = clock();
                printf("Tempo Bubble Sort: %f segundos\n", ((double)(end - start))/CLOCKS_PER_SEC);
                break;

            case 2:
                copyArray(original, arr, size);
                start = clock();
                selectionSort(arr, size);
                end = clock();
                printf("Tempo Selection Sort: %f segundos\n", ((double)(end - start))/CLOCKS_PER_SEC);
                break;

            case 3:
                copyArray(original, arr, size);
                start = clock();
                insertionSort(arr, size);
                end = clock();
                printf("Tempo Insertion Sort: %f segundos\n", ((double)(end - start))/CLOCKS_PER_SEC);
                break;

            case 4:
                copyArray(original, arr, size);
                start = clock();
                quickSort(arr, 0, size - 1);
                end = clock();
                printf("Tempo Quick Sort: %f segundos\n", ((double)(end - start))/CLOCKS_PER_SEC);
                break;

            case 5:
                copyArray(original, arr, size);
                start = clock();
                mergeSort(arr, 0, size - 1);
                end = clock();
                printf("Tempo Merge Sort: %f segundos\n", ((double)(end - start))/CLOCKS_PER_SEC);
                break;

            case 6:
                copyArray(original, arr, size);
                start = clock();
                shellSort(arr, size);
                end = clock();
                printf("Tempo Shell Sort: %f segundos\n", ((double)(end - start))/CLOCKS_PER_SEC);
                break;

            case 7:
                printf("\nExecutando todos...\n");
                copyArray(original, arr, size);
                start = clock(); bubbleSort(arr, size); end = clock();
                printf("Bubble: %f s\n", ((double)(end-start))/CLOCKS_PER_SEC);

                copyArray(original, arr, size);
                start = clock(); selectionSort(arr, size); end = clock();
                printf("Selection: %f s\n", ((double)(end-start))/CLOCKS_PER_SEC);

                copyArray(original, arr, size);
                start = clock(); insertionSort(arr, size); end = clock();
                printf("Insertion: %f s\n", ((double)(end-start))/CLOCKS_PER_SEC);

                copyArray(original, arr, size);
                start = clock(); quickSort(arr,0,size-1); end = clock();
                printf("Quick: %f s\n", ((double)(end-start))/CLOCKS_PER_SEC);

                copyArray(original, arr, size);
                start = clock(); mergeSort(arr,0,size-1); end = clock();
                printf("Merge: %f s\n", ((double)(end-start))/CLOCKS_PER_SEC);

                copyArray(original, arr, size);
                start = clock(); shellSort(arr,size); end = clock();
                printf("Shell: %f s\n", ((double)(end-start))/CLOCKS_PER_SEC);
                break;
        }

    }while(option != 0);

    // ==> Fim
    puts("Software feito pelo o acadêmico: Pedro Henrique Garcia Dos Santos\n");

    return EXIT_SUCCESS;
}