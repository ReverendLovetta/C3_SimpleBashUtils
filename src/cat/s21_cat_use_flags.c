/* Функция s21_use_flags. В зависимости от флага выводит видоизмененное
 * содержимое файлов.
 */

#include "s21_cat.h"

void s21_cat_use_flags(flags* param, FILE *file) {
#ifdef __APPLE__
  char c = '\0';
  int i = 0;
  int j = 0;
#endif  // __APPLE__
#ifdef __linux__
  int c = 0;
  static int i = 0;
  //static int j = 0;
#endif  // __linux__
  char temp1 = '\0';
  char temp2 = '\0';
  char flag_first_str = '0';
  while ((c = fgetc(file)) != EOF) {
    if (param->b == 1) {
      if (param->n == 1) {
        param->n = 0;
      }
      if ((temp1 == '\n' && temp2 == '\n' && flag_first_str != '0')) {
        continue;
      } else {
        printf("%6d\t", i);
        i++;
      }
    // } else if (param->e == 1) {
    } if (param->n == 1 && temp1 == '\n') {
      printf("\nПараметр n активировался\n");
    }
    //   if (temp1 == '\n') {
    //         }
    // } else if (param->s == 1) {
    // } else if (param->t == 1) {
    // } else if (param->v == 1) {
    // }
    printf("%c", c);
    temp2 = temp1;
    temp1 = c;
    if (flag_first_str == '0') {
      flag_first_str = '1';
    }
  }
}
