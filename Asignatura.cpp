/*
 * Asignatura.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: sofia
 */

#include "Asignatura.h"

Asignatura::Asignatura() {
	codigo = "";
	nombre = "";
	creditos = 0;
}

Asignatura::Asignatura(string codigo, string nombre, int creditos) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->creditos = creditos;
}

Asignatura::~Asignatura() {
}

void Asignatura::asociarAsignaturaOferta(OfertaLaboral& of) {
}

bool Asignatura::fueSalvada(string ci) {
	return NULL;
}

DTAsignaturaSalvada Asignatura::getDatosAprobacionAsignatura() {
	DTAsignaturaSalvada dt;
	return dt;
}
