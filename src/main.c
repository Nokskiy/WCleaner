#include <stdio.h>
#include <direct.h>
#include <stdlib.h>

#include <conio.h>

#include "logger.h"
#include "cleaner.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");

    log_info("Programm was been launched");
    clean_dir("F:\\WCleaner\\test");

    getch();
}