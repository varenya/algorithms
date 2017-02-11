function updateInventory(arr1, arr2) {
    var curr = arr1.reduce(function(prev, current) {
        prev[current[1]] = current[0];
        return prev;
    }, {});
    arr2.forEach(function(item) {
        if (curr.hasOwnProperty(item[1])) {
            curr[item[1]] += item[0];
        } else {
            curr[item[1]] = item[0];
        }
    });
    return Object.keys(curr).sort().map(function(key) {
        return [curr[key], key];
    });
}
var curInv = [
    [
        21, "Bowling Ball"
    ],
    [
        2, "Dirty Sock"
    ],
    [
        1, "Hair Pin"
    ],
    [5, "Microphone"]
];

var newInv = [
    [
        2, "Hair Pin"
    ],
    [
        3, "Half-Eaten Apple"
    ],
    [
        67, "Bowling Ball"
    ],
    [7, "Toothpaste"]
];

console.log(updateInventory(curInv, newInv));
