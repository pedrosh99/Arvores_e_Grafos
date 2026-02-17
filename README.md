// Acadêmico: Pedro Henrique Garcia Dos Santos
// Matrícula: 2412276
// Matéria: Árvores e Grafos
// Professor: Vinícius Siqueira
// Objetivo: Atividade Prática - Fase 1 - Semana 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <limits.h>

void preencherVetorDecrescente(int *vetor,int tamanho){
    int i;
    for(i=0; i<tamanho; i++){
        vetor[i] = tamanho - i;
    }
}

void bubbleSort(int *vetor,int tamanho,int *comparacoes,int *movimentacoes){
    int i,j,temp;
    *comparacoes = 0;
    *movimentacoes = 0;

    for(i=0; i < tamanho - 1; i++){
        for(j=0; j < tamanho - i - 1; j++){
            (*comparacoes)++;
            if(vetor[j] > vetor[j + 1]){
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                *movimentacoes += 3;
            }
        }
    }
}

void selectionSort(int *vetor,int tamanho,int *comparacoes,int *movimentacoes){
    int i,j,min,temp;
    *comparacoes = 0;
    *movimentacoes = 0;

    for(i=0; i < tamanho - 1; i++){
        min = i;
        for(j = i + 1; j<tamanho; j++){
            (*comparacoes)++;
            if(vetor[j]<vetor[min]){
                min = j;
            }
        }
        if(min!=i){
            temp = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = temp;
            *movimentacoes += 3;
        }
    }
}

void executarTeste(const char *algoritmo,void (*sortFunction)(int *,int,int *,int *),int tamanho){
    int *vetor = (int *)malloc(tamanho*sizeof(int));
    if(vetor == NULL) 
    return;

    int comparacoes,movimentacoes;
    clock_t inicio,fim;
    double tempo;
    
    preencherVetorDecrescente(vetor,tamanho);
    
    inicio = clock();
    sortFunction(vetor,tamanho,&comparacoes,&movimentacoes);
    fim = clock();
    
    tempo = ((double)(fim - inicio)*1000.0) / CLOCKS_PER_SEC;
    
    printf("| %-14s | %-7d | %-10.3f | %-12d | %-14d |\n",algoritmo,tamanho,tempo,comparacoes,movimentacoes);
    
    free(vetor);
}

int main(int argc,char *argv[]){
  
    setlocale(LC_ALL,"Portuguese");
    
    puts("Tabela de Valores:\n");
    puts("| Algoritmo      | Tamanho | Tempo (ms) | Comparações  | Movimentações  |");
    puts("|----------------|---------|------------|--------------|----------------|");
    
    // ==> Testes com 100 elementos
    executarTeste("Bubble Sort",bubbleSort,100);
    executarTeste("Selection Sort",selectionSort,100);
    puts("|----------------|---------|------------|--------------|----------------|");
    
    // ==> Testes com 1.000 elementos
    executarTeste("Bubble Sort",bubbleSort,1000);
    executarTeste("Selection Sort",selectionSort,1000);
    puts("|----------------|---------|------------|--------------|----------------|");
    
    // ==> Testes com 10.000 elementos
    executarTeste("Bubble Sort",bubbleSort,10000);
    executarTeste("Selection Sort",selectionSort,10000);
    puts("|----------------|---------|------------|--------------|----------------|\n");
    
    // ==> Fim
    puts("Software feito pelo o acadêmico: Pedro Henrique Garcia Dos Santos\n");
    
    return EXIT_SUCCESS;
}
