
CC = gcc
CFLAGS = 
LD = gcc
LDFLAGS = 

OBJS = list.o test_list.o
TARGET = test_list

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)
