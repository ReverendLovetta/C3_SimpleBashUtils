/* Функция открывает файл filename
 *
 */

#include "s21_grep.h"

FILE* s21_open_file_grep(const char filename[]) {
  FILE* file;
  if (!(file = fopen(filename, "r"))) {
    fprintf(stderr, "s21_grep: Не удалось открыть файл %s\n", filename);
    exit(2);
  } else {
    return file;
  }
}
