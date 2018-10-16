#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>

//The socket() function shall create an unbound socket in a communications domain
//bind() publishes socket on network
//listen() marks the connection mode
//accept() is use to read and write data from or to socket
//send() is use to send data

int main(int argc, char *argv[]) {
    char message[256] = "Hi! I'm a Server\n";

    int socket_1;
    socket_1 = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons(8000);

    bind(socket_1, (struct sockaddr *) &server, sizeof(server));

    listen(socket_1, 5);

    int client_socket = accept(socket_1, NULL, NULL);

    send(client_socket, message, sizeof(message), 0);
    return 0;
}
