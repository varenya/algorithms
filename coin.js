// Initialzing dp array
var dp = [];


function max(a,b){
	return a > b ? a : b;
}

// Recursion
function change(x,y,z){
	// if result is already calculated return it ( Memoization )
	if( z > 0 && dp[z] != -1){
		return dp[z];
	}
	else if( x <= z && y <= z){
		// If result is not memoized calculate store repeat..
		dp[z]= max( x + change(x,y,z-x) , y + change(x,y,z-y) );
		return dp[z];
	}
	else if( x <= z){
		return x + change(x,y,z-x);
	}
	else if(y <= z){
		return y + change(x,y,z-y);
	}
	else{
		return 0;
	}
}

function getTips(x,y,z){
	dp = [];
	for(var i=0;i<200;i++){
		dp.push(-1);
	}
	return z - change(x,y,z);
}

console.log(getTips(15,19,33));
console.log(getTips(5,7,43));
console.log(getTips(5,6,10));
console.log(getTips(2,5,109));
console.log(getTips(2,10,109));
