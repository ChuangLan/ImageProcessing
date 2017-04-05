#pragma once
#include <opencv2/core/core.hpp>   
#include <opencv2/highgui/highgui.hpp>  

#include <opencv2/opencv.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include<opencv2/imgproc/imgproc.hpp>  

#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
class EdgeDetection
{
public:
	EdgeDetection();
	EdgeDetection(const cv::Mat& img, std::string name);
	~EdgeDetection();
	void run();
	void canny();
	void canny2();
	void sobel();
	void laplace();
	void scharr();
	void output(const cv::Mat& img);
	void read_file(std::string filename);
private:
	cv::Mat img;
	std::string img_name;
};

