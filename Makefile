    CC     = gcc -g
    CFLAGS =
    LFLAGS = -lcgraph -lgvc -lcdt

      PROG = toposort
      OBJS = graph.o \
             $(PROG).o

.PHONY: limpa faxina clean distclean purge all

%.o: %.c %.h utils.h sislin.h
        $(CC) -c $(CFLAGS) $<

$(PROG):  $(OBJS)
        $(CC) -o $@ $^ $(LFLAGS)

clean:
        @rm -f *~ *.bak

purge:   clean
        @rm -f *.o core a.out
        @rm -f $(PROG)