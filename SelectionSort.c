//Selection Sort
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int vezes = 0;

int main()
{
  // array que contem os valores a serem trocados
  int i;
  srand(time(0));
  int tamanho = 100000;
  int a[tamanho];

  for(i = 0; i < tamanho; i++)
  {
    a[i] = rand();
  }

  
  for (int i = 0; i < tamanho - 1; i++)
  {
    //encontra o menor valor e a posição que ele esta no array
    int min_pos = i;
    for (int j = i + 1; j < tamanho; j++)
    {
      if (a[j] > a[min_pos]) min_pos = j;
      vezes++;
    }
      
    
    //se o elemento salvo não for o elemento na posição I trocalo
    if (min_pos != i)
    {
      int Aux = a[i];
      a[i] = a[min_pos];
      a[min_pos] = Aux;

      vezes++;
    }
    vezes++;
  }
  
  // printa o array no console
  for (int i = tamanho; i > 0; i--)
    printf("a[%d] = %d\n", i, a[i - 1]);
    printf("\n");
    printf("rodou %d vezes", vezes);
  
  return 0;
}