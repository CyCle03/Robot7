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

void show12()
{
	cv::VideoCapture cap(0);
	if (!cap.isOpened())
	{
		std::cout << "웹 캠이 없습니다.\n";
		return;
	}
	int width = cvRound(cap.get(cv::CAP_PROP_FRAME_WIDTH));
	int height = cvRound(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
	double fps1 = cap.get(cv::CAP_PROP_FPS);
	int fps2 = cvRound(cap.get(cv::CAP_PROP_FPS));
	//코덱을 선택해 주세요.
	int fourcc = cv::VideoWriter::fourcc('D', 'I', 'V', 'X');
	int delay = cvRound(1000 / fps2);
	cv::VideoWriter outputVideo("output.avi", fourcc, 30, cv::Size(width,height));
	cv::Mat screen;
	while (true)
	{
		cap >> screen;
		outputVideo << screen;
		cv::imshow("VIDEO", screen);
		if (cv::waitKey(10) == 27) break;
	}
	cap.release();
	cv::destroyAllWindows();
}

void show13()
{
	cv::Mat canvas(600, 600, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::line(canvas, cv::Point(50, 50), cv::Point(200, 50), cv::Scalar(0, 0, 255), 2);
	cv::arrowedLine(canvas, cv::Point(50, 200), cv::Point(150, 200), cv::Scalar(0, 255, 0), 2);
	cv::drawMarker(canvas, cv::Point(30, 350), cv::Scalar(255, 0, 0));
	cv::Point p1 = cv::Point(300, 100);
	cv::Point p2 = cv::Point(100, 200);
	cv::Point p3 = cv::Point(500, 200);
	cv::Point p4 = cv::Point(150, 400);
	cv::Point p5 = cv::Point(450, 400);
	
	cv::line(canvas, p1, p4, cv::Scalar(255, 255, 0), 2);
	cv::line(canvas, p1, p5, cv::Scalar(255, 255, 0), 2);
	cv::line(canvas, p2, p3, cv::Scalar(255, 255, 0), 2);
	cv::line(canvas, p2, p5, cv::Scalar(255, 255, 0), 2);
	cv::line(canvas, p3, p4, cv::Scalar(255, 255, 0), 2);


	cv::imshow("CANVAS", canvas);
	cv::waitKey();
	cv::destroyAllWindows();
}

void show14()
{
	cv::Mat canvas(600, 600, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::circle(canvas, cv::Point(250, 250), 60, cv::Scalar(255, 0, 0));
	std::vector<cv::Point> points;
	points.push_back(cv::Point(250, 250));
	points.push_back(cv::Point(300, 250));
	points.push_back(cv::Point(300, 300));
	points.push_back(cv::Point(350, 300));
	points.push_back(cv::Point(350, 350));
	points.push_back(cv::Point(250, 350));
	cv::polylines(canvas, points, true, cv::Scalar(0, 255, 0), 2);

	cv::putText(canvas, "I LOVE YOU", cv::Point(20, 50), cv::FONT_HERSHEY_PLAIN, 2.0, cv::Scalar(0, 0, 255));

	cv::imshow("CANVAS", canvas);
	cv::waitKey();
	cv::destroyAllWindows();
}

void show15()
{
	cv::Mat img = cv::imread("lenna.png");
	cv::namedWindow("LENNA");
	cv::imshow("LENNA", img);
	while (true)
	{
		int key_value = cv::waitKey(0);
		std::cout << "Input key is " << key_value << "\n";
		if (key_value == 'i' or key_value == 'I')
		{
			img = ~img;
			imshow("LENNA", img);
		}
		else if (key_value == 'q' or key_value == 'Q' or key_value == 27)
		{
			std::cout << "종료\n";
			break;
		}
	}
	cv::destroyAllWindows();
}

static cv::Point old_pt;
static cv::Mat img;
void on_mouse(int mouse_event, int mouse_x, int mouse_y, int flag, void* _userdata)
{
	//std::cout << "마우스 이벤트\n";
	switch (mouse_event)
	{
	case cv::EVENT_LBUTTONDOWN: // 1 
		std::cout << "왼쪽 버튼 클릭\n";
		old_pt = cv::Point(mouse_x, mouse_y);
		break;
	case cv::EVENT_LBUTTONUP: // 4
		std::cout << "왼쪽 버튼 놓을 때\n";
		break;
	case cv::EVENT_MOUSEMOVE: // 0
		std::cout << "마우스가 움직일 때\n";
		if (flag & cv::EVENT_FLAG_LBUTTON)
		{
			cv::line(img, old_pt, cv::Point(mouse_x, mouse_y), cv::Scalar(0, 255, 255), 2);
			cv::imshow("LENNA", img);
			old_pt = cv::Point(mouse_x, mouse_y);
		}
		break;
	}
}

void show16()
{
	img = cv::imread("lenna.png");
	if (img.empty()) return;

	cv::namedWindow("LENNA");
	cv::setMouseCallback("LENNA", on_mouse);
	cv::imshow("LENNA", img);
	cv::waitKey(0);
	cv::destroyAllWindows();
}

void on_level_changed(int position, void* userdata)
{
	//cv::Mat img = *(cv::Mat*)userdata; //userdata -> 주소. (cv::Mat*) 로 형변환 후 *로 주소에 접근
	cv::Mat img = *(static_cast<cv::Mat*>(userdata)); // modern C style, safety-casting
	img.setTo(position * 16); // 바를 움직일 때 마다 * 16
	cv::imshow("CANVAS", img);
}

void show17()
{
	cv::Mat canvas(800, 800, CV_8UC1);//grayscale
	cv::namedWindow("CANVAS");
	cv::createTrackbar("Level", "CANVAS", 0, 16, on_level_changed, (void*)&canvas);
	cv::waitKey();
	cv::destroyAllWindows();
}

void show18()
{
	cv::Mat src = cv::imread("lenna.png");
	cv::Mat mask = cv::imread("mask_smile.bmp");
	src.setTo(cv::Scalar(0 , 255, 0), mask);
	cv::imshow("LENNA", src);
	cv::imshow("MASK", mask);
	cv::waitKey();
	cv::destroyAllWindows();
}

void show19()
{
	cv::Mat src = cv::imread("airplane.bmp");
	cv::Mat mask = cv::imread("mask_plane.bmp");
	cv::Mat dst = cv::imread("field.bmp");
	cv::Scalar total_pixel = cv::sum(src)(0);
	std::cout << "총 픽셀은 : " << total_pixel(0) << std::endl;
	cv::imshow("DST", dst);
	src.copyTo(dst, mask);
	cv::imshow("Original", src);
	cv::imshow("MASK", mask);
	cv::imshow("Destination", dst);
	cv::waitKey();
	cv::destroyAllWindows();
}
