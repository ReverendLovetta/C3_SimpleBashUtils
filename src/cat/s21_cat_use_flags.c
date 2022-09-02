/* Функция s21_use_flags. В зависимости от флага выводит видоизмененное
 * содержимое файлов.
 */

#include "s21_cat.h"

void s21_cat_use_flags(flags* param, FILE* file) {
#ifdef __APPLE__
  int c = '\0';
  int i = 0;
  int j = 0;
  char temp1 = '\0';
#endif  // __APPLE__

#ifdef __linux__
  int c = 0;
  static int i = 1;
  static char temp1 = '\0';
  static int j = 1;
#endif  // __linux__

  char temp2 = '\0';
  char flag_first_str = '0';
  while ((c = fgetc(file)) != EOF) {
    if (param->b == 1) {
      if (param->n == 1) {
        param->n = 0;
      }
      if ((temp1 == '\n' && c != '\n') || i == 1) {
        printf("%6d\t", i);
        i++;
      }
    }
    if (param->s == 1) {
      if (temp2 == '\n' && temp1 == '\n' && c == '\n') {
        continue;
      }
    }
    if (param->n == 1 && (temp1 == '\n' || j == 1)) {
      printf("%6d\t", j);
      j++;
    }
    if (param->t == 1) {
      if (c == '\t') {
        printf("^");
        c = 'I';
      }
    }
    if (param->e == 1) {
      if (c == '\n') {
        printf("$");
      }
    }
    if (param->v == 1) {
      if ((c >= 0 && c < 32 && c != 9 && c != 10) || c == 127) {
        if (c == 127) {
          c = '?';
        } else {
          c += 64;
        }
        printf("^%c", c);

      } else if (c > 127) {
        if (c < 160) {
          printf("M-^%c", c - 128 + 64);
        } else if (c == 255) {
          printf("M-^?");
        } else {
          printf("M-%c", c - 128);
        }
      } else {
        printf("%c", c);
      }
    } else {
      printf("%c", c);
    }
    temp2 = temp1;
    temp1 = c;
    if (flag_first_str == '0') {
      flag_first_str = '1';
    }
  }
}
