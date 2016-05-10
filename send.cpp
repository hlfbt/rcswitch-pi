/*
 Usage: ./send <systemCode> <unitCode> <command>
 Command is 0 for OFF and 1 for ON
 */

#include "rcswitch-pi/RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    int PIN = 0;
    int channel = atoi(argv[1]);
    int _switch = atoi(argv[2]);
    int command = atoi(argv[3]);

    if (wiringPiSetup () == -1) return 1;
    printf("sending to channel %i, switch %i, command %i\n", channel, _switch, command);
    RCSwitch mySwitch = RCSwitch();
    mySwitch.enableTransmit(PIN);
    mySwitch.setProtocol(1);
    mySwitch.setRepeatTransmit(7);
    mySwitch.setPulseLength(426);

    char code[] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '0', '0'};

    switch (channel) {
        case 1:
            code[3] = '1';
            code[5] = '1';
            code[7] = '1';
            break;
        case 2:
            code[1] = '1';
            code[5] = '1';
            code[7] = '1';
            break;
        case 3:
            code[1] = '1';
            code[3] = '1';
            code[7] = '1';
            break;
        case 4:
            code[1] = '1';
            code[3] = '1';
            code[5] = '1';
            break;
        default:
            printf("the first channel argument accepts a value between 1-4\n");
            return -1;
    }

    switch (_switch) {
        case 1:
            code[11] = '1';
            code[13] = '1';
            code[15] = '1';
            break;
        case 2:
            code[9]  = '1';
            code[13] = '1';
            code[15] = '1';
            break;
        case 3:
            code[9]  = '1';
            code[11] = '1';
            code[15] = '1';
            break;
        case 4:
            code[9]  = '1';
            code[11] = '1';
            code[13] = '1';
            break;
        default:
            printf("the second switch argument accepts a value between 1-4\n");
            return -1;
    }

    switch (command) {
        case 1:
            code[23] = '1';
            break;
        case 0:
            break;
        default:
            printf("the third command argument accepts either 0 or 1\n");
            return -1;
    }

    printf("sending code %s\n", code);
    mySwitch.send(code);

    return 0;
}
