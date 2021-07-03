#ifndef COMMONNAME_H
#define COMMONNAME_H
#include <string>
using namespace std;

class CommonName
{
private:
	int ordinal;
	string name;
	
public:
	CommonName(int, string);
	int getOrdinal() { return ordinal; }
	string getName() { return name; }

};

#endif