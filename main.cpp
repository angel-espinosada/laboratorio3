#include <iostream>
#include "rle.h"
#include "lz78.h"
#include <fstream>
#include <string>

using namespace std;

string leerArch(const string& nomArch);
    int main() {
        try {
            string texto = leerArch("entrada.txt");

            // ---- RLE ----
            string comp = compRLE(texto);
            string decomp = decompRLE(comp);

            cout << "Original: " << texto << endl;
            cout << "RLE: " << comp << endl;
            cout << "Recuperado: " << decomp << endl;
 } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;


}
    string leerArch(const string& nomArch) {
        ifstream file(nomArch);
        if (!file) throw runtime_error("No se pudo abrir el archivo");

        string contenido((istreambuf_iterator<char>(file)),
                         istreambuf_iterator<char>());
        return contenido;
    }
