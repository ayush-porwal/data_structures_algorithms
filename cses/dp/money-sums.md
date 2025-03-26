<!-- Dp state explanation -->

**DP State:**

1. **Define the State**: Use a boolean array `dp` where `dp[s]` represents whether a sum `s` can be formed using a subset of the coins processed so far.

2. **Initialization**: Start with `dp[0] = true` (sum of 0 is achievable with no coins).

3. **Transition**: For each coin value `x`, iterate backward through the possible sums (from the current maximum possible sum down to `x`). Update `dp[s]` to `true` if `dp[s - x]` was `true` (i.e., adding `x` to a previously achievable sum `s - x` creates a new achievable sum `s`).

4. **Avoid Overcounting**: Processing coins in reverse order (from high to low sums) ensures each coin is used at most once in any subset.

5. **Maximum Sum**: The size of the DP array should be up to the sum of all coin values, as that's the largest possible sum.

Think about how to efficiently track achievable sums and update them iteratively for each coin.


### Go Code:

```go
package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	coins := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&coins[i])
	}

	total := 0
	for _, x := range coins {
		total += x
	}

	dp := make([]bool, total+1)
	dp[0] = true

	for _, x := range coins {
		for s := total; s >= x; s-- {
			if dp[s-x] {
				dp[s] = true
			}
		}
	}

	result := []int{}
	for s := 1; s <= total; s++ {
		if dp[s] {
			result = append(result, s)
		}
	}

	fmt.Println(len(result))
	for _, s := range result {
		fmt.Printf("%d ", s)
	}
	fmt.Println()
}
```

---

### Implementation details:

Track achievable sums using a boolean array (`dp`)

Iterate backward through sums when processing each coin

Collect and print results in sorted order (automatically achieved since we iterate sums in order)

Handle up to 100 coins with values up to 1000 efficiently

The key idea is to reuse the previous state (before considering the current coin) when updating the DP array, which is why we iterate backwards through the sums.