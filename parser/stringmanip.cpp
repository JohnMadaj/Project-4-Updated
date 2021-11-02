/*
 * stringmanip.h
 *
 *  Created on: Feb 28, 2021
 *      Author: keith
 */

#include "../includes/constants.h"
#include "../includes/stringmanip.h"
#include <string>
#include <algorithm>
namespace KP{
	/**
	 * Calculate the exact amount of memory needed to allocate a that consists of the old string with all tags replaced by tag_replacements.
	 * Don't forget the terminating null!
	 *
	 * ex. src="a large ship"
	 *     tag="large"
	 *     tag_replacement="really large"
	 *
	 *     then
	 *     len_src = 14
	 *     numbTagsToReplace=1
	 *     len_tag=5
	 *     len_tag_replacement=12
	 *
	 *     the function should return 22
	 *
	 * \param len_src - length of original string
	 * \param numbTagsToReplace - number of tags to replace in the original string
	 * \param len_tag - length of the tag
	 * \param len_tag_replacement - length of the tag replacement
	 * \return
	 */
	int amountOfMemoryToAllocateForNewString(int len_src, int numbTagsToReplace, int len_tag, int len_tag_replacement){
		//NULL TERMINATOR /0 = ONE bit of memory
		return (len_src + (numbTagsToReplace * (len_tag_replacement - len_tag))+1);
	}



	/**
	 * If src,new_src, tag or tag_replacment are null then returns INVALID_NULL_PTR_DETECTED
	 *
	 * Copies src char string to new_src char string, replaces all tag occurrences with tag_replacement.
	 * Please ensure that new_src is allocated and of proper size before calling this function
	 *
	 * ex.
	 * 	src ="a large bucket on a large ship"
		tag="large"
		tag_replacement="really large"
		then when the function returns
		new_src="a really large bucket on a really large ship"
	 *
	 * \param src  initial char string, may be deleted and reallocated by this function
	 * \param new_src char string with enough space to hold src string with all tag occurrences replaced by tag_replacement
	 * \param tag  the tag to search for
	 * \param tag_replacement  replaces all occurrences of tag
	 * \return INVALID_NULL_PTR_DETECTED one or more of src, tag or tag_replacement is NULL
	 * 		   SUCCESS everything went well, src contains the
	 */
	int replace(const char *src, char *new_src, const char *tag, const char *tag_replacement){
		if (src == NULL || new_src == NULL || tag == NULL || tag_replacement == NULL)
			return INVALID_NULL_PTR_DETECTED;
		std::string srcstr(src);
		std::string newsrcstr(new_src);
		size_t position;

		while ((position = srcstr.find(tag)) != std::string::npos)
			srcstr.replace(position, 1, tag_replacement);

		src = srcstr.c_str();

		return SUCCESS;

	}

	/**
	 * how often does the string in tag occur in src?
	 *
	 * \param src  initial char string
	 * \param tag  the tag to search for
	 * \return INVALID_NULL_PTR_DETECTED one or more of src, or tag is NULL
	 *         otherwise the number of times tag occurs in src
	 */
	int findNumbOccurrences(const char *src,  const char *tag){ //TODO
		if (src == NULL || tag == NULL)
			return INVALID_NULL_PTR_DETECTED;
		std::string srcstr(src);
		int count = 0;
		size_t position = srcstr.find(tag, 0);
		while (position != std::string::npos){
			count++;
			position = srcstr.find(tag, position+1);
		}
		return count;

	}
}
