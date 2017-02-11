// jshint esversion:6
//

const suffix = {
    1: "st",
    2: "nd",
    3: "rd"
};

const month = {
    1: "January",
    2: "February",
    3: "March",
    4: "April",
    5: "May",
    6: "June",
    7: "July",
    8: "August",
    9: "September",
    10: "October",
    11: "November",
    12: "December"
};

function dateString(str) {
    const expr = /(\d{4})-(\d{2})-(\d{2})/;
    const dates = str.match(expr).slice(1, 4).map(function(item) {
        return parseInt(item);
    });

    const monthStr = `${month[dates[1]]}`;
    const dayStr = `${dates[2]}${suffix[dates[2]]
        ? suffix[dates[2]]
        : "th"}`;
    const yearStr = dates[0];
    return {month: monthStr, day: dayStr, year: yearStr, monthNum : dates[1],dayNum:dates[2]};
}

function checkYear([year1,month1,day1],[year2,month2,day2]){
  if(year1 === year2){
    return true;
  }
  else if( year2 - year1 === 1 && month2 < month1){
    return true;
  }
  else if(year2-year1 === 1 && month2 === month1 && day2 < day1){
    return true;
  }
  else{
    return false;
  }
}

function makeFriendlyDates(arr) {
    const first = dateString(arr[0]);
    const second = dateString(arr[1]);
    const yearDiff = checkYear( [parseInt(first.year),parseInt(first.monthNum),parseInt(first.dayNum)], [parseInt(second.year),parseInt(second.monthNum),parseInt(second.dayNum)]);
    if( first.month === second.month && first.year === second.year && first.day === second.day){
        return [`${first.month} ${first.day}, ${first.year}`];
    }
    else if (first.month === second.month && first.year === second.year) {
        // console.log("first");
        return [`${first.month} ${first.day}`, `${second.day}`];
    } else if ( yearDiff && first.year === 2016) {
      // console.log("second");
        return [`${first.month} ${first.day}`, `${second.month} ${second.day}`];
    } else if (yearDiff) {
      // console.log("third");
        return [`${first.month} ${first.day}, ${first.year}`, `${second.month} ${second.day}`];
    } else {
      // console.log("fourth");
        return [`${first.month} ${first.day}, ${first.year}`, `${second.month} ${second.day}, ${second.year}`];
    }
}

console.log(makeFriendlyDates(['2016-07-01', '2016-07-04']));
console.log(makeFriendlyDates(["2016-12-01", "2017-02-03"]));
console.log(makeFriendlyDates(["2017-03-01", "2017-05-05"]));
console.log(makeFriendlyDates(["2022-09-05", "2023-09-04"]));

// console.log(result);
