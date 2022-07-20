#ifndef SRC_S21_CAT_H_
#define SRC_S21_CAT_H_

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct flags {
  int b;
  int e;
  int v;
  int n;
  int s;
  int t;
} flags;

char** reading_parameters(int* argc, char* argv[], flags* param);
void s21_cat_core(flags* param, int argc_core, char* argv_core[]);
FILE* s21_open_file(const char filename[]);
void s21_use_flags(flags* param, FILE* file_string, const char argv_core[]);
void s21_print_file(const char argv_core[]);
#endif  // SRC_S21_CAT_H_