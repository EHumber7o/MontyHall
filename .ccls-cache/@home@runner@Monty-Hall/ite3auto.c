#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  srand(time(NULL));
  
  int it, suc = 0, def = 0;
  double suc_rate, def_rate, it_rate;
  
  for (it = 1; it <= 12000; it++) {
    int door, in_entry, fi_entry, op;
  
    door = rand()%3 + 1;
    in_entry = rand()%3 +1;
    printf("Porta inicial: %d\n",in_entry);
    op = 1;
    while (op == door || op == in_entry)
      op = rand()%3 + 1;
    for (fi_entry = 1; fi_entry == in_entry || fi_entry == op; fi_entry++);
    printf("Porta final: %d\n",fi_entry);
    if (fi_entry == door)
      suc++;
    else
      def++;
    suc_rate = 100.0 * (((double)suc)/it);
    def_rate = 100.0 * (((double)def)/it);
    it_rate = suc_rate + def_rate;
    printf("Sucessos: %d\nFracassos: %d\nIterações: %d\nTaxa de Sucesso: %.3lf%%\nTaxa de Fracasso: %.3lf%%\nTaxa Global: %.3lf%%\n\n",suc, def, it, suc_rate, def_rate, it_rate);
  }
  return 0;
}