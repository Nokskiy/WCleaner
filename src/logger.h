#pragma once
#include <stdio.h>

int log_cleaned = 0;

static inline void log_info(const char* log)
{
    const char* log_type = "[Info] %s\n";
    printf(log_type, log);
    FILE* file = fopen(".\\wcleaner_logs.txt", log_cleaned == 1 ? "a" : "w");
    log_cleaned = 1;

    fprintf(file, log_type, log);
    fclose(file);
}

static inline void log_warning(const char* log)
{
    const char* log_type = "[Warning] %s\n";
    printf(log_type, log);
    FILE* file = fopen(".\\wcleaner_logs.txt", log_cleaned == 1 ? "a" : "w");
    log_cleaned = 1;

    fprintf(file, log_type, log);
    fclose(file);
}

static inline void log_error(const char* log)
{
    const char* log_type = "[Error] %s\n";
    printf(log_type, log);
    FILE* file = fopen(".\\wcleaner_logs.txt", log_cleaned == 1 ? "a" : "w");
    log_cleaned = 1;

    fprintf(file, log_type, log);
    fclose(file);
}

static inline char* concat(const char* s1, const char* s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);

    char* result = malloc(len1 + len2 + 1);
    if (!result)
        return NULL;
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1);

    return result;
}
