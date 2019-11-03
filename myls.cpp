/*
 * Author: Andrew Greaves
 * Lists the contents of a directory, and gives the permissions of a file or contents of a
 * directory if -l is included. If no parameters are included it lists the contents of
 * the current directory
 * Date: October 3rd 2019
 */
#include "fileManager.h"

using namespace std;

int main(int argc, char *argv[]) {
	vector<fileManager*> children;
	std::string option="";
	if(argc>1)
		option = argv[1];

	if (argc == 1) { //If no arguments are provided by user
		fileManager file1(".");
		children = file1.expand();
		for (int i = 0; i < children.size(); i++)
			cout << "Filename: " << children[i]->getFileName()<<endl;
	}

	else if (argc == 2 && option.compare("-l") == 0) { //if -l is provided but no file/directory name
		fileManager file1(".");
		children = file1.expand();
		for (int i = 0; i < children.size(); i++) {
			cout <<"Filename: "<< children[i]->getFileName()<<"\n";
			cout << "Permissions: ";
			if (children[i]->getType() & S_IRUSR)
				cout << "r";
			else
				cout << "-";
			if (children[i]->getType() & S_IWUSR)
				cout << "w";
			else
				cout << "-";
			if (children[i]->getType() & S_IXUSR)
				cout << "x";
			else
				cout << "-";
			if (children[i]->getType() & S_IRGRP)
				cout << "r";
			else
				cout << "-";
			if (children[i]->getType() & S_IWGRP)
				cout << "w";
			else
				cout << "-";
			if (children[i]->getType() & S_IXGRP)
				cout << "x";
			else
				cout << "-";

			if (children[i]->getType() & S_IROTH)
				cout << "r";
			else
				cout << "-";
			if (children[i]->getType() & S_IWOTH)
				cout << "w";
			else
				cout << "-";
			if (children[i]->getType() & S_IXOTH)
				cout << "x" << endl;
			else
				cout << "-" << endl;

			cout<<"Owner: "<<children[i]->getOwnerString()<<endl;

			cout<<"Group: "<<children[i]->getGroupString()<<endl;

			cout<<"File Size: "<<children[i]->getSize()<< " bytes"<<endl;

			cout<<"Mod time: "<<children[i]->getModTime()<<"\n\n";
		}

	}

	else if (option.compare("-l") == 0) { //if -l is provided along with file/directory name

		fileManager file1(argv[2]);
		if (S_ISREG(file1.getType())) {
			cout << "Filename: " << file1.getFileName() << endl;
			cout << "Permissions: ";
			if (file1.getType() & S_IRUSR)
				cout << "r";
			else
				cout << "-";
			if (file1.getType() & S_IWUSR)
				cout << "w";
			else
				cout << "-";
			if (file1.getType() & S_IXUSR)
				cout << "x";
			else
				cout << "-";

			if (file1.getType() & S_IRGRP)
				cout << "r";
			else
				cout << "-";
			if (file1.getType() & S_IWGRP)
				cout << "w";
			else
				cout << "-";
			if (file1.getType() & S_IXGRP)
				cout << "x";
			else
				cout << "-";

			if (file1.getType() & S_IROTH)
				cout << "r";
			else
				cout << "-";
			if (file1.getType() & S_IWOTH)
				cout << "w";
			else
				cout << "-";
			if (file1.getType() & S_IXOTH)
				cout << "x" << endl;
			else
				cout << "-" << endl;

			cout<<"Owner: "<<file1.getOwnerString()<<endl;

			cout<<"Group: "<<file1.getGroupString()<<endl;

			cout<<"File Size: "<<file1.getSize()<<" bytes"<<endl;

			cout<<"Mod time: "<<file1.getModTime()<<"\n\n";
		}

		else {
			children = file1.expand();
			for (int i = 0; i < children.size(); i++) {
				cout << "Filename: " << children[i]->getFileName() <<"\n";
				cout << "Permissions: ";
				if (children[i]->getType() & S_IRUSR)
					cout << "r";
				else
					cout << "-";
				if (children[i]->getType() & S_IWUSR)
					cout << "w";
				else
					cout << "-";
				if (children[i]->getType() & S_IXUSR)
					cout << "x";
				else
					cout << "-";

				if (children[i]->getType() & S_IRGRP)
					cout << "r";
				else
					cout << "-";
				if (children[i]->getType() & S_IWGRP)
					cout << "w";
				else
					cout << "-";
				if (children[i]->getType() & S_IXGRP)
					cout << "x";
				else
					cout << "-";

				if (children[i]->getType() & S_IROTH)
					cout << "r";
				else
					cout << "-";
				if (children[i]->getType() & S_IWOTH)
					cout << "w";
				else
					cout << "-";
				if (children[i]->getType() & S_IXOTH)
					cout << "x" << endl;
				else
					cout << "-" << endl;

				cout<<"Owner: "<<children[i]->getOwnerString()<<endl;

				cout<<"Group: "<<children[i]->getGroupString()<<endl;

				cout<<"File Size: "<< children[i]->getSize()<<" bytes"<<endl;

				cout<<"Mod time: "<<children[i]->getModTime()<<endl;
			}
		}

	}

	else { //if only file/directory name provided
		fileManager file1(argv[1]);
		if (S_ISREG(file1.getType()))
			cout << "Filename: " << file1.getFileName() << endl;
		else {
			children = file1.expand();
			for (int i = 0; i < children.size(); i++) {
				cout << "Filename: " << children[i]->getFileName() << endl;
			}
		}
	}
}

