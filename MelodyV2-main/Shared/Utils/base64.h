#ifndef _BASE64_H_
#define _BASE64_H_

#include <vector>
#include <string>
#include <stdint.h>

std::string base64_encode(uint8_t const* buf, unsigned int bufLen);
std::vector<uint8_t> base64_decode(std::string const&);

#endif