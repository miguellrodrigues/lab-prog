#include <stdio.h>

typedef struct Car {
  char name[60];
  float cosumeKm;
};

int main(void)
{
  struct Car cars[5], best;

  best.cosumeKm = 0;

  for(size_t i = 0; i < 5; ++i) {
    printf("\nDigite o modelo do %d carro: ", i + 1);
    scanf("%s", &cars[i].name);
   
    printf("\nDigite o consumo de combustivel por km: ");
    scanf("%f", &cars[i].cosumeKm);

    if (cars[i].cosumeKm > best.cosumeKm) {
      best = cars[i];
    }
  }

  printf("\n\nModelo de carro mais economico: %s\nConsumo: %.3f Km/L\n\n", best.name, best.cosumeKm);

  for(size_t i = 0; i < 5; ++i) 
  {
    printf("\nModelo: %s | Consumo em 1000 km: %.3f L\n", cars[i].name, (1000.0 / cars[i].cosumeKm));
  }

  return 0;
}