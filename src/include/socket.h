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
int32_t initSocket(struct socketStruct* socketPointer);
int32_t sendData(struct socketStruct* socket, struct destination * dest, const char* data, u_int64_t dataLength);
int32_t recvData(struct socketStruct* socket, char * dataBuffer, u_int64_t dataBufferLength);
int32_t closeSocket(struct socketStruct * socket);
void freeSocket(struct socketStruct * socket);

int32_t initSocketTCP(struct socketStruct* socketPointer);
int32_t bindPort(struct socketStruct* socketPointer, uint16_t port);
int32_t connectPort(struct socketStruct* socketPointer, struct destination* dest);
struct socketStruct * acceptClient(struct socketStruct* socketPointer);
int32_t sendDataTCP(struct socketStruct* socketPointer, const char* data, uint64_t dataBufferSize);
int32_t recvDataTCP(struct socketStruct* socketPointer, char* dataBuffer, int32_t packetSize);

int32_t getSocketError();