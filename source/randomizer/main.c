#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomize(char* inputPath, char* outputPath);

int main(int argc, char* argv[])
{
  if (argc <= 2)
  {
    printf("  %s input.json output.json\n", argv[0]);
    return 1;
  }

  return randomize(argv[1], argv[2]);
}


// {"date":"2016-09-06 19:30:00","open":"4.3354","close":"4.3354","min":"4.3347","max":"4.3354"}
int randomize(char* inputPath, char* outputPath)
{
  int i;
  char c;

  char date[16];
  int hours, minutes, seconds;
  float open, close, min, max;

  FILE* input  = fopen(inputPath,  "r");
  FILE* output = fopen(outputPath, "w");

  srand((unsigned int)time(NULL));

  fprintf(output, "[");

  c = fgetc(input);
  if (c != '[')
    return 1;

  while (c != ']')
  {

    //90
    fscanf(input, "{\"date\":\"%10s %d:%d:%d\",\"open\":\"%6f\",\"close\":\"%6f\",\"min\":\"%6f\",\"max\":\"%6f\"}",
           date, &hours, &minutes, &seconds, &open, &close, &min, &max);

    c = fgetc(input);

    for (i = 0; i < 90; i++)
    {
      if (seconds >= 60)
      {
        seconds = 0;
        ++minutes;
      }

      open  += (((float)rand()/(float)(RAND_MAX)/1.0) - 0.5)/100.0;
      close += (((float)rand()/(float)(RAND_MAX)/1.0) - 0.5)/100.0;
      min   += (((float)rand()/(float)(RAND_MAX)/1.0) - 0.5)/100.0;
      max   += (((float)rand()/(float)(RAND_MAX)/1.0) - 0.5)/100.0;

      fprintf(output, "{\"date\":\"%s %02d:%02d:%02d\",\"open\":\"%.4f\",\"close\":\"%.4f\",\"min\":\"%.4f\",\"max\":\"%.4f\"}",
              date, hours, minutes, seconds, open, close, min, max);

      if (c == ',' || i < 89)
        fprintf(output, ",\n");

      seconds += 10;
    }

    if (c == EOF)
    {
      fclose(input);
      fclose(output);
      return 1;
    }
  }

  fprintf(output, "]");

  fclose(input);
  fclose(output);

  return 0;
}
