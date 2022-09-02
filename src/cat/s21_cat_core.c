/* Основная логика функции s21_cat.
 *
 */

#include "s21_cat.h"

void s21_cat_core(flags* param, int argc_core, char* argv_core[]) {
  for (int i = 0; i < argc_core; i++) {
    FILE* file = fopen(argv_core[i], "r");
    if (!file) {
      fprintf(stderr, "s21_cat: Не удалось открыть файл %s\n", argv_core[i]);
      continue;
    }
    s21_cat_use_flags(param, file);
    fclose(file);
  }
}
