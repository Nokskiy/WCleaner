#pragma once
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#include "logger.h"

int path_exists(const char* path);
int is_dir(const char* path);

int clean_dir(const char* path)
{
    if (!path_exists(path))
    {
        char* log = "path with name ";
        log = concat(log, path);
        log = concat(log, " not exists");
        log_error(log);
        return 1;
    }

    if (is_dir(path))
    {
        struct dirent* entry;

        DIR* dir = opendir(path);

        while ((entry = readdir(dir)) != NULL)
        {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;

            char* fp = concat(path, entry->d_name);

            if (is_dir(fp))
                clean_dir(concat(fp, "\\"));
            else
            {
                log_info(concat(concat("file with path \"",fp),"\" was been removed"));
                remove(fp);
            }

            free(fp);
        }
        if ((entry = readdir(dir)) == NULL)
            rmdir(path);
    }

    return 0;
}

inline int path_exists(const char* path)
{
    return access(path,F_OK) == 0;
}

inline int is_dir(const char* path)
{
    struct stat statbuf;
    if (stat(path, &statbuf) == 0)
    {
        return S_ISDIR(statbuf.st_mode);
    }
    return 0;
}