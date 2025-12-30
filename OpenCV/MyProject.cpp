#include "opencv2/opencv.hpp"
#include <iostream>
#include <ctime>
#include <vector>

struct Picture
{
	cv::Point position; // x, y
	int radius;
	bool active;
	bool flipped;
	bool inverted;
	cv::Mat pic_src;
	Picture()
	{
		this->position = cv::Point();
		this->radius = 0;
		this->active = true;
		this->flipped = false;
		this->inverted = false;
	}
};

static cv::Point getRandomPosition(int width, int height, int radius)
{
	int x = rand() % (width - 2 * radius) + radius;
	int y = rand() % (height - 2 * radius) + radius;
	return cv::Point(x, y);
}

void runMyProject() CV_NOEXCEPT
{
	srand((unsigned int)time(0));
	cv::VideoCapture cap(0);
	if (!cap.isOpened())
	{
		std::cerr << "웹캠이 없습니다.\n";
		return;
	}
	int width = cvRound(cap.get(cv::CAP_PROP_FRAME_WIDTH));
	int height = cvRound(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
	cv::Mat prev_gray; // 이전 화면
	cv::Mat src = cv::imread("lenna.png");
	cv::Mat dst;
	Picture pic;
	pic.radius = 15;
	cv::resize(src, dst, cv::Size(pic.radius * 2, pic.radius * 2));
	pic.pic_src = dst;
	pic.position = getRandomPosition(width, height, pic.radius);
	int score = 0;
	const double COOLDOWN = 0.5;
	double countdown = 0.0;
	int64 t0 = cv::getTickCount();
	while (true)
	{
		cv::Mat frame, gray_frame, diff, thresh; // 흰 픽셀(ball)
		cap >> frame;
		double now = (cv::getTickCount() - t0) / cv::getTickFrequency();
		if (frame.empty()) break;
		cv::flip(frame, frame, 1); // 거울처럼 반전
		//움직임 감지
		cv::cvtColor(frame, gray_frame, cv::COLOR_BGR2GRAY);
		cv::GaussianBlur(gray_frame, gray_frame, cv::Size(15, 15), 0);
		if (prev_gray.empty())
		{
			gray_frame.copyTo(prev_gray);
			continue;
		}
		// absdiff() 명암과 객체 분리
		cv::absdiff(prev_gray, gray_frame, diff); // 차이 객체를 diff에
		cv::threshold(diff, thresh, 25.0, 255.0, cv::THRESH_BINARY);
		if (pic.active)
		{
			//pic 외곽선 사각형
			int x1 = cv::max(0, pic.position.x - pic.radius);
			int y1 = cv::max(0, pic.position.y - pic.radius);
			int x2 = cv::min(width, pic.position.x + pic.radius);
			int y2 = cv::min(height, pic.position.y + pic.radius);
			cv::Rect picRect(x1, y1, x2 - x1, y2 - y1);

			cv::Mat roi = thresh(picRect);
			int movementPixels = cv::countNonZero(roi);
			// 픽셀들의 움직임을 체크
			int area = (pic.radius * 2) * (pic.radius * 2);
			if (movementPixels > area * 0.1 and countdown <= now)
			{
				std::cout << "터치 " << ++score << "\r\n";
				if(pic.radius < 50)
				{
					++pic.radius;
					cv::resize(src, dst, cv::Size(pic.radius * 2, pic.radius * 2));
					pic.pic_src = dst;
					x1 = std::max(0, pic.position.x - pic.radius);
					y1 = std::max(0, pic.position.y - pic.radius);
					x2 = std::min(width, pic.position.x + pic.radius);
					y2 = std::min(height, pic.position.y + pic.radius);
					picRect = cv::Rect(x1, y1, x2 - x1, y2 - y1);
				}
				pic.flipped = !pic.flipped;
				if (rand() % 2 == 0)
					pic.inverted = !pic.inverted;
				pic.position = getRandomPosition(width, height, pic.radius);
				countdown = now + COOLDOWN;
				
			}
			cv::Mat roi_frame = frame(picRect);

			cv::Mat resized;
			cv::resize(pic.pic_src, resized, cv::Size(x2 - x1, y2 - y1));

			if (resized.channels() == 1)
				cv::cvtColor(resized, resized, cv::COLOR_GRAY2BGR);
			if (pic.flipped)
				cv::flip(resized, resized, 1);
			if (pic.inverted)
				cv::bitwise_not(resized, resized);

			resized.copyTo(roi_frame);
		}
		cv::putText(frame, "Score : " + std::to_string(score), cv::Point(20, 30),
			cv::FONT_HERSHEY_PLAIN, 2, cv::Scalar(255, 255, 255), 2);
		cv::imshow("GAME", frame);
		gray_frame.copyTo(prev_gray); // 화면에 업데이트
		if (cv::waitKey(10) == 27) break;
	}
	cap.release();
	cv::destroyAllWindows();
}
