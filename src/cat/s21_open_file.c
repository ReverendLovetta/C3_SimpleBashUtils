/* Функция открывает файл filename
 *
 */

#include "s21_cat.h"

FILE* s21_open_file(const char filename[]) {
  FILE* file;
  if (!(file = fopen(filename, "r"))) {
    fprintf(stderr, "Не удалось открыть файл %s\n", filename);
    exit(2);
  } else {
    return file;
  }
}
