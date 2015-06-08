/*
 * FechaSistema.h
 *
 *  Created on: Jun 8, 2015
 *      Author: marccio
 */

#ifndef FECHASISTEMA_H_
#define FECHASISTEMA_H_

#include "Date.h"

class FechaSistema {
private:
	static FechaSistema * instance;
	Date * fecha;
public:
	static FechaSistema * getInstance();
	Date * getFecha();
	void setFecha(Date * d);
};

#endif /* FECHASISTEMA_H_ */