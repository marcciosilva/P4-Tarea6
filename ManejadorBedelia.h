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
 * Archivo: ManejadorBedelia.h
 *******************************************************************************/

#ifndef MANEJADORBEDELIA_H_
#define MANEJADORBEDELIA_H_

// STL
#include <map>
#include <set>
#include <string>
#include <iostream>

// DataTypes
#include "DataOferta.h"
#include "DTEstudiante.h"
#include "FullDTOferta.h"

// Clases
#include "IStrategy.h"
#include "Estudiante.h"
#include "Carrera.h"
#include "Asignatura.h"
#include "ManejadorOfertaLaboral.h"
#include "Salva.h"

using namespace std;

class ManejadorBedelia {
private:
	static ManejadorBedelia * instancia;
	ManejadorBedelia();
	IStrategy * estrategia;
	set<string> * estrategiaUno;
	set<string> * estrategiaDos;

	set<IObserver*> * observadores;
	map<string, Estudiante*> * estudiantes;
	map<string, Carrera*> * carreras;
	map<string, Asignatura*> * asignaturas;

public:
	static ManejadorBedelia * getInstance();

	// operaciones
	set<DTEstudiante*> * listarEstudiantes();
	DataEstudiante * consultarDatosEstudiante(string cedula);
	set<DataOferta*> * mostrarNotificacionesDeEstudiante(string cedula);
	set<DTEstudiante*> * listarNoInscriptos(int exp);
	Estudiante * getEstudiante(string cedula);
	bool existeAsignatura(string codigo);
	Estudiante * asignarCargo(FirmaContrato * fir, string cedula);
	void modificarEstudiante(string cedula, string nombre, string apellido, Date * fecha, int tel);
	void addCarrera(string cedula, string idCar);
	void quitCarrera(string cedula, string idCar);
	bool validarAsignaturas(set<string> * asignaturas);
	bool existenCandidatos(set<string> * asignaturas);
	set<string> * getEstrategiaDos(set<string> * asignaturasRequeridas);
	set<string> * getEstrategiaUno();
	set<string> * actualizarRequerimientos(int criterio, set<string> * asignaturasRequeridas);
	void agregarAsignaturas(OfertaLaboral * of, set<string> * asignaturas);
	Asignatura * getAsignatura(string codigo);
	void notificarObservers(DataOferta * dtO);
	void addAsignatura(string cedula, Date * fecha, int nota, string codigo);
	void quitAsignatura(string cedula, string codigo);

/* Estas operaciones no aparece en los
 * diagramas de comunicacion
 * pero sin dudas tienen que estar!!!
 *
 * Es decir, hay que modificarlos
 * para que incluiyan lo del patron
 * Observer.
 */
	void agregar(IObserver * ob);
	void quitar(IObserver * ob);

	// main
	void crearCarrera(string idC, string nombre);
	void crearAsignatura(string codigo, string nombre, int creditos);
	void asociarAsignaturaACarrera(string idAs, string idC);
	void crearEstudiante(string ci, string nom, string ap, Date * fecha_nac, int telefono, int cred);
	void asociarEstudianteACarrera(string ci, string idC);
};

#endif /* MANEJADORBEDELIA_H_ */
