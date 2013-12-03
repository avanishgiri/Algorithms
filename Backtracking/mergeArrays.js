var a = [ [1,2,3], [8,9,10], [4,5,6], [7,8,9]];

var merge = function(array,index1,index2){
	var aux = [];
	var a1 = array[index1];
	var a2 = array[index2];
	if(!a2)
		return;
	var i = 0, j = 0;
	while(i < a1.length && j < a2.length){
		if(a1[i] < a2[j])
			aux.push(a1[i++]);
		else
			aux.push(a2[j++]);
	}

	while( i < a1.length){
		aux.push(a1[i++]);
	}
	while( j < a2.length){
		aux.push(a2[j++]);
	}

	a[index1] = aux;
	a.splice(index2,1);
	console.log(array);
}

var mergeSort = function(array){
	while(array.length > 1)
		for(var i = 0; i < array.length; i += 2){
			merge(array,i,i+1);
		}
}

console.log(a);
mergeSort(a);
console.log(a);