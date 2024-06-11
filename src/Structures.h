// Structures.h
#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <vector>
#include <string>

struct DBDataStruct
{
	std::string dbPath;
	std::vector<std::string> tables;
	int error;
};

#endif