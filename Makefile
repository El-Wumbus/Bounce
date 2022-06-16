CC = gcc
CFLAGS = -lncurses
source = src/main.c
BIN = "dist/main"
defualt: build

build: ${source}
	mkdir -p dist
	${CC} -o ${BIN} src/main.c ${CFLAGS}

install: build
	mkdir -p "${PREFIX}${DESTDIR}/usr/bin"
	mkdir -p "${DESTDIR}${PREFIX}/usr/share/doc"
	install -Dm755 dist/main "${PREFIX}${DESTDIR}/usr/bin/main"
	install -Dm644 README.rst "${DESTDIR}${PREFIX}/usr/share/doc/main"

clean:
	$(RM) -rf $(BIN)