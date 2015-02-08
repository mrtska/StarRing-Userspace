#ブート時
FILE :=  init.o
TARGET := init.elf

LD		:= x86_64-pc-linux-gnu-ld
AS		:= x86_64-pc-linux-gnu-as
OBJCOPY	:= x86_64-pc-linux-gnu-objcopy
NM		:= x86_64-pc-linux-gnu-nm

.c.o:
	x86_64-pc-linux-gnu-gcc -g -Wl,-Map $(TARGET).map -pipe  -Wall $< -o $@
.S.o:
	x86_64-pc-linux-gnu-gcc -O2 -Wall -c $< -o $@

#コンパイル
compile: $(TARGET)
$(TARGET):$(FILE)
	
	
	$(CP) -f ./$(FILE) /cygdrive/g/$(TARGET)


#バイナリ消去
clean:
	$(RM) -f $(FILE) $(TARGET)


#テストコード
test:
#	$(CC) -E -I../$(INCLUDE) -o test.E main.c
	x86_64-pc-linux-gnu-gcc -Wall -I./include -o init.o init.c ../lib/libstarring.a

