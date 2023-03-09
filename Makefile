EXECBIN = disko
GCC = gcc -o ${EXECBIN} -Werror -Wall -Wextra -std=c99

SOURCES = $(wildcard ./src/*)

.PHONY: disko
${EXECBIN}:
	${GCC} ${SOURCES}

.PHONY: clean
clean:
	rm ${EXECBIN}
