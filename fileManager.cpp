/*
 * Author: Andrew Greaves
 * Code File for fileManager
 * Date: October 3rd 2019
 */
#include "fileManager.h"

/*
 * Function Name: fileManager
 * Constructor for fileManager
 * Param: String name of File
 */
  fileManager::fileManager(std::string name){
	struct stat st;
	struct group *grp;
	struct passwd *pwd;
	errNum=0;
    fileName=name;
    if(myFile.is_open()==false)
    	myFile.open(name);
    stat(name.c_str(),&st);
    errNum=errno; //sets error number to the error code of stat function
    if(errNum!=0){
    	std::cout<<"Error: "<<getErrString()<<std::endl;
    	exit(1);
    }
    type=st.st_mode;
    size=st.st_size;
    owner=st.st_uid;
    group=st.st_gid;
    accessTime=st.st_atime;
    modTime=st.st_mtime;
    statusTime=st.st_ctime;
    blockSize=st.st_blksize;

    //gets group and owner string names
    grp=getgrgid(group);
    pwd=getpwuid(owner);
    ownerString=pwd->pw_name;
    groupString=grp->gr_name;
  }

  /*
   * Function Name: ~fileManager
   * Deconstructor
   */
  fileManager::~fileManager(){
  }

  /*
   * Function Name: getFileName
   * Gets the name of the File
   * returns filename
   */
  std::string fileManager::getFileName(){
	  return fileName;
  }

  /*
   * Function Name: getType
   * Gets the type of File
   * returns type
   */
  mode_t fileManager::getType(){
	  return type;
  }

  /*
   * Function Name: getSize
   * Gets the size of File
   * returns size
   */
  int fileManager::getSize(){
	  return size;
  }

  /*
   * Function Name: getOwner
   * Gets the owner of the file
   * returns owner
   */
  uid_t fileManager::getOwner(){
	  return owner;
  }

  /*
   * Function Name: getOwnerString
   * Gets the string representation of the owner of the string
   * returns ownerString
   */
  char* fileManager::getOwnerString(){
	  return ownerString;
  }

  /*
   * Function Name: getGroup
   * Gets the group of the file
   * returns group
   */
  gid_t fileManager::getGroup(){
	  return group;
  }

  /*
   * Function Name: getGroupString
   * Gets the string representation of the group
   * returns groupString
   */
  char* fileManager::getGroupString(){
	  return groupString;
  }

  /*
   * Function Name: getPermissions
   * Gets the permissions of the file
   * returns type
   */
  mode_t fileManager::getPermissions(){
	  return type;
  }

  /*
   * Function Name: getAccessTime
   * Gets the time of last access
   * returns accessTime
   */
  time_t fileManager::getAccessTime(){
	  return accessTime;
  }

  /*
   * Function Name: getModTime
   * Gets the time of last modification
   * returns modTime
   */
  time_t fileManager::getModTime(){
	  return modTime;
  }

  /*
   * Function Name: getStatusTime
   * Gets the time of last status change
   * returns statusTime
   */
  time_t fileManager::getStatusTime(){
	  return statusTime;
  }

  /*
   * Function Name: getBlockSize
   * Gets optimal chunk size for I/O operations for the file
   * returns blockSize
   */
  blksize_t fileManager::getBlockSize(){
	  return blockSize;
  }

  /*
   * Function Name: getErrString
   * Gets the string representation of error code
   * returns strerror(errNum)
   */
  char* fileManager::getErrString(){
 	  return strerror(errNum);
   }

  /*
   * Function Name: getErrNum
   * Gets the error code
   * returns errNum
   */
  int fileManager::getErrNum(){
	  return errNum;
  }

  /*
   * Function Name: renameFile
   * Renames a file with a new name specified by the user
   * Param: newName
   * return nothing
   */
  void fileManager::renameFile(std::string newName){
   	  rename(getFileName().c_str(),newName.c_str());
   	  errNum=errno;
   	  if(errNum!=0){
   		 std::cout<<"Error: "<<getErrString()<<std::endl;
   		 exit(1);
   	  }
   	 fileName=newName;
     }


  /*
   * Function Name: setFileName
   * Sets the name of the file with a new name using the renameFile function
   * Param: new name
   * returns nothing
   */
  void fileManager::setFileName(std::string newName){
	  renameFile(newName);
  }

  /*
   * Function Name: setAccessTime
   * Sets the last time of access
   * Param: new access time
   * returns nothing
   */
  void fileManager::setAccessTime(time_t newAccessTime) {
    		accessTime = newAccessTime;
    	}

  /*
   * Function Name: setBlockSize
   * Sets the optimal chunk size for I/O operations
   * Param: new block size
   * returns nothing
   */
  void fileManager::setBlockSize(blksize_t newBlockSize) {
    		blockSize = newBlockSize;
    	}


  /*
   * Function Name: setGroup
   * Sets the group of a file
   * Param: new group
   * returns nothing
   */
  void fileManager::setGroup(gid_t newGroup) {
    		group = newGroup;
    	}

  /*
   * Function Name: setModTime
   * Sets the last time of modification
   * Param: new mod time
   * returns nothing
   */
  void fileManager::setModTime(time_t newModTime) {
    		modTime = newModTime;
    	}

  /*
   * Function Name: setOwner
   * Sets owner of file
   * Param: new owner
   * returns nothing
   */
  void fileManager::setOwner(uid_t newOwner) {
    		owner = newOwner;
    	}

  /*
   * Function Name: setSize
   * Sets the size of a file
   * Param: new size
   * returns nothing
   */
  void fileManager::setSize(off_t newSize) {
    		size = newSize;
    	}

  /*
   * Function Name: setStatusTime
   * Sets the time of last staus change
   * Param: new status time
   * returns nothing
   */
  void fileManager::setStatusTime(time_t newStatusTime) {
    		statusTime = newStatusTime;
    	}

  /*
   * Function Name: setType
   * Sets the type of a file
   * Param: new Type
   * returns nothing
   */
  void fileManager::setType(mode_t newType) {
    		type = newType;
    	}

  /*
   * Function Name: dump
   * Dumps the contents of a file to a file stream
   * Param: a file stream
   * returns nothing
   */
  void fileManager::dump(std::ostream& fileStream){
	  if(S_ISDIR(getType())){
		  errNum=ENOTSUP;
		  std::cout<<"Error: "<<getErrString()<<std::endl;
		  exit(1);
	  }

	  std::ifstream file(getFileName());
	  std::vector <char> buffer((int)getBlockSize(),0);
	  file.read(&buffer[0], (int)getBlockSize()); // reads the contents of the file into the buffer
	  fileStream.write(&buffer[0], (int)getBlockSize()); //writes buffer to file stream
	  file.close();
  }


  /*
   * Function Name: remove
   * resets attributes of a file then removes it
   * returns nothing
   */
  void fileManager::remove(){
	  setFileName(" ");
	  setAccessTime(0);
	  setBlockSize(0);
	  setGroup(0);
	  setModTime(0);
	  setOwner(0);
	  setSize(0);
	  setStatusTime(0);
	  setType(0);
	  unlink(getFileName().c_str());
	  errNum=errno;
	  if(errNum!=0){
	  	std::cout<<"Error: "<<getErrString()<<std::endl;
	  	exit(1);
	  }

  }

  /*
   * Function Name: compare
   * Compares two files and outputs if they are the same or not
   * Param: A file
   * returns nothing
   */
  void fileManager::compare(std::ifstream& file2){
	  std::ifstream currentFile(getFileName());
	  std::vector<char>buffer1((int)getBlockSize(),0);
	  std::vector<char>buffer2((int)getBlockSize(),0);
	  errNum=errno;
	  if(errNum!=0){
		  std::cout<<"Error: "<<getErrString()<<std::endl;
	  }
	  //Reads both files into two buffers and compares them
	  currentFile.read(&buffer1[0], (int)getBlockSize());
	  file2.read(&buffer2[0],(int)getBlockSize());
	  if(buffer1==buffer2)
		  std::cout<<"The files are the same"<<std::endl;
	  else
		  std::cout<<"The files are different"<<std::endl;
	  currentFile.close();
	  file2.close();
  }

  /*
   * Function Name: expand
   * Fils in the children of the file object this function was invoked upon
   * returns a vector of fileManager pointer, ie the children
   */
  std::vector<fileManager*> fileManager::expand(){
	  if(S_ISDIR(getType())){
		  DIR *dir;
		  std::ifstream file1;
		  struct dirent *ent;
		  dir=opendir(getFileName().c_str()); //opens directory
		  errNum=errno;
		  if(errNum!=0){
		  	std::cout<<"Error: "<<getErrString()<<std::endl;
		  	exit(1);
		  }
		  if(dir==NULL)
			  return children;
		  if(dir!=NULL){
			  while((ent=readdir(dir))!=NULL){ //reads contents of directory
				  errNum=errno;
				  if(errNum!=0){
					  std::cout<<"Error: "<<getErrString()<<std::endl;
					  exit(1);
				  }
				  std::string newFileName=ent->d_name;
				  if(newFileName.compare(".")!=0 && newFileName.compare("..")!=0){
					  newFileName="./"+getFileName()+"/"+newFileName; //gets pathname
					 file1.open(newFileName);
					 fileManager *newFile=new fileManager(newFileName);
					 children.push_back(newFile);
				  }
			  }
			  closedir(dir);
		  }
		  return children;
	  }
	  else throw std::invalid_argument("Call can only be made on directories");

  }



