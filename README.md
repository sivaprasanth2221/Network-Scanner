This project is a simple port scanner implemented in C. It allows users to scan a range of IP addresses for a specific port to check if it is open or closed. Below is a description that you can use to upload this project to GitHub:

---

# Port Scanner in C

This is a command-line port scanner implemented in C programming language. The purpose of this tool is to scan a range of IP addresses for a specific port and determine whether the port is open or closed.

## Features

- Scans a range of IP addresses for a given port number.
- Determines whether the specified port is open or closed on each scanned IP address.
- Supports IPv4 addresses.
- Simple and easy-to-use command-line interface.

## Usage

To use the port scanner, follow these steps:

1. Compile the program using a C compiler (e.g., gcc).
   ```
   gcc port_scanner.c -o port_scanner
   ```

2. Run the compiled program with the following arguments:
   ```
   ./port_scanner <start_ip> <end_ip> <port>
   ```
   Replace `<start_ip>` and `<end_ip>` with the starting and ending IP addresses of the range you want to scan, and `<port>` with the port number you want to check.

## Example

Scan the range of IP addresses from `192.168.0.1` to `192.168.0.10` for port `80`:
```
./port_scanner 192.168.0.1 192.168.0.10 80
```


## Acknowledgments

- This project is for educational purposes and should be used responsibly.
- Inspired by network security and port scanning techniques.

---
