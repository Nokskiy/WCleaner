#pragma once

#include <stdio.h>
#include <string.h>

void log_info(const char *log)
{
    printf("[Info] %s\n", log);
}

void log_warning(const char *log)
{
    printf("[Warning] %s\n", log);
}

void log_error(const char *log)
{
    printf("[Error] %s\n", log);
}