IDIR =include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=src/obj
LDIR =lib

LIBS=-lm

_DEPS = selection.h insertion.h treesort.h bubblesort.h merge.h quick.h sortingtests.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = selection.o insertion.o treesort.o bubblesort.o merge.o quick.o sortingtests.o sorting.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

srt: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 
