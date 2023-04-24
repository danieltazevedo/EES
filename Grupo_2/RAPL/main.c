/*
 *  Análise e Teste de Software
 *  João Saraiva
 *  2016-2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "rapl.h"
#include <dirent.h>

#define RUNTIME

int main(int argc, char **argv)
{
  char command[500], res[500];
  int ntimes = 1;
  int core = 0;
  int i = 0;

#ifdef RUNTIME
  clock_t begin, end;
  double time_spent;

  struct timeval tvb, tva;

#endif

  FILE *fp;

  // printf("Program to be executed: %d",argc);
  // strcpy( command, "./" );
  strcat(command, argv[1]);
  printf("Program to be executed: %s\n", argv[1]);
  strcpy(command, "");

  strcat(command, argv[1]);

  ntimes = atoi(argv[2]);

  strcpy(res, argv[3]);
  strcat(res, "_");
  strcat(res, argv[4]);
  strcat(res, ".J");
  printf("Command: %s  %d-times res: %s\n", command, ntimes, res);

  printf("\n\n RUNNING THE PARAMETRIZED PROGRAM:  %s\n\n\n", command);
  fflush(stdout);

  fp = fopen(res, "w");
  rapl_init(core);

  fprintf(fp, "Language, Program, Package , Core(s) , GPU , DRAM? , Time (msec), Temp (C) \n");

  for (i = 0; i < ntimes; i++)
  {
    sleep(1); // sleep 1 second
    fprintf(fp, "%s,", argv[3]);
    fprintf(fp, "%s,", argv[4]);
    rapl_before(fp, core);

#ifdef RUNTIME
    begin = clock();
    gettimeofday(&tvb, 0);
#endif

    system(command);

#ifdef RUNTIME
    end = clock();
    gettimeofday(&tva, 0);
    //	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    time_spent = (tva.tv_sec - tvb.tv_sec) * 1000000 + tva.tv_usec - tvb.tv_usec;
#endif

    rapl_after(fp, core);

#ifdef RUNTIME
    fprintf(fp, " %G", time_spent);
#endif
    
    const char *root_path = "/sys/class/hwmon/hwmon";
    int max_files = 0;
    const char *max_path = NULL;
    char wanted_path[50];
    char real_path[50];
    char needed_file[100];

    for (int i = 0; i != -1; i++)
    {
        sprintf(wanted_path, "%s%d", root_path, i);

        DIR *dir = opendir(wanted_path);
        if (!dir)
        {
            i = -1;
            break;
        }

        int file_count = 0;
        struct dirent *entry;
        while ((entry = readdir(dir)))
        {
            if (entry->d_type == DT_REG && strstr(entry->d_name, "_input"))
            {
                file_count++;
            }
        }

        closedir(dir);

        if (file_count > max_files)
        {
            sprintf(real_path, "%s%d", root_path, i);
            max_files = file_count;
            max_path = real_path;
            sprintf(needed_file, "%s%d/temp1_input", root_path, i);
        }
    }

    // Read temperature value from file and add it at the end of the row
    FILE *temp_file = fopen(needed_file, "r");
    if (temp_file != NULL) {
      char temp_str[10];
      if (fgets(temp_str, 10, temp_file) != NULL) {
        double temp_value = atof(temp_str) / 1000.0;
        fprintf(fp, ", %G", temp_value);
      }
      fclose(temp_file);
    }
    
    fprintf(fp, "\n");
  }

  printf("\n\n END of PARAMETRIZED PROGRAM: \n");

  fclose(fp);
  fflush(stdout);

  return 0;
}
