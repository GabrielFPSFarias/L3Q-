#include <stdio.h>

void trocar(int* a, int* b){
  int c;
  c = *a;
  *a = *b;
  *b = c;
}

int particionar(int* A, int p, int r, int* t){
  int x = A[r];
  int i = p - 1;
  for(int j = p; j < r; j++){
    if(A[j] <= x){
      i++;
        trocar(&A[i], &A[j]);
        (*t)++;
    }
  }
    trocar(&A[i+1], &A[r]);
    (*t)++;
  return i + 1;
}

void quicksort(int* A, int p, int r, int* t, int M){
  if(p < r){
    int q = particionar(A, p, r, t);
    printf("\n");
    for(int i = 0; i < M; i++){
      printf("%i ", A[i]);
    }
    printf("\n");
    quicksort(A, p, q-1, t, M);
    quicksort(A, q+1, r, t, M);
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
  quicksort(A, 0, M-1, &t, M);
  printf("\nNº de trocas: %i\nResultado: ", t);
  for(int i = 0; i < M; i++){
    printf("%i ", A[i]);
  }
  return 0;
}
