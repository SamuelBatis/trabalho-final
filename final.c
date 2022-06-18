#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

float r(float t)
{
  float result = 300 * exp(0.3 * t);
  // printf("%f\n", result);
  return result;
};
float trapezio(int a, int b, int num)
{
  int xn = b;
  int xo = a;
  int n = num;
  float p;
  float h = (xn - xo) / n;
  float x = xo + h;
  float soma = 0;
  for (int i = 1; i != n; i++)
  {
      soma += r(x);
      x += h;
    }
  p = h * ((r(xo) + r(xn)) / 2 + soma);
  printf("h %f\n", h);
  return p;
};

int main()
{
  int n;
  scanf("%d", &n);

  struct Pesquisadores
  {
    char nome[45];
    int periodo;
    int a;
    int b;
    double r;
  };

  struct Pesquisadores pesquisadores[n];

  // input dos dados
  for (int i = 0; i < n; i++)
  {
    pesquisadores[i].periodo = i;
    printf("\ninsira o nome: ");
    scanf("\n%s", &pesquisadores[i].nome);
    printf("\ninsira o valor de a: ");
    scanf("\n%d", &pesquisadores[i].a);
    printf("\ninsira o valor de b: ");
    scanf("\n%d", &pesquisadores[i].b);
  };

  // chamada das funçoes
  for (int k = 0; k < n; k++)
  {
    printf("A e B dentro do for %d, %d\n", pesquisadores[k].a, pesquisadores[k].b);
    float aux = trapezio(pesquisadores[k].a, pesquisadores[k].b, n);
    printf(" ok %f", aux);
    pesquisadores[k].r = aux;
  }
  printf("\na = %d e b = %d\n", pesquisadores[0].a, pesquisadores[0].b);
  printf("valor retornado do trapezio: %.2f\n", pesquisadores[0].r);

  // output
  printf("pesquisadores %d\n", n);
  printf("periodo   nome do pesquisador  Intervalo[a,b]  Valor proporcional");
  for (int k = 0; k < n; k++)
  {
    double rr = pesquisadores[k].r + 1200;
    printf("\n%d          %s                   [%d, %d]           %.2f\n",
           k + 1,
           pesquisadores[k].nome,
           pesquisadores[k].a,
           pesquisadores[k].b,
           rr);
  }

  return 0;
}
