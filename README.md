# About

Simple command line tool to send typical RF controlled wall switches codes with cheap 433Mhz RF sender modules and a Raspberry Pi.

## Compiling

First you have to install the [wiringpi](https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/) library.
After that you can compile the program *send* by executing *make*.
You may want to change the used GPIO pin before compilation in the send.cpp source file.
A compiled binary for armv6l is included in the repository.

## Usage

```
./send <channel> <switch> <command>
```

So for instance:

```
./send 4 1 1
```

To send "ON" to the first switch of the third channel.
