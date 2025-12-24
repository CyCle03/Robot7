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
	cv::Mat move = cv::getAffineTransform(srcPts, dstPts);
	cv::Mat dst;
	cv::warpAffine(src, dst, move, cv::Size());
	cv::imshow("DST", dst);
	cv::waitKey();
	cv::destroyAllWindows();
}

void show34()
{
	cv::Mat src = cv::imread("tekapo.bmp");
	cv::Mat move1 = cv::Mat_<float>({ 2, 3 }, { 1.0f, 0.0f, 150.f, 0.0f, 1.0f, 100.f });
	cv::Mat move2 = cv::Mat_<float>({ 2, 3 }, { 1.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f });
	cv::Mat move3 = cv::Mat_<float>({ 2, 3 }, { 1.0f, 0.0f, 0.0f, 0.2f, 1.0f, 0.0f });
	cv::Mat dst;

	cv::warpAffine(src, dst, move3, src.size());
	cv::imshow("SRC", src);
	cv::imshow("DST", dst);

	cv::waitKey();
	cv::destroyAllWindows();
}
