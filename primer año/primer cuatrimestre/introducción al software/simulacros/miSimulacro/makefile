program_NAME := futbolClub.c

SRCS = futbolClub.h futbolClub.c

.PHONY: all

all: $(program_NAME)

$(program_NAME): $(SRCS) 
    ar -rcs libmylib.a mylib.o
    cc -m32 prog.o -L. -lmylib