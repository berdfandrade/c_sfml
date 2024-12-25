#include "collision.h"
#include <stdbool.h>

bool checkCirclCollision(float x1, float y1, float r1, float x2, float y2, float r2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float distance = sqrt(dx * dx + dy * dy);
    return distance <= (r1 + r2); 
}

