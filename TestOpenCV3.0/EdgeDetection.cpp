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

	/****************Canny Function Parameters****************

	��һ��������InputArray���͵�image������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɣ�����Ϊ��ͨ��8λͼ��
	�ڶ���������OutputArray���͵�edges������ı�Եͼ����Ҫ��ԴͼƬ��һ���ĳߴ�����͡�
	������������double���͵�threshold1����һ���ͺ�����ֵ��
	���ĸ�������double���͵�threshold2���ڶ����ͺ�����ֵ��
	�����������int���͵�apertureSize����ʾӦ��Sobel���ӵĿ׾���С������Ĭ��ֵ3��
	������������bool���͵�L2gradient��һ������ͼ���ݶȷ�ֵ�ı�ʶ����Ĭ��ֵfalse��

	****************Canny Function Parameters****************/

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
	/****************Sobel Function Parameters****************

	��һ��������InputArray ���͵�src��Ϊ����ͼ����Mat���ͼ��ɡ�
	�ڶ���������OutputArray���͵�dst����Ŀ��ͼ�񣬺����������������Ҫ��ԴͼƬ��һ���ĳߴ�����͡�
	������������int���͵�ddepth�����ͼ�����ȣ�֧������src.depth()��ddepth����ϣ�
	��src.depth() = CV_8U, ȡddepth =-1/CV_16S/CV_32F/CV_64F
	��src.depth() = CV_16U/CV_16S, ȡddepth =-1/CV_32F/CV_64F
	��src.depth() = CV_32F, ȡddepth =-1/CV_32F/CV_64F
	��src.depth() = CV_64F, ȡddepth = -1/CV_64F
	���ĸ�������int����dx��x �����ϵĲ�ֽ�����
	�����������int����dy��y�����ϵĲ�ֽ�����
	������������int����ksize����Ĭ��ֵ3����ʾSobel�˵Ĵ�С;����ȡ1��3��5��7��
	���߸�������double���͵�scale�����㵼��ֵʱ��ѡ���������ӣ�Ĭ��ֵ��1����ʾĬ���������û��Ӧ�����ŵġ����ǿ������ĵ��в���getDerivKernels����ؽ��ܣ����õ���������ĸ�����Ϣ��
	�ڰ˸�������double���͵�delta����ʾ�ڽ������Ŀ��ͼ���ڶ�������dst��֮ǰ��ѡ��deltaֵ����Ĭ��ֵ0��
	�ھŸ������� int���͵�borderType�����ǵ��������ˣ����������һ�����������߽�ģʽ��Ĭ��ֵΪBORDER_DEFAULT��������������ڹٷ��ĵ���borderInterpolate���õ�����ϸ����Ϣ��

	****************Sobel Function Parameters****************/

	/***TODO***/
	// output Sobel edge detection
 
	// 0. Create grad_x and grad_y
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y, dst;

	// 1. Compute grad_x
	Sobel(img, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
	//imshow("Lena_grad_x", abs_grad_x);

	// 2. Compute grad_y
	Sobel(img, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);
	//imshow("Lena_grad_y", abs_grad_y);

	// 3. Combine them together
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);

	// 4. Show the effect image
	imshow("Lena_Sobel", dst);
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