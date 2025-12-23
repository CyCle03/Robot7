#include "opencv2/opencv.hpp"

void show24()
{
	cv::Mat img1 = cv::imread("lenna256.bmp", cv::IMREAD_GRAYSCALE);
	cv::Mat img2 = cv::imread("square.bmp", cv::IMREAD_GRAYSCALE);
	cv::Mat dst1 = img1 + img2; //saturate : 포화 상태가 된다.(포화 연산)
	cv::Mat dst2 = img1 - img2;
	cv::Mat dst3(256, 256, CV_8UC1);

	for (int i = 0; i < 256; ++i)
	{
		for (int j = 0; j < 256; ++j)
		{
			dst3.at<uchar>(i, j) =
			cv::saturate_cast<uchar>(img1.at<uchar>(i, j) + img2.at<uchar>(i, j));
		}
	}

	cv::imshow("img1", img1);
	cv::imshow("img2", img2);
	cv::imshow("dst1", dst1);
	cv::imshow("dst2", dst2);
	cv::imshow("dst3", dst3);
	cv::waitKey(0);

	cv::destroyAllWindows();

	return;
}

void show25()
{
	cv::Mat img1 = cv::imread("lenna256.bmp", cv::IMREAD_GRAYSCALE);
	cv::Mat img2 = cv::imread("square.bmp", cv::IMREAD_GRAYSCALE);
	cv::Mat dst1;
	cv::Mat dst2;
	cv::Mat dst3;

	cv::add(img1, img2, dst1);
	cv::subtract(img1, img2, dst2);
	cv::absdiff(img1, img2, dst3);

	cv::imshow("dst1", dst1);
	cv::imshow("dst2", dst2);
	cv::imshow("dst3", dst3);

	cv::waitKey();
	cv::destroyAllWindows();
}
