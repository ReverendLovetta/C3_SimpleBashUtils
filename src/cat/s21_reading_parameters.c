/* Функция void reading_parameters(int* n, char** agrv, flags* param). 
 * Заполняет структуру start флагами из stdin.
 */

#include <s21_cat.h>

void reading_parameters(int* argc, char* argv[], flags* param) {
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

    }
    #endif  // __APPLE__
    #ifdef __linux__
    
    #endif  // __linux__
}