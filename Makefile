CFLAGS += -g -fPIC
LDLIBS += -ldl -lncurses

default: worst-game better-game better-game-module.so

worst-game:

better-game: better-game-host.o
	$(CC) -o $@ $< $(LDLIBS)

better-game-module.so: better-game-module.o
	$(CC) -shared -o $@ $^ $(LDLIBS)

clean:
	-rm *.o worst-game better-game better-game-module.so
