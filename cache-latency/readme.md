# Cache Latency
- program 1 has almost 100% cache hit, making it a good estimator for cache latency 
- program 2 has almost 100% cache miss, making it a good estimator for memory latency calculator
- compile: `g++ -O0 L1_latency.cpp -o L1_latency.out`
-run: `perf stat -e L1-dcache-loads,L1-dcache-load-misses,LLC-loads,cycles ./L1_latency.out`