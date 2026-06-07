CC=gcc
CFLAGS=-Iinclude 
OBJ=src/main.o src/memory_slave.o src/fifo_slave.o src/lifo_slave.o src/i2c_bus.o src/master.o
i2c_simulator: $(OBJ)
	$(CC) $(OBJ) -o i2c_simulator
src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o
src/memory_slave.o: src/memory_slave.c include/memory_slave.h
	$(CC) $(CFLAGS) -c src/memory_slave.c -o src/memory_slave.o
src/fifo_slave.o: src/fifo_slave.c include/fifo_slave.h
	$(CC) $(CFLAGS) -c src/fifo_slave.c -o src/fifo_slave.o
src/lifo_slave.o: src/lifo_slave.c include/lifo_slave.h
	$(CC) $(CFLAGS) -c src/lifo_slave.c -o src/lifo_slave.o
src/i2c_bus.o: src/i2c_bus.c include/i2c_bus.h
	$(CC) $(CFLAGS) -c src/i2c_bus.c -o src/i2c_bus.o
src/master.o: src/master.c include/master.h
	$(CC) $(CFLAGS) -c src/master.c -o src/master.o
clean:
	rm -f src/*.o i2c_simulator
