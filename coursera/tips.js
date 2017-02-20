// Initialzing dp array
var dp = [];

// Recursion
function change(x, y, z) {
    if (z <= 0) {
        return Math.abs(z);
    } else if (dp[z] != -1) {
      // if alread calculated return (Memoization)
        return dp[z];
    } else {
        // If not already calculated calculate and store it
        dp[z] = Math.min(change(x, y, z - x), change(x, y, z - y))
        return dp[z];
    }
}

function getTips(x, y, z) {
    dp = [];
    for (var i = 0; i < 200; i++) {
        dp.push(-1);
    }
    return change(x, y, z);
}

console.log(getTips(15, 19, 33));
console.log(getTips(5, 7, 43));
console.log(getTips(5, 6, 10));
console.log(getTips(2, 5, 109));
console.log(getTips(2, 10, 109));
