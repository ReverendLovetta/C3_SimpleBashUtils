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

#endif  // SRC_S21_CAT_H_