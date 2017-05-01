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

void output(const cv::Mat & src, string img_name)
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
//
//void EdgeDetection::read_file(std::string filename)
//{
//	std::ifstream infile(filename);
//	int rows, cols;
//	infile >> rows >> cols;
//	int x, y;
//	while (infile >> x >> y) {
//		cout << x - cols / 2 << " " << rows / 2 - y << endl;
//	}
//	infile.close();
//}

Mat src; Mat src_gray;
int mode = 0;
int color = 0;
int thresh = 100;
int max_thresh = 255;
int brush_size = 2;
int max_brush_size = 50;
IplImage* contour_image = 0;
CvPoint prev_pt = { -1,-1 };

RNG rng(12345);

int main(int argc, char ** argv);

/// Function header
void thresh_callback(int, void*);
void brush_callback(int, void*);
void on_mouse(int event, int x, int y, int flags, void* zhang);

int main(int argc, char **argv)
{
	if (argc < 2) 
		return 0;

	printf("Hot keys: \n"
				"\tESC - quit the program\n"
				"\te - erase the edge\n"
				"\td draw edge\n"
				"\ts save the edge file\n");

	string file_name = argv[1];
	src = imread(file_name, 1);

	//Convert image to gray and blur it
	cvtColor(src, src_gray, CV_BGR2GRAY);
	blur(src_gray, src_gray, Size(3, 3));

	//Create Window
	char* source_window = "Source";
	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
	imshow(source_window, src);
	createTrackbar("Canny Thresh", "Source", &thresh, max_thresh, thresh_callback);
	createTrackbar("Brush Size", "Source", &brush_size, max_brush_size, brush_callback);

	thresh_callback(0, 0);
	brush_callback(0,0);
	cvSetMouseCallback("Contours", on_mouse, 0);

	for (;;)
	{
		int c = waitKey(0);

		if ((char)c == 'd')
			color = 255;

		if ((char)c == 'e')
			color = 0;

		if ((char)c == 's') {
			Mat image = cvarrToMat(contour_image);
			output(image, file_name);
			break;
		}
	}

	return 0;

}

/** @functions */
void thresh_callback(int, void*)
{
	Mat canny_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	/// Detect edges using canny
	Canny(src_gray, canny_output, thresh, thresh * 2, 3);
	/// Find contours
	//findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// Draw contours
	Mat drawing = canny_output;//Mat::zeros(canny_output.size(), CV_8UC3);
	/*for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}*/

	/// Show in a window
	namedWindow("Contours", CV_WINDOW_AUTOSIZE);
	imshow("Contours", drawing);

	contour_image = cvCloneImage(&(IplImage)drawing);
}

void brush_callback(int, void*) {

}

void on_mouse(int event, int x, int y, int flags, void* zhang)
{
	if (!contour_image)
		return;

	if (event == CV_EVENT_LBUTTONUP || !(flags & CV_EVENT_FLAG_LBUTTON))
		prev_pt = cvPoint(-1, -1);
	else if (event == CV_EVENT_LBUTTONDOWN)
		prev_pt = cvPoint(x, y);
	else if (event == CV_EVENT_MOUSEMOVE && (flags & CV_EVENT_FLAG_LBUTTON))
	{
		CvPoint pt = cvPoint(x, y);
		if (prev_pt.x < 0)
			prev_pt = pt;
		cvLine(contour_image, prev_pt, pt, cvScalarAll(color), brush_size, 8, 0);
		prev_pt = pt;
		cvShowImage("Contours", contour_image);
	}
}