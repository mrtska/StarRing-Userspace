#ブート時
FILE := graphics.o
TARGET := gui.sys


.c.o:
	x86_64-pc-linux-gnu-gcc -Wl,-Map $(TARGET).map -pipe -nostdlib -O2 -Wall -I../include $< -c -o $@

.S.o:
	$(CC) -mcmodel=kernel -I../$(INCLUDE) -ffreestanding -nostdlib -mno-red-zone -Wall -c $< -o $@

#コンパイル
compile: $(TARGET)
$(TARGET):$(FILE)

	$(LD) -r -o $(TARGET) $(FILE)
	

#バイナリ消去
clean:
	$(RM) -f $(FILE) $(TARGET)


#テストコード
test:
	$(CC) -S -I../$(INCLUDE) -o test.S page.c

