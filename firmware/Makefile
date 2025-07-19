# firmware/Makefile

CC = gcc
CFLAGS = -Iinclude

SRC = bootloader.c secure_model_load.c inference_engine.c crypto_utils.c
OBJ = $(SRC:.c=.o)
TARGET = secure_tinyml_boot

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o
