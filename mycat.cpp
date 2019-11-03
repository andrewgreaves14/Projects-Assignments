/*
 * Author: Andrew Greaves
 * Displays the contents of all files given as parameters by the user
 * Date: October 3rd 2019
 */
#include "fileManager.h"

using namespace std;

int main(int argc, char *argv[]) {
	string line;
	filebuf fb;
	ifstream outFile;
	fb.open("temptext.txt", ios::out); //creates a temporary file to store the contents of parameters
	ostream outStream(&fb);
	for(int i=1;i<argc;i++){
		fileManager file1(argv[i]);
		file1.dump(outStream);
	}
	outFile.open("temptext.txt");
	while(!outFile.eof()){
		getline(outFile,line); // prints concatenated files
		cout<<"\n"<<line;
	}
	outFile.close();
	fb.close();
	fileManager file2("temptext.txt");
	file2.remove(); //removes temporary file
}

