CC = g++
OBJ = driver.o
OBJ2 = memory.o

driver: $(OBJ) $(OBJ2) 
	$(CC) $(OBJ) $(OBJ2) -o $@


.cpp.o : 
	$(CC) -c $<


clean:
	rm *.o driver

archive:
	

