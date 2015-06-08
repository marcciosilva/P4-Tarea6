/*
 * Sucursal.h
 *
 *  Created on: Jun 7, 2015
 *      Author: marccio
 */

#ifndef SUCURSAL_H_
#define SUCURSAL_H_

#include <string>
#include <set>
#include <map>

#include "DTSeccion.h"
#include "DTSucursal.h"
#include "DataOferta.h"
#include "OfertaLaboral.h"

class Empresa;

using namespace std;

class Sucursal {
private:
	string nombre;
	int telefono;
	string direccion;
	Empresa * empresa;
	map<string, Seccion*> * secciones;
public:
	Sucursal(string nombre,
			int telefono,
			string direccion,
			Empresa * empresa,
			map<string, Seccion*> * secciones);
	~Sucursal();
	DTSucursal * crearDT();
	set<DTSeccion*> * listarSecciones();
	bool seleccionarSeccion(string idSec);
	OfertaLaboral * crearOferta(string idSec, DataOferta * dataOferta);
	DTAplicacion * getDatosSucursal();
	string getNombreEmpresa();
	string getNombre();
	string getDireccion();
	int getTelefono();
};

#include "Empresa.h"

#endif /* SUCURSAL_H_ */