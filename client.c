#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>

//socket() used to create socket
//connect() is use to connect to socket
//recv is use to get message from socket created [server]

int main() {
    int socket_1;
    socket_1 = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons(8000);

    int conn_status = connect(socket_1, (struct sockaddr *) &server, sizeof(server));

    if (conn_status == -1)
        printf("Error Connecting Server\n");

    char server_message[256];
    recv(socket_1, &server_message, sizeof(server_message), 0);

    printf(server_message);
    return 0;
}
