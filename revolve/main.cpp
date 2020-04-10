#include<opencv2\opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main() {
	Mat src, dst;
	src = imread("D:\\1.png", 1);
	float angle = 10.0, scale = 1;
	Point2f center(src.cols*0.5, src.rows*0.5);
	Mat rot = getRotationMatrix2D(center, angle, scale);
	Rect bbox = RotatedRect(center, src.size(), angle).boundingRect();
	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;
	warpAffine(src, dst, rot, bbox.size());

	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);

}

