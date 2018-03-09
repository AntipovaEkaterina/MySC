.PHONY: mySC

mySC:
	$(CC) -w *.c -o mySC
clean:
	rm mySC