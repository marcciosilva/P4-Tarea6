/*
 * Estudiante.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#include "Estudiante.h"
#include <iostream>


Estudiante::Estudiante(string cedula, string nombre, string apellido,
		Date* fecha_nac, int telefono, int creditosObtenidos) {
	this->cedula = cedula;
	this->nombre = nombre;
	this->apellido = apellido;
	this->fecha_nac = fecha_nac;
	this->telefono = telefono;
	this->creditosObtenidos = creditosObtenidos;
	contratos = NULL;
	salvadas = NULL;
	carreras = NULL;
	notificaciones = NULL;
	aplicaciones = NULL;
}

Estudiante::~Estudiante() {
	/*
	for (set<FirmaContrato*>::iterator it = contratos->begin() ;
			it != contratos->end() ; it++) {
		delete * it;
	}
	*/
	contratos->clear();
	delete contratos;
	for (set<Notificacion*>::iterator it = notificaciones->begin() ;
			it != notificaciones->end() ; it++) {
		delete * it;
	}
	notificaciones->clear();
	delete notificaciones;
	salvadas->clear();
	delete salvadas;

}

string Estudiante::getCedula() {
	return cedula;
}

string Estudiante::getNombre() {
	return nombre;
}

string Estudiante::getApellido() {
	return apellido;
}

Date * Estudiante::getFechaNacimiento() {
	return fecha_nac;
}

int Estudiante::getTelefono() {
	return telefono;
}

int Estudiante::getCreditosObtenidos() {
	return creditosObtenidos;
}

DTEstudiante* Estudiante::crearDT() {
	DTEstudiante * dt = new DTEstudiante(
			cedula,
			nombre,
			apellido,
			fecha_nac,
			telefono,
			creditosObtenidos);
	return dt;
}

DataEstudiante* Estudiante::consultarDatosEstudiante() {
	set<DTCarrera*> * setCarreras = NULL;
	for (set<Carrera*>::iterator it = carreras->begin() ;
			it != carreras->end() ; it++) {
		DTCarrera * dt = (*it)->crearDT();
		setCarreras->insert(dt);
	}
	set<DTAsignaturaSalvada*> * setSalvadas = NULL;
	for (set<Salva*>::iterator it = salvadas->begin() ;
			it != salvadas->end() ; it++) {
		DTAsignaturaSalvada * dt = (*it)->getDatosAprobacionAsignatura();
		setSalvadas->insert(dt);
	}
	set<DTAplicacion*> * setAplicaciones = NULL;
	for (set<Aplica*>::iterator it = aplicaciones->begin() ;
			it != aplicaciones->end() ; it++) {
		DTAplicacion * dt = (*it)->getDatosAplicacion();
		setAplicaciones->insert(dt);
	}
	DataEstudiante * dtOut = new DataEstudiante(
			cedula,
			nombre,
			apellido,
			fecha_nac,
			telefono,
			creditosObtenidos,
			setCarreras,
			setSalvadas,
			setAplicaciones);
	return dtOut;
}

set<FullDTOferta*>* Estudiante::mostrarNotificaciones() {
	set<FullDTOferta*> * setOut = NULL;
	for (set<Notificacion*>::iterator it = notificaciones->begin() ; it != notificaciones->end() ; it++) {
		setOut->insert((*it)->mostrarNotificacion());
	}
	return setOut;
}

void Estudiante::cancelarContrato(FirmaContrato* f) {
	for (set<FirmaContrato*>::iterator it = contratos->begin() ;
			it != contratos->end() ; it++) {
		if ((*it)->getOferta()->getNumeroDeExpediente() == f->getOferta()->getNumeroDeExpediente()) {
			contratos->erase(it);
			break;
		}
	}
}

void Estudiante::cancelarAplica(Aplica* a) {
	for (set<Aplica*>::iterator it = aplicaciones->begin() ;
			it != aplicaciones->end() ; it++) {
		if ((*it)->getDatosAplicacion()->getExpedienteOferta() ==
				a->getDatosAplicacion()->getExpedienteOferta()) {
			aplicaciones->erase(it);
			break;
		}
	}
}

bool Estudiante::estaInscripto(int exp) {
	//retorna true si el estudiante no esta inscripto a la oferta laboral (exp)
	for (set<Aplica*>::iterator it = aplicaciones->begin() ;
			it != aplicaciones->end() ; it++) {
		if ((*it)->estaInscripto(exp)) return true;
	}
	return false;
}

void Estudiante::asignarAplicacion(Aplica* a) {
	aplicaciones->insert(a);
}

void Estudiante::asociarContrato(FirmaContrato * fir) {
	contratos->insert(fir);
}

void Estudiante::modificarEstudiante(string nombre, string apellido,
		Date * fecha, int telefono) {
	this->nombre = nombre;
	this->apellido = apellido;
	this->fecha_nac = fecha;
	this->telefono = telefono;
}

void Estudiante::addCarrera(Carrera* c) {
	carreras->insert(c);
}

void Estudiante::quitCarrera(Carrera* c) {
	for (set<Carrera*>::iterator it = carreras->begin() ;
			it != carreras->end() ; it++) {
		if (c->getCodigo() == (*it)->getCodigo()) {
			carreras->erase(it);
			break;
		}
	}
}

void Estudiante::addSalva(Salva* s) {
	creditosObtenidos += s->getAsignatura()->getCreditos();
	salvadas->insert(s);
}

bool Estudiante::esCandidato(set<string>* asignaturasRequeridas) {
	bool candidato = true;
	for (set<string>::iterator it1 = asignaturasRequeridas->begin() ;
			it1 != asignaturasRequeridas->end() ; it1++) {
		bool asignaturaEncontrada = false;
		for (set<Salva*>::iterator it2 = salvadas->begin() ; it2 != salvadas->end() ; it2++) {
			if ((*it2)->getDatosAprobacionAsignatura()->getNombre() == (*it1)) {
				asignaturaEncontrada = true;
				break;
			}
		}
		if (not asignaturaEncontrada) return false;
	}
	return true;
}

set<DTAsignaturaSalvada*>* Estudiante::listarSalvadas() {
	set<DTAsignaturaSalvada*>* setOut = NULL;
	for (set<Salva*>::iterator it = salvadas->begin() ;
			it != salvadas->end() ; it++) {
		DTAsignaturaSalvada * dt = (*it)->getDatosAprobacionAsignatura();
		setOut->insert(dt);
	}
	return setOut;
}

bool Estudiante::asignaturaEnCarrera(string a) {
	for (set<Carrera*>::iterator it = carreras->begin() ;
			it != carreras->end() ; it++) {
		if ((*it)->asignaturaEnCarrera(a)) return true;
	}
	return false;
}

void Estudiante::agregarCreditos(int creditos) {
	creditosObtenidos += creditos;
}

void Estudiante::quitarCreditos(int creditos) {
	creditosObtenidos -= creditos;
	if (creditosObtenidos < 0) creditosObtenidos = 0;
}

void Estudiante::quitAsignatura(Salva* s) {
	for (set<Salva*>::iterator it = salvadas->begin() ;
			it != salvadas->end() ; it++) {
		if (s->getAsignatura()->getCodigo() == (*it)->getAsignatura()->getCodigo()) {
			delete * it;
			salvadas->erase(it);
			break;
		}
	}
}

void Estudiante::notificar(Notificacion * notificacion, set<string> * asignaturas) {
	if (this->esCandidato(asignaturas)) notificaciones->insert(notificacion);
}
