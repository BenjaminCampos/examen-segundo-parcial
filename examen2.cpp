//benjamin campos salvador
//ingeneria en computacion
//estructura de datos
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;


struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *raiz;
};
void preOrden(Nodo *&);
void enOrden(Nodo *&);
void postOrden(Nodo *&); 
 
Nodo *crearNodo(int, Nodo*);
void insertarNodo(Nodo *&, int, Nodo *);
void mostrarArbol(Nodo *&, int);
void menu();


 Nodo *arbol = NULL;
int main(){
   menu();
   
     cin.get();
	return 0;
}


void menu(){
	system("color 0b");
	cout<<"\t examen primer parcial ";
	cout<<"\n\t Benjamin Campos Salvador\n";
	cout<<"\t ico 22";
	cout<<"\n\n";
    int dato, opcion, contador=0;
    do{
        cout << "  dijite una opcion para trabajar en el programa" << endl;
        cout << "\t 1.- generar numeros aleatorios" << endl;
        cout << "\t 2.- mostrar como queda el arbol" << endl;
        cout << "\t 3.- dar los recorridos" << endl;
        cout << "\t 4.- Salir" << endl;
        cout << "   inserte opcion:  ";
        cin >> opcion;
        switch(opcion){
            case 1:
                 int n, d;
                srand(time(NULL));
                int numero;
                cout << "cuantas veces desea lanzar la moneda: ";
                cin >> numero;
        
                for(d = 0; d <= numero; d++)
				{
                    n = 0 + rand() % ((2)-(0));//generamos los numeros aleatorios
                    cout << n << " ";
                    insertarNodo(arbol, n, NULL);//aqui es donde se manda los numeros aleatorios a la creacion de los nodos
                }
                cout << endl;
                system("pause");
                system("cls");
                break;
            case 2:
            	system("color 0a");
                mostrarArbol(arbol, contador);
                system("pause");
                break;

            case 3:
            	system("pause");
            	system("cls");
            	system("color 0e");
                cout << "Recorridos " << endl;
                cout << "\t En orden   :  ";   enOrden(arbol);
                cout<<"\n\n";
                cout << "\t Pre Orden  :  ";   preOrden(arbol);
                cout<<"\n\n";
                cout << "\t Post Orden :  ";   postOrden(arbol);
                cout << endl << endl;
                system("pause");
                break;
            case 4:
                break;
            default:
                continue;
        }
        system("cls");
    }while(opcion != 4);
}
void mostrarArbol(Nodo *&arbol, int cont){
    if(arbol==NULL){
        return;
    }else{
        mostrarArbol(arbol->der, cont+1);
        for(int i=0; i<cont; i++){
            cout << "   ";
        }
        cout<< arbol->dato <<endl;
            mostrarArbol(arbol->izq, cont+1);
    }
}

 void preOrden(Nodo *&arbol){
  if(arbol!=NULL){
    cout << arbol->dato <<" ";
    preOrden(arbol->izq);
    preOrden(arbol->der);
  }
}
void enOrden(Nodo *&arbol){
  if(arbol!=NULL){
    enOrden(arbol->izq);
    cout << arbol->dato << " ";
    enOrden(arbol->der);
  }
}
void postOrden(Nodo *&arbol){
  if(arbol!=NULL){
    postOrden(arbol->izq);
    postOrden(arbol->der);
    cout << arbol->dato << " ";
  }
}
Nodo *crearNodo(int n, Nodo *raiz){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->raiz = raiz;
     return nuevo_nodo;
}
void insertarNodo(Nodo *&arbol, int n, Nodo *raiz){
    if(arbol == NULL){
        Nodo *nuevo_nodo = crearNodo(n, raiz);
        arbol = nuevo_nodo;
    }else{
        int valorRaiz = arbol->dato;
        if(n == 0){
            insertarNodo(arbol->izq, n, arbol);
        }else{
            insertarNodo(arbol->der, n, arbol);
        }
    }
}
