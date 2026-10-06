#include "encriptar.h"
#include <string>
using namespace std;
//Función para rotar izquierda un byte
unsigned char rotar_izquierda(unsigned char byte, int n) {
    return (byte << n) | (byte >> (8 - n));
}

//Función para rotar ala derecha un byte
unsigned char rotar_derecha(unsigned char byte, int n) {
    return (byte >> n) | (byte << (8 - n));
}


string encriptar(const string& datos, int n, unsigned char claveK) {
    string resultado = datos;
    for (size_t i = 0; i < datos.length(); i++) {
        //Rotación a la izquierda n posiciones
        unsigned char byterotado = rotar_izquierda(static_cast<unsigned char>(datos[i]), n);
        //Operación XOR con la clave K
        resultado[i] = static_cast<char>(byterotado ^ claveK);
    }
    return resultado;
}

// Función para desencriptar los datos
string desencriptar(const string& datosEncriptados, int n, unsigned char claveK) {
    string resultado = datosEncriptados;
    for (size_t i = 0; i < datosEncriptados.length(); i++) {
        // Aplicar XOR con la misma clave k para revertir el XOR
        unsigned char byteSinXor = static_cast<unsigned char>(datosEncriptados[i]) ^ claveK;
        // Invertir la rotación desplazando a la derecha n posiciones
        resultado[i] = static_cast<char>(rotar_derecha(byteSinXor, n));
    }
    return resultado;
}
