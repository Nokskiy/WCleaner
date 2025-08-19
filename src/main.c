#include <stdio.h>
#include <direct.h>
#include <stdlib.h>

#include <conio.h>

#include "logger.h"
#include "cleaner.h"
#include <locale.h>

char* paths[4];
void fill_paths();

int main()
{
    setlocale(LC_ALL, "");
    fill_paths();

    log_info("Program was been launched");
    for (int i = 0;i < sizeof(paths) / sizeof(char);i++)
        clean_dir(paths[i]);
}

void fill_paths()
{
    paths[0] = concat(getenv("TEMP"),"\\");
    paths[1] = concat(getenv("USERPROFILE"),"\\Pictures\\Screenshots\\");
    paths[2] = concat(getenv("LOCALAPPDATA"),"\\NVIDIA\\");
    paths[3] = "C:\\$Recycle.Bin\\";
}
