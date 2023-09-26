/*
 * main.cpp
 *
 *  Created on: 7 sep. 2023
 *      Author: julian
 */
#include "Fantasma.h"
//#include "interaccionesFantasma.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	//se crea el objeto fantasma
	unsigned int numeroOpcion=0;
	Fantasma fantasma;
	string pregunta;
	//bienvenida del fantasma
	fantasma.bienvenida();
	//menu de interaccion
	cout<<"usted se ha encontrado con un fantasma que se encuentra detras"<<endl;
	cout<<"de una puerta. quiere hablar con el fantasma o desea salir del lugar?"<<endl;
	do{
	cout<<"(marque  1 para hablar, 2 para salir)"<<endl;
	cout<<"1- hablar con el fantasma"<<endl;
	cout<<"2- salir"<<endl;
	cin>>numeroOpcion;
	cin.ignore();// para ignorar este cin del string
	switch (numeroOpcion){
		case 1:
			cout<<"que le quiere decir?(terminar la pregunta con '?'): "<<endl;
			/*guarda la pregunta que hace el usuario
			 *en la variable pregunta*/
			getline(cin,pregunta,'\n');
			fantasma.recibirPregunta(pregunta);
		break;
		case 2:
			//despedida del fantasma
			fantasma.despedirse();
		break;
		default:
			cout<<"opcion incorrecta. Vuelva a ingresar"<<endl;
	}
	}while(numeroOpcion != 2);
	return 0;
}
