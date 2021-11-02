#include "../includes/fileio.h"
#include "../includes/constants.h"
#include <string>
#include <fstream>
	using std::ofstream;
#include <iostream>

/**
 * write data in contents to filename
 *
 * \param filename: where data will go, overwrite if already there
 * \param contents: data to write to filename
 *        hint:  you can get a const char * by calling the method .c_str() on a std::string
 * \return
 *        INVALID_NULL_PTR_DETECTED if contents ==NULL
 *        SUCCESS otherwise
 */
int writeFile(std::string &filename,char *contents){//TODO
	if (contents==NULL)
		return INVALID_NULL_PTR_DETECTED;

	ofstream of;
	of.open(filename, std::ios::out);
	of << contents;



	of.close();
	return SUCCESS;
}

/**
 * Reads info from filename into contents
 *
 * \param filename where data is
 * \param contents data to write to file
 * \return
 *        FAIL_CANNOT_OPEN_FILE  if filename cannot be opened
 *        SUCCESS
 */
int readFile(std::string &filename,std::string &contents){
	std::ifstream ms;
	ms.open(filename);

	if(!ms.is_open())
			return FAIL_CANNOT_OPEN_FILE;
	ms.seekg(std::ios::beg);

		std::string line;	//go line by line
		while(!ms.eof()){
			getline(ms, line);
			contents+=line+'\n';
		}
	return SUCCESS;

}


