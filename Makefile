main: backsubst.c gauss.c mat_io.c main.c
	cc -lm -o main backsubst.c gauss.c mat_io.c main.c

clean:
	rm main
