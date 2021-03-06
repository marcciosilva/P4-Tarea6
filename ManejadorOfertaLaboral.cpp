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
 * Archivo: ManejadorOfertaLaboral.cpp
 *******************************************************************************/

#include "ManejadorOfertaLaboral.h"
#include "ManejadorBedelia.h"
#include <stdexcept>

ManejadorOfertaLaboral * ManejadorOfertaLaboral::instancia = NULL;

ManejadorOfertaLaboral::ManejadorOfertaLaboral() {
	ofertas = new map<int, OfertaLaboral*>;
}

ManejadorOfertaLaboral * ManejadorOfertaLaboral::getInstance(){
	if (instancia == NULL)
		instancia = new ManejadorOfertaLaboral();
	return instancia;
};

set<FullDTOferta*>* ManejadorOfertaLaboral::listarOfertasActivas() {
	set<FullDTOferta*>* salida = new set<FullDTOferta*>;

	for (map<int, OfertaLaboral*>::iterator it = ofertas->begin(); it != ofertas->end(); it++) {
		OfertaLaboral* of = (*it).second;
		if (of->esActiva()) {
			FullDTOferta* temp = of->getFullDatos();
			salida->insert(temp);
		}
	}

	return salida;
}

set<DTOferta*>* ManejadorOfertaLaboral::listarOfertasTodas() {
	set<DTOferta*>* salida = new set<DTOferta*>;

	for (map<int, OfertaLaboral*>::iterator it = ofertas->begin(); it != ofertas->end(); ++it) {
		OfertaLaboral* of = it->second;
		DTOferta * dt = of->crearDT();
		salida->insert(dt);
	}

	return salida;
}

set<DTOferta*>* ManejadorOfertaLaboral::listarOfertasFinalizadas() {
	set<DTOferta*>* salida = new set<DTOferta*>;

	for (map<int, OfertaLaboral*>::iterator it = ofertas->begin(); it != ofertas->end(); ++it) {
		if (it->second->esFinalizada() && (it->second->getPuestosDisponibles() > 0)) {
			DTOferta * dt = it->second->crearDT();
			salida->insert(dt);
		}
	}

	return salida;
}

bool ManejadorOfertaLaboral::seleccionarOferta(int numExp) {
	map<int, OfertaLaboral*>::iterator it;
	it = ofertas->find(numExp);

	return (it != ofertas->end());
}

bool ManejadorOfertaLaboral::seleccionarOfertaActiva(int numExp) {
	map<int, OfertaLaboral*>::iterator it;
	it = ofertas->find(numExp);
	if (it != ofertas->end()) {
		return it->second->esActiva();
	}
	return false;
}

void ManejadorOfertaLaboral::darDeBaja(int numExp) {
	map<int, OfertaLaboral*>::iterator it;
	it = ofertas->find(numExp);
	if (it != ofertas->end()){
		OfertaLaboral* of = (*it).second;
		ofertas->erase(it);
		of->cancelar();
		delete of;
	}
}

bool ManejadorOfertaLaboral::esElegible(int numExp, string cedula) {
	map<int, OfertaLaboral*>::iterator it;
	it = ofertas->find(numExp);

	if (it != ofertas->end()){
		return it->second->esElegible(cedula);
	}
	return false;
}

OfertaLaboral* ManejadorOfertaLaboral::getOfertaLaboral(int numExp) {
	map<int, OfertaLaboral*>::iterator it = ofertas->find(numExp);
	if (it != ofertas->end()) return (*it).second;
	else throw std::invalid_argument("El número de expediente ingresado no coinicide \n con ninguna oferta laboral presente en el sistema.");
}

void ManejadorOfertaLaboral::modificarOferta(int numExp, DataOfertaRestringida * dataOferta) {
	map<int, OfertaLaboral*>::iterator it = ofertas->find(numExp);
	if (it != ofertas->end())
		(*it).second->modificarOferta(dataOferta);
}

bool ManejadorOfertaLaboral::seleccionarAsignatura(bool accion, string codigo, int numExp) {
	map<int, OfertaLaboral*>::iterator it = ofertas->find(numExp);
	if (it != ofertas->end())
		return (*it).second->seleccionarAsignatura(accion, codigo);
	return false;
}

void ManejadorOfertaLaboral::agregarAsignatura(string codigo, int numExp) {
	map<int, OfertaLaboral*>::iterator it = ofertas->find(numExp);
	if (it != ofertas->end()) {
		ManejadorBedelia * mb = ManejadorBedelia::getInstance();
		Asignatura * a = mb->getAsignatura(codigo);
		(*it).second->agregarAsignatura(a);
	}
}

void ManejadorOfertaLaboral::quitarAsignatura(string codigo, int numExp) {
	map<int, OfertaLaboral*>::iterator it = ofertas->find(numExp);
		if (it != ofertas->end()) {
			(*it).second->quitarAsignaturaRequerida(codigo);
		}
}

set<DTEstudiante*>* ManejadorOfertaLaboral::listarInscriptos(int numExp) {
	map<int, OfertaLaboral*>::iterator it = ofertas->find(numExp);
	if (it != ofertas->end()) return it->second->listarInscriptos();
	else return new set<DTEstudiante*>;
}

void ManejadorOfertaLaboral::asignarCargo(FirmaContrato* fir,int numExp) {
	// esta rara esta operacion, si quieren revisarle el diag. de com. esta en AsignacionOfertaEstudiante
	map<int, OfertaLaboral*>::iterator it = ofertas->find(numExp);
	if (it != ofertas->end()) {
		(*it).second->asociarContrato(fir);
	} else throw std::invalid_argument("Expediente no valido.");
}

bool ManejadorOfertaLaboral::agendarEntrevista(Date* fecha, int numExp) {
	map<int, OfertaLaboral*>::iterator it = ofertas->find(numExp);
	return (*it).second->agendarEntrevista(fecha);
}

void ManejadorOfertaLaboral::crearEntrevista(int numExp, string cedula, Date* fecha) {
	map<int, OfertaLaboral*>::iterator it = ofertas->find(numExp);
	(*it).second->crearEntrevista(cedula, fecha);
}

bool ManejadorOfertaLaboral::chequearExpedienteDisponible(int numExp) {
	map<int, OfertaLaboral*>::iterator it = ofertas->find(numExp);
	return (it == ofertas->end()); //devuelve TRUE si no existe la oferta
}

void ManejadorOfertaLaboral::agregarOfertaLaboral(OfertaLaboral* of) {
	ofertas->insert(pair<int, OfertaLaboral*>(of->getNumeroDeExpediente(), of));
}

void ManejadorOfertaLaboral::asociarAsignaturaAOferta(OfertaLaboral* of,
		Asignatura* asignatura) {
	of->agregarAsignatura(asignatura);
}

ManejadorOfertaLaboral::~ManejadorOfertaLaboral() {
	ofertas->clear(); //cada seccion borra sus ofertas
}

void ManejadorOfertaLaboral::destroyInstance() {
	if (instancia != NULL) {
		delete instancia;
		instancia = NULL;
	}
}
