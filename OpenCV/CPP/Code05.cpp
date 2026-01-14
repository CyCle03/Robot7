#include "opencv2/opencv.hpp"

void show26()
{
	float filter_data[] = { -1.0f, -1.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f };
	cv::Mat emboss(3, 3, CV_32FC1, filter_data); // embossing 만드는 필터
	cv::Mat src = cv::imread("rose.bmp", cv::IMREAD_GRAYSCALE);
	cv::Mat dst;
	cv::filter2D(src, dst, -1, emboss, cv::Point(-1, -1), 80.0);

	cv::imshow("scr", src);
	cv::imshow("dst", dst);
	cv::waitKey(0);
	cv::destroyAllWindows();
}

void show27()
{
	float blur_filter[] = { 1 / 9.f, 1 / 9.f, 1 / 9.f,
		1 / 9.f, 1 / 9.f, 1 / 9.f,1 / 9.f, 1 / 9.f, 1 / 9.f, };
	cv::Mat src = cv::imread("rose.bmp", cv::IMREAD_GRAYSCALE);
	cv::Mat dst;
	cv::Mat blur(3, 3, CV_32FC1, blur_filter);
	cv::filter2D(src, dst, -1, blur, cv::Point(-1, -1), 0);

	//blur 함수 사용하기.
	cv::Mat dst2; // blur 필터를 통과 후 만들어질 이미지
	cv::blur(src, dst2, cv::Size(3, 3));

	cv::imshow("SRC", src);
	cv::imshow("DST", dst);
	cv::imshow("DST2", dst2);
	cv::waitKey();
	cv::destroyAllWindows();
}

void show28()
{
	cv::Mat src = cv::imread("rose.bmp", cv::IMREAD_GRAYSCALE);
	cv::imshow("SRC", src);
	cv::Mat dst;
	
	for (int sigma = 1; sigma <= 5; ++sigma)
	{
		cv::GaussianBlur(src, dst, cv::Size(), sigma);
		cv::putText(dst, cv::format("Sigma : %d", sigma), cv::Point(10, 30),
			cv::FONT_HERSHEY_PLAIN, 1.0, cv::Scalar(255), 1, cv::LINE_AA);
		//python의 f'{}', {}.format과 같은
		cv::imshow(cv::format("Sigma : %d", sigma), dst);
		cv::waitKey();
	}
	cv::waitKey();
	cv::destroyAllWindows();
}

void show29()
{
	cv::Mat src(cv::imread("rose.bmp", cv::IMREAD_GRAYSCALE));
	// uniform initailizer
	cv::imshow("SRC", src);
	cv::Mat blurred; // Gaussian을 통과해서 만들어질 이미지
	float alpha = 1.0f;
	for (int sigma = 1; sigma <= 5; ++sigma)
	{
		cv::GaussianBlur(src, blurred, cv::Size(), sigma);
		cv::Mat dst = (1 + alpha) * src - (alpha * blurred);
		cv::putText(dst, cv::format("Sigma : %d", sigma), cv::Point(10, 30),
			cv::FONT_HERSHEY_PLAIN, 1.0, cv::Scalar(255), 1, cv::LINE_AA);
		cv::imshow(cv::format("Sigma : %d", sigma), dst);
		cv::waitKey();
	}
	cv::waitKey();
	cv::destroyAllWindows();
}

void show30()
{
	cv::Mat src = cv::imread("lenna.png", cv::IMREAD_GRAYSCALE);
	cv::Mat dst;
	cv::imshow("SRC", src);
	for (int stddev = 10; stddev <= 30; stddev += 10)
	{
		cv::Mat noise(src.size(), CV_32SC1);
		cv::randn(noise, 0, stddev);//가우시안 분포
		cv::add(src, noise, dst, cv::noArray(), CV_8UC1); //dst = src + noise;
		cv::putText(dst, cv::format("STDDEV : %d", stddev), cv::Point(10, 30),
			cv::FONT_HERSHEY_PLAIN, 1.0, cv::Scalar(255), 1, cv::LINE_AA);
		cv::imshow(cv::format("STDDEV : %d", stddev), dst);
		cv::waitKey();
	}
	cv::waitKey();
	cv::destroyAllWindows();
}

void show31()
{
	cv::Mat src = cv::imread("lenna.png", cv::IMREAD_GRAYSCALE);
	cv::imshow("SRC", src);
	cv::Mat dst1; // 가우시안 노이즈가 들어간 영상
	cv::Mat dst2; // 양방향필터를 통과한 영상 (어느정도 노이즈가 제거된 영상)
	cv::Mat noise(src.size(), CV_32SC1); // 512x512 singed float Matrix
	cv::randn(noise, 0, 5); // mean : 0, standard deviation : 5
	cv::add(src, noise, dst1, cv::noArray(), CV_8UC1);
	cv::imshow("NOISED", dst1);
	cv::bilateralFilter(dst1, dst2, -1, 20, 5);
	cv::imshow("Filtered", dst2);
	cv::waitKey();
	cv::destroyAllWindows();
}

void yaku1()
{
	cv::Mat src = cv::imread("yaku.png");
	cv::imshow("SRC", src);
	cv::Mat dst1; // 양방향필터를 통과한 영상 (어느정도 노이즈가 제거된 영상)
	cv::Mat dst2; // 미디언 필터를 통과한 영상
	cv::bilateralFilter(src, dst1, 9, 20, 5);
	cv::medianBlur(src, dst2, 3);
	cv::imshow("Filtered1", dst1);
	cv::imshow("Filtered2", dst2);
	cv::waitKey(0);
	cv::destroyAllWindows();
}

void show32()
{
	cv::Mat src = cv::imread("lenna.png", cv::IMREAD_GRAYSCALE);
	cv::imshow("SRC", src);
	int num = static_cast<int>(src.total() * 0.1);
	for (int i = 0; i < num; ++i)
	{
		int x = rand() % src.cols;
		int y = rand() % src.rows;
		src.at<uchar>(y, x) = (i % 2) * 255;// salt 255, pepper 0
	}
	cv::Mat dst1; // Gaussian Filter를 통과한 영상
	cv::Mat dst2; // Median Filter를 통과한 영상
	
	cv::GaussianBlur(src, dst1, cv::Size(), 1);
	cv::medianBlur(src, dst2, 3);

	cv::imshow("Gaussian", dst1);
	cv::imshow("Medina", dst2);

	cv::imshow("DirtySRC", src);
	cv::waitKey();
	cv::destroyAllWindows();
}
