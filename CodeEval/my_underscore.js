Array.prototype.last = function(){
	return this.length ? this[this.length-1] : null
}

console.log([1,2,3].last() == 3)