#include <iostream>
#include "Roster.h"
#include "Student.h"
using namespace std;

int main() {
	Roster roster;
	roster.parse();
	roster.printAll();
	return 0;
}