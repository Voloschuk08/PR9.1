// sum.cpp
#include "sum.h"
#include "dod.h"
#include "var.h"
#include <cmath>

using namespace nsDod;
using namespace nsVar;

void nsSum::sum() {
    n = 0;
    a = 1.0 / x; // Перший член ряду
    s = a;
    do {
        n++;
        dod(); // виклик функції обчислення доданку
        s += a;
    } while (fabs(a) >= eps);
}
