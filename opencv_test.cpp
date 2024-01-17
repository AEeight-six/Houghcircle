#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void DetectCircle();
int main()

{
	DetectCircle();


}

void DetectCircle()
{
	Mat src;
	src = imread("circle.jpg", IMREAD_GRAYSCALE);
	vector<Vec3f> circles;
	HoughCircles(src, circles, HOUGH_GRADIENT, 1, 120, 100, 30, 30, 80);
	for (size_t i = 0; i < circles.size(); i++)
	{
		//��ȡ��Բ������Ͱ뾶
		Point center(round(circles[i][0]), round(circles[i][1]));
		int radius = round(circles[i][2]);

		//��Բ��
		circle(src, center, 3, Scalar(255), -1, 4, 0);
		//��Բ����
		circle(src, center, radius, Scalar(255), 3, 4, 0);
	}
	imshow("Circle_find", src);
	waitKey(0);
}	
