#pragma once
#include <direct.h>
#include <stdlib.h>
#include <dirent.h>

#include "logger.h"

int clean_dir(const char *path)
{
    DIR *dir = opendir(path);

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL)
    {
        log_info(entry->d_name);
    }
    return 0;
}