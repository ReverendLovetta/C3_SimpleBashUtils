#include "s21_grep.h"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    flags options = {0};
    char arg_pattern[N];  // Двумерный массив для записи паттернов
    memset(arg_pattern, '\0', N - 1);
    argv = reading_parameters_grep(
        &argc, argv, &options,
        arg_pattern);  // Заполняем структуру с флагами через getopt
    s21_grep_core(argc, argv, arg_pattern);
  } else {
    fprintf(stderr, "s21_grep: Недостаточно аргументов для выполнения функции");
    return 2;
  }
  return 0;
}
