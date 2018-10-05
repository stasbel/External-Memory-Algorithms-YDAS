all: run

build:
	g++ main.cpp -O2 -std=c++14 -o main

run: build
	timeout 2m ./main seq-read
	timeout 2m ./main seq-write
	timeout 2m ./main rnd-read
	timeout 2m ./main rnd-write
	timeout 2m ./main rnd-read-parallel 32
	timeout 2m ./main rnd-write-parallel 32

