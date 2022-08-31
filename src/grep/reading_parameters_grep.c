/*Функция void ** reading_parameters_grep(int* n, char** argv, flags* param).
 * Заполняет структуру options флагами из stdin*/

#include "s21_grep.h"

void s21_fill_param_f(char* mass, char* p_optarg);

char** reading_parameters_grep(int* argc, char* argv[], flags* param,
                               char* mass) {
  char ch = '\0';  // Переменная для хранения флага
  while ((ch = getopt(*argc, argv, "e:ivclnhsf:o")) != EOF) {
    switch (ch) {
      case 'e': {
        if (param->e != 1) {
          param->e = 1;
        }
        if (strlen(mass) > 0) {
          strcat(mass, "|");
          strcat(mass, optarg);
        } else {
          strcat(mass, optarg);
        }
        break;
      }
      case 'i': {
        param->i = 1;
        break;
      }
      case 'v': {
        param->v = 1;
        break;
      }
      case 'c': {
        param->c = 1;
        break;
      }
      case 'l': {
        param->l = 1;
        break;
      }
      case 'n': {
        param->n = 1;
        break;
      }
      case 'h': {
        param->h = 1;
        break;
      }
      case 's': {
        param->s = 1;
        break;
      }
      case 'f': {
        if (param->f != 1) {
          param->f = 1;
        }
        s21_fill_param_f(mass, optarg);
        break;
      }
      case 'o': {
        param->o = 1;
        break;
      }
      default: {
        fprintf(stderr, "s21_grep: Неизвестный параметр: '%s'\n", optarg);
        exit(1);
      }
    }
  }
  *argc = *argc - optind;
  argv += optind;
  if (param->e == 0 && param->f == 0) {
    strcat(mass, argv[0]);
    *argc = *argc - 1;
    argv += 1;
  }
  return argv;
}

void s21_fill_param_f(char* mass, char* p_optarg) {
  FILE* file_f = NULL;  // Указатель на поток данных, который содержит паттерны
  file_f = s21_open_file_grep(p_optarg);
  char mass_f[BUF];
  memset(mass_f, '\0', BUF - 1);
  while (fgets(mass_f, BUF, file_f) != NULL) {
    if (strlen(mass_f) >= 1) {
      if (mass_f[strlen(mass_f) - 1] == '\n') {
        mass_f[strlen(mass_f) - 1] = '\0';
      }
    }
    if (mass_f[0] == '\0') {
      continue;
    } else {
      if (strlen(mass) > 0) {
        strcat(mass, "|");
        strcat(mass, mass_f);
      } else {
        strcat(mass, mass_f);
      }
      memset(mass_f, '\0', strlen(mass_f));
    }
  }
  fclose(file_f);
}
