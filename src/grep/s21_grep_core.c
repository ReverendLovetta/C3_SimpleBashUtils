/* Основная логика функции s21_grep.
 *
 */

#include "s21_grep.h"

void s21_grep_core(flags* param, int argc, char* argv[], char* mass) {
  for (int i = 0; i < argc; i++) {
    FILE* file = fopen(argv[i], "r");
    if (file == NULL) {
      if (param->s == 0) {
        fprintf(stderr, "s21_grep: Не удалось открыть файл %s\n", argv[i]);
      }
      continue;
    }
    s21_grep_use_flags(param, file, mass, argv[i], argc);
    fclose(file);
  }
}
