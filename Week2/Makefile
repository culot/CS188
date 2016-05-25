CC=	g++
LD=	g++
CFLAGS=	-g -Wall -Werror -std=c++11
BINS=	pacman
OBJS=	$(wildcard *.o)

PACMAN_SRCS=	pacman.cc pov.cc
PACMAN_OBJS=	$(PACMAN_SRCS:.cc=.o)

all:	$(BINS)

pacman:	$(PACMAN_OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

%.o:	%.cc
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(BINS) $(OBJS)
