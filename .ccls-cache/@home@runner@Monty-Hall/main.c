#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main0(void) {

  srand(time(NULL));
  
  while (1){
  int door, entry, op, doors[3] = {1,2,3};

  door = rand()%3 + 1;
  do {
    printf("Escolha uma porta: ");
    scanf("%d",&entry);
  } while (entry > 3 || entry < 1);
  for (int i = 0; i < 3; i++) 
    if (entry == doors[i]) 
      doors[i] = 0;
  for (int i = 0; i < 3; i++) 
    if (doors[i] != door && doors[i] != 0) {
      op = doors[i];
      doors[i] = 0;
      break;
    }
  printf("O prêmio não está atrás da porta %d.\n",op);
  char trade;
  do {
    printf("Deseja trocar?\n");
    scanf(" %c",&trade);
  } while (tolower(trade) != 's' && tolower(trade) != 'n');
  if (tolower(trade) == 's') 
    for(int i = 0; i < 3; i++) 
      if (doors[i] > 0) 
        entry = doors[i];
  if (entry == door) printf("Você Ganhou!\n");
  else printf("Você Perdeu!\n");
  }
  return 0;
}