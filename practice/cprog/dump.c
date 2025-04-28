#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  char buf[200];
  snprintf(buf, 100, "echo \"TSDB_FILTER_GROUP_IF_NO_SUBJECT 1\nTSDB_RETENTION_POLICY_PERIOD\" >> diff.txt");
  system(buf);

  return 0;
}
