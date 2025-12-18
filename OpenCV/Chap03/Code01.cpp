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
