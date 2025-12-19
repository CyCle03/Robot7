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
