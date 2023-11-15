#include "math.h"
#include <iostream>

namespace math
{
	bool isPointBetween(int checkPoint, int minPoint, int maxPoint) {
		if (minPoint <= checkPoint && checkPoint <= maxPoint) {
			return true;
		}
		return false;
	}
	/*float normVector(int point, float fDirectionX, float fDirectionY) {
		fDirectionX = fDirectionX / sqrt(pow(fDirectionX,2)+pow(fDirectionY,2));
		fDirectionY = fDirectionY / sqrt(pow(fDirectionX,2)+pow(fDirectionY,2));
	}*/
}