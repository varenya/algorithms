function flatten(i,arr){
	if(i >= arr.length){
		return [];
	}
	else if( Array.isArray(arr[i]) ){

		return flatten(0,arr[i]).concat(flatten(i+1,arr));
	}
	else{
		return [arr[i]].concat(flatten(i+1,arr));
	}
}

var array = [1,2,[1,[1,2,[3,2]]],[2,23,9]];

console.log(flatten(0,array));
