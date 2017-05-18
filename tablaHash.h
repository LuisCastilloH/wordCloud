#ifndef TABLAHASH_H_INCLUDED
#define TABLAHASH_H_INCLUDED

#include <stdlib.h>
#include <string>
#include <fstream>
#include "ABB.h"
//el tamaño de la tabla es de 97 ya que es un numero primo y ayuda a disminuir las colisiones
#define TAM 97

template <class T>
class tablaHash
{
private:
	ABB<T> tabla[TAM];
	int cantidad;

public:
	tablaHash() {cantidad = 0;}
	void inserta (T dato);
	void carga();
	int mayor();
	int contar();
	bool existe(T dato);
};

//metodo utilizado para la parte de palabras reservadas
template <class T>
bool tablaHash<T>::existe(T dato)
{
    for(int i=0; i < TAM; i++)
        if(tabla[i].existe(dato))
            return true;
    return false;
}

//metodo utilizado para obtener la "top word"
template <class T>
int tablaHash<T>::mayor()
{
    int mayor = 0;
    for(int i=0; i < TAM; i++)
        if(tabla[i].porcentaje() > mayor)
            mayor = tabla[i].porcentaje();
    return mayor;
}

//metodo utilizado para obtener el no. de palabras que cumplen el requisito de repetirse al menos el 10% de la "top word"
template <class T>
int tablaHash<T>::contar()
{
    int cont = 0;
    for(int i=0; i < TAM; i++)
        cont = tabla[i].cuenta2(mayor()*0.1) + cont;
    return cont;
}

//funcion hashing que suma cada letra de la palabra y ese resultado hace residuo con el TAM de la tabla
//Las colisiones se manejan por encadenamiento externo con un abb
template <class T>
void tablaHash<T>::inserta (T dato)
{
    int cont=0;
    for(int i=0; i<dato.length(); i++)
        cont = cont + int(dato[i]);
    int posicion = cont % TAM;
	tabla[posicion].inserta(dato);
	cantidad++;
}

//metodo que se utiliza para desplegar los datos en el archivo html
template <class T>
void tablaHash<T>::carga()
{
    ofstream archSal;
    archSal.open("WordCloud.html");
	//cout << "Cantidad de datos: "<<contar()<<"\n";
	archSal << "<html><body style = \"background-color: White\"><style>h1{ color:#660099; font-size:23pt; text-align:center} as{ color:DarkBlue; font-size:8pt; text-align:center}</style><h1>Word Cloud <as>by LACH</as></h1>";
	for (int i = 0; i < TAM; i++)
        tabla[i].carga(&archSal, mayor(), contar());
	archSal << "</body></html>";
	archSal.close();
}

#endif // TABLAHASH_H_INCLUDED
