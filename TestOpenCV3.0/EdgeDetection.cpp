#include "EdgeDetection.h" 




using namespace cv;
using namespace std;

EdgeDetection::EdgeDetection()
{
}

EdgeDetection::EdgeDetection(const Mat& image, string name)
{
	img = image.clone();
	img_name = name;
}


EdgeDetection::~EdgeDetection()
{
}

//void EdgeDetection::run() 
//{
//	/***TODO***/
//	// called in the main func
//	// this func would call all the edge detection funcs
//
//	// Show the original image
//	imshow("Original", img);
//
//	// Call each function of edge detection
//	canny_contour();
//	//canny2();
//	//sobel();
//	//laplace();
//	//scharr();
//
//	// Wait input
//	waitKey();
//}
//
//void EdgeDetection::canny_contour()
//{
//	/****************Canny Function Parameters****************
//
//	��һ��������InputArray���͵�image������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɣ�����Ϊ��ͨ��8λͼ��
//	�ڶ���������OutputArray���͵�edges������ı�Եͼ����Ҫ��ԴͼƬ��һ���ĳߴ�����͡�
//	������������double���͵�threshold1����һ���ͺ�����ֵ��
//	���ĸ�������double���͵�threshold2���ڶ����ͺ�����ֵ��
//	�����������int���͵�apertureSize����ʾӦ��Sobel���ӵĿ׾���С������Ĭ��ֵ3��
//	������������bool���͵�L2gradient��һ������ͼ���ݶȷ�ֵ�ı�ʶ����Ĭ��ֵfalse��
//
//	****************Canny Function Parameters****************/
//
//	/***TODO***/
//	// output easy Canny edge detection
//
//
//	Mat canny_output;
//	vector<vector<Point> > contours;
//	vector<Vec4i> hierarchy;
//	// Call the Canny() function
//	Canny(img, canny_output, thresh, thresh*2, 3);
//	// Find contours
//	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
//
//	// Draw contours
//	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
//	for (size_t i = 0; i< contours.size(); i++)
//	{
//		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
//		drawContours(drawing, contours, (int)i, color, 2, 8, hierarchy, 0, Point());
//	}
//	// Show in a window
//	namedWindow("Contours", WINDOW_AUTOSIZE);
//	imshow("Contours", drawing);
//
//	// read_file("Bucket.txt");
//
//	// output(drawing);
//}
//
//void EdgeDetection::canny2()
//{
//	/***TODO***/
//	// output better Canny edge detection
//	// This function will output the RGB version of Canny output image
//
//	Mat dst, edge, gray;
// 
//	// 1. Create mat with same size and type (dst)
//	dst.create(img.size(), img.type());
//
//	// 2. Transfer the original to grayScale image
//	cvtColor(img, gray, CV_BGR2GRAY);
// 
//	// 3. Use 3*3 core to reduce noise
//	blur(gray, edge, Size(3, 3));
//
//	// 4. Run Canny function
//	Canny(edge, edge, 150, 100, 3);
// 
//	// 5. Set all element as 0 in dst
//	dst = Scalar::all(0);
//
//	// 6. Use the edge computed by canny as mask, and copy source image to dst
//	img.copyTo(dst, edge);
// 
//	// 7. Show the effect image
//	imshow("Canny2", dst);
//}
//
//void EdgeDetection::sobel() 
//{
//	/****************Sobel Function Parameters****************
//
//	��һ��������InputArray ���͵�src��Ϊ����ͼ����Mat���ͼ��ɡ�
//	�ڶ���������OutputArray���͵�dst����Ŀ��ͼ�񣬺����������������Ҫ��ԴͼƬ��һ���ĳߴ�����͡�
//	������������int���͵�ddepth�����ͼ�����ȣ�֧������src.depth()��ddepth����ϣ�
//	��src.depth() = CV_8U, ȡddepth =-1/CV_16S/CV_32F/CV_64F
//	��src.depth() = CV_16U/CV_16S, ȡddepth =-1/CV_32F/CV_64F
//	��src.depth() = CV_32F, ȡddepth =-1/CV_32F/CV_64F
//	��src.depth() = CV_64F, ȡddepth = -1/CV_64F
//	���ĸ�������int����dx��x �����ϵĲ�ֽ�����
//	�����������int����dy��y�����ϵĲ�ֽ�����
//	������������int����ksize����Ĭ��ֵ3����ʾSobel�˵Ĵ�С;����ȡ1��3��5��7��
//	���߸�������double���͵�scale�����㵼��ֵʱ��ѡ���������ӣ�Ĭ��ֵ��1����ʾĬ���������û��Ӧ�����ŵġ����ǿ������ĵ��в���getDerivKernels����ؽ��ܣ����õ���������ĸ�����Ϣ��
//	�ڰ˸�������double���͵�delta����ʾ�ڽ������Ŀ��ͼ���ڶ�������dst��֮ǰ��ѡ��deltaֵ����Ĭ��ֵ0��
//	�ھŸ������� int���͵�borderType�����ǵ��������ˣ����������һ�����������߽�ģʽ��Ĭ��ֵΪBORDER_DEFAULT��������������ڹٷ��ĵ���borderInterpolate���õ�����ϸ����Ϣ��
//
//	****************Sobel Function Parameters****************/
//
//	/***TODO***/
//	// output Sobel edge detection
// 
//	Mat grad_x, grad_y;
//	Mat abs_grad_x, abs_grad_y, dst;
//
//	// 1. Compute grad_x
//	Sobel(img, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
//	convertScaleAbs(grad_x, abs_grad_x);
//	//imshow("Sobel_X", abs_grad_x);
//
//	// 2. Compute grad_y
//	Sobel(img, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
//	convertScaleAbs(grad_y, abs_grad_y);
//	//imshow("Sobel_Y", abs_grad_y);
//
//	// 3. Combine them together
//	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
//
//	// 4. Show the effect image
//	imshow("Sobel", dst);
//}
//
//void EdgeDetection::laplace()
//{
//	/****************Laplace Function Parameters****************
//
//	��һ��������InputArray���͵�image������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɣ�����Ϊ��ͨ��8λͼ��
//	�ڶ���������OutputArray���͵�edges������ı�Եͼ����Ҫ��ԴͼƬ��һ���ĳߴ��ͨ������
//	������������int���͵�ddept��Ŀ��ͼ�����ȡ�
//	���ĸ�������int���͵�ksize�����ڼ�����׵������˲����Ŀ׾��ߴ磬��С����Ϊ������������Ĭ��ֵ1��
//	�����������double���͵�scale������������˹ֵ��ʱ���ѡ�ı������ӣ���Ĭ��ֵ1��
//	������������double���͵�delta����ʾ�ڽ������Ŀ��ͼ���ڶ�������dst��֮ǰ��ѡ��deltaֵ����Ĭ��ֵ0��
//	���߸������� int���͵�borderType���߽�ģʽ��Ĭ��ֵΪBORDER_DEFAULT��������������ڹٷ��ĵ���borderInterpolate()���õ�����ϸ����Ϣ��
//
//	****************Laplace Function Parameters****************/
//
//	/***TODO***/
//	// output Laplace edge detection
//
//	Mat src, src_gray, dst, abs_dst;
//
//	// 1. Gaussian Blur remove noise
//	GaussianBlur(img, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
//
//	// 2. Convert to gray scale image
//	cvtColor(src, src_gray, CV_RGB2GRAY);
//
//	// 3. Call Laplace Func
//	Laplacian(src_gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
// 
//	// 4. Calculate Abs() and convert to 8-bit
//	convertScaleAbs(dst, abs_dst);
//
//	// 5. Show the effect image
//	imshow("Laplace", abs_dst);
//}
//
//void EdgeDetection::scharr()
//{
//
//	/****************Scharr Function Parameters****************
//
//	��һ��������InputArray ���͵�src��Ϊ����ͼ����Mat���ͼ��ɡ�
//	�ڶ���������OutputArray���͵�dst����Ŀ��ͼ�񣬺����������������Ҫ��ԴͼƬ��һ���ĳߴ�����͡�
//	������������int���͵�ddepth�����ͼ�����ȣ�֧������src.depth()��ddepth����ϣ�
//	��src.depth() = CV_8U, ȡddepth =-1/CV_16S/CV_32F/CV_64F
//	��src.depth() = CV_16U/CV_16S, ȡddepth =-1/CV_32F/CV_64F
//	��src.depth() = CV_32F, ȡddepth =-1/CV_32F/CV_64F
//	��src.depth() = CV_64F, ȡddepth = -1/CV_64F
//	���ĸ�������int����dx��x�����ϵĲ�ֽ�����
//	�����������int����dy��y�����ϵĲ�ֽ�����
//	������������double���͵�scale�����㵼��ֵʱ��ѡ���������ӣ�Ĭ��ֵ��1����ʾĬ���������û��Ӧ�����ŵġ����ǿ������ĵ��в���getDerivKernels����ؽ��ܣ����õ���������ĸ�����Ϣ��
//	���߸�������double���͵�delta����ʾ�ڽ������Ŀ��ͼ���ڶ�������dst��֮ǰ��ѡ��deltaֵ����Ĭ��ֵ0��
//	�ڰ˸������� int���͵�borderType�����ǵ��������ˣ����������һ�����������߽�ģʽ��Ĭ��ֵΪBORDER_DEFAULT��������������ڹٷ��ĵ���borderInterpolate���õ�����ϸ����Ϣ��
//
//	****************Scharr Function Parameters****************/
//
//	/***TODO***/
//	// output Scharr edge detection
// 
//	Mat grad_x, grad_y;
//	Mat abs_grad_x, abs_grad_y, dst;
//
//	// 1. Compute the X-gradient
//	Scharr(img, grad_x, CV_16S, 1, 0, 1, 0, BORDER_DEFAULT);
//	convertScaleAbs(grad_x, abs_grad_x);
//	//imshow("Scharr_X", abs_grad_x);
//
//	// 2. Compute the Y-gradient
//	Scharr(img, grad_y, CV_16S, 0, 1, 1, 0, BORDER_DEFAULT);
//	convertScaleAbs(grad_y, abs_grad_y);
//	//imshow("Scharr_Y", abs_grad_y);
// 
//	// 3. Combine them together
//	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
//
//	// 4. Show the effect image
//	imshow("Scharr", dst);
//}

