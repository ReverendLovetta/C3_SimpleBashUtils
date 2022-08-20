/* Cat - одна из наиболее часто используемых команд в Unix-подобных операционных
 * системах. Команда имеет три взаимосвязанные функции в отношении текстовых
 * файлов: отображение, объединение их копий и создание новых.
 *
 * cat [OPTION] [FILE]...
 */

#include "s21_cat.h"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    flags start = {0};
    argv = reading_parameters(&argc, argv, &start);
    s21_cat_core(&start, argc, argv);
  } else {
    fprintf(stderr, "Недостаточно аргументов для выполнения функции\n");
    return 1;
  }
  return 0;
}