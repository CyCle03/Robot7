#include "opencv2/opencv.hpp"

void show10()
{
	cv::VideoCapture capture(0);
	if (!capture.isOpened())
	{
		std::cerr << "카메라가 없습니다." << std::endl;
		return;
	}
	std::cout << "Wev CAM HEIGHT : " << cvRound(capture.get(cv::CAP_PROP_FRAME_HEIGHT)) << std::endl;
	std::cout << "Wev CAM WIDTH : " << cvRound(capture.get(cv::CAP_PROP_FRAME_WIDTH)) << std::endl;

	cv::Mat screen;
	while (true)
	{
		capture >> screen;
		if (screen.empty())
		{
			std::cerr << "프레임이 들어오지 않습니다." << std::endl;
			break;
		}
		cv::imshow("WEBCAM", screen);
		if (cv::waitKey(10) == 27) break; // 27 -> ESC 키를 누르면 무한루프 종료
	}
	screen.release();
	cv::destroyAllWindows();
}

void show11()
{
	cv::VideoCapture capture("stopwatch.avi");
	if (!capture.isOpened())
	{
		std::cerr << "동영상이 없습니다." << std::endl;
		return;
	}
	std::cout << "MOVIE HEIGHT : " << cvRound(capture.get(cv::CAP_PROP_FRAME_HEIGHT)) << std::endl;
	std::cout << "MOVIE WIDTH : " << cvRound(capture.get(cv::CAP_PROP_FRAME_WIDTH)) << std::endl;
	std::cout << "MOVIE FRAME COUNT : " << cvRound(capture.get(cv::CAP_PROP_FRAME_COUNT)) << std::endl;
	std::cout << "MOVIE FPS : " << cvRound(capture.get(cv::CAP_PROP_FPS)) << std::endl;

	cv::Mat screen;
	cv::Mat inverse_screen;
	while (true)
	{
		capture >> screen;
		if (screen.empty())
		{
			std::cerr << "프레임이 들어오지 않습니다." << std::endl;
			break;
		}
		inverse_screen = ~screen;
		cv::imshow("MOVIE", screen);
		cv::imshow("INVERSE_MOVIE", inverse_screen);
		if (cv::waitKey(10) == 27) break; // 27 -> ESC 키를 누르면 무한루프 종료
	}
	screen.release();
	inverse_screen.release();
	cv::destroyAllWindows();
}
