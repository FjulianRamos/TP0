/*
 * interaccionesFantasma.h
 *
 *  Created on: 7 sep. 2023
 *      Author: julian
 */

#ifndef INTERACCIONESFANTASMA_H_
#define INTERACCIONESFANTASMA_H_
//pre:
//post:da una calida? bienvenida al usuario.
void darBienvenida();
//post: responde al usuario cuando pregunta por su nombre
void responderPorNombre();
//post: responde el tiempo que paso en ese lugar
void responderPorTiempo();
//post: devuelve texto en pantalla diciendo donde se encuentra.
void responderDondeEsta();
//post: devuelve un indicador de la placa arduino
void responderComoEsta();
//post: devuelve simbolos que suponen silencio
void responderSilencio();
//post: devuelve un sonido de una puerta agitandose.
void agitarPuerta();
//post: devuelve sonido de una puerta abriendose
void abrirPuerta();
//post: devuelve sonido de risa demoniaca
void risaDemoniaca();

//void responderNada();
//post: devuelve por pantalla una despedida del fantasma
void despedirseDeUsuario();


#endif /* INTERACCIONESFANTASMA_H_ */
