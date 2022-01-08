all: producer consumer

producer:
	gcc producer.c -o p

consumer:
	gcc consumer.c -o c

clean:
	rm p c

