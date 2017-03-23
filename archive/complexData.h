#pragma once

#include "Archive.h"

class ComplexData
{
public:

	int x;
	float y;
	bool z;
	std::string w;

	ComplexData();

};

Archive& operator << (Archive& ar, const ComplexData& cd);
Archive& operator >> (Archive& ar, ComplexData& cd);
