#include <stdio.h>
/// http://www.cplusplus.com/reference/cstdio/fseek/
int main() {
  FILE *pFile;
  pFile = fopen("example.txt", "wb");
  fputs("This is an apple.", pFile);
  fseek(pFile, 9, SEEK_SET); // SEEK_SET 表示 Beginning of file
  fputs(" sam", pFile);
  fclose(pFile);
  return 0;
}
