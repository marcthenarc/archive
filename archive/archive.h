#pragma once

#include <fstream>
#include <string>

class Archive
{
	std::fstream fs;

	std::streamoff l;

public:

	Archive();

	bool toRead(const std::string& fn);
	bool toWrite(const std::string& fn);
	void Close();

	Archive& operator << (const std::string& str);
	Archive& operator >> (std::string& str);

	Archive & operator << (const int &i);
	Archive & operator >> (int &i);

	Archive & operator << (const unsigned char &uc);
	Archive & operator >> (bool &uc);
	Archive & operator << (const bool &uc);
	Archive & operator >> (unsigned char &uc);
	Archive & operator << (const size_t &i);
	Archive & operator >> (size_t &i);

	Archive & operator << (const float& s);
	Archive & operator >> (float& s);
};




