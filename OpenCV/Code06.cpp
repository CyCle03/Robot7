#include "opencv2/opencv.hpp"

void show33()
{
	cv::Mat src = cv::imread("tekapo.bmp");
	cv::imshow("SRC", src);
	cv::Point2f srcPts[3]; //affine은 3점만 알고 있어도 나머지 한 점은 저절로 알 수 있다.
	cv::Point2f dstPts[3];
	srcPts[0] = cv::Point2f(0, 0);
	srcPts[1] = cv::Point2f(src.cols - 1.0f, 0.0f);
	srcPts[2] = cv::Point2f(src.cols - 1.0f, src.rows - 1.0f);
	dstPts[0] = cv::Point2f(50.0f, 50.0f);
	dstPts[1] = cv::Point2f(src.cols - 100.0f, 100.f);
	dstPts[2] = cv::Point2f(src.cols - 50.f, src.rows - 50.f);
	cv::waitKey();
	cv::destroyAllWindows();
}
