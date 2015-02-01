export LANG=C

#定義群
HOME_DIR	= "$(CURDIR)"

CC		:= x86_64-pc-linux-gnu-gcc -O2
LD		:= x86_64-pc-linux-gnu-ld
AS		:= x86_64-pc-linux-gnu-as
OBJCOPY	:= x86_64-pc-linux-gnu-objcopy
NM		:= x86_64-pc-linux-gnu-nm
RM		:= rm
MAKE	:= make
CP		:= cp
CD		:= cd
MAKE	:= make
INCLUDE := include

export CC
export LD
export OBJCOPY
export NM
export RM
export CP
export CD
export MAKE
export INCLUDE


OBJECTS :=

.PHONY: all
all: compile

.PHONY: compile
compile:

	$(CD) userspace;$(MAKE)
	#$(CD) gui;$(MAKE)

.PHONY: libmake
libmake:
	
	$(CD) lib;$(MAKE) clean
	$(MAKE) clean
	$(CD) gui;$(MAKE)
	$(CD) lib;$(MAKE)
	$(CD) userspace;$(MAKE)


.PHONY: clean
clean:
	$(CD) userspace;$(MAKE) clean
	$(CD) gui;$(MAKE) clean
	
.PHONY: test
test:
	
	sh ./freetype/configure
	$(CD) freetype; $(MAKE)
	
	
	
	
