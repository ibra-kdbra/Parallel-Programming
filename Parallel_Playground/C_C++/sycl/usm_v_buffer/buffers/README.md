# To run

```sh
./nbody.x 2000 500 1
```

This will simulate 2000 particles for 500 seconds, with 100% of the computation done on the CPU.

## Expected Result

The simulation is initialized on an Intel(R) Xeon(R) CPU E5-2660 0 @ 2.20GHz with 2000 particles.

| s   | dt  | kenergy | time (s) | GFlops |
|-----|-----|---------|----------|--------|
| 50  | 5   | 0.1432  | 0.26196  | 22.148 |
| 100 | 10  | 2.4341  | 0.19766  | 29.353 |
| 150 | 15  | 8.1256  | 0.19748  | 29.38  |
| 200 | 20  | 17.877  | 0.19733  | 29.403 |
| 250 | 25  | 32.966  | 0.20042  | 28.948 |
| 300 | 30  | 55.786  | 0.19829  | 29.26  |
| 350 | 35  | 91.132  | 0.19331  | 30.013 |
| 400 | 40  | 150.12  | 0.19377  | 29.942 |
| 450 | 45  | 264.78  | 0.19502  | 29.75  |
| 500 | 50  | 571.53  | 0.20833  | 27.85  |
