#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int n = 123;

  pid_t pid = fork();
  if (pid < 0) {
    perror("fork error");
    exit(-1);
  } else if (pid == 0) {
    // 子プロセス
    sleep(5);
    printf("child  n[%p]=%d\n", &n, n);
    n = 456;
    printf("child  n[%p]=%d\n", &n, n);
    return 12;
  }

  // 親プロセス
  printf("parent process start\n");

  printf("parent n[%p]=%d\n", &n, n);
  n = 789;
  printf("parent n[%p]=%d\n", &n, n);

  int status;
  pid_t r = waitpid(pid, &status, 0); //子プロセスのプロセスIDを指定して、終了を待つ
  if (r < 0) {
    perror("waitpid");
    exit(-1);
  }
  if (WIFEXITED(status)) {
    // 子プロセスが正常終了の場合
    int exit_code = WEXITSTATUS(status); //子プロセスの終了コード
    printf("child exit-code=%d\n", exit_code);
  } else {
    printf("child status=%04x\n", status);
  }

  printf("parent process end\n");
  return 0;
}


// プログラムの戻り値は親プロセスの戻り値
// echo $?
