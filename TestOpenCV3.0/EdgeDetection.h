#pragma once
#include <opencv2/core/core.hpp>   
#include <opencv2/highgui/highgui.hpp>  

#include <opencv2/opencv.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include<opencv2/imgproc/imgproc.hpp>  
class EdgeDetection
{
public:
	EdgeDetection();
	EdgeDetection(const cv::Mat& img);
	~EdgeDetection();
	void run();
	void canny();
	void canny2();
	void sobel();
	void laplace();
	void scharr();

private:
	cv::Mat img;
};

