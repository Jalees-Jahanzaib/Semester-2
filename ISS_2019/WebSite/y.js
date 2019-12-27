<script>
function myArray(arr){
	var sum=0;
	for(var i=0;i<arr.length;i++)
	{
		sum+=arr[i];
	}
	this.sum=function(){
    	return sum;
    }
	var prod=1;
	for(var i=0;i<arr.length;i++)
	{
		prod*=arr[i];
	}
	this.product=function(){
    	return prod;
    }
	this.display = () => {
		for(var i=0;i<arr.length;i++)
			console.log(arr[i]);
	}
	this.modify=function(i,num){                           //This function takes i an the index input
		if(i<arr.length)								   //and modifies the number at index i with a
		arr[i]=num;
		else
			console.log("Index dont exist");
	}
	this.sort=function(){
		for (var i = 0; i <arr.length; ++i){
            for (var j = i + 1; j <arr.length; ++j)
			{
		    if (arr[i] > arr[j]) 
	        {
            a =  arr[i];
            arr[i] = arr[j];
            arr[j] = a;
            }
            }
        }
	}	
}


num=[5,4,3,2,1];
var numObject=new myArray(num);
console.log("PRESENT ARRAY");
numObject.display();
console.log("SUM")
console.log(numObject.sum());
console.log("PRODUCT")
console.log(numObject.product());
numObject.sort();
console.log("Sorted array")
numObject.display();
numObject.modify(3,14);
console.log("MODIFIED ARRAY");
numObject.display();
</script>