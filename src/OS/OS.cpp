#include <stdio.h>
#include <errno.h>
#include <string>

#include "OS.hpp"
#include "dirent.h"

void OS::ListDir(std::string dirPath)
{
    /* Open directory stream */
	DIR *dir = opendir(dirPath.c_str());

	if (!dir) {
		fprintf(stderr, "Cannot open %s (%s)\n", dirPath.c_str(), strerror(errno));
        return;
	}

	struct dirent *ent;

	while ((ent = readdir(dir)) != NULL) {
        if(ent->d_type == DT_REG)
            printf("FILE: %s\n", ent->d_name);
	}

	closedir(dir);
}