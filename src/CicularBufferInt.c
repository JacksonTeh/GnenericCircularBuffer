#include "CicularBufferInt.h"

void copyInt(void *source, void *dest)
{
	int *obj = (int *)source;
	int *cbBuffer = (int *)dest;
	
	*cbBuffer = *obj ;
}