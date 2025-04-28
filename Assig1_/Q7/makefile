CC = gcc
CFLAGS = -Wall -g
TARGETS = ADD2PB findPhone

all: $(TARGETS)

ADD2PB: ADD2PB.c
	$(CC) $(CFLAGS) -o ADD2PB ADD2PB.c

findPhone: findPhone.c
	$(CC) $(CFLAGS) -o findPhone findPhone.c

clean:
	rm -f $(TARGETS)
