#include <stdio.h>
#include <math.h>
#include <string.h>

float r (float t) {
    float result = 300*exp(0.3*t);
  return result;
};
float trapezio (int a,int b) {
    int xn = b; 
    int xo = a;   
    int n = 5;
    float h = (xn - xo) / n;
    float x = xo + h;
    float soma = 0;
    for (int i = 1; i != n ; i++) {
      soma += r(x);
      x += h;
    }
    float p = h * ((r(xo) + r(xn)) / 2 + soma);
    printf("h %f\n", h);
  return p;
};



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
  for (int i = 0; i < n; i++)
  {
    printf("\ninsira o nome: ");
    scanf("\n%s", &pesquisadores[i].nome);
    printf("\ninsira o periodo: ");
    scanf("\n%d", &pesquisadores[i].periodo);
    printf("\ninsira o valor de a: ");
    scanf("\n%d", &pesquisadores[i].a);
    printf("\ninsira o valor de b: ");
    scanf("\n%d", &pesquisadores[i].b);

  };

  float r = trapezio(2, 3);
  printf("r = %f\n", r);
  


  // chamada das funçoes
for (int k = 0; k < n; k++) {
    printf("A e B dentro do for %d, %d\n", pesquisadores[k].a, pesquisadores[k].b);
    float aux = trapezio(pesquisadores[k].a, pesquisadores[k].b);
    printf("%f", aux);
    pesquisadores[k].r = aux;
}
  printf("a = %d e b = %d\n", pesquisadores[0].a, pesquisadores[0].b);
  printf("valor retornado do trapezio: %f\n", pesquisadores[0].r);
  
  printf("pesquisadores\n");
  for (int k = 0; k < n; k++)
  {
    printf("\n%d nome: %s, periodo: %d,  valor de a: %d, valor de b: %d, valor de r: %f\n", k + 1, pesquisadores[k].nome, pesquisadores[k].periodo, pesquisadores[k].a, pesquisadores[k].b, pesquisadores[k].r);
  }

  return 0;
}
