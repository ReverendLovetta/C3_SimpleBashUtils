#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10000
#define BUF 100000
#define ERR 1024

typedef struct {
  unsigned char e : 1;
  unsigned char i : 1;
  unsigned char v : 1;
  unsigned char c : 1;
  unsigned char l : 1;
  unsigned char n : 1;
  unsigned char h : 1;
  unsigned char s : 1;
  unsigned char f : 1;
  unsigned char o : 1;
} flags;

char** reading_parameters_grep(int* argc, char* argv[], flags* param,
                               char* mass);
void s21_grep_core(flags* param, int argc, char* argv[], char* mass);
void s21_grep_use_flags(flags* param, FILE* file, char* mass, char* filename,
                        int count_files);

#endif  // SRC_GREP_S21_GREP_H_
