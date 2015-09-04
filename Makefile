##
## BriefLZ - small fast Lempel-Ziv
##
## GCC Makefile
##

.SUFFIXES:

.PHONY: clean all

CFLAGS = -Wall -Wextra -ansi -pedantic -Ofast -flto
LDFLAGS = -fuse-linker-plugin

ifeq ($(OS),Windows_NT)
  LDFLAGS += -static
  ifeq ($(CC),cc)
    CC = gcc
  endif
endif

objs = example/blzpack.o example/parg.o brieflz.o depack.o

target = blzpack

all: $(target)

%.o : %.c
	$(CC) $(CFLAGS) -I . -o $@ -c $<

$(target): $(objs)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

clean:
	$(RM) $(objs) $(target)
