# Latency & Throughput 

## Throughput

Number of operations in a single cycle.

$$Throughput= \frac {\text{cpu-frequency} * \text{Time of execution}}{\text{number of operation}}$$

here the operations can be executed parallely or can be pipelined.

## Latency 

Number of cycles taken by an operation to complete.

$$Latency= \frac {\text{cpu-frequency} * \text{Time of execution}}{\text{number of operation}}$$

but here the operations are made sure to be serialised.

### How to calculate time ?

linux provides a way to calculate the time of execution of an execuatable using "time" command.

~~~~
g++ -c assembly-file.S
g++ assembly-file.o -o executable
time ./executable
~~~~
