#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PORT 8081
extern int errno;
int main()
{
  struct sockaddr_in server;
  struct sockaddr_in from;
  char tampon[100];
  int sd;
  if((sd=socket(AF_INET,SOCK_STREAM,0))==-1)
  {
    perror("eroare socket()\n");
    return errno;
  }
bzero(&server, sizeof(server));
bzero(&from, sizeof(from));
server.sin_family=AF_INET;
server.sin_addr.s_addr=htons(INADDR_ANY);
server.sin_port=htons(PORT);
  if(bind(sd,(struct sockaddr*)&server,sizeof(struct sockaddr))==-1)
    {
    perror("eroare la bind(). \n");
    return errno;
    }
  if (listen(sd,5)==-1)
    {
    perror("eroare listen(). \n");
    return errno;
    }
    
while(1)
{
int client;
int length=sizeof(from);
printf("se asteapta la portul %d ... \n",PORT);
fflush(stdout);
client=accept(sd,(struct sockaddr*)&from,&length);
if(client<0)
{
perror("eroare la accept(). \n");
continue;
}
bzero(tampon,100);
printf("asteapta mesajul... \n");
fflush(stdout);
if(read(client,tampon,100)<=0)
{
perror("eroare la read() de la client. \n");
close(client);
continue;
}
printf("mesaj receptionat... \n"
       "trimit mesaj inapoi...");
if(write(client,tampon,100)<=0)
       {
       perror("eroare la write() catre client. \n");
       continue;
       }
   else
      printf("transmitere cu success. \n");
close(client);
      }
}


