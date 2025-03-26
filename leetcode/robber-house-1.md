To solve the House Robber problem using dynamic programming, we can define multiple dynamic programming states and approaches. Here are the different methods along with their explanations and code implementations in C++ and Go:

---

### **1. 1D Dynamic Programming Array**
**State Definition**: `dp[i]` represents the maximum money that can be robbed up to the `i`-th house.  
**Recurrence Relation**:  
`dp[i] = max(dp[i-1], dp[i-2] + nums[i])`  
**Base Cases**:  
`dp[0] = nums[0]`, `dp[1] = max(nums[0], nums[1])`  

#### **C++ Code**
```cpp
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp.back();
}
```

#### **Go Code**
```go
func rob(nums []int) int {
    n := len(nums)
    if n == 0 {
        return 0
    }
    if n == 1 {
        return nums[0]
    }
    dp := make([]int, n)
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])
    for i := 2; i < n; i++ {
        dp[i] = max(dp[i-1], dp[i-2]+nums[i])
    }
    return dp[n-1]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```

---

### **2. Space-Optimized DP (Two Variables)**
**Optimization**: Track only the previous two values to reduce space complexity to O(1).  

#### **C++ Code**
```cpp
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int prev_prev = nums[0], prev = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
        int curr = max(prev, prev_prev + nums[i]);
        prev_prev = prev;
        prev = curr;
    }
    return prev;
}
```

#### **Go Code**
```go
func rob(nums []int) int {
    n := len(nums)
    if n == 0 {
        return 0
    }
    if n == 1 {
        return nums[0]
    }
    prevPrev := nums[0]
    prev := max(nums[0], nums[1])
    for i := 2; i < n; i++ {
        curr := max(prev, prevPrev + nums[i])
        prevPrev, prev = prev, curr
    }
    return prev
}
```

---

### **3. State Machine Approach**
**State Variables**: `rob` (max money if current house is robbed) and `notRob` (max money if not robbed).  
**Recurrence**:  
- `new_rob = notRob + nums[i]`  
- `new_notRob = max(rob, notRob)`  

#### **C++ Code**
```cpp
int rob(vector<int>& nums) {
    int rob = 0, notRob = 0;
    for (int num : nums) {
        int currRob = notRob + num;
        int currNotRob = max(rob, notRob);
        rob = currRob;
        notRob = currNotRob;
    }
    return max(rob, notRob);
}
```

#### **Go Code**
```go
func rob(nums []int) int {
    rob, notRob := 0, 0
    for _, num := range nums {
        currRob := notRob + num
        currNotRob := max(rob, notRob)
        rob, notRob = currRob, currNotRob
    }
    return max(rob, notRob)
}
```

---

### **4. 2D DP Array (Rob or Not Rob)**
**State Definition**: `dp[i][0]` (not robbed) and `dp[i][1]` (robbed).  
**Recurrence**:  
- `dp[i][0] = max(dp[i-1][0], dp[i-1][1])`  
- `dp[i][1] = dp[i-1][0] + nums[i]`  

#### **C++ Code**
```cpp
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = nums[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + nums[i];
    }
    return max(dp.back()[0], dp.back()[1]);
}
```

#### **Go Code**
```go
func rob(nums []int) int {
    n := len(nums)
    if n == 0 {
        return 0
    }
    dp := make([][2]int, n)
    dp[0][0], dp[0][1] = 0, nums[0]
    for i := 1; i < n; i++ {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1])
        dp[i][1] = dp[i-1][0] + nums[i]
    }
    return max(dp[n-1][0], dp[n-1][1])
}
```

---

### **5. Recursive Memoization**
**Approach**: Use recursion with memoization to avoid redundant calculations.  

#### **C++ Code**
```cpp
#include <vector>
#include <algorithm>
using namespace std;

int helper(vector<int>& nums, int i, vector<int>& memo) {
    if (i >= nums.size()) return 0;
    if (memo[i] != -1) return memo[i];
    int take = nums[i] + helper(nums, i+2, memo);
    int notTake = helper(nums, i+1, memo);
    return memo[i] = max(take, notTake);
}

int rob(vector<int>& nums) {
    vector<int> memo(nums.size(), -1);
    return helper(nums, 0, memo);
}
```

#### **Go Code**
```go
func rob(nums []int) int {
    memo := make([]int, len(nums))
    for i := range memo {
        memo[i] = -1
    }
    var helper func(int) int
    helper = func(i int) int {
        if i >= len(nums) {
            return 0
        }
        if memo[i] != -1 {
            return memo[i]
        }
        take := nums[i] + helper(i+2)
        notTake := helper(i+1)
        memo[i] = max(take, notTake)
        return memo[i]
    }
    return helper(0)
}
```

---

### **Conclusion**
Each approach uses dynamic programming but varies in state definitions and space optimization. The state machine and space-optimized versions are preferred for their O(1) space complexity, while the recursive approach is useful for understanding the problem structure. Choose the method based on constraints and readability requirements.