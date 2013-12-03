var swap = function(array, i, j){
	var temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

var partition = function(array, low, high){
	var firsthigh = low;
	var pivot = high;

	for(var i = low; i < high; i++){
		if(array[i] < array[pivot]){
			swap(array[i], array[firsthigh]);
			firsthigh++;
		}
	}
	swap(array,pivot,firsthigh);
	return firsthigh;
}

var quicksort = function(array, low, high){
	var p;
	if(low < high){
		p = partition(array, low, high);
		quicksort(array, low, p-1);
		quicksort(array, p+1, high);
	}
}