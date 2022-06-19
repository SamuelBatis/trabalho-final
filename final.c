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
  int n = 2;
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
  return p;
};

static const char * unidades[]  = { "Zero", "Um", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove" };
static const char * dez_vinte[] = { "", "Onze", "Doze", "Treze", "Quatorze", "Quinze", "Dezesseis", "Dezessete", "Dezoito", "Dezenove" };
static const char * dezenas[]   = { "", "Dez", "Vinte", "Trinta", "Quarenta", "Cinquenta", "Sessenta", "Setenta", "Oitenta", "Noventa" };
static const char * centenas[]  = { "", "Cento", "Duzentos", "Trezentos", "Quatrocentos", "Quinhentos", "Seiscentos", "Setecentos", "Oitocentos", "Novecentos" };


char * strcatb( char * dst, const char * src )
{
    size_t len = strlen(src);
    memmove( dst + len, dst, strlen(dst) + 1 );
    memcpy( dst, src, len );
    return dst;
}


char * traduzir_numero( char * nome, int n )
{
    int c = n / 100;
    int d = n / 10 - c * 10;
    int u = n - (n / 10) * 10;
    int dv = d * 10 + u;


    strcpy( nome, unidades[ u ] );

    if( n < 10 )
        return nome;

    if ( (dv > 10) && (dv < 20) )
    {
        strcpy( nome, dez_vinte[ dv - 10 ] );
    }
    else
    {
        if( u == 0 )
        {
            strcpy( nome, dezenas[ d ] );
        }
        else
        {
            strcatb( nome, " e " );
            strcatb( nome, dezenas[d] );
        }
    }

    if( n < 100 )
        return nome;

    if( (d == 0) && ( u == 0 ) )
    {
        if( c == 1 )
            strcpy( nome, "Cem" );
        else
            strcpy( nome, centenas[c] );
    }
    else
    {
        strcatb( nome, " e " );
        strcatb( nome, centenas[c] );
    }

    return nome;
}

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
    float aux = trapezio(pesquisadores[k].a, pesquisadores[k].b, n);
    pesquisadores[k].r = aux;
  }

 /*char extenso[100];
  printf("%s", c);*/

  // output
  printf("periodo  nome do pesquisador  Intervalo[a,b]  Valor proporcional\n");
  for (int k = 0; k < n; k++)
  {
    char extenso[100];
    double rr = pesquisadores[k].r + 1200;
    printf("%s\t", traduzir_numero(extenso, k + 1));
    printf("%s\t", pesquisadores[k].nome);
    printf("\t\t[%d, %d]", pesquisadores[k].a, pesquisadores[k].b);
    printf("\t\t%.2f    \n", rr);
  }

  return 0;
}
