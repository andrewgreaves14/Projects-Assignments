/*
 * Author: Andrew Greaves
 * Used to remove a file
 * Date: October 3rd 2019
 */
#include "fileManager.h"

int main(int argc, char *argv[]){
	fileManager file(argv[1]);
	file.remove();
}




