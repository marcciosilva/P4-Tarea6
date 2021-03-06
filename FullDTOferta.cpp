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
 * Archivo: FullDTOferta.cpp
 *******************************************************************************/

#include "FullDTOferta.h"

FullDTOferta::FullDTOferta(int numero_de_expediente, string titulo,
		string descripcion, int horas_semanales, float sueldo_min,
		float sueldo_max, Date * comienzo_llamado, Date * fin_llamado,
		int puestos_disponibles, string empresa, string ubicacionSucursal,
		int cantidad_inscriptos) {
	this->numero_de_expediente = numero_de_expediente;
	this->titulo = titulo;
	this->descripcion = descripcion;
	this->horas_semanales = horas_semanales;
	this->sueldo_min = sueldo_min;
	this->sueldo_max = sueldo_max;
	this->comienzo_llamado = new Date(comienzo_llamado->getDd(), comienzo_llamado->getMm(), comienzo_llamado->getAaaa());
	this->fin_llamado = new Date(fin_llamado->getDd(), fin_llamado->getMm(), fin_llamado->getAaaa());
	this->puestos_disponibles = puestos_disponibles;
	this->empresa = empresa;
	this->ubicacionSucursal = ubicacionSucursal;
	this->cantidad_inscriptos = cantidad_inscriptos;
}

FullDTOferta::~FullDTOferta() {
	delete comienzo_llamado;
	delete fin_llamado;
}

string FullDTOferta::getEmpresa() {
	return this->empresa;
}

string FullDTOferta::getUbicacionSucursal() {
	return this->ubicacionSucursal;
}

int FullDTOferta::getCantidadInscriptos() {
	return this->cantidad_inscriptos;
}

Date * FullDTOferta::getComienzoLlamado() {
	return this->comienzo_llamado;
}

string FullDTOferta::getDescripcion() {
	return this->descripcion;
}

Date * FullDTOferta::getFinLlamado() {
	return this->fin_llamado;
}

int FullDTOferta::getHorasSemanales() {
	return this->horas_semanales;
}

int FullDTOferta::getNumeroDeExpediente() {
	return this->numero_de_expediente;
}

int FullDTOferta::getPuestosDisponibles() {
	return this->puestos_disponibles;
}

float FullDTOferta::getSueldoMax() {
	return this->sueldo_max;
}

float FullDTOferta::getSueldoMin() {
	return this->sueldo_min;
}

string FullDTOferta::getTitulo() {
	return this->titulo;
}
