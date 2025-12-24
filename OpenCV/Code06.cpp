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
	cv::Mat move = cv::Mat_<float>({ 2, 3 }, { 1.0f, 0.0f, 150.f, 0.0f, 1.0f, 100.f });
	cv::Mat dst;

	cv::warpAffine(src, dst, move, src.size());
	cv::imshow("SRC", src);
	cv::imshow("DST", dst);

	cv::waitKey();
	cv::destroyAllWindows();
}

void show35()
{
	float m;
	std::cout << "전단 변환 할 값(m)을 입력하세요.(1.0 이하 추천): ";
	std::cin >> m;

	cv::Mat src = cv::imread("tekapo.bmp");
	cv::Mat move1 = cv::Mat_<float>({ 2, 3 }, { 1.0f, m, 0.0f, 0.0f, 1.0f, 0.0f });
	cv::Mat move2 = cv::Mat_<float>({ 2, 3 }, { 1.0f, 0.0f, 0.0f, m, 1.0f, 0.0f });
	cv::Mat dst;

	cv::warpAffine(src, dst, move1, cv::Size(cvRound(src.cols + src.rows * m), cvRound(src.rows + src.cols * m)));
	cv::imshow("SRC", src);
	cv::imshow("DST", dst);

	cv::waitKey();
	cv::destroyAllWindows();
}

void show36()
{
	float s;
	std::cout << "크기 변환 할 값(s)을 입력하세요.(배로 늘어납니다.): ";
	std::cin >> s;
	cv::Mat src = cv::imread("tekapo.bmp");
	cv::Mat move = cv::Mat_<float>({ 2, 3 }, { s, 0.0f, 0.0f, 0.0f, s, 0.0f });
	cv::Mat dst;

	cv::warpAffine(src, dst, move, cv::Size(src.cols * s,  src.rows * s));
	cv::imshow("SRC", src);
	cv::imshow("DST", dst);

	cv::waitKey();
	cv::destroyAllWindows();
}

void show37()
{
	cv::Mat src = cv::imread("rose.bmp");
	if (src.empty())
	{
		std::cerr << "Image load failed!\n";
		return;
	}

	cv::Mat dst1, dst2, dst3, dst4;
	cv::resize(src, dst1, cv::Size(), 4, 4, cv::INTER_NEAREST);
	cv::resize(src, dst2, cv::Size(1920, 1080));
	cv::resize(src, dst3, cv::Size(1920, 1080), 0, 0, cv::INTER_CUBIC);
	cv::resize(src, dst4, cv::Size(1920, 1080), 0, 0, cv::INTER_LANCZOS4);

	cv::imshow("SRC", src);
	cv::imshow("dst1", dst1(cv::Rect(400, 500, 400, 400)));
	cv::imshow("dst2", dst2(cv::Rect(400, 500, 400, 400)));
	cv::imshow("dst3", dst3(cv::Rect(400, 500, 400, 400)));
	cv::imshow("dst4", dst4(cv::Rect(400, 500, 400, 400)));

	cv::waitKey();
	cv::destroyAllWindows();
}

void show38()
{
	cv::Mat src = cv::imread("tekapo.bmp");
	cv::Point2f center(src.cols / 1, src.rows / 2);
	// 2x3 affine
	cv::Mat move = cv::getRotationMatrix2D(center, 20.0, 1.0);
	cv::Mat dst;
	cv::warpAffine(src, dst, move, cv::Size());

	cv::imshow("SRC", src);
	cv::imshow("DST", dst);

	cv::waitKey();
	cv::destroyAllWindows();
}

void show39()
{
	cv::Mat src = cv::imread("eastsea.bmp");
	cv::imshow("SRC", src);

	cv::Mat dst;
	cv::flip(src, dst, 1); // y축 대칭(좌우 대칭)
	cv::imshow("좌우 대칭", dst);

	cv::flip(src, dst, 0); // x축 대칭(상하 대칭)
	cv::imshow("상하 대칭", dst);

	cv::flip(src, dst, -1); // x,y축 대칭(원점 대칭)
	cv::imshow("원점 대칭", dst);

	cv::waitKey();
	cv::destroyAllWindows();
}

static int count = 0;
static cv::Point2f dstQuad[4];
static cv::Point2f srcQuad[4];
static cv::Mat src;

void on_mouse2(int event, int x, int y, int flag, void* userdata)
{
	if (event == cv::EVENT_LBUTTONDOWN)
	{
		if (count < 4)
		{
			srcQuad[count++] = cv::Point2f(x, y);
			cv::circle(src, cv::Point(x, y), 5, cv::Scalar(0, 0, 255), -1);
			cv::imshow("SRC", src);
		}
		if (count == 4)
		{ 
			int width = 200;
			int height = 300;
			dstQuad[0] = cv::Point2f(0, 0);
			dstQuad[1] = cv::Point2f(width - 1, 0);
			dstQuad[2] = cv::Point2f(width - 1, height - 1);
			dstQuad[3] = cv::Point2f(0, height - 1);
			cv::Mat move = cv::getPerspectiveTransform(srcQuad, dstQuad);
			cv::Mat dst;
			cv::warpPerspective(src, dst, move, cv::Size(width, height));
			cv::imshow("DST", dst);
		}
	}
}

void show40()
{
	src = cv::imread("Card.bmp");
	cv::namedWindow("SRC");
	cv::setMouseCallback("SRC", on_mouse2);
	cv::imshow("SRC", src);
	cv::waitKey();
	cv::destroyAllWindows();
}
