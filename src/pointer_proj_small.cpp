//============================================================================
// Name        : pointer_proj_small.cpp
// Author      : John Madaj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
#include "../includes/constants.h"
#include "../includes/stringmanip.h"
#include "../includes/fileio.h"


int main(int argc, char *argv[]) {	
	//TODO Get commandline arguments
	if (argc != EXPECTED_NUMBER_ARGUMENTS)
		cout<<HELP_STRING1<<endl;
		return FAIL_WRONG_NUMBER_ARGS;
	
		//TODO
	string in = argv[1];		//TODO THESE ARGUMENT INDICES COULD BE WRONG FIX THEM
	string out = argv[2];

	string tag = argv[3];
	char* tag_char = new char[tag.length() + 1];
	copy(tag.begin(), tag.end(), tag_char);

	string replacement = argv[4];
	char* replacement_char = new char[replacement.length() + 1 ];
	copy(replacement.begin(), replacement.end(), replacement_char);

	string src; //tODO FIX ME
	char* src_char = new char[src.length() + 1];
	copy(src.begin(), src.end(), src_char);
	string contents; //this ones fine like this





	//TODO can we read file? Fail if not
	int read = readFile(in, contents);
	if (read == FAIL_CANNOT_OPEN_FILE){
		return read;
	}
	//TODO how many tags found in file?
	int numbTags = KP::findNumbOccurrences(src_char,  tag_char);
	//TODO how much memory to allocate?
	int required_memory = KP::amountOfMemoryToAllocateForNewString(src.length(), numbTags,
			tag.length(), replacement.length());
	//TODO allocate memory
	
	//TODO replace original tag with new tags
	
	//TODO deallocate any memory allocated
}
