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
#include <string.h>
#include <dirent.h>

#define RUNTIME
#define MAX_PATH_LENGTH 100


char *get_file_path(const char *root_path)
{
    int max_files = 0;
    int i = 0;
    int res;
    char wanted_path[MAX_PATH_LENGTH];
    char end_path[MAX_PATH_LENGTH];
    static char needed_file[MAX_PATH_LENGTH]; // Declare needed_file as static to avoid its contents being lost after the function returns.

    while (1)
    {
        res = snprintf(wanted_path, MAX_PATH_LENGTH, "%s%d", root_path, i);
        if (res < 0 || res >= MAX_PATH_LENGTH) {
            fprintf(stderr, "Failed to generate path.\n");
            return NULL;
        }

        DIR *dir = opendir(wanted_path);
        if (!dir)
        {
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
            res = snprintf(end_path, MAX_PATH_LENGTH, "%s%d", root_path, i);
            if (res < 0 || res >= MAX_PATH_LENGTH) {
                fprintf(stderr, "Failed to generate path.\n");
                return NULL;
            }
            max_files = file_count;
            sprintf(needed_file, "%s%d/temp1_input", root_path, i);
        }
        i++;
    }

    return needed_file;
}


float get_value_from_file(const char *result)
{
    FILE *fp;
    float value;

    fp = fopen(result, "r");
    if (fp == NULL)
    {
        printf("Error opening file: %s\n", result);
        return 1;
    }

    if (fscanf(fp, "%f", &value) != 1)
    {
        printf("Error reading value from file: %s\n", result);
        return 1;
    }

    value /= 1000.0f;

    fclose(fp);

    return value;
}


int main(int argc, char **argv)
{
  char command[500], res[500];
  int ntimes = 1;
  int core = 0;
  int i = 0;
  const char *root_path = "/sys/class/hwmon/hwmon";
  float temperature = 0.0f;

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

  fprintf(fp, "Language , Program , Package , Core(s) , GPU , DRAM? , Time (msec) , Temp (ºC) \n");

  for (i = 0; i < ntimes; i++)
  {
    while (temperature = get_value_from_file(get_file_path(root_path)) > 80.00f)
    {
      printf("Waiting for CPU to cool down... %.2fºC > 80.00ºC \n", temperature);
      sleep(10);
    }
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
    fprintf(fp, " %G, %.2f \n", time_spent, get_value_from_file(get_file_path(root_path)));
#endif
  }

  printf("\n\n END of PARAMETRIZED PROGRAM: \n");

  fclose(fp);
  fflush(stdout);

  return 0;
}
