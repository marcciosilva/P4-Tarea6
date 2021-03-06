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
 * Archivo: Aplica.h
 *******************************************************************************/

#ifndef APLICA_H_
#define APLICA_H_

// STL
#include <set>
#include <iterator>

// DataTypes
#include "DTAplicacion.h"
#include "DTEstudiante.h"
#include "Date.h"

// Clases
#include "Entrevista.h"
#include "Estudiante.h"
#include "FechaSistema.h"
#include "OfertaLaboral.h"

using namespace std;

class Aplica {
private:
	Date * fecha;

	set<Entrevista*> * entrevistas;
	Estudiante * estudiante;
	OfertaLaboral * oferta;

public:
	Aplica();
	~Aplica();

	// setters
	void setEstudiante(Estudiante * e);
	void setOferta(OfertaLaboral * o);

	// operaciones
	DTAplicacion * crearDT();
	void cancelar();
	bool estaInscripto(int numExp);
	DTEstudiante * getDTEstudiante();
	void crearEntrevista(Date * fecha);
};

#endif /* APLICA_H_ */
