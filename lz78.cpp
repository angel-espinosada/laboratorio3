#include "lz78.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct Linea {
    int prefix;
    char c;
};

int encLinea(Linea* dict, int size, int prefix, char c) {
    for (int i = 1; i < size; i++) {
        if (dict[i].prefix == prefix && dict[i].c == c)
            return i;
    }
    return -1;
}
void compLZ78(const char* entrada, int n) {

    cout << "Compresion LZ78" <<endl << "---------------" << endl;
    Linea* dict = new Linea[100];
    int tamDict = 1;

    int i = 0;
    while (i < n) {
        int prefix = 0;
        int j = i;

        while (j < n) {
            int idx = encLinea(dict, tamDict, prefix, entrada[j]);
            if (idx == -1) break;
            prefix = idx;
            j++;
        }

        char c = entrada[j];
        cout << "(" << prefix << "," << c << ") ";

        dict[tamDict].prefix = prefix;
        dict[tamDict].c = c;
        tamDict++;

        i = j + 1;
    }
    cout << "Diccionario: " << endl;
    for (int i=0; i<=tamDict; i++){
        cout<<dict[i].c << "," << dict[i].prefix << endl;
    }

    delete[] dict;
}
