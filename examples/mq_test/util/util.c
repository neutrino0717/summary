#include <util/util.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>


#define MAX_BYTES_PER_SOCKET_WRITE 65000; 

struct sockaddr_in si_me;
struct sockaddr_in si_other;
struct sockaddr_in si_other_out;
struct sockaddr_in si_msg_out;

I32 slen=sizeof(si_other);

void assert_internal(const char* file, int line){
  printf("Hit ASSERT in file %s, line %d. Aborting\n", file, line);
  exit(1);
}

void assert_good(void){
  return;
}





