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
 * Archivo: CtrlEstudiante.cpp
 *******************************************************************************/

#include "CtrlEstudiante.h"

CtrlEstudiante::CtrlEstudiante() {
	listadoEstudiantes = NULL;
	cedula = "";
}

CtrlEstudiante::~CtrlEstudiante() {
}

set<DTEstudiante*>* CtrlEstudiante::listarEstudiantes() {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	this->listadoEstudiantes = mb->listarEstudiantes(); // se guarda el listado en memoria

	return this->listadoEstudiantes;
}

bool CtrlEstudiante::seleccionarEstudiante(string cedula) {
	bool encontre = false;
	set<DTEstudiante*>::iterator it = listadoEstudiantes->begin();
	while( it != listadoEstudiantes->end() && not encontre) {
		if (cedula == (*it)->getCedula()) {
			encontre =true;
			this->cedula = cedula;
		}
		it++;
	}

	return encontre;
}

DataEstudiante* CtrlEstudiante::consultarDatosEstudiante() {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();

	return mb->consultarDatosEstudiante(this->cedula);
}

set<FullDTOferta*>* CtrlEstudiante::mostrarNotificacionesDeEstudiante(string cedula) {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();

	return mb->mostrarNotificacionesDeEstudiante(cedula);
}

void CtrlEstudiante::modificarEstudiante(string nombre, string apellido,
		Date* fecha, int tel) {
}

void CtrlEstudiante::addCarrera(string idCarrera) {
}

void CtrlEstudiante::quitCarrera(string idCarrera) {
}

void CtrlEstudiante::addAsignatura(Date* fecha, int nota, string idAs) {
}

void CtrlEstudiante::quitAsignatura(string idAs) {
}
