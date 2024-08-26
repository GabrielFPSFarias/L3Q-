#include <stdio.h>

void trocar(int* a, int* b){
  int c;
  c = *a;
  *a = *b;
  *b = c;
}

int retornarIndicePai(i){
  return (i + 1) / 2 - 1;
}

int retornarIndiceFilhoEsquerda(i){
  return 2 * (i + 1) - 1;
}

int retornarIndiceFilhoDireita(i){
  return 2 * (i + 1);
}

void maxHeapfy(int* A, int i, int M, int* t){
  int l = retornarIndiceFilhoEsquerda(i);
  int r = retornarIndiceFilhoDireita(i);
  int maior = i;
  if(l <= M && A[l] > A[i]){
    maior = l;
    }
  if(r <= M && A[r] > A[maior]){
    maior = r;
  }
  if(maior != i){
    trocar(&A[i], &A[maior]);
    *t = *t + 1;
  }
  for(int j = 0; j < M; j++){
    printf("%i ", A[j]);
  }
  printf("\n");
  if(maior != i){
      maxHeapfy(A, maior, M, t);
  }
}

void construirMaxHeap(int* A, int M, int* t){
  for(int i = M / 2 - 1; i >= 0; i--){
    maxHeapfy(A, i, M, t);
  }
}

int main(void) {
  int M = 0;
  int t = 0;
  do{
    printf("Digite o tamanho da lista: ");
    scanf("%i", &M);
    getchar();
    if(M < 1){
      printf("Valor inválido!\n");
    }
  }while(M < 1);
  int A[M];
  for(int i = 0; i < M; i++){
    printf("Digite o %iº valor: ", i + 1);
    scanf("%i", &A[i]);
    getchar();
  }
  printf("\nVetor original: ");
  for(int i = 0; i < M; i++){
    printf("%i ", A[i]);
  }
  printf("\n");
  construirMaxHeap(A, M, &t);
  printf("\nNº de trocas: %i\nResultado: ", t);
  for(int i = 0; i < M; i++){
    printf("%i ", A[i]);
  }
  return 0;
}
