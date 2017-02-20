function bombAlgo(inputStr){
	var newString = inputStr.split('').reduce( function(prev,next,index){
		//console.log(prev,next);
		var last = prev.length-1;
		if (prev[last <0 ? 0 : last] !=next){
			//console.log("here");
			return prev+next;
		}
		else{
			return prev.slice(0,-1);
		}
	},"")

	if(newString.length == inputStr.length) return newString;
	else return bombAlgo(newString);
}

function bomb(input,index){
	if(index > input.length-1 || index < 0){
		return "";
	}
	else if(input[index-1] == input[index]){
		return bomb(input,index-2) + bomb(input,index+1);
	}
	else{
		return bomb(input,index+1);
	}
}

function bomb2(input,index){
	if(index >= input.length || index < 0){
		return "";
	}
	else if(input[index] == input[index+1]){
		return bomb2(input.slice(0,index-1)+input.slice(index+2),0);
	}
	else{
		return bomb2(input,index+1);
	}
}
console.log(bombAlgo("geeksforgeeks"));
console.log(bombAlgo("aabbacaabba"));
//console.log(bombAlgo("abalslaaccddd"));
