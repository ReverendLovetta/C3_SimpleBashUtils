/* Основная логика функции s21_grep.
 *
 */

#include "s21_grep.h"

void s21_grep_core(  // flags* param,
    int argc, char* argv[], char* mass) {
  int l = 0;
  for (int i = 0; i < argc; i++) {
    FILE* file = s21_open_file_grep(argv[i]);
    printf("Открыли файл %s\n", argv[i]);

    printf("mass = %s\n", mass);
    printf("l = %d", l);
    l++;
    // s21_grep_use_flags(param, file, mass);
    fclose(file);
  }
}
