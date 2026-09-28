#include "rle.h"
#include <fstream>
#include <string>
#include <iostream>

/* RLE */
using namespace std;

string compRLE(const string& entrada) {

    cout << "Compresion RLE" <<endl << "---------------" << endl;
    string salida = "";
    int n = entrada.size();

    cout << "Tamaño en bytes: " << sizeof(entrada) << endl << "Caracteres: " << n << endl;

    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i + 1 < n && entrada[i] == entrada[i + 1]) {
            count++;
            i++;
        }
        salida += to_string(count) + entrada[i];
        cout << salida << endl;
    }
    return salida;
}

string decompRLE(const string& entrada) {

    cout << "Decompresion RLE" <<endl << "---------------" << endl;
    string salida = "";
    int n = entrada.size();

    for (int i = 0; i < n; i++) {
        int count = entrada[i] - '0';
        char c = entrada[++i];

        for (int j = 0; j < count; j++)
            salida += c;
        cout << salida << endl;
    }
    return salida;
}


