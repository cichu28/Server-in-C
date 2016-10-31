# Server-in-C

*** HOW TO COMPILE? ***
1 terminal:
gcc -o server LedON.c LedON.h server.c -lwiringPi
sudo ./server

2 terminal:
gcc -o client client.c
sudo ./client
