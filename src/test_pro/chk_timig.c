#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define SECS_IN_DAY    86400
#define SECS_IN_HR     3600
#define SECS_IN_MIN    60

static unsigned long convert_time_in_seconds(char *time)
{
  int len = strlen(time);
  char op = time[len - 1];  // Find the type, ex. 'h'
  int val = atoi(time);    // Find the value, ex. 12

  switch(op)
  {
    case 'S': // time already in seconds
    case 's': // time already in seconds
      return val;
    case 'M': // time in minutes
    case 'm': // time in minutes
      return val * SECS_IN_MIN;
    case 'H': // time in Hours
    case 'h': // time in Hours
      return val * SECS_IN_HR;
    case 'D': // time in Days
    case 'd': // time in Days
      return val * SECS_IN_DAY;
    default: // unidentified Symbol: Seconds.
      return val;
  }
  return 0;
}

int main()
{
  struct stat fl_st;
  int ret = stat("ll", &fl_st);
  if(!ret)
  {
    int tot = convert_time_in_seconds("20m");
    printf("%d\n", tot);
    if((fl_st.st_mtime != time(NULL)) && ((time(NULL) - tot) > fl_st.st_mtime))
      printf("delete the file\n");
    else
      printf("not mod, last mod time %ld\n", fl_st.st_mtime);
  }
  return 0;
}
