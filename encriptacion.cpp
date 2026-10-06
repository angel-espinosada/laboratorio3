#include "encriptacion"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
// Functor/Función para rotar hacia la izquierda un byte
unsigned char rotarIzquierda(unsigned char byte, int n) {
    return (byte << n) | (byte >> (8 - n));
}

// Functor/Función para rotar hacia la derecha un byte (deshacer rotación)
unsigned char rotarDerecha(unsigned char byte, int n) {
    return (byte >> n) | (byte << (8 - n));
}

// Función para encriptar los datos
string encriptar(const string& datos, int n, unsigned char claveK) {
    string resultado = datos;
    for (size_t i = 0; i < datos.length(); i++) {
        // 1. Rotación a la izquierda n posiciones
        unsigned char byteRotado = rotarIzquierda(static_cast<unsigned char>(datos[i]), n);
        // 2. Operación XOR con la clave K
        resultado[i] = static_cast<char>(byteRotado ^ claveK);
    }
    return resultado;
}

// Función para desencriptar los datos
string desencriptar(const string& datosEncriptados, int n, unsigned char claveK) {
    string resultado = datosEncriptados;
    for (size_t i = 0; i < datosEncriptados.length(); i++) {
        // 1. Aplicar XOR con la misma clave K para revertir el XOR
        unsigned char byteSinXor = static_cast<unsigned char>(datosEncriptados[i]) ^ claveK;
        // 2. Invertir la rotación desplazando a la derecha n posiciones
        resultado[i] = static_cast<char>(rotarDerecha(byteSinXor, n));
    }
    return resultado;
}
