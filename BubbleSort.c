#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int a[], int tamanho);

int vezes = 0;

int main(void)
{ 
  int i;
  srand(time(0));
  int tamanho = 100000;
  int a[tamanho];

  for(i = 0; i < tamanho; i++)
  {
    a[i] = rand();
  }

  bubble_sort(a, tamanho);
  
  //Da o output do array para ver se foi trocado
  for (int i = 0; i < tamanho; i++)
    printf("a[%d] = %d\n", i, a[i]);
    printf("\n");
    printf("rodou %d vezes", vezes);

  return 0;
}

//usa to tamanho do Array para trocar cada um dos valores com Bubble Sort
void bubble_sort(int a[], int tamanho)
{
  bool trocado = false;
  int i = 0;

  // o loop de fora vai rodar enquanto o array não estiver em ordem, se não ouver mais trocas a variavel trocado é alterado para false assim parando o loop
  do 
  {
    trocado = false;

    //loop de dentro olha todos os valores do array e se o proximo valor for maior que o valor anterior ele inverte os dois.
    for (int j = 0; j < (tamanho - 1 - i); j++)
    {
      if (a[j] > a[j + 1])
      {
        int Aux = a[j];
        a[j] = a[j + 1];
        a[j + 1] = Aux;
        trocado = true;
        vezes++;
      } 
      vezes++;
    }
    i++;
  } while (trocado);
}