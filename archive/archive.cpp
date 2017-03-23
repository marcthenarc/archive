#include "stdafx.h"
#include "archive.h"
#include <vector>
#include <iostream>

Archive::Archive()
{

}

bool Archive::toRead(const std::string& fn)
{
	fs.open(fn.c_str(), std::ios::binary | std::ios::in);

	return fs.is_open();
}

bool Archive::toWrite(const std::string& fn)
{
	fs.open(fn.c_str(), std::ios::binary | std::ios::out);

	return fs.is_open();
}

void Archive::Close()
{
	if (fs.is_open())
		fs.close();
}

#define WRITE(x) fs.write(reinterpret_cast<const char*>(&x), sizeof(x));  return *this
#define READ(x) fs.read(reinterpret_cast<char*>(&x), sizeof(x)); return *this

Archive& Archive::operator << (const int& i)
{
	WRITE(i);
}

Archive& Archive::operator >> (int& i)
{
	READ(i);
}
Archive& Archive::operator << (const size_t& s)
{
	WRITE(s);
}

Archive& Archive::operator >> (size_t& s)
{
	READ(s);
}

Archive& Archive::operator << (const float& f)
{
	WRITE(f);
}

Archive& Archive::operator >> (float& f)
{
	READ(f);
}

Archive& Archive::operator << (const unsigned char& uc)
{
	WRITE(uc);
}

Archive& Archive::operator << (const bool& b)
{
	WRITE(b);
}

Archive& Archive::operator >> (bool& b)
{
	READ(b);
}

Archive& Archive::operator >> (unsigned char& b)
{
	READ(b);
}

Archive& Archive::operator << (const std::string& str)
{
	size_t s = str.size();

	*this << s;

	fs.write(str.c_str(), s);
	return *this;
}

Archive& Archive::operator >> (std::string& str)
{
	size_t s;
	*this >> s;
	std::vector<char> v;
	v.resize(s + 1);
	fs.read(v.data(), s);
	str.assign(v.data());

	return *this;
}


