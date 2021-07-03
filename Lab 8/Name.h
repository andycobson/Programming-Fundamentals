#ifndef NAME_H
#define NAME_H
#include <string>
#include "CommonName.h"
using namespace std;
class Name
{
private:
	CommonName* namepair[1000] = { nullptr };
	int nextName;

public:
	Name();
	class invalidInput {};
	void addName(CommonName*);
	void sortNames(int, int);
	int findLinear(string);
	int findBinary(string);
	void printSort();
	
private:
	int partition(int, int);
};

#endif