/*
 * Author: Andrew Greaves
 * Used to rename and move files around
 * Date: October 3rd 2019
 */
#include "fileManager.h"

using namespace std;

int main(int argc, char *argv[]){
	fileManager file1(argv[1]);
	filebuf fb;
	fb.open(argv[2],ios::out);
	ostream outStream(&fb);
	file1.renameFile(argv[2]);
	if(file1.getErrNum()==EXDEV && (S_ISREG(file1.getType()))){
		file1.dump(outStream);
		file1.remove();
	}
}



