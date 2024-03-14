#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

void scan_port(const char* ip, int port) {
    int sockfd;
    struct sockaddr_in target_addr;
    // Socket creation
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        return;
    }
    // Set target address
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &(target_addr.sin_addr)) <= 0) {
        perror("Invalid address");
        close(sockfd);
        return;
    }
    // Connect to target
    if (connect(sockfd, (struct sockaddr*)&target_addr, sizeof(target_addr)) < 0) {
        printf("Port %d: Closed\n", port);
    } else {
        printf("Port %d: Open\n", port);
        close(sockfd);
    }
}
int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <start_ip> <end_ip> <port>\n", argv[0]);
        return 1;
    }
    const char* start_ip = argv[1];
    const char* end_ip = argv[2];
    int port = atoi(argv[3]);
    struct in_addr start, end;
    if (inet_pton(AF_INET, start_ip, &start) <= 0 || inet_pton(AF_INET, end_ip, &end) <= 0) {
        perror("Invalid IP address");
        return 1;
    }
    unsigned int start_ip_num = ntohl(start.s_addr);
    unsigned int end_ip_num = ntohl(end.s_addr);
    unsigned int curr_ip_num;
    // Iterate over IP range
    for (curr_ip_num = start_ip_num; curr_ip_num <= end_ip_num; curr_ip_num++) {
        struct in_addr curr_ip;
        curr_ip.s_addr = htonl(curr_ip_num);
        char curr_ip_str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(curr_ip.s_addr), curr_ip_str, INET_ADDRSTRLEN);
        printf("Scanning %s...\n", curr_ip_str);
        scan_port(curr_ip_str, port);
    }
    return 0;
}
