#include <unistd.h>

int main(void) {
  char *s = "123456789";

  write(STDOUT_FILENO, s, sizeof(s)+1);

  return 0;
}
