CC = gcc
CFLAGS = -Wall -ffast-math -Os -s -fno-ident -fno-math-errno -ffunction-sections -fdata-sections -fno-stack-protector -fno-unwind-tables -fno-asynchronous-unwind-tables -Wl,--build-id=none -Wl,-z,norelro -Wl,--gc-sections -Wl,--hash-style=gnu 

clizeit: clizeit.c
	$(CC) $(CFLAGS) -o clizeit clizeit.c

clean:
	rm -f clizeit
