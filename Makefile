CFLAGS += -g -fPIC
LDLIBS += -ldl -lncurses

worst-game:

better-game: better-game.o better-game-module.so
	$(CC) -o $@ $^ $(LDLIBS)

better-game-module.so: better-game-module.o
	$(CC) -shared -o $@ $^ $(LDLIBS)

better-game: better-game-module.so

clean:
	-rm *.o worst-game better-game better-game-module.so
