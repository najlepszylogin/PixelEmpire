#include "Empire.h"

empirec::empirec(int colorr)
{
	colorId = colorr;
	color.r = 255 - colorId;
	color.g = 0;
	color.b = 0;

}