INC_DIR=$(HOME)/graduation/c/mq_test

mq: mqueue_test.c $(INC_DIR)/util/util.c
	gcc mqueue_test.c $(INC_DIR)/util/util.c -I$(INC_DIR) -lpthread -lrt -o mqueue_test.o
	$(INC_DIR)/mqueue_test.o
all: mq

clean:
	rm -rf *.o 
