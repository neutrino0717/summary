#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define DATA "Hello World of socket"
int main(int argc, char *argv[])
{
  /* variables */
  /* create socket */
  //server-->/* call bind */
  //server-->/* listen */
  //server-->/* accept */
  /* connect */

  /* variables */
  int sock;
  struct sockaddr_in server;
  struct hostent *hp;     //new in client
  //int mysock;
  char buff[1024];
  //int rval;
  /* create socket */
  sock = socket(AF_INET, SOCK_STREAM, 0); //same as server
  if(sock <0) {
    perror("Failed to create socket");
    exit(1);
  }
  hp = gethostbyname("localhost");   //new in client
  printf("hp->h_name: %s\n", hp->h_name);
  printf("hp->h_addrtype: %d\n", hp->h_addrtype);
  printf("hp->h_length: %d\n", hp->h_length);
  printf("hp->h_addr: %s\n", hp->h_addr);


  if(hp == 0){
    perror("gethostbyname failed.");
    close(sock);
    exit(1);
  }
  server.sin_family = AF_INET;
  //server.sin_addr.s_addr = INADDR_ANY;
  memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
  server.sin_port = htons(5000);
  printf("htons(5000): sin_port: %d\n", htons(5000));

  if(connect(sock, (struct sockaddr *) &server, sizeof(server)) <0) {
    perror("connect failed");
    close(sock);
    exit(1);
  }
  if(send(sock, DATA, sizeof(DATA), 0 ) < 0) {
    perror("send failed");
    close(sock);
    exit(1);
  }
  perror("send done");
  printf("sent: %s\n", DATA);
  close(sock);

  return 0;
}
