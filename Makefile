CC = gcc
CFLAGS = -g
TARGET = dl_list_ex
SOURCES = dl_list.c dl_list_ex.c
OBJ = $(patsubst %.c,%.o,$(SOURCES))

$(TARGET):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)
	rm *.o

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
