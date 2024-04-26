#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sendfile.h>

int main() {
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in addr = {
    AF_INET,
    htons(8080),
    htons(0)
  };

  bind(sock, &addr, sizeof(addr));

  listen(sock, 10);

  int client_fd = accept(sock, 0, 0);

  char buffer[256] = { 0 };
  recv(client_fd, buffer, 256, 0);

  printf("%s\n", buffer);

  int resp_fd = open("info", O_RDONLY);

  sendfile(client_fd, resp_fd, 0, 256);

  close(resp_fd);
  close(client_fd);
  close(sock);

  return 0;
}
