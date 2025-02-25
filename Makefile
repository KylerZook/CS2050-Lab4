CC = gcc
CFLAGS = -Wall -Werror -c -g -std=c11
SAN_FLAGS = -fsanitize=address
LDFLAGS = -lm
OBJS = main.o lab4.o


a.out: CFLAGS += $(SAN_FLAGS)
a.out: LDFLAGS += $(SAN_FLAGS)
a.out: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o a.out


a_nosan.out: $(OBJS)
	$(CC) $(OBJS) -o a_nosan.out

%.o : %.c
	$(CC) $(CFLAGS) -c $<


.PHONY: clean asan nosan

asan: clean a.out 
nosan: clean a_nosan.out  

clean:
	rm -f a.out a_nosan.out $(OBJS)


