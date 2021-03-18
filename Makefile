CC = gcc
CFLAGS = -Wall -g

all: cardlist solution nocoalesce testheap testnocoalesce

cardlist: cardmain.o cardlist.o card.o heapmgr.o
	$(CC) $(CFLAGS) -o cardlist cardmain.o card.o cardlist.o heapmgr.o

cardlist.o: cardlist.c cardlist.h card.h heapmgr.h
	$(CC) $(CFLAGS) -c cardlist.c

cardmain.o: cardmain.c cardlist.h card.h
	$(CC) $(CFLAGS) -c cardmain.c

card.o : card.c card.h
	$(CC) $(CFLAGS) -c card.c

heapmgr.o: heapmgr.c heapmgr.h
	$(CC) $(CFLAGS) -c heapmgr.c 

test_heap.o: test_heap.c heapmgr.h
	$(CC) $(CFLAGS) -c test_heap.c

.PHONY: clean
clean:
	@-rm -f *.o cardlist solution nocoalesce testheap testnocoalesce

solution: cardmain.o cardlist.o card.o solution.o
	$(CC) $(CFLAGS) -o solution cardmain.o cardlist.o card.o solution.o

nocoalesce: cardmain.o cardlist.o card.o nocoalesce.o
	$(CC) $(CFLAGS) -o solution cardmain.o cardlist.o card.o nocoalesce.o

testheap: test_heap.o solution.o
	$(CC) $(CFLAGS) -o testheap test_heap.o solution.o

testnocoalesce: test_heap.o nocoalesce.o
	$(CC) $(CFLAGS) -o testnocoalesce test_heap.o nocoalesce.o 

solution.o:
	ln -s /home/isaacman/public_html/366/solution.o

nocoalesce.o:
	ln -s /home/isaacman/public_html/366/nocoalesce.o

