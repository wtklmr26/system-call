#include<fcntl.h>
#include<unistd.h>

int main(void) {
  int fdr, fdw, n;
  char buf[80];

  fdr = open("read.txt", O_RDONLY);
  fdw = open("write.txt", O_WRONLY);

  n = read(fdr, buf, sizeof(buf));

  write(fdw, buf, n);

  close(fdr);
  close(fdw);
}
