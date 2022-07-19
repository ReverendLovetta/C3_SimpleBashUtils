#ifndef SRC_S21_CAT_H_
#define SRC_S21_CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

typedef struct flags {
    int b;
    int e;
    int v;
    int n;
    int s;
    int t;
} flags;

void reading_parameters(int* argc, char* argv[], flags* param);

#endif  // SRC_S21_CAT_H_