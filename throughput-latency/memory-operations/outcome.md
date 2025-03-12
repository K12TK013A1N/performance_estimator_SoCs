## LOAD

In both independent as well as dependent case the loop ran for 2^30 times while each iteration had 2^5 operation.

$$Throughput = \frac{480 * 10^{6} * 76.647}{2^{30} * 2^{5}}$$
$$Latency = \frac{480 * 10^{6} * 216.531}{2^{30} * 2^{5}}$$
$$Throughput = 1.07$$
$$Latency = 3.02$$

Here the latency is 3 times throughput suggesting there are 3 memory loading paths that can work simmultaneously or the load instruction is pipelined in 3 phases.

