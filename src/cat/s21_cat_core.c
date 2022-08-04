/* Основная логика функции s21_cat.
 *
 */

#include "s21_cat.h"

void s21_cat_core(flags* param, int argc_core, char* argv_core[]) {
  printf("Программа начала выполнятся\n");
  for (int i = 0; i < argc_core; i++) {
    FILE* file = s21_open_file(argv_core[i]);
    s21_cat_use_flags(param, file);
    fclose(file);
  }
}
