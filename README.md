# Coin Flip Simulator

A small C++ program that flips a fair coin `n` times and reports how many heads and tails came up, with percentages.

## Build

Requires a C++17 compiler (g++ or clang++).

```
make
```

Or without make:

```
g++ -std=c++17 -O2 coin_flip.cpp -o coin_flip
```

## Run

```
./coin_flip
```

Enter the number of flips when prompted. Invalid input (letters, zero, negative numbers) is rejected, and the program asks again.

On Windows, run `coin_flip.exe` instead.

## Example

```
How many flips? 1000000
Flips: 1000000
Heads: 499750 (49.98%)
Tails: 500250 (50.02%)
```

Results are random, so your numbers will differ.

## How it works

- Random numbers come from `std::mt19937` (Mersenne Twister), seeded with `std::random_device`.
- Each flip is a draw from `std::bernoulli_distribution(0.5)`: `true` is heads, `false` is tails.
- Tails is computed as `n - heads`, so the two counts always sum to `n`.
- Counts are stored as `long long`, so large values of `n` don't overflow.

As `n` grows, the heads percentage converges toward 50% (law of large numbers). Small runs swing much more.

## License

MIT. See [LICENSE](LICENSE).
