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
        while (i + 1 < n && entrada[i] == entrada[i + 1]&&count<255) {
            count++;
            i++;
        }
        salida += (unsigned char)count;
        salida+=entrada[i];
        for (size_t i = 0; i < salida.size(); i += 2) {
            cout <<(int)(unsigned char)salida[i] << salida[i+1];
        }
        cout << endl;
    }

    return salida;
}

string decompRLE(const string& entrada) {

    cout << "Decompresion RLE" <<endl << "---------------" << endl;
    string salida = "";
    int n = entrada.size();

    for (int i = 0; i < n; i++) {
        int count = (unsigned char)entrada[i];
        char c = entrada[++i];

        for (int j = 0; j < count; j++)
            salida += c;
        cout << salida << endl;
    }
    return salida;
}


void imprimirRLE(const string& salida) {
    for (size_t j = 0; j < salida.size(); j += 2) {
        cout << (int)(unsigned char)salida[j] << salida[j + 1];
    }
    cout << endl;
}
