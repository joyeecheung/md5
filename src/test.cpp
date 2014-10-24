#include <iostream>
#include <sstream>
#include <fstream>
#include "test.h"

using std::cout;
using std::ifstream;
using std::getline;

namespace joyee {

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
static const string slash = "\\";
#else
static const string slash = "/";
#endif

void testMD5(const string src, const string expected) {
  static int count = 1;
  string actual = md5(src);

  if (actual == expected) {
    cout << "[PASS] MD5 Test " << count << ":\n";
  } else {
    cout << "[FAIL] Test " << count << ":\n";
  }

  cout << "         SRC: " << src << '\n';
  cout << "    EXPECTED: " << expected << '\n';
  cout << "      ACTUAL: " << actual << '\n';
  cout << "---------------------------------------------------------------\n";
  count++;
}

void runTests() {
  cout << "---------------------------------------------------------------\n";
  cout << "Test MD5\n";
  cout << "---------------------------------------------------------------\n";

  ifstream testin, testout;

  string inpath = "testcase";
  inpath += slash;
  inpath += "in";

  string outpath = "testcase";
  outpath += slash;
  outpath += "out";

  testin.open(inpath.c_str());
  testout.open(outpath.c_str());
  string instr, outstr;

  while (getline(testin, instr)) {
    getline(testout, outstr);
    testMD5(instr, outstr);
  }

  testin.close();
  testout.close();
}

}
