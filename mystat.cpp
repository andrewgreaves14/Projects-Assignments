/*
 * Author: Andrew Greaves
 * Outputs all the information on the file. ie name,type,size,owner,group,permissions
 * access time, modification time, status time and block size
 * Date: October 3rd 2019
 */
#include "fileManager.h"

using namespace std;
int main(int argc, char *argv[]){
	fileManager file(argv[1]);
	string permissions;

	cout<<"Filename: "<<file.getFileName()<<endl;

	if(S_ISREG(file.getType()))
		cout<<"Filetype: Regular File"<<endl;
	else if(S_ISDIR(file.getType()))
		cout<<"Filetype: Directory"<<endl;

	cout<<"Size: "<<file.getSize()<<" bytes"<<endl;

	cout<<"Owner: "<<file.getOwnerString()<<endl;

	cout<<"Group: "<<file.getGroupString()<<endl;

	cout<<"Permissions: ";
	if(file.getType() & S_IRUSR)
		cout<<"r";
	else
		cout<<"-";
	if(file.getType() & S_IWUSR)
		cout<<"w";
	else
		cout<<"-";
	if(file.getType() & S_IXUSR)
		cout<<"x";
	else
		cout<<"-";

	if(file.getType() & S_IRGRP)
		cout<<"r";
	else
		cout<<"-";
	if(file.getType() & S_IWGRP)
		cout<<"w";
	else
		cout<<"-";
	if(file.getType() & S_IXGRP)
		cout<<"x";
	else
		cout<<"-";

	if(file.getType() & S_IROTH)
		cout<<"r";
	else
		cout<<"-";
	if(file.getType() & S_IWOTH)
		cout<<"w";
	else
		cout<<"-";
	if(file.getType() & S_IXOTH)
		cout<<"x"<<endl;
	else
		cout<<"-"<<endl;

	cout<<"Access time: "<<file.getAccessTime()<<endl;

	cout<<"Modification time: "<<file.getModTime()<<endl;

	cout<<"Status change time: "<<file.getStatusTime()<<endl;

	cout<<"Block size: "<<file.getBlockSize()<<endl;


}



