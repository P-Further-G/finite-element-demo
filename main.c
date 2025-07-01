#include <stdio.h>


float SEGMENTS = 10.0;
float COEFFS[10] = {};


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

/*
 * "image_function" fonksiyonunun türevi.
 */
float image_function_derivative(float no, float segments, float x)
{
	float segment_length = 1/segments;
	float segment_no = no * segment_length;
	if(x<=segment_no && x>=segment_no-segment_length)
	{
		return segments;
	}
	else if(x>=segment_no && x<=segment_no+segment_length)
	{
		return -segments;
	}
	else
	{
		return 0;
	}
}

/*
 * Farazi bir fonksiyon. her fonksiyonunda çalışıyor olmalı.
 * Hangi fonksiyonlar daha hızlı çözüme götürür araştırma meselesi.
 */
float test_function(float x)
{
	return x;
}

/*
 * "test_function" fonksiyonunun türevi. Manuel olarak giriliyor (henüz).
 */
float test_function_derivative(float x)
{
	return 1;
}

/*
 * Kuvvet dağılımı fonksiyonu. Değiştirilebilir.
 */
float force_function(float x)
{
	return 2.0;
}

int main()
{
	printf("\n%f\n",image_function(2.0, 10.0, 0.15));
	return 0;
}
