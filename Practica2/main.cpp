#include "quicksort.hpp"
#include "medio_nivel.hpp"
#include <iostream>
#include <getopt.h>

using namespace std;

int main(int argc, char** argv){
    char c;
    int min, max, inc, rep, med, minMed;
    bool hflag = false;

    srand(time(0));
    
    static struct option long_options[] = {
        {"min", required_argument, NULL, 'm'},
        {"max", required_argument, NULL, 'M'},
        {"incremento", required_argument, NULL, 'i'},
        {"repeticiones", required_argument, NULL, 'r'},
        {"mediana", required_argument, NULL, 'n'},
        {"minMed", required_argument, NULL, 'e'},
        {"help", no_argument, NULL, 'h'},
        {0, 0, 0, 0}
    };

    while ((c = getopt_long(argc, argv, "m:M:i:r:n:e:h", long_options, NULL)) != -1){
        switch(c){
            case 'm':
                min = stoi(optarg);
                cout << "m: " << min << endl;
            break;

            case 'M':
                max = stoi(optarg);
                cout << "M: " << max << endl;
            break;

            case 'i':
                inc = stoi(optarg);
                cout << "i: " << inc << endl;
            break;

            case 'r':
                rep = stoi(optarg);
                cout << "r: " << rep << endl;
            break;

            case 'n':
                med = stoi(optarg);
                cout << "n: " << med << endl;
            break;

            case 'e':
                minMed = stoi(optarg);
                cout << "n: " << minMed << endl;
            break;

            case 'h':
                cout << "Pedir ayuda es para debiles" << endl;
                exit(EXIT_SUCCESS);
            break;

            case '?':
                cout << "Parametro no reconocido" << endl;
                exit(EXIT_FAILURE);

            default:
                cout << "Error inesperado" << endl;
                exit(EXIT_FAILURE);
        }
    }

    comparacionVariantesQuicksort(min, max, inc, rep, med, minMed);

    return 0;
}