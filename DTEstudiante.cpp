/*******************************************************************************
 * Programación 4 - Laboratorio 6 - Año 2015
 *
 * Profesor: Pablo Milanese
 * Grupo: 17
 * Integrantes: Juan Pablo Copello - jpcopel@gmail.com
 * 			Gastón Haro - harogaston@gmail.com
 * 			Sofia Honty - sofisho@gmail.com
 * 			Marccio Silva - marcciosilva@gmail.com
 *
 * Archivo: DTEstudiante.cpp
 *******************************************************************************/

#include "DTEstudiante.h"

DTEstudiante::DTEstudiante(string cedula, string nombre, string apellido,
		Date * fechaNac, int telefono, int creditosObtenidos) {
	this->cedula = cedula;
	this->nombre = nombre;
	this->apellido = apellido;
	this->fechaNac = new Date(fechaNac->getDd(), fechaNac->getMm(), fechaNac->getAaaa());
	this->telefono = telefono;
	this->creditosObtenidos = creditosObtenidos;
}

DTEstudiante::~DTEstudiante() {
	delete fechaNac;
}

string DTEstudiante::getCedula() {
	return this->cedula;
}

string DTEstudiante::getNombre() {
	return this->nombre;
}

string DTEstudiante::getApellido() {
	return this->apellido;
}

Date * DTEstudiante::getFechaNac() {
	return this->fechaNac;
}

int DTEstudiante::getTelefono() {
	return this->telefono;
}

int DTEstudiante::getCreditosObtenidos() {
	return this->creditosObtenidos;
}
