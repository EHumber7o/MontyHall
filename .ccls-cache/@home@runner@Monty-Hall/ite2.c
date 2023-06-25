#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main1(void) {

  srand(time(NULL));
  
  while (1){
  int door, in_entry, fi_entry, op;

  door = rand()%3 + 1;
  do {
    printf("Escolha uma porta: ");
    scanf("%d",&in_entry);
  } while (in_entry > 3 || in_entry < 1);
  for (op = 1; op == door || op == in_entry; op++);
  printf("O prêmio não está atrás da porta %d.\n",op);
  char trade;
  do {
    printf("Deseja trocar?\n");
    scanf(" %c",&trade);
  } while (tolower(trade) != 's' && tolower(trade) != 'n');
  if (tolower(trade) == 's')
    for (fi_entry = 1; fi_entry == in_entry || fi_entry == op; fi_entry++);
  if (fi_entry == door) printf("Você Ganhou!\n");
  else printf("Você Perdeu!\n");
  }
  return 0;
}