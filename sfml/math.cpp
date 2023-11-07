#include "math.h"

namespace math
{
	bool isPointBetween(int checkPoint, int minPoint, int maxPoint) {
		return minPoint < checkPoint && checkPoint < maxPoint;
	}
}