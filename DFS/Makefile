include Rules.make

LIBS = -lArray -lEnhancedStack -lLinkedList -lGraph

OBJS = Heuristic.o \
       main.o

Heuristic.o: Heuristic.c
	$(CC) $(CFLAGS) -c -o Heuristic.o Heuristic.c -I$(INC_DIR) -L$(LIB_DIR) $(LIBS)
main.o : main.c
	$(CC) $(CFLAGS) -c -o main.o main.c -I$(INC_DIR) -L$(LIB_DIR) $(LIBS)

all: $(OBJS)
	$(CC) $(CPPFLAGS) -o $(TARGET) $(OBJS) -I$(INC_DIR) -L$(LIB_DIR) $(LIBS)

clean:
	find -name "*.o" -exec rm {} \;
	@rm -v -f $(TARGET)

distclean: clean
	@for i in $(MODULES); do \
		echo "Clearing in $$i..."; \
		(cd $$i; $(MAKE) distclean); \
		(cd $$i; $(MAKE) clean); \
	done
