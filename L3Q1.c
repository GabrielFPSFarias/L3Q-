#include <stdio.h>

void merge(int* A, int p, int q, int r){
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1 + 1];
  int R[n2 + 1];
  for(int i = 0; i < n1; i++){
    L[i] = A[p + i];
  }
  for(int i = 0; i < n2; i++){
    R[i] = A[q + i + 1];
  }
  L[n1] = 2147483647;
  R[n2] = 2147483647;
  int i = 0;
  int j = 0;
  for(int k = p; k <= r; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
  }
}

void mergesort(int* A, int p, int r, int M){
  if(p < r){
    int q = (p + r) / 2; 
    mergesort(A, p, q, M);
    mergesort(A, q + 1, r, M);
    merge(A, p, q, r);
    printf("\n");
    for(int i = 0; i < M; i++){
      printf("%i ", A[i]);
    }
    printf("\n");
  }
}

int main(void) {
int M = 0;
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
  mergesort(A, 0, M - 1, M);
  printf("\nResultado: ");
  for(int i = 0; i < M; i++){
    printf("%i ", A[i]);
  }
  return 0;
}
