#include <stdio.h>

/*
* 0-1 aralığını "segments" sayısına kadar böler. Burdaki her parçaların
* uzunluğu "segment_length" olarak geçer.
* "no" sayısı bu parçaların kaçıncısı olduğunu söyler.
* "x" değerinin "no" numaralı parçaya olan uzaklığına göre 0-1 arasında bir
* değer verir.
* Eğer "x" değeri "no" numaralı parçaya "segment_length" kadar bir mesafeden
* daha uzaksa 0 değerini verir. Eğer daha yakınsa yakınlığına göre lineer bir
* şekilde 1 değerine kadar artar. "x" değeri "no" numaralı parçanın üzerindeyse
* 1 değerini verir.
*/
float image_function(float no, float segments, float x)
{
	float segment_length = 1/segments;
	float segment_no = no * segment_length;
	if(x<=segment_no && x>=segment_no-segment_length)
	{
		return (x-segment_no+segment_length)*segments;
	}
	else if(x>=segment_no && x<=segment_no+segment_length)
	{
		return -(x-segment_no+segment_length)*segments;
	}
	else
	{
		return 0;
	}
}


int main()
{
	printf("\n%f\n",image_function(2.0, 10.0, 0.15));
	return 0;
}
