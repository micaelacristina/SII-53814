// Raqueta.cpp: implementation of the Raqueta class.
//
//////////////////////////////////////////////////////////////////////

#include "Raqueta.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Raqueta::Raqueta()
{
	
}

Raqueta::~Raqueta()
{

}

void Raqueta::Mueve(float t)
{
y1+= velocidad.y*t; // mueve el pto y del primer extremo, actualizando su posicion en funcion de la velocidad*tiempo (lo que se ha desplazado), añadiendoselo al pto inicial y1
x1+= velocidad.x*t; // mueve el pto x del primer extremo
y2+= velocidad.y*t; // mueve el pto y del segundo extremo
x2+= velocidad.x*t; // mueve el pto x del segundo extremo

}
