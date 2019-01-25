#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>
#include <strings.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "destination.h"

struct socketStruct{
    int32_t socketDescriptor;
};


struct socketStruct * createSocket();
int initSocket(struct socketStruct* socketPointer);
int sendData(struct socketStruct* socket, struct destination * dest, const char* data, size_t dataLength);
int recvData(struct socketStruct* socket, char * dataBuffer, size_t dataBufferLength);
int closeSocket(struct socketStruct * socket);
void freeSocket(struct socketStruct * socket);

int initSocketTCP(struct socketStruct* socketPointer);
int bindPort(struct socketStruct* socketPointer, uint16_t port);
int connectPort(struct socketStruct* socketPointer, struct destination* dest);
struct socketStruct * acceptClient(struct socketStruct* socketPointer);
int sendDataTCP(struct socketStruct* socketPointer, const char* data, size_t dataBufferSize);
int recvDataTCP(struct socketStruct* socketPointer, char* dataBuffer, int32_t packetSize);

int getSocketError();