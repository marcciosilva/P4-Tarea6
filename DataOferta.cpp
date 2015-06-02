/*
 * DataOferta.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#include "DataOferta.h"

DataOferta::DataOferta() {
	numero_de_expediente = 0;
	titulo = "";
	descripcion = "";
	horas_semanales = 0;
	sueldo_min = 0.0;
	sueldo_max = 0.0;
	comienzo_llamado = NULL;
	fin_llamado = NULL;
	puestos_disponibles = 0;
	asignaturasRequeridas = NULL;
}

DataOferta::DataOferta(int numero_de_expediente, string titulo,
		string descripcion, int horas_semanales, float sueldo_min,
		float sueldo_max, Date& comienzo_llamado, Date& fin_llamado,
		int puestos_disponibles, vector<string>& asignaturasRequeridas) {
	this->numero_de_expediente = numero_de_expediente;
	this->titulo = titulo;
	this->descripcion = descripcion;
	this->horas_semanales = horas_semanales;
	this->sueldo_min = sueldo_min;
	this->sueldo_max = sueldo_max;
	this->comienzo_llamado = &comienzo_llamado;
	this->fin_llamado = &fin_llamado;
	this->puestos_disponibles = puestos_disponibles;
	this->asignaturasRequeridas = &asignaturasRequeridas;
}

DataOferta::~DataOferta() {
	asignaturasRequeridas->erase(asignaturasRequeridas->begin(), asignaturasRequeridas->end());
	delete(comienzo_llamado);
	delete(fin_llamado);
}

vector<string>* DataOferta::getAsignaturasRequeridas() {
	return this->asignaturasRequeridas;
}

Date* DataOferta::getComienzoLlamado() {
	return this->comienzo_llamado;
}

string DataOferta::getDescripcion() {
	return this->descripcion;
}

Date* DataOferta::getFinLlamado() {
	return this->fin_llamado;
}

int DataOferta::getHorasSemanales() {
	return this->horas_semanales;
}

int DataOferta::getNumeroDeExpediente() {
	return this->numero_de_expediente;
}

int DataOferta::getPuestosDisponibles() {
	return this->puestos_disponibles;
}

float DataOferta::getSueldoMax() {
	return this->sueldo_max;
}

float DataOferta::getSueldoMin() {
	return this->sueldo_min;
}

string DataOferta::getTitulo() {
	return this->titulo;
}
