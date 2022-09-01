/* Функция для вывода на экран результата работы s21_grep с учетом параметров и
 * массива с паттернами */

#include "s21_grep.h"

void s21_grep_use_flags(flags* param, FILE* file, char* mass,
                        const char* filename) {
  regex_t compiled;  // Структура для компилирования регулярного выражения
  regmatch_t regmatch[1] = {
      0};  // Массив структур содержащих основное и субрегулярные выражения
  size_t n_regmatch = 1;  // Размер массива regmatch
  char string[BUF];  // строка для записи данных из потока данных file
  memset(string, '\0', BUF - 1);
  int err = 0;  // номер ошибки при неудачном компилировании рег. выражения
  char err_mesage[ERR];  // строка, содержащая ошибку при неудачном
                         // компилировании рег. выражения
  memset(err_mesage, '\0', ERR - 1);
  int cflags_i =
      0;  // опция при компилировании рег. выражения при присутствия флага -i
  int count_lines = 0;  // Счетчик строк в файле

  if (param->i == 1) {
    cflags_i = REG_ICASE;
  }
  err = regcomp(&compiled, mass, REG_EXTENDED | cflags_i);
  if (err) {
    regerror(err, &compiled, err_mesage, ERR);
    fprintf(stderr,
            "s21_grep: Ошибка при компиляции регулярного выражения: %s : %s.\n",
            mass, err_mesage);
    fclose(file);
    exit(4);
  }
  while (fgets(string, BUF, file)) {
    err = regexec(&compiled, string, n_regmatch, regmatch, 0);
    if (err == REG_NOMATCH) {
      continue;
    } else if (err) {
      fprintf(stderr,
              "s21_grep: Ошибка при анализе регулярного выражения: %s : %s.\n",
              mass, err_mesage);
      fclose(file);
      exit(5);
    }
    putchar(string);
    printf("\n");
    memset(string, '\0', strlen(string));
  }
}
