/* Основная логика функции s21_grep.
 *
 */

#include "s21_grep.h"

void s21_grep_core(flags* param, int argc, char* argv[], char* mass) {
  for (int i = 0; i < argc; i++) {
    FILE* file = s21_open_file_grep(argv[i]);
    s21_grep_use_flags(param, file, mass, argv[i]);
    fclose(file);
  }
}
