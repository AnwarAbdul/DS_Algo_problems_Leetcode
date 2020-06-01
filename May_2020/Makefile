CC = g++
CFLAGS = -pipe -O2 -std=c++14
LFLAGS = -lm

.PHONY: build
build: $(file)
	$(CC) $(CFLAGS) $(file) $(LFLAGS)
.PHONY: clean
clean:
	rm -f *.out *.o
