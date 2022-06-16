#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
  // char nome[45];
  int n;
  scanf("%d", &n);

  struct Pesquisadores
  {
    char nome[45];
    int periodo;
    int a;
    int b;
    float r;
  };

  struct Pesquisadores pesquisadores[n];
  int i;

  // input dos dados
  for (i = 0; i < n; i++)
  {
    printf("\ninsira o nome: ");
    scanf("\n%s", &pesquisadores[i].nome);
    printf("\ninsira o periodo: ");
    scanf("\n%d", &pesquisadores[i].periodo);
    printf("\ninsira o valor de a: ");
    scanf("\n%d", &pesquisadores[i].a);
    printf("\ninsira o valor de b: ");
    scanf("\n%d", &pesquisadores[i].b);
    printf("\ninsira o r: ");
    scanf("\n%f", &pesquisadores[i].r);
  };

  float r (t) {
    float result = 300*exp(0.3*t);
    return result;
  };

  float trapezio (int *a,int *b) {
    int xn = b; 
    int xo = a;   
    int n = 500;
    float h = (xn - xo) / n;
    float x = xo + h;
    int soma = 0;
    for (int i = 1; i != n ; i++) {
      soma += r(x);
      x += h;
    }
    float p = h * ((r(xo) + r(xn)) / 2 + soma);
    printf("soma %d\n", p);
    pesquisadores[0].r = p;
    return p;
  };
 
  int l = trapezio(pesquisadores[0].a, pesquisadores[0].b);
  printf("valor retornado do trapezio: %d\n", pesquisadores[0].r);
  
  printf("pesquisadores\n");
  for (int k = 0; k < n; k++)
  {
    printf("\n%d nome: %s, periodo: %d,  valor de a: %d, valor de b: %d, valor de r: %f\n", k + 1, pesquisadores[k].nome, pesquisadores[k].periodo, pesquisadores[k].a, pesquisadores[k].b, pesquisadores[k].r);
  }

  return 0;
}
