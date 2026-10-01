#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

extern int errno;
int port;
int main(int argc, char*argv[])
{
int sd;
struct sockaddr_in server;
char tampon[100];
if(argc!=3)
{
printf("sintaxa:%s<adresa_server><port> \n", argv[0]);
return -1;
}
port=atoi(argv[2]);
if((sd=socket(AF_INET,SOCK_STREAM,0))==-1)
{
perror("eroare la socket(). \n");
return errno;
}
server.sin_family=AF_INET;
server.sin_addr.s_addr=inet_addr(argv[1]);
server.sin_port=htons(port);
if(connect(sd,(struct sockaddr*)&server, sizeof(struct sockaddr))==-1)
{
perror("eroare la connect(). \n");
return errno;
}
bzero(tampon,100);
printf("introduceti mesajul:");
fflush(stdout);
read(0,tampon,100);
if(write(sd,tampon,100)<=0)
{
perror("eroare la write() spre server. \n");
return errno;
}
if (read(sd,tampon,100)<0)
{
perror("eroare la read() de la server. \n");
return errno;
}
printf("mesajul primit este:%s \n", tampon);
close(sd);
}
