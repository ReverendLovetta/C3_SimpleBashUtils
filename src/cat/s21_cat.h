#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct flags {
  unsigned char b : 1;
  unsigned char e : 1;
  unsigned char v : 1;
  unsigned char n : 1;
  unsigned char s : 1;
  unsigned char t : 1;
} flags;

char** reading_parameters(int* argc, char* argv[], flags* param);
void s21_cat_core(flags* param, int argc_core, char* argv_core[]);
void s21_cat_use_flags(flags* param, FILE* file);
#endif  // SRC_CAT_S21_CAT_H_
