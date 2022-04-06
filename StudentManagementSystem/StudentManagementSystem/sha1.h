/*
SHA-1 hash function header
Credit: https://github.com/vog/sha1
*/

#ifndef SHA1_H
#define SHA1_H

#include "Header.h"

class SHA1
{
public:
	SHA1();
	void update(const std::string &s);
	void update(std::istream &is);
	std::string final();

private:
	uint32_t digest[5];
	std::string buffer;
	uint64_t transforms;
};


#endif // SHA1_H