FROM gcc:12-bullseye

WORKDIR /app

COPY . .

RUN g++ -o radix radix.cpp

CMD ["./radix", "primer_vhoda.txt"]

