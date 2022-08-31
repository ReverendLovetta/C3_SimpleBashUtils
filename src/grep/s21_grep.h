#ifndef _SRC_GREP_S21_GREP_H_
#define _SRC_GREP_S21_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10000
#define BUF 100000

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

char** reading_parameters_grep(int* argc, char* argv[], flags* param,
                               char* mass);
void s21_grep_core(int argc, char* argv[], char* mass);
void s21_grep_use_flags(flags* param, FILE* file, char* mass);
FILE* s21_open_file_grep(const char filename[]);

#endif  // _SRC_GREP_S21_GREP_H_