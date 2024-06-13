#include "to_lower_case.h"

string toLowerCase(string str) {
	string lowerStr;
	transform(str.begin(), str.end(), back_inserter(lowerStr), ::tolower);
	return lowerStr;
}