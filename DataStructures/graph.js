a = [1, 0, 0, 0, 1]

b = [1, 1, 1, 1, 0]

function add(a,b,carry){
	if(!carry)
		carry = 0;
	var a1 = a.slice(a.length-1);
	var b1 = b.slice(b.length-1);
	if(!a1);
		return [carry];
	else
	{
		var tot;
		tot = a1[0] + b1[0] + carry % 2;
		carry = a1[0] + b1[0] + carry / 2;
		return add(a1, b1, carry).concat(tot);
	}
}