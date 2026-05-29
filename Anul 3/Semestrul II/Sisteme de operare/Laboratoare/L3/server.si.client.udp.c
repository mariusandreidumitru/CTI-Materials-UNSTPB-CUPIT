UDP Server Client Implementation in C for Unix/Linux
Here's a simple UDP Server Client Implementation in C for Unix/Linux.
As UDP is a connection-less protocol, it is not reliable or we can say that we don't send acknowledgements for the packets sent.

Here is a concurrent UDP server which can accept packets from multiple clients simultaneously.
The port mentioned here can be changed to any value between 1024 and 65535 (since upto 1024 are known ports).

//UDPServer.c

/* 
 *  gcc -o server UDPServer.c
 *  ./server
 */
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#define BUFLEN 512
#define PORT 9930

void err(char *str)
{
    perror(str);
    exit(1);
}

int main(void)
{
    struct sockaddr_in my_addr, cli_addr;
    int sockfd, i; 
    socklen_t slen=sizeof(cli_addr);
    char buf[BUFLEN];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
      err("socket");
    else 
      printf("Server : Socket() successful\n");

    bzero(&my_addr, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(PORT);
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if (bind(sockfd, (struct sockaddr* ) &my_addr, sizeof(my_addr))==-1)
      err("bind");
    else
      printf("Server : bind() successful\n");

    while(1)
    {
        if (recvfrom(sockfd, buf, BUFLEN, 0, (struct sockaddr*)&cli_addr, &slen)==-1)
            err("recvfrom()");
        printf("Received packet from %s:%d\nData: %s\n\n",
               inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port), buf);
    }

    close(sockfd);
    return 0;
}



//UDPClient.c

/*
 * gcc -o client UDPClient.c
 * ./client 
 */

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#define BUFLEN 512
#define PORT 9930

void err(char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char** argv)
{
    struct sockaddr_in serv_addr;
    int sockfd, i, slen=sizeof(serv_addr);
    char buf[BUFLEN];

    if(argc != 2)
    {
      printf("Usage : %s <Server-IP>\n",argv[0]);
      exit(0);
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
        err("socket");

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_aton(argv[1], &serv_addr.sin_addr)==0)
    {
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);
    }

    while(1)
    {
        printf("\nEnter data to send(Type exit and press enter to exit) : ");
        scanf("%[^\n]",buf);
        getchar();
        if(strcmp(buf,"exit") == 0)
          exit(0);

        if (sendto(sockfd, buf, BUFLEN, 0, (struct sockaddr*)&serv_addr, slen)==-1)
            err("sendto()");
    }

    close(sockfd);
    return 0;
}