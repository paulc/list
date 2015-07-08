
CC = cc 
CFLAGS = -g
LD = cc
LDFLAGS = -g

LIST_OBJS = list.o test_list.o 
LIST_TARGET = test_list
BUFFER_OBJS = buffer.o test_buffer.o 
BUFFER_TARGET = test_buffer

all: $(LIST_TARGET) $(BUFFER_TARGET)
	
$(LIST_TARGET): $(LIST_OBJS)
	$(LD) $(LDFLAGS) $(LIST_OBJS) -o $(LIST_TARGET)

$(BUFFER_TARGET): $(BUFFER_OBJS)
	$(LD) $(LDFLAGS) $(BUFFER_OBJS) -o $(BUFFER_TARGET)

clean:
	rm -f $(LIST_TARGET) $(LIST_OBJS)
	rm -f $(BUFFER_TARGET) $(BUFFER_OBJS)
