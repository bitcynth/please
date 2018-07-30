CC = gcc

SRCS = main.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -c
LDFLAGS = 

MAIN = please

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

$(MAIN): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

all: $(MAIN)

install: $(MAIN)
	cp $(MAIN) /bin/please
	chown root:root /bin/please
	chmod 4701 /bin/please
