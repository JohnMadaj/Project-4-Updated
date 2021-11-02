//============================================================================
// Name        : pointer_proj_small.cpp
// Author      : John Madaj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>

#include "../includes/constants.h"
#include "../includes/stringmanip.h"
#include "../includes/fileio.h"

using namespace std;
using namespace KP;



int main(int argc, char *argv[]) {	
	//TODO Get commandline arguments
	if (argc != EXPECTED_NUMBER_ARGUMENTS){
		cout<<HELP_STRING1<<endl;
		return FAIL_WRONG_NUMBER_ARGS;
	}
	
		//TODO
	string in = argv[1];
	string out = argv[2];

	string tag = argv[3];
	char* tag_char = new char[tag.length() + 1];
	copy(tag.begin(), tag.end(), tag_char);

	string replacement = argv[4];
	char* replacement_char = new char[replacement.length() + 1 ];
	copy(replacement.begin(), replacement.end(), replacement_char);

	string src;

	//TODO can we read file? Fail if not
	int read = readFile(in, src);
	if (read == FAIL_CANNOT_OPEN_FILE){
		cout<<CANNOT_OPEN_FILE<<endl;
		return read;
	}

	char* src_char = new char[src.length() + 1];
		copy(src.begin(), src.end(), src_char);

	//TODO how many tags found in file?
	int numbTags = findNumbOccurrences(src_char,  tag_char);

	//TODO how much memory to allocate?
	int required_memory = amountOfMemoryToAllocateForNewString(src.length(), numbTags,
			tag.length(), replacement.length());

	//TODO allocate memory
	char* modified_src_char = new char[required_memory + 1];
	
	//TODO replace original tag with new tags
//	int replace(const char *src, char *new_src, const char *tag, const char *tag_replacement){
	int replaced = KP::replace(src_char, modified_src_char, tag_char, replacement_char);
	if (replaced == INVALID_NULL_PTR_DETECTED)
		return replaced;
	int write = writeFile(out, modified_src_char);
	if (write == INVALID_NULL_PTR_DETECTED){
		cout<<HELP_STRING2<<endl;
		return write;
	}


	
	//TODO deallocate any memory allocated
	if (src_char)
		delete src_char;
	if (modified_src_char)
		delete modified_src_char;
	if (tag_char)
		delete tag_char;
	if (replacement_char)
		delete replacement_char;

	return SUCCESS;

}
