/*
 * Fantasma.h
 *
 *  Created on: 7 sep. 2023
 *      Author: julian
 */

#ifndef FANTASMA_H_
#define FANTASMA_H_
#include <string>
#define MAX_CANTIDAD_CARACTERES 50
#define MAX_PREGUNTAS 5
#define PALABRA_MIEDO "miedo"
#define PALABRA_ABRE "abre"
#define PALABRA_ABRO "abro"
#define PALABRA_ABRIR "abrir"

class Fantasma {
private:
	unsigned int numeroDePregunta;
	bool nombroMiedo;

	//pre: recibe la pregunta con mayusculas y minusculas
	//post: devuelve la pregunta en letras minusculas.
	std::string convertirEnMinuscula(std::string pregunta);
public:
	//constructor
	Fantasma();

	//pre:
	//post: devuelve el numero de preguntas que se hicieron
	unsigned int getNumeroDePregunta();

	//pre: recibe el numero de pregunta a modificar
	//post:
	void setNumeroDePregunta(unsigned int numeroDePregunta);

	//pre:
	//post devuelve true si se dijo la palabra miedo, false caso contrario.
	bool getNombroMiedo();

	//pre:recibe un booleano que cambia el estado del atributo
	//post:
	void setNombroMiedo(bool tieneMiedo);

	//pre:
	//post: el usuario recibe la binvenida del fanatasma
	void bienvenida();
	//pre:recibe un string para analizar la respuesta del fantasma.
	//post: da una respuesta segun a la pregunta()
	void recibirPregunta(std::string pregunta);
	//pre:
	//post: el fantasma se despide del usuario.
	void despedirse();

	//virtual ~Fantasma();
};

#endif /* FANTASMA_H_ */
