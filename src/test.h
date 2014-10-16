#include <iostream>
#include <string>
#include "md5.h"

using std::cout;
using std::string;

#ifndef TEST_H
#define TEST_H

namespace joyee {

void testMD5(const string src, const string expected);

}

#endif