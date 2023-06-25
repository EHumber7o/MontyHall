#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void) {

  srand(time(NULL));
  
  int it, suc = 0;
  double suc_rate;
  
  for (it = 1; it <= 120; it++) {
    int door, in_entry, fi_entry, op;
  
    door = rand()%3 + 1;
    in_entry = rand()%3 +1;
    printf("Porta inicial: %d",in_entry);
    for (op = 1; op == door || op == in_entry; op++);
    printf("O prêmio não está atrás da porta %d.\n",op);
    for (fi_entry = 1; fi_entry == in_entry || fi_entry == op; fi_entry++);
    printf("Porta final: %d",fi_entry);
    if (fi_entry == door){
      suc++;
      printf("Ganho!\n");
    } 
    else printf("Perca!\n");
      suc_rate = 100.0 * (((double)suc)/it);
      printf("Sucessos: %d\nTaxa de Sucesso: %lf\n\n",suc, suc_rate);
  }
  return 0;
}