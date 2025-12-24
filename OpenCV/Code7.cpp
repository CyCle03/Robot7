#include "opencv2/opencv.hpp"

void show41()
{
	cv::Mat src = cv::imread("lenna.png", cv::IMREAD_GRAYSCALE);
	cv::Mat dx; // x 성분의 미분
	cv::Mat dy; // y 성분의 미분

	cv::Sobel(src, dx, CV_32FC1, 1, 0); // dx만 하겠다.
	cv::Sobel(src, dy, CV_32FC1, 0, 1); // dy만 하겠다.

	cv::imshow("SRC", src);
	cv::imshow("dx", dx);
	cv::imshow("dy", dy);

	cv::Mat mag; // 크기를 볼 Mattrix
	cv::magnitude(dx, dy, mag); // abs
	mag.convertTo(mag, CV_8UC1); // uchar
	cv::imshow("MAG", mag);

	//임계감. Threshold
	cv::Mat real_edge;
	real_edge = mag > 150;

	cv::imshow("REAL_EDGE", real_edge);

	cv::waitKey();
	cv::destroyAllWindows();
}

void show42()
{
	cv::Mat src = cv::imread("lenna.png", cv::IMREAD_GRAYSCALE);
	cv::Mat dst1;
	cv::Mat dst2;
	
	cv::Canny(src, dst1, 50, 100); // 50 ~ 100
	cv::Canny(src, dst2, 50, 150); // 50 ~ 150
	
	cv::imshow("SRC", src);
	cv::imshow("DST1", dst1);
	cv::imshow("DST2", dst2);

	cv::waitKey();
	cv::destroyAllWindows();
}

void show43()
{
	cv::Mat src = cv::imread("building.jpg", cv::IMREAD_GRAYSCALE);
	cv::imshow("SRC", src);

	cv::Mat edges;
	cv::Canny(src, edges, 50, 150);
	cv::imshow("Edges", edges);
	
	std::vector<cv::Vec2f> lines;
	cv::HoughLines(edges, lines, 1.0, CV_PI / 180, 250); //CV_PI / 180 -> 1 radian
	
	/*for (int i = 0; i < lines.size(); ++i)
	{
		std::cout << lines[i] << std::endl;
	}*/
	cv::Mat dst;
	cv::cvtColor(edges, dst, cv::COLOR_GRAY2BGR); // Color 선을 쓰기 위해 BGR로 변환
	
	for (int i = 0; i < lines.size(); ++i)
	{
		float r = lines[i][0];
		float t = lines[i][1];
		double cos_t = cos(t);
		double sin_t = sin(t);
		double x0 = r * cos_t;
		double y0 = r * sin_t;
		cv::Point pt1(cvRound(x0 + 1000 * (-sin_t)), cvRound(y0 + 1000 * cos_t));
		cv::Point pt2(cvRound(x0 - 1000 * (-sin_t)), cvRound(y0 - 1000 * cos_t));
		cv::line(dst, pt1, pt2, cv::Scalar(0, 0, 255), 2, cv::LINE_AA);
	}

	cv::imshow("DST", dst);

	cv::waitKey();
	cv::destroyAllWindows();
}

void show44()
{
	cv::Mat src = cv::imread("coins3.jpg", cv::IMREAD_GRAYSCALE);
	std::vector<cv::Vec3f> circles;

	cv::Mat blurred;
	cv::blur(src, blurred, cv::Size(3,3)); // 검출을 잘 하기 위해 블러로 노이즈 제거

	cv::Mat dst;
	cv::HoughCircles(blurred, circles, cv::HOUGH_GRADIENT, 1, 10, 250, 100);
	cv::cvtColor(blurred, dst, cv::COLOR_GRAY2BGR);

	for (auto&& circle : circles)
	{
		cv::Point center(cvRound(circle[0]), cvRound(circle[1])); 
		int radius = cvRound(circle[2]);
		cv::circle(dst, center, radius, cv::Scalar(0, 0, 255), 2);
	}

	cv::imshow("SRC", src);
	cv::imshow("DST", dst);

	cv::waitKey();
	cv::destroyAllWindows();
}
