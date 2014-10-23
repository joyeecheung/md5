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

// LSB first
string byteToString(const uint8_t* arr) {
  std::ostringstream ss;
  for (size_t i = 0; i < 3; ++i) {
    ss << +arr[i] << ' ';
  }
  ss << + arr[3];
  return ss.str();
}

bool byteEqual(const uint8_t* a, const uint8_t* b) {
  for (size_t i = 0; i < 4; ++i) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

void testEncoder(const uint32_t src, const uint8_t* expected) {
  static int count = 1;
  uint8_t actual[4];
  MD5::u32tou8a(actual, src);

  if (byteEqual(actual, expected)) {
    cout << "[PASS] Encoder Test " << count << ":\n";
  } else {
    cout << "[FAIL] Test " << count << ":\n";
  }

  cout << "         SRC: "
       << std::showbase << std::hex << src
       << std:: dec << std::noshowbase << '\n';
  cout << "    EXPECTED: " << byteToString(expected) << "(little endian)\n";
  cout << "      ACTUAL: " << byteToString(actual) << "(little endian)\n";
  cout << "---------------------------------------------------------------\n";
  count++;
}

void testDecoder(const uint8_t* src, const uint32_t expected) {
  static int count = 1;
  uint32_t actual = 0;
  MD5::u8atou32(actual, src);

  if (actual == expected) {
    cout << "[PASS] Decoder Test " << count << ":\n";
  } else {
    cout << "[FAIL] Test " << count << ":\n";
  }

  cout << "         SRC: " << byteToString(src) << "(little endian)\n";
  cout << "    EXPECTED: " << std::showbase << std::hex << expected
       << std:: dec << std::noshowbase << '\n';
  cout << "      ACTUAL: " << std::showbase << std::hex << actual
       << std:: dec << std::noshowbase << '\n';
  cout << "---------------------------------------------------------------\n";
  count++;
}

void runTests() {
  uint8_t u8a1[4] = {0, 0, 0, 0};
  uint8_t u8a2[4] = {255, 255, 255, 255};
  uint8_t u8a3[4] = {0, 0, 255, 255};
  uint32_t u32i1 = 0;
  uint32_t u32i2 = 0xffffffff;
  uint32_t u32i3 = 0xffff0000;

  cout << "---------------------------------------------------------------\n";
  cout << "Test encoders\n";
  cout << "---------------------------------------------------------------\n";

  testEncoder(u32i1, u8a1);
  testEncoder(u32i2, u8a2);
  testEncoder(u32i3, u8a3);

  cout << "---------------------------------------------------------------\n";
  cout << "Test decoders\n";
  cout << "---------------------------------------------------------------\n";

  testDecoder(u8a1, u32i1);
  testDecoder(u8a2, u32i2);
  testDecoder(u8a3, u32i3);

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