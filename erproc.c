#include "erproc.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

/* Системный вызов socket() создает новый сокет */
int Socket(int domain, int type, int protocol) {
    int res = socket(domain, type, protocol);
    if (res == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    return res;
}
/* Системный вызов bind() привязывает сокет к заданному адресу */
void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    int res = bind(sockfd, addr, addrlen);
    if (res == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}
/* Системный вызов listen() делает потоковый сокет, на который указывает
файловый дескриптор sockfd , пассивным. Впоследствии этот сокет будет
использоваться для приема соединений от других (активных) сокетов. */
void Listen(int sockfd, int backlog) {
    int res = listen(sockfd, backlog);
    if (res == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
}
/* Системный вызов accept() принимает входящее соединение на слушающем потоковом
сокете, на который указывает файловый дескриптор sockfd . Если вызов accept() не
обнаруживает ожидающих соединений, то блокируется и ждет, пока не поступит
соответствующий запрос. */
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    int res = accept(sockfd, addr, addrlen);
    if (res == -1) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    return res;
}
/* Системный вызов connect() соединяет активный сокет, на который указывает файловый
дескриптор sockfd, со слушающим сокетом, чей адрес задан в виде аргументов addr и addrlen. */
void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    int res = connect(sockfd, addr, addrlen);
    if (res == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
}

void Inet_pton(int af, const char *src, void *dst) {
    int res = inet_pton(af, src, dst);
    if (res == 0) {
        printf("inet_pton failed: src does not contain a character"
            " string representing a valid network address in the specified"
            " address family\n");
        exit(EXIT_FAILURE);
    }
    if (res == -1) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }
}

ssize_t Read(int fd, void *buf, size_t count) {
    ssize_t res = read(fd, buf, count);
    if (res == -1) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }
    if (res == 0) {
        printf("EOF occured\n");
    }
    return res;
}


