/*
 * Fantasma.cpp
 *
 *  Created on: 7 sep. 2023
 *      Author: julian
 */

#include "Fantasma.h"
#include "interaccionesFantasma.h"
#include <iostream>
#include <string>
#include <algorithm> // para usar la funcion reverse
//#include <chrono>
using namespace std;
/*************PRIVATE****************************/

//CONSTRUCTOR
Fantasma::Fantasma() {
	this->numeroDePregunta=0;
	this->nombroMiedo = false;
}
//metodo privado

string Fantasma::convertirEnMinuscula(string pregunta){

	//para pasar el texto con mayusculas en minusculas
	/*for(auto x:pregunta){
			pregunta= (char)tolower(x);
	}*/

	for(size_t i=0;i<(pregunta.length());i++){
			pregunta[i]= (char)tolower(pregunta[i]);
		}
	return pregunta;
}

unsigned int Fantasma::getNumeroDePregunta(){
	return this->numeroDePregunta;
}

void Fantasma::setNumeroDePregunta(unsigned int numeroDePregunta){
	this->numeroDePregunta = numeroDePregunta;
}

bool Fantasma::getNombroMiedo(){
	return this->nombroMiedo;
}

void Fantasma::setNombroMiedo(bool tieneMiedo){
	this->nombroMiedo = tieneMiedo;
}

/************METODOS PUBLICOS****************************/


void Fantasma::bienvenida(){
	darBienvenida();
}

void Fantasma::recibirPregunta(string pregunta){
	//variable para usar cuando se invierta la pregunta
	string preguntaOriginal=pregunta;
	//variable para pasar la pregunta a letras minusculas
	string preguntaEnMinuscula = this->convertirEnMinuscula(pregunta);
	//variable para ubicar la posicion de la palabra si se nombra o no
	size_t posicionPalabraReservada;
	bool encontroPalabra=false;
	if(((this->getNumeroDePregunta())<MAX_PREGUNTAS)&&(!this->getNombroMiedo())){
		//analizando la palabra miedo
		posicionPalabraReservada = preguntaEnMinuscula.find(PALABRA_MIEDO);
		if (posicionPalabraReservada != string::npos){
			//la palabra se encuentra en la pregunta
			this->setNombroMiedo(posicionPalabraReservada != string::npos);
			abrirPuerta();
			risaDemoniaca();
			}else{
				//analizando las palabras abro,abrir y abre
				//si alguna de las tres aparece se agitara la puerta
				posicionPalabraReservada = preguntaEnMinuscula.find(PALABRA_ABRE);
				if (posicionPalabraReservada != string::npos){
					encontroPalabra=true;
					agitarPuerta();
				}
				posicionPalabraReservada = preguntaEnMinuscula.find(PALABRA_ABRIR);
				if (posicionPalabraReservada != string::npos){
					encontroPalabra=true;
					agitarPuerta();
				}
				posicionPalabraReservada = preguntaEnMinuscula.find(PALABRA_ABRO);
				if (posicionPalabraReservada != string::npos){
					encontroPalabra=true;
					agitarPuerta();
				}
				posicionPalabraReservada = preguntaEnMinuscula.find("como te llamas?");
				if (posicionPalabraReservada != string::npos){
					encontroPalabra=true;
					responderPorNombre();
				}
				posicionPalabraReservada = preguntaEnMinuscula.find("cuantos años tenes?");
				if (posicionPalabraReservada != string::npos){
					encontroPalabra=true;
					responderPorTiempo();
				}
				posicionPalabraReservada = preguntaEnMinuscula.find("donde estas?");
				if (posicionPalabraReservada != string::npos){
					encontroPalabra=true;
					responderDondeEsta();
				}
				posicionPalabraReservada = preguntaEnMinuscula.find("como estas?");
				if (posicionPalabraReservada != string::npos){
					encontroPalabra=true;
					responderComoEsta();
				}
				/*si no entra en las otras preguntas reservadas se pasara
				a analizar la pregunta segun otros casos*/
				if (!encontroPalabra){
					if (preguntaOriginal.length() > MAX_CANTIDAD_CARACTERES){
						responderSilencio();
					}else{
						reverse(preguntaOriginal.begin(),preguntaOriginal.end());
						cout<<preguntaOriginal<<endl;
					}
				}
			}
	this->setNumeroDePregunta(this->getNumeroDePregunta()+1);
	}else{
	/*cuando se supera al numero de preguntas o
	 luego de que el usuario uso la palabra miedo
	 (fin de interaccion del fantasma con el usuario)*/
	responderSilencio();
	}
}

void Fantasma::despedirse(){
	despedirseDeUsuario();
}
