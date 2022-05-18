#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "erproc.h"

int main() {
    int fd = Socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in adr = {0};
    adr.sin_family = AF_INET;
    adr.sin_port = htons(8080);
    Inet_pton(AF_INET, "127.0.0.1", &adr.sin_addr);
    Connect(fd, (struct sockaddr *) &adr, sizeof adr);
    write(fd, "Hello\n", 6);        
    ssize_t nread;
    char buf[256];
    nread = Read(fd, buf, 256);
    write(STDOUT_FILENO, buf, nread);
    sleep(10);
    close(fd);
    return 0;
}
