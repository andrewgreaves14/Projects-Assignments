/*
 * Author: Andrew Greaves
 * Compares two files and outputs if they are the same or not
 * Date: October 3rd 2019
 */
#include "fileManager.h"

int main(int argc, char *argv[]){
	fileManager file1(argv[1]);
	std::ifstream file2(argv[2]);

	file1.compare(file2);
}




