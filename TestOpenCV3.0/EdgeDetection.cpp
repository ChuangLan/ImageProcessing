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

	// Show the original image
	imshow("Lena", img);

	// Call each function of edge detection
	canny();
	canny2();

	// Wait input
	waitKey();
}

void EdgeDetection::canny()
{
	/***TODO***/
	// output easy Canny edge detection
	Mat out;

	// 1. Call the Canny() function
	Canny(img, out, 150, 100, 3);

	// 2. Show the effect image
	imshow("Lena_Canny", out);
}

void EdgeDetection::canny2()
{
	/***TODO***/
	// output better Canny edge detection
	// This function will output the RGB version of Canny output image

	Mat dst, edge, gray;
 
	// 1. Create mat with same size and type (dst)
	dst.create(img.size(), img.type());

	// 2. Transfer the original to grayScale image
	cvtColor(img, gray, CV_BGR2GRAY);
 
	// 3. Use 3*3 core to reduce noise
	blur(gray, edge, Size(3, 3));

	// 4. Run Canny function
	Canny(edge, edge, 150, 100, 3);
 
	// 5. Set all element as 0 in dst
	dst = Scalar::all(0);

	// 6. Use the edge computed by canny as mask, and copy source image to dst
	img.copyTo(dst, edge);
 
	// 7. Show the effect image
	imshow("Lena_Canny2", dst);
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