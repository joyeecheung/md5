#include <cstdio>
#include "md5.h"

namespace joyee {

MD5::MD5() {
  init();
}

void MD5::update(const uint8_t* in, size_t len) {

}

void MD5::update(const char* in, size_t len) {

}

void MD5::finalize() {

}

string MD5::toString() const {
  return string("");
}

void MD5::init() {
  finalized = false;
}

void MD5::transform(const uint8_t block[BLOCK_SIZE]) {

}

inline void MD5::u8atou32a(uint32_t* out, const uint8_t* in, size_t len) {

}

inline void MD5::u32atou8a(uint8_t* out, const uint32_t* in, size_t len) {

}

inline void MD5::u8atou32(uint32_t& out, const uint8_t* in) {

}

inline void MD5::u32tou8a(uint8_t* out, uint32_t in) {

}

string md5(const string str) {
  MD5 md5 = MD5();
  md5.update(str.c_str(), str.size());
  md5.finalize();
  return md5.toString();
}

}
