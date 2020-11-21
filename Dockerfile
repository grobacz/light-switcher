from perl:latest
workdir /src/

copy . .
run cd Device-Osram-Lightify/ && \
	perl Makefile.PL && \
	make && make install

run apt-get update && \
	apt-get install python2.7

cmd ["python", "/src/light-demon.py"]
