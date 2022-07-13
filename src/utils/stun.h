#include <sys/socket.h>
#include <netinet/in.h>

int get_external_ip(const char* hostname, const uint16_t host_port, const uint16_t local_port, char* result)
{
    unsigned int address;

    if((address = inet_addr(hostname)) == INADDR_NONE)
    {
        hostent* entity = gethostbyname(hostname);

        if(entity == NULL)
        {
            return -1;
        }

        address = *(DWORD*)(entity->h_addr_list[0]);
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sockfd == INVALID_SOCKET)
    {
        return -2;
    }

    sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.S_un.S_addr = address;
    servaddr.sin_port = htons(host_port);

    sockaddr_in localaddr;
    memset(&localaddr, 0, sizeof(localaddr));
    localaddr.sin_family = AF_INET;
    localaddr.sin_port = htons(local_port);

    short temp = bind(sockfd, (sockaddr*) &localaddr, sizeof(localaddr));

    if(temp == SOCKET_ERROR)
    {
        return -3;
    }

    unsigned char request[20];
    *(short*)(&request[ 0]) = htons(0x0001);       // message type
    *(short*)(&request[ 2]) = htons(0x0000);       // message length
    *(  int*)(&request[ 4]) = htonl(0x2112A442);   // magic cookie
    *(  int*)(&request[ 8]) = htonl(0x63c7117e);   // transaction id
    *(  int*)(&request[12]) = htonl(0x0714278f);   // transaction id
    *(  int*)(&request[16]) = htonl(0x5ded3221);   // transaction id

    temp = sendto(sockfd, (char*) request, sizeof(request), 0, (sockaddr*) &servaddr, sizeof(servaddr));

    if(temp == -1)
    {
        return -4;
    }

    unsigned char response[200];

    temp = recvfrom(sockfd, (char*) response, sizeof(response), 0, NULL, 0);

    if(temp == -1)
    {
        return -5;
    }

    if(*(short*)(&response) == htons(0x0101))
    {
        int i = 20;

        while(i < sizeof(response))
        {
            short type = htons(*(short*)(&response[i]));
            short length = htons(*(short*)(&response[i + 2]));

            if(type == 0x0020)
            {
                unsigned short port = ntohs(*(short *)(&response[i + 6]));
                port ^= 0x2112;

                sprintf(result, "%d.%d.%d.%d:%d",
                        response[i +  8] ^ 0x21,
                        response[i +  9] ^ 0x12,
                        response[i + 10] ^ 0xA4,
                        response[i + 11] ^ 0x42,
                        port);

                break;
            }

            i += 4 + length;
        }
    }

    closesocket(sockfd);
    return 0;
}