#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <class T>
class NodoArbol
{ public:
    int cont;
	T info;
	NodoArbol<T> *izq, *der;
	NodoArbol() { izq = der = NULL; cont = 1;}
	NodoArbol(T dato) { info = dato; izq = der = NULL; cont = 1;}
};


template <class T>
class ABB
{
private:
		NodoArbol<T> *raiz;
public:
		ABB() { raiz = NULL;}
		bool existe (T dato);
		void inserta (T valor) { insertaR(raiz, valor); }
		void carga(ofstream *archSal, int mayor, int contar) { cargaR(raiz, *archSal, mayor, contar);}
		int porcentaje() { int maximo = 0; return porcentajeR(raiz, maximo); }
		int cuenta2(int mayEsp) { return contar2(raiz, mayEsp); }
		~ABB() { libera(raiz); }
};

template <class T>
bool ABB<T>::existe(T dato)
{
	NodoArbol<T> *aux = raiz;
	while (aux != NULL && aux->info != dato)
		aux = (dato < aux->info? aux->izq : aux->der);
	return !(aux == NULL);
}

//se recorre el arbol para obtener la "top word"
template <class T>
int porcentajeR(NodoArbol<T>* raiz, int &maximo)
{
    if(raiz != NULL)
    {
        porcentajeR(raiz->izq, maximo);
        if(raiz->cont > maximo)
            maximo = raiz->cont;
        porcentajeR(raiz->der, maximo);
    }
    return maximo;
}

//se carga las palabras al html con ciertas condiciones de acuerdo a sus repeticiones
template <class T>
void cargaR(NodoArbol<T>* raiz, ofstream &archSal, int mayor, int contar)
{
    if(raiz != NULL)
    {
        cargaR(raiz->izq, archSal, mayor, contar);
        if(raiz->cont > (mayor * 0.1))
        {
            archSal << "<span style=\"color: rgb(70,70," << raiz->cont * 255 / mayor << "); line-height:100%; font-size:";
            if(contar < 25)
                archSal << (raiz->cont * 155 / mayor);
            else if(contar < 51)
                archSal << (raiz->cont * 130 / mayor);
            else if(contar <76)
                archSal << (raiz->cont * 115 / mayor);
            else if(contar <101)
                archSal << (raiz->cont * 100 / mayor);
            else if(contar <126)
                archSal << (raiz->cont * 90 / mayor);
            else if(contar <151)
                archSal << (raiz->cont * 85 / mayor);
            else if(contar <176)
                archSal << (raiz->cont * 70 / mayor);
            else if(contar < 201)
                archSal << (raiz->cont * 55 / mayor);
            else if(contar <226)
                archSal << (raiz->cont * 40 / mayor);
            else if(contar <251)
                archSal << (raiz->cont * 25 / mayor);
            else
                archSal << (raiz->cont * 20 / mayor);
            archSal <<"pt\">" << raiz->info << "       " /*<< raiz->cont*/ << "</span>";
        }
        cargaR(raiz->der, archSal, mayor, contar);
    }
}

//Para obtener un anticipado de cuantas palabras se desplegaran
template <class T>
int contar2 (NodoArbol<T>* raiz, int mayEsp)
{
	if (raiz == NULL)
		return 0;
	return((raiz->cont > mayEsp ? 1:0)+contar2(raiz->izq, mayEsp)+contar2(raiz->der, mayEsp));
}

//se insertan en el arbol de manera recursiva
template <class T>
void insertaR (NodoArbol<T>*& raiz, T valor)
{
	if(raiz == NULL)
        raiz = new NodoArbol<T>(valor);
    else if(raiz->info == valor)
        raiz->cont++;
    else if(raiz->info > valor)
        insertaR(raiz->izq, valor);
    else
        insertaR(raiz->der, valor);
}

//metodo destructor
template <class T>
void libera (NodoArbol<T>* raiz)
{
	if (raiz != NULL)
	{ 	libera(raiz->izq);
		libera(raiz->der);
		delete(raiz);
	}
}


#endif // BST_H_INCLUDED
