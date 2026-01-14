#include "opencv2/opencv.hpp"
#include <iostream>

void show45()
{
	cv::Mat src = cv::imread("butterfly.jpg", cv::IMREAD_COLOR);
	cv::imshow("SRC", src); // src 채널3

	cv::Mat B(src.size(), CV_8UC1); // Blue
	cv::Mat G(src.size(), CV_8UC1); // Green
	cv::Mat R(src.size(), CV_8UC1); // Red

	for (int i = 0; i < src.rows; ++i)
	{
		for (int j = 0; j < src.cols; ++j)
		{
			cv::Vec3b& p1 = src.at<cv::Vec3b>(i, j);
			uchar& p_b = B.at<uchar>(i, j);
			p_b = p1[0]; // blue
			uchar& p_g = G.at<uchar>(i, j);
			p_g = p1[1]; // green
			uchar& p_r = R.at<uchar>(i, j);
			p_r = p1[2]; // red
		}
	}

	cv::imshow("Blue channel", B);
	cv::imshow("Green channel", G);
	cv::imshow("Red channel", R);

	cv::waitKey();
	cv::destroyAllWindows();
}

void show46()
{
	cv::Mat src = cv::imread("candies.png", cv::IMREAD_UNCHANGED);
	std::vector<cv::Mat> bgr_plans;
	cv::split(src, bgr_plans);
	std::cout << std::size(bgr_plans) << std::endl;
	cv::imshow("SRC", src);
	cv::imshow("Blue", bgr_plans[0]);
	cv::imshow("Green", bgr_plans[1]);
	cv::imshow("Red", bgr_plans[2]);
}

static void on_hue_change(int, void*); // 함수의 proto type
static cv::Mat src;
static cv::Mat src_hsv;
static int lower_bound = 0;
static int upper_bound = 0;
static cv::Mat mask;
void show47()
{
	src = cv::imread("candies.png");
	cv::cvtColor(src, src_hsv, cv::COLOR_BGR2HSV);
	cv::namedWindow("SRC");
	cv::createTrackbar("Lower HUE", "SRC", &lower_bound, 179, on_hue_change); // hue 0 ~ 179
	cv::createTrackbar("Upper HUE", "SRC", &upper_bound, 179, on_hue_change); // hue 0 ~ 179
	cv::imshow("CANDIES", src);
	cv::waitKey();
	cv::destroyAllWindows();
}

void on_hue_change(int, void*)
{
	cv::Scalar lower(lower_bound, 150, 0); // s >= 150, v >= 0
	cv::Scalar upper(upper_bound, 255, 255); // s <= 255, v <= 255
	cv::inRange(src_hsv, lower, upper, mask);
	cv::imshow("SRC", mask);
}
