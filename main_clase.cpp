#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#define NOMBRE_ARCHIVO "archivo.bin"

class Pokemon{
    public:
        char nombre[20];
        char tipo[20];
        int generacion;
        bool shiny;

        void mostrar();
};

void Pokemon::mostrar(){
    cout << "Nombre: " << this->nombre << endl
    << "Tipo: " << this->tipo << endl
    << "Generacion: " << this->generacion << endl
    << "Es shiny: " << ((this->shiny)?"Si":"No") << endl;
}

void escribirArchivo();
void leerArchivo();

int main(){

    //escribirArchivo();
    leerArchivo();

    return 1;
}

void escribirArchivo(){
    Pokemon *miPokemon = new Pokemon();

    strcpy(miPokemon->nombre,"Luxray");
    strcpy(miPokemon->tipo,"Electrico");
    miPokemon->generacion = 4;
    miPokemon->shiny = true;

    ofstream archivo(NOMBRE_ARCHIVO, ios::app|ios::binary);

    archivo.write((char *)miPokemon,sizeof(Pokemon));

    archivo.close();
}

void leerArchivo(){
    Pokemon *miPokemon = new Pokemon();

    ifstream archivo(NOMBRE_ARCHIVO, ios::binary);

    if(!archivo.good()){
        cout << "El archivo no existe" << endl;
    }else{
        archivo.read((char *)miPokemon,sizeof(Pokemon));
        miPokemon->mostrar();
    }

    archivo.close();
}