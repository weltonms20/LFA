#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main ()
{
	ofstream myfile;
	myfile.open ("exemplo.txt");
	myfile << "Writing this to a file.\n";
	myfile.close();	
	return 0;
}