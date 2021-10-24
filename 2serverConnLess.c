#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
int main(){
int sockfd,clilen;
struct sockaddr_in serv_addr,cli_addr;
char msg[50];
sockfd = socket(AF_INET,SOCK_DGRAM,0);
if(sockfd <0){
printf("invalid socket");
exit(0);
}
serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
serv_addr.sin_port = htons(4578);
if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0){
printf("bind invlaid");
exit(0);
}
clilen = sizeof(cli_addr);
recvfrom(sockfd,msg,50,0,(struct sockaddr *)&cli_addr,&clilen);
printf("Message recevied from client is : %s\n",msg);
sendto(sockfd,msg,50,0,(struct sockaddr *)&cli_addr,clilen);
close(sockfd);
}
