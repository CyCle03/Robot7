#include "opencv2/opencv.hpp"

void show20()
{
	cv::Mat src = cv::imread("lenna.png", cv::IMREAD_GRAYSCALE);
	cv::Mat dst = src - 100;
	cv::Mat dst2(512, 512, CV_8UC1);
	for (int i = 0; i < src.rows; ++i)
	{
		for (int j = 0; j < src.cols; ++j)
		{
			dst2.at<uchar>(i, j) = src.at<uchar>(i, j) - 100;
		}
	}
	cv::imshow("SRC", src);
	cv::imshow("DST", dst);
	cv::imshow("DST2", dst2);
	cv::waitKey();
	cv::destroyAllWindows();
}

void on_brightness(int position, void* userdata)
{
	std::cout << "Trackbar\n";
	cv::Mat src = *(cv::Mat*)userdata;
	cv::Mat dst = src + position;
	cv::imshow("DST", dst);
}

	void show21()
	{
		cv::Mat src = cv::imread("lenna.png", cv::IMREAD_GRAYSCALE);
		cv::namedWindow("DST");
		cv::createTrackbar("Brightness", "DST", 0, 100, on_brightness, (void*)&src);
		cv::waitKey();
		cv::destroyAllWindows();
	}
