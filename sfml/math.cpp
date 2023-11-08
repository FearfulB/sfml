#include "math.h"

namespace math
{
	bool isPointBetween(int checkPoint, int minPoint, int maxPoint) {
		if (minPoint < checkPoint && checkPoint < maxPoint) {
			return true;
		}
		return false;
	}
}