#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>

class Base {
private:
    virtual std::ostream& print(std::ostream& os) const = 0;
public:
    friend std::ostream& operator<<(std::ostream& os, const Base& base);
};

#endif