#pragma once
#include <direct.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "logger.h"

char* full_path(const char* path1, const char* path2);

static inline int clean_dir(const char* path)
{
    DIR* dir = opendir(path);

    if (dir == NULL)
    {
        char* mess = concat("directory with name", path);
        mess = concat(mess,"not exists");
        log_error(mess);
        free(mess);
    }


    struct dirent* entry;

    rewinddir(dir);
    while ((entry = readdir(dir)))
    {
        if (strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0) continue;

        char* fp = concat(path, entry->d_name);
        log_info(fp);
        free(fp);
    }

    return 0;
}