#
#    Makefile for sunaarashi
#

SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
ARCH	= $(shell gcc -print-multiarch)
LIBS	= -ljpeg

DEFCFLAGS = -DARCH=\"$(ARCH)\"	  \
		$(LIBS)

DEFLDFLAGS = $(LIBS)

all: $(TARGET) $(OBJS)

$(TARGET): $(OBJS)
ifeq ($(CMDLINE), 0)
	@echo "  BUILD   $@"
	@$(CC) $(LDFLAGS) $^ -o $@ $(DEFLDFLAGS)
else
	$(CC) $(LDFLAGS) $^ -o $@ $(DEFLDFLAGS)
endif

%.o: %.c %.h
ifeq ($(CMDLINE), 0)
	@echo "  CC      $@"
	@$(CC) $(CFLAGS) -c $< -o $@ $(DEFCFLAGS)
else
	$(CC) $(CFLAGS) -c $< -o $@ $(DEFCFLAGS)
endif

install-bin: $(TARGET)
	install -pd $(BINDIR)
	install -pm 755 $< $(BINDIR)/

clean:
	-$(RM) -f $(OBJS)
	-$(RM) -f $(TARGET)

.PHONY: all		\
	install-bin	\
	clean
