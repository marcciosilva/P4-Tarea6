/*
 * Entrevista.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#include "Entrevista.h"

Entrevista::Entrevista(Date * fecha) {
	this->fecha = fecha;
}

Entrevista::~Entrevista() {
}

Date* Entrevista::getFecha() {
	return this->fecha;
}