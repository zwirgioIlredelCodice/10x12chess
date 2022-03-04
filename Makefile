src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

10x12chess.out: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(obj) 10x12chess.out