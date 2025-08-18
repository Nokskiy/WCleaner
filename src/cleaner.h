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

    struct dirent* entry;

    rewinddir(dir);
    while ((entry = readdir(dir)))
    {
        if (strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0) continue;

        char* fp = full_path(path, entry->d_name);
        log_info(fp);
        free(fp);
    }

    return 0;
}

inline char* full_path(const char* path1, const char* path2)
{
    const size_t len1 = strlen(path1);
    const size_t len2 = strlen(path2);

    char* result = malloc(len1 + len2 + 1);
    if (!result)
        return NULL;
    memcpy(result, path1, len1);
    memcpy(result + len1, path2, len2 + 1);

    return result;
}
