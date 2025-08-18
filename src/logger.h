#pragma once
#include <stdio.h>

static inline void log_info(const char* log)
{
    const char* log_type = "[Info] %s\n";
    printf(log_type, log);
    FILE* file = fopen(".\\logs.txt", "a");
    fprintf(file, log_type, log);
    fclose(file);
}

static inline void log_warning(const char* log)
{
    const char* log_type = "[Warning] %s\n";
    printf(log_type, log);
    FILE* file = fopen(".\\logs.txt", "a");
    fprintf(file, log_type, log);
    fclose(file);
}

static inline void log_error(const char* log)
{
    const char* log_type = "[Error] %s\n";
    printf(log_type, log);
    FILE* file = fopen(".\\logs.txt", "a");
    fprintf(file, log_type, log);
    fclose(file);
}
