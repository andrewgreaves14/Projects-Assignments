/*
 * Author: Andrew Greaves
 * Copy the contents of a file to another location
 * Date: October 3rd 2019
 */
#include "fileManager.h"

using namespace std;

int main(int argc, char *argv[]){
	fileManager file1(argv[1]);
	filebuf fb;
	fb.open(argv[2],ios::out);
	ostream outStream(&fb);
	file1.dump(outStream);
}



