#include <iostream>

using namespace std;

struct Nodo{
	int dato;
	struct Nodo *siguiente;
};
Nodo* cola=NULL;

void agregar(int nuevo){
	if (cola==NULL){
		cola=new Nodo();
		cola->dato=nuevo;
		cola->siguiente=NULL;
	}else{
		Nodo* aux=cola;
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=new Nodo();
		aux=aux->siguiente;
		aux->dato=nuevo;
		aux->siguiente=NULL;
	}
}

int mostrar(){
	if (cola!=NULL){
		cout<<"\nEl valor que se encuentra primero es: ";
		cout<<cola->dato<<endl;
	}else{
		cout<<"\nNo existen valores en la cola"<<endl;
	}
	cout<<endl;
}

void eliminar(){
	if (cola==NULL) return;
	Nodo* aux=cola;
	cola=cola->siguiente;
	delete aux;
	cout<<"\nValor Eliminado\n"<<endl;
}

void menu(){
    cout<<"\nMenú de opciones \n"<<endl;
    cout<<"1 Insertar valor \n"<<"2 Mostrar valor \n"<<"3 Eliminar valor \n"<<"4 Salir \n"<<endl;
    cout<<"Elige una opción del menú: \n"<<endl;
}

int main(){
	char *locale;
    locale=setlocale(LC_ALL,"");
	int opcion, nuevo;
	int repetir=true;
	while(repetir){
		system("CLS");
		menu();
		cin>>opcion;
		if(opcion==1){
            system("CLS");
            cout<<"Ingresa un valor: ";
            cin>>nuevo;
			agregar(nuevo);	
		}else if(opcion==2){
			system("CLS");
			mostrar();
			system ("pause");
		}else if(opcion==3){
			system("CLS");
			eliminar();
			system ("pause");
		}else {
			break;
		}
	}
	return 0;
}
