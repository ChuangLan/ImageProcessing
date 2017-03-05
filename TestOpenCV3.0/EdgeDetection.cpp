#include "EdgeDetection.h" 
#include <iostream>  



using namespace cv;
using namespace std;

EdgeDetection::EdgeDetection()
{
}

EdgeDetection::EdgeDetection(const Mat& image)
{
	img = image.clone();
}


EdgeDetection::~EdgeDetection()
{
}

void EdgeDetection::run() 
{
	/***TODO***/
	// called in the main func
	// this func would call all the edge detection funcs

	imshow("Lena", img);
	canny();
	waitKey();
}

void EdgeDetection::canny()
{
	/***TODO***/
	// output easy Canny edge detection
	Mat out;
	Canny(img, out, 150, 100, 3);
	imshow("Lena_Canny", out);
}

void EdgeDetection::canny2()
{
	/***TODO***/
	// output better Canny edge detection
}

void EdgeDetection::sobel() 
{
	/***TODO***/
	// output Sobel edge detection
}

void EdgeDetection::laplace()
{
	/***TODO***/
	// output Laplace edge detection
}

void EdgeDetection::scharr()
{
	/***TODO***/
	// output Scharr edge detection
}

int main()
{
	Mat img = imread("Lena.jpg");
	if (img.empty())
	{
		cout << "error";
		return -1;
	}

	EdgeDetection impl = EdgeDetection(img);
	impl.run();

	return 0;

}