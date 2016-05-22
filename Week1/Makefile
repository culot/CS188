CC=	g++
CFLAGS=	-g -Wall -Werror -std=c++11
BINS=	addition

all:	${BINS}

addition:	addition.cc
	${CC} ${CPPFLAGS} -o $@ $^

clean:
	@rm -f ${BINS}
