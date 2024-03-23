#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int vezes = 0;

void merge_sort(int a[], int tamanho);
void merge_sort_recursividade(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);

int main()
{
  int i;
  srand(time(0));
  int tamanho = 100000;
  int a[tamanho];

  for(i = 0; i < tamanho; i++)
  {
    a[i] = rand();
  }

  // Função que trocara os valores do array
  merge_sort(a, tamanho);
  
  // Printa os valores do array no console
  for (int i = 0; i < tamanho; i++)
    printf("a[%d] = %d\n", i, a[i]);
    printf("\n");
    printf("rodou %d vezes", vezes);
  
  return 0;
}

// Performa o metodo de MergeSort no array
void merge_sort(int a[], int tamanho)
{
  // chama o metodo de recursividade do MergeSort pegando o valor 0 e o valor de tamanho - 1 para ver o array inteiro
  merge_sort_recursividade(a, 0, tamanho - 1);
}


void merge_sort_recursividade(int a[], int l, int r)
{
  // Recursividade é para quando l < r
  if (l < r)
  {
    // encontra o meio termo entre l e r
    int m = l + (r - l) / 2;
  
    // usa o metodo de recursividade para dividir o array em 2 partes a esquerda e a direita apartir do meio do array
    merge_sort_recursividade(a, l, m);
    merge_sort_recursividade(a, m + 1, r);
  
    //Unifica o array apos ele ter sido organizado pelo metodo.
    merge_sorted_arrays(a, l, m, r);
  }
  vezes++; 
}

// unifica o Array que foram organizados devolta ao Array "a" entre os indexes de l e r
void merge_sorted_arrays(int a[], int l, int m, int r)
{
  // calcula o tamanho das porçoes esquerda e direita do array
  int esquerda_tamanho = m - l + 1;
  int direita_tamanho = r - m;
  
  // cria arrays Auxiliares para armazenar essas partes
  int aux_esquerda[esquerda_tamanho];
  int aux_direita[direita_tamanho];
  
  int i, j, k;
  
  // copia a porção esquerda para o array auxiliar
  for (int i = 0; i < esquerda_tamanho; i++){
    aux_esquerda[i] = a[l + i];
    vezes++;
  }
  // Copia a porção direira para o array auxiliar
  for (int i = 0; i < direita_tamanho; i++){
    aux_direita[i] = a[m + 1 + i];
    vezes++;
    }
  
  // usando o index I para mover pelo aux_esquerda e J pelo aux_direita e K para checkar o array principal, assim que o array for organizado ele sera colocado na posição correta no Array A
  for (i = 0, j = 0, k = l; k <= r; k++)
  {
    if ((i < esquerda_tamanho) &&
        (j >= direita_tamanho || aux_esquerda[i] <= aux_direita[j]))
    {
      a[k] = aux_esquerda[i];
      i++;
    }
    // 
    else
    {
      a[k] = aux_direita[j];
      j++;
    }
    vezes++;
  }  
  vezes++; 
}
