#ifndef _SRC_GREP_S21_GREP_H_
#define _SRC_GREP_S21_GREP_H_

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
} flags;

char** reading_parameters(int* argc, char* argv[], flags* param);
void s21_grep_core(flags* param, int argc, char* argv[]);
void s21_grep_use_flags(flags* param, FILE* file);
FILE* s21_open_file(const char filename[]);

#endif  // _SRC_GREP_S21_GREP_H_