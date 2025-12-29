#include "opencv2/opencv.hpp"

static void on_thread(int, void*);
void show48()
{
	cv::Mat src = cv::imread("neutrophils.png", cv::IMREAD_GRAYSCALE);
	cv::namedWindow("SRC");
	cv::namedWindow("DST");
	cv::imshow("SRC", src);

	cv::createTrackbar("Threshold", "DST", 0, 255, on_thread, (void*)&src);
	cv::setTrackbarPos("Threshold", "DST", 128); // 처음 시작할 때 중간 값을 넣어주세요.

	cv::waitKey();
	cv::destroyAllWindows();
}

void on_thread(int position, void* userdata)
{
	cv::Mat src = *(static_cast<cv::Mat*>(userdata));
	cv::Mat dst;
	cv::threshold(src, dst, position, 255.0, cv::THRESH_BINARY);
	cv::imshow("DST", dst);
}

static void on_trackbar(int position, void* userdata)
{
	cv::Mat* src = (static_cast<cv::Mat*>(userdata));
	//cv::Mat src = *(static_cast<cv::Mat*>(userdata));
	int block_size = position;
	if (block_size % 2 == 0) --block_size; // block size 홀수가 좋다.
	//짝수면 하나 줄여서 홀수로 만들어라.
	if (block_size < 3) block_size = 3; // 최소 3 이상이어야 한다.
	cv::Mat dst;
	cv::adaptiveThreshold(*src, dst, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, block_size, 5.0);
	cv::imshow("DST", dst);
}

void show49()
{
	cv::Mat src = cv::imread("sudoku.jpg", cv::IMREAD_GRAYSCALE);
	cv::imshow("SUDOKU", src);
	cv::namedWindow("DST"); // DST
	cv::createTrackbar("Blocksize", "DST", 0, 200, on_trackbar, (void*)&src);

	cv::waitKey();
	cv::destroyAllWindows();
}

void show50()
{
	const auto src = cv::imread("milkdrop.bmp", cv::IMREAD_GRAYSCALE);
	//모폴로지를 하려면 반드시 이진화 -> threshold
	cv::Mat binary_image;
	cv::threshold(src, binary_image, 0.0, 255.0, cv::THRESH_BINARY | cv::THRESH_OTSU);
	cv::Mat dst_open;
	cv::Mat dst_close;
	cv::morphologyEx(binary_image, dst_open, cv::MORPH_OPEN, cv::Mat()); //침식 -> 팽창
	cv::morphologyEx(binary_image, dst_close, cv::MORPH_CLOSE, cv::Mat()); //팽창 -> 침식
	for(int i = 0; i < 10; ++i)
	{
		cv::morphologyEx(dst_open, dst_open, cv::MORPH_OPEN, cv::Mat()); //침식 -> 팽창
		cv::morphologyEx(dst_close, dst_close, cv::MORPH_CLOSE, cv::Mat()); //팽창 -> 침식
	}

	cv::imshow("SRC", src);
	cv::imshow("Binary", binary_image);
	cv::imshow("OPEN", dst_open);
	cv::imshow("CLOSE", dst_close);
	cv::waitKey();
	cv::destroyAllWindows();
}
