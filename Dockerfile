FROM gcc:12-bullseye

WORKDIR /app

COPY . .

RUN g++ -o radix dn1.cpp

CMD ["./radix", "primer_vhoda.txt"]

