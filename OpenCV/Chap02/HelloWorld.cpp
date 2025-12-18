#include "opencv2/opencv.hpp"
//#include <iostream>

int main()
{
    std::cout << "Hello OpenCV!" << CV_VERSION << std::endl;

    cv::Mat img; // 객체가 생성자를 호출해서 만들어 짐.
    img = cv::imread("lenna.png");

    if (img.empty())
    {
        std::cerr << "파일이 없습니다." << std::endl;
        return -1;
    }

    cv::namedWindow("LENNA");
    cv::imshow("LENNA", img);
    cv::waitKey(); //cv::waitKey(1000) 단위ms이므로 1000은 1초
    cv::destroyWindow("LENNA");
    //cv::destroyAllWindows();

    return 0;
}
