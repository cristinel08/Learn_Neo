CC=gcc
CFLAGS=-mcpu=cortex-a57 -mfpu=neon -mfloat-abi=hard -c -Wall
LIBS=-WL, --start-group, -lgcc, -lc, --end-group

main.o:main.c
	${CC} ${CFLAGS} -o main.o main.c
clean:
	rm *.o