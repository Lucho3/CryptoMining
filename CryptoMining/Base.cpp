#include "base.h"

std::ostream& operator<<(std::ostream& os, const Base& base) {
    return base.print(os);
}