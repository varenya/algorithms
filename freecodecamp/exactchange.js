const valueMap = [
    {
        name: "ONE HUNDRED",
        value: 100
    }, {
        name: "TWENTY",
        value: 20
    }, {
        name: "TEN",
        value: 10
    }, {
        name: "FIVE",
        value: 5
    }, {
        name: "ONE",
        value: 1
    }, {
        name: "QUARTER",
        value: 0.25
    }, {
        name: "DIME",
        value: 0.1
    }, {
        name: "NICKEL",
        value: 0.05
    }, {
        name: "PENNY",
        value: 0.01
    }
];
function checkCashRegister(price, cash, cid) {
    const sum = cid.reduce(function(prev, curr) {
        return prev + curr[1];
    }, 0);
    let  change = cash - price;
    if (change > sum) {
        return "Insufficient Funds";
    } else if (change === sum) {
        return "Closed";
    } else {
        cid.reverse();

        const result = valueMap.reduce(function(acc, current, index) {
            if (current.value < change) {
                let currentValue = 0.0;
                while (change >= current.value && cid[index][1] > 0) {
                    currentValue += current.value;
                    change -= current.value;
                    change = Math.round(change*100)/100;
                    cid[index][1] -= current.value;
                }
                return acc.concat([[current.name, currentValue]]);
            } else {
                return acc;
            }
        }, [])
        return result.length > 0 && change === 0 ? result : "Insufficient Funds";
    }
}

console.log(checkCashRegister(3.26, 100.00, [
    [
        "PENNY", 1.01
    ],
    [
        "NICKEL", 2.05
    ],
    [
        "DIME", 3.10
    ],
    [
        "QUARTER", 4.25
    ],
    [
        "ONE", 90.00
    ],
    [
        "FIVE", 55.00
    ],
    [
        "TEN", 20.00
    ],
    [
        "TWENTY", 60.00
    ],
    ["ONE HUNDRED", 100.00]
]));
