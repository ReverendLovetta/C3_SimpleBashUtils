/* Функция для вывода на экран результата работы s21_grep с учетом параметров и
 * массива с паттернами */

#include "s21_grep.h"

void s21_grep_use_flags(flags* param, FILE* file, char* mass, char* filename,
                        int count_files) {
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
  size_t count_lines = 0;  // Счетчик совпадающих строк в файле
  size_t count_n_lines = 0;  // Счетчик несовпадающих строк в файле
  if (param->i == 1) {
    cflags_i = REG_ICASE;
  }
  err = regcomp(&compiled, mass, REG_EXTENDED | cflags_i);
  if (err) {
    regerror(err, &compiled, err_mesage, ERR);
    fprintf(stderr,
            "s21_grep: Ошибка при компиляции регулярного выражения: %s : %s.\n",
            mass, err_mesage);
    regfree(&compiled);
    fclose(file);
    exit(4);
  }

  while (fgets(string, BUF, file)) {
    err = regexec(&compiled, string, n_regmatch, regmatch, 0);
    if (err == REG_NOMATCH) {
      count_n_lines++;
      if (!param->v) {
        memset(string, '\0', strlen(string));
        continue;
      }
    } else if (err) {
      fprintf(stderr,
              "s21_grep: Ошибка при анализе регулярного выражения: %s : %s.\n",
              mass, err_mesage);
      regfree(&compiled);
      fclose(file);
      exit(5);
    }
    count_lines++;
    if (!param->c && !param->l) {
      if (count_files > 1 && !param->h &&
          ((param->v && err == REG_NOMATCH && !param->o) ||
           (!param->v && err == 0))) {
        printf("%s:", filename);
      }
      if (param->n) {
        printf("%ld:", count_lines + count_n_lines);
      }
      if (param->o && !param->v) {
        char* p_string = string;
        while (!err) {
          if (regmatch[0].rm_eo == regmatch[0].rm_so) {
            break;
          }
          printf("%.*s\n", (int)(regmatch[0].rm_eo - regmatch[0].rm_so),
                 p_string + regmatch[0].rm_so);
          p_string += regmatch[0].rm_eo;
          err = regexec(&compiled, p_string, n_regmatch, regmatch, REG_NOTBOL);
        }
      }
      if (strlen(string) == 0) {
        string[0] = '\n';
      } else if (string[strlen(string) - 1] != '\n') {
        string[strlen(string)] = '\n';
      }
      if (!param->o &&
          ((!param->v && err == 0) || (param->v && err == REG_NOMATCH))) {
        printf("%s", string);
      }
    }
    memset(string, '\0', strlen(string));
  }
  if (param->c) {
    if (count_files > 1 && !param->h && !param->l) {
      printf("%s:", filename);
    }
    if (!param->l) {
      if (!param->v) {
        printf("%ld\n", count_lines);
      } else {
        printf("%ld\n", count_n_lines);
      }
    }
  }
  if (param->l && count_lines) {
    printf("%s\n", filename);
  }
  regfree(&compiled);
}