void EdgeDetection::output(const cv::Mat & src)
{
	// Write to the file. 
	ofstream outfile(img_name.substr(0, img_name.find(".")) + ".txt");
	// The first line define row and cols
	outfile << src.rows << " " << src.cols << endl;
	// Loop over each pixel and write to the file
	for (int x = 0; x < src.rows; x++) {
		for (int y = 0; y < src.cols; y++) {
			if ((int)src.at<uchar>(x, y) > 0) {
				outfile << x << " " << y << endl;
				//cout << (int)src.at<uchar>(x, y) << endl;
			}
		}
	}
	outfile.close();

}

void EdgeDetection::read_file(std::string filename)
{
	std::ifstream infile(filename);
	int rows, cols;
	infile >> rows >> cols;
	int x, y;
	while (infile >> x >> y) {
		cout << x - cols / 2 << " " << rows / 2 - y << endl;
	}
	infile.close();
}

Mat src; Mat src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

/// Function header
void thresh_callback(int, void*);

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++) {

		src = imread(argv[i], 1);
		/// Convert image to gray and blur it
		cvtColor(src, src_gray, CV_BGR2GRAY);
		blur(src_gray, src_gray, Size(3, 3));

		/// Create Window
		char* source_window = "Source";
		namedWindow(source_window, CV_WINDOW_AUTOSIZE);
		imshow(source_window, src);

		createTrackbar(" Canny thresh:", "Source", &thresh, max_thresh, thresh_callback);
		thresh_callback(0, 0);

		waitKey(0);
	}
	return 0;

}

/** @function thresh_callback */
void thresh_callback(int, void*)
{
	Mat canny_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	/// Detect edges using canny
	Canny(src_gray, canny_output, thresh, thresh * 2, 3);
	/// Find contours
	findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// Draw contours
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}

	/// Show in a window
	namedWindow("Contours", CV_WINDOW_AUTOSIZE);
	imshow("Contours", drawing);
}