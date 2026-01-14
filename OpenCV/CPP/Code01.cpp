#include "opencv2/opencv.hpp"

void show1()
{
	cv::Mat image1 = cv::imread("lenna.png");
	cv::Mat image2 = cv::imread("dog.jpg");
	cv::Mat image3;

	if (image1.empty() or image2.empty())
	{
		std::cerr << "파일이 없습니다." << std::endl;
		
		return;
	}

	image3 = image1.clone();

	std::cout << "lenna, 몇 차원? : " << image1.dims << std::endl;
	std::cout << "lenna, 열(column)? : " << image1.cols << std::endl;
	std::cout << "lenna, 행(row)? : " << image1.rows << std::endl;

	std::cout << "dog, 몇 차원? : " << image2.dims << std::endl;
	std::cout << "dog, 열(column)? : " << image2.cols << std::endl;
	std::cout << "dog, 행(row)? : " << image2.rows << std::endl;

	std::cout << "clone, 몇 차원? : " << image3.dims << std::endl;
	std::cout << "clone, 열(column)? : " << image3.cols << std::endl;
	std::cout << "clone, 행(row)? : " << image3.rows << std::endl;

	cv::namedWindow("LENNA");
	cv::imshow("LENNA", image1);

	cv::namedWindow("Dog");
	cv::imshow("Dog", image2);

	cv::namedWindow("Clone");
	cv::imshow("Clone", image3);

	cv::waitKey();
	cv::destroyAllWindows();
}

void show2()
{
	cv::namedWindow("Color");

	cv::Mat image2(1024, 1024, CV_8UC1);
	cv::imshow("Color", image2);
	cv::waitKey(0);
	cv::destroyAllWindows();

	cv::Mat image3(cv::Size(512, 512), CV_8UC3);
	cv::imshow("Color", image3);
	cv::waitKey(0);
	cv::destroyAllWindows();

	for (int i = 0; i < 256; ++i)
	{
		cv::Mat image(512, 512, CV_8UC3, cv::Scalar(i, i, i));// CV_8UC3 == Unsigned 8bit Channel 3
		cv::imshow("Color", image);
		cv::waitKey(10);
	}

	for (int i = 255; i >= 0; --i)
	{
		cv::Mat image(512, 512, CV_8UC3, cv::Scalar(i, i, i));// CV_8UC3 == Unsigned 8bit Channel 3
		cv::imshow("Color", image);
		cv::waitKey(10);
	}
	cv::waitKey(0);
}

void show3()
{
	cv::Mat img1 = cv::Mat::zeros(512, 512, CV_8UC1);
	cv::Mat img2 = cv::Mat::ones(512, 512, CV_8UC1);
	cv::Mat img3 = cv::Mat::eye(512, 512, CV_8UC1) * 255;
	cv::namedWindow("WINDOW");
	cv::imshow("WINDOW", img3);
	cv::waitKey();
	cv::destroyAllWindows();
}

void show4()
{
	cv::Mat img1 = cv::imread("dog.bmp");
	if (img1.empty())
	{
		std::cerr << "파일이 없습니다." << std::endl;
	}
	cv::Mat img2 = img1.clone();

	cv::Mat img3;
	img2.copyTo(img3);

	cv::Mat img4 = img1;

	img1.setTo(cv::Scalar(0, 255, 255));

	cv::namedWindow("DOG");
	cv::imshow("DOG", img1);
	cv::namedWindow("CLONE_DOG");
	cv::imshow("CLONE_DOG", img2);
	cv::namedWindow("COPY_DOG");
	cv::imshow("COPY_DOG", img3);
	cv::namedWindow("DOG2");
	cv::imshow("DOG2", img4);
	cv::waitKey();
	cv::destroyAllWindows();
}

void show5()
{
	cv::Mat img1 = cv::imread("cat.bmp");
	if (img1.empty())
	{
		std::cerr << "파일이 없습니다." << std::endl;
	}
	cv::Mat img2 = ~img1;
	cv::Mat img3 = img1(cv::Rect(220, 120, 340, 240));
	cv::namedWindow("CAT");
	cv::imshow("CAT", img1);
	cv::namedWindow("NOT_CAT");
	cv::imshow("NOT_CAT", img2);
	cv::namedWindow("CUT_CAT");
	cv::imshow("CUT_CAT", img3);
	cv::waitKey();
	cv::destroyAllWindows();
}

void show6()
{
	cv::Mat img1 = cv::Mat::zeros(256, 256, CV_8UC1);
	uchar value = 0;
	for (int i = 0; i < img1.rows; ++i)
	{
		for (int j = 0; j < img1.cols; ++j)
		{
			++value;
			img1.at<uchar>(i, j) = value;
		}
	}
	cv::namedWindow("IMAGE1");
	cv::imshow("IMAGE1", img1);
	cv::waitKey();
	cv::destroyAllWindows();
}

void show7()
{
	cv::Mat img1 = cv::imread("coins.png", cv::IMREAD_UNCHANGED);
	if (img1.empty()) return;
	std::cout << "이미지 폭 : " << img1.cols << std::endl;
	std::cout << "이미지 높이 : " << img1.rows << std::endl;
	std::cout << "이미지 사이즈 : " << img1.size << std::endl;
	std::cout << "픽셀 한 개의 사이즈 : " << img1.elemSize() << std::endl;
	std::cout << "채널 : " << img1.channels() << std::endl;
	if (img1.type() == CV_8UC1) std::cout << "Gray" << std::endl;
	else if (img1.type() == CV_8UC3) std::cout << "Color" << std::endl;
	else std::cout << "PNG" << std::endl;
}

void show8()
{

	float data1[] = {1.0f, 2.0f, 3.0f, 4.0f};
	cv::Mat mat1(2, 2, CV_32FC1, data1);
	cv::Mat mat2 = mat1.inv();
	cv::Mat mat3 = mat1* mat2;
	std::cout << mat1 << std::endl << mat2 << std::endl << mat3 << std::endl << std::endl;

	float data2[] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f };
	cv::Mat mat4(4, 4, CV_32FC1, data2);
	cv::Mat mat5 = mat4.inv();
	cv::Mat mat6 = mat4 * mat5;
	std::cout << mat4 << std::endl << mat5 << std::endl << mat6 << std::endl << std::endl;

	uchar data3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	cv::Mat mat7(3, 4, CV_8UC1, data3);
	std::cout << mat7 << std::endl;
	cv::Mat mat8 = mat7.reshape(0, 4);
	std::cout << mat8 << std::endl;

	cv::Mat img1 = cv::imread("lenna.png", cv::IMREAD_GRAYSCALE);
	cv::namedWindow("LENNA");
	cv::imshow("LENNA", img1);

	cv::Mat img2 = img1 + 50;
	cv::namedWindow("LENNA2");
	cv::imshow("LENNA2", img2);

	cv::Mat img3 = img1 - 50;
	cv::namedWindow("LENNA3");
	cv::imshow("LENNA3", img3);

	cv::Mat img4 = img1.t();
	cv::namedWindow("LENNA4");
	cv::imshow("LENNA4", img4);

	cv::Mat img5 = img4.t();
	cv::namedWindow("LENNA5");
	cv::imshow("LENNA5", img5);

	cv::waitKey();
	cv::destroyAllWindows();
}

void printMat(cv::InputArray _mat1)//cv::InputArray -> cv::Mat을 포함
{
	cv::Mat mat = _mat1.getMat();
	std::cout << mat << std::endl;
}

void inputArrayOf()
{
	uchar data1[] = { 1, 2, 3, 4, 5, 6 }; // 256 -> 0 
	cv::Mat mat1(2, 3, CV_8U, data1); // data1 -> 2 x 3 행렬로 변경
	printMat(mat1);
}

void show9()
{
	inputArrayOf();
}
