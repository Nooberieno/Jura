CC := clang
CFLAGS := -std=c99 -D_POSIX_C_SOURCE=200809L -Wextra -Wall -pedantic
INSTALL_DIR := /usr/local/bin

TARGET := jura
SRC := $(wildcard src/*.c)
HEADERS := $(wildcard src/include/*.h)

.PHONY: all install develop clean uninstall

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $@

install: $(TARGET)
	install -m 755 $(TARGET) $(INSTALL_DIR)/$(TARGET) 

develop: CFLAGS += -g -Og
develop: clean $(TARGET)

uninstall:
	rm -f $(INSTALL_DIR)/$(TARGET) 

clean:
	rm -f $(TARGET)