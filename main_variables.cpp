#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

#define NOMBRE_ARCHIVO "archivo.bin"

void escribirArchivo();
void leerArchivo();

int main(){
    
    //escribirArchivo();
    leerArchivo();

    return 1;
}

void escribirArchivo(){
    int numero = 10;
    int numero2 = 20;
    char letra = 'L';

    ofstream archivo(NOMBRE_ARCHIVO,ios::app|ios::binary);

    archivo.write((char *)&numero,sizeof(int));
    archivo.write((char *)&numero2,sizeof(int));
    archivo.write((char *)&letra,sizeof(char));

    archivo.close();
}

void leerArchivo(){
    int numero;
    int numero2;
    char letra;

    ifstream archivo(NOMBRE_ARCHIVO,ios::binary);

    if(!archivo.good()){
        cout << "El archivo no existe" << endl;
    }else{
        archivo.read((char *)&numero,sizeof(int));
        cout << "Numero: " << numero << endl;

        archivo.read((char *)&numero2,sizeof(int));
        cout << "Numero2: " << numero2 << endl;

        archivo.read((char *)&letra,sizeof(char));
        cout << "letra: " << letra << endl;
    }
}