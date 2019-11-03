/*
 * Author: Andrew Greaves
 * Header file for fileManager
 * Date: October 3rd 2019
 */
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <dirent.h>
#include <vector>
#include<ostream>
#include<string.h>
#include<grp.h>
#include <pwd.h>
#ifndef fileManager_h
#define fileManager_h

class fileManager{

public:
  fileManager(std::string name);

  ~fileManager();

  std::string getFileName();

  mode_t getType();

  int getSize();

  uid_t getOwner();

  gid_t getGroup();

  mode_t getPermissions();

  time_t getAccessTime();

  time_t getModTime();

  time_t getStatusTime();

  blksize_t getBlockSize();

  void setFileName(std::string newName);

  void setAccessTime(time_t newAccessTime);

  void setBlockSize(blksize_t newBlockSize);

  void setGroup(gid_t newGroup);

  void setModTime(time_t newModTime);

  void setOwner(uid_t newOwner);

  void setSize(off_t newSize);

  void setStatusTime(time_t newStatusTime);

  void setType(mode_t newType);

  void dump(std::ostream& fileStream);

  void renameFile(std::string newName);

  void remove();

  void compare(std::ifstream& file2);

  std::vector<fileManager*> expand();

  char* getErrString();

  char* getGroupString();

  char* getOwnerString();

  int getErrNum();


private:
	std::string fileName;
	std::ifstream myFile;
	std::string userName;
	std::vector<fileManager*>children;
	mode_t type;
	off_t size;
    uid_t owner;
    gid_t group;
    char * groupString;
    char * ownerString;
    time_t accessTime;
    time_t modTime;
    time_t statusTime;
    blksize_t blockSize;
    int errNum;
};
#endif
