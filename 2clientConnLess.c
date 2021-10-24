#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
int main()
{
int sockfd,servlen;
struct sockaddr_in serv_addr,cli_addr;
char msg[50],msg1[50];
sockfd = socket(AF_INET,SOCK_DGRAM,0);
if(sockfd <0){
printf("invalid socket");
exit(0);
}
serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
serv_addr.sin_port = htons(4578);
printf("Enter the message :");
scanf("%s",msg);
if(sendto(sockfd,msg,80,0,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0){
printf("t");
exit(0);
}
servlen = sizeof(serv_addr);
if(recvfrom(sockfd,msg1,50,0,(struct sockaddr *)&serv_addr,&servlen)<0){
printf("s");
exit(0);
}
else{
printf("Message recieved : %s\n",msg1);
}
close(sockfd);
}
