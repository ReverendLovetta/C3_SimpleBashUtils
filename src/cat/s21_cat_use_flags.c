/* Функция s21_use_flags. В зависимости от флага выводит видоизмененное
 * содержимое файлов.
 */

#include "s21_cat.h"

void s21_cat_use_flags(flags* param, const FILE* file_string,
                       const char argv_core[]) {
#ifdef __APPLE__
  char c = '\0';
  int i = 0;
  int j = 0;
#endif  // __APPLE__
#ifdef __linux__
  int c = 0;
  static int i = 0;
  static int j = 0;
#endif  // __linux__
  char temp1 = '\0';
  char temp2 = '\0';
  while (!feof(file_string)) {
    c = fgetc(file_string);
    if (param->b == 1) {
      if (param->n == 1) {
        param->n = 0;
      }

    } else if (param->e == 1) {
    } else if (param->n == 1) {
      if (temp1 == '\n') {
            }
    } else if (param->s == 1) {
    } else if (param->t == 1) {
    } else if (param->v == 1) {
    } else {
    }
    temp2 = temp1;
    temp1 = c;
  }
}