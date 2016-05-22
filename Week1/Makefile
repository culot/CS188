CC=	g++
CFLAGS=	-g -Wall -Werror -std=c++11
BINS=	addition buyLotsOfFruit

all:	${BINS}

addition:	addition.cc
	${CC} ${CFLAGS} -o $@ $^

buyLotsOfFruit:	buyLotsOfFruit.cc
	${CC} ${CFLAGS} -o $@ $^

clean:
	@rm -f ${BINS}
