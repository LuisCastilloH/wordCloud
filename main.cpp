#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "tablaHash.h"

using namespace std;

int main ()
{
    tablaHash<string> hashing;
    tablaHash<string> pR; //palabras reservadas
    char frase[1000000];
    int i=0;
    char *ptr;
    ifstream archEntrada;
    string nombre;
    string linea;
    string word;
    string aux;
    ifstream archE;
    //cargamos en una tabla de hash las palabras reservadas
    archE.open("reservadas.txt");
    while(!archE.eof())
    {
        archE >> aux;
        pR.inserta(aux);
    }
    archE.close();
    cout << "Ingresa el nombre del archivo de datos ";
    cin >> nombre;
    archEntrada.open(nombre.c_str());
    while(!archEntrada.eof())
    {
        getline(archEntrada, linea);
        strncpy(frase, linea.c_str(), sizeof(frase));
        frase[sizeof(frase) - 1] = 0;
        //se eliminan caracteres secundarios tales como .,/% etc.
        ptr = strtok(frase,"     », .:-_´`'?¡¿!()/\%$#|°¬¨*+~[]{}^;<>=\"...");
        while(ptr != NULL)
        {
            i = 0;
            word = ptr;
            ptr = strtok(NULL, "     », .:-_´`'?¡¿!()/\%$#|°¬¨*+~[]{}^;<>=\"...");
            while(word[i])
            {
                word[i] = tolower(word[i]);
                i++;
            }
            //cout << word << endl;
            //Aqui se insertaran las palabras a la EDD verificando previamente que no sea una palabra reservada
            if(!(pR.existe(word)))
                hashing.inserta(word);
        }
    }
    archEntrada.close();
    //se carga los datos al archivo html
    hashing.carga();
    cout << "El Word Cloud del archivo " << nombre <<" ha sido generado!!!" << endl;
    return 0;
}
