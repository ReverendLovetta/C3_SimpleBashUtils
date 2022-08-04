/* Функция void reading_parameters(int* n, char** agrv, flags* param).
 * Заполняет структуру start флагами из stdin.
 */

#include "s21_cat.h"

char** reading_parameters(int* argc, char* argv[], flags* param) {
#ifdef __APPLE__
  char ch;
  while ((ch = getopt(*argc, argv, "benst")) != EOF) {
    switch (ch) {
      case 'b': {
        param->b = 1;
        break;
      }
      case 'e': {
        param->e = 1;
        param->v = 1;
        break;
      }
      case 'n': {
        param->n = 1;
        break;
      }
      case 's': {
        param->s = 1;
        break;
      }
      case 't': {
        param->t = 1;
        param->v = 1;
        break;
      }
      default: {
        fprintf(stderr, "Неизвестный параметр: '%s'\n", optarg);
        exit(1);
      }
    }
    *argc = *argc - optind;
    argv += optind;
    return argv;
  }
#endif  // __APPLE__
#ifdef __linux__
  printf("Массив до обработки:\n");
  for (int i = 0; i < *argc; i++) {
    printf("Элемент %d-й массива: %s\n", i, argv[i]);
  }
  const char* short_options = "benstET";
  const struct option long_options[] = {
      {"number-nonblank", no_argument, NULL, 'b'},
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {NULL, 0, NULL, 0}};
  int res = 0;
  int option_index = -1;
  while ((res = getopt_long(*argc, argv, short_options, long_options,
                            &option_index)) != -1) {
    switch (res) {
      case 'b': {
        param->b = 1;
        break;
      }
      case 'e': {
        param->e = 1;
        param->v = 1;
        break;
      }
      case 'n': {
        param->n = 1;
        break;
      }
      case 's': {
        param->s = 1;
        break;
      }
      case 't': {
        param->t = 1;
        param->v = 1;
        break;
      }
      default: {
        fprintf(stderr, "Неизвестный параметр: '%s'\n", optarg);
        exit(1);
      }
    }
  }
  printf("optind1 = %d\n", optind);
  *argc = *argc - optind;
  argv += optind;
  printf("Массив после обработки\n");
  printf("argc после = %d\n", *argc);
  for (int j = 0; j < *argc; j++) {
    printf("%d-й элемент массива: %s\n", j, argv[j]);
  }
  return argv;
#endif  // __linux__
}
