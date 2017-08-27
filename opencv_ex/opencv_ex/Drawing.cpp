#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//디버그용 라이브러리
#ifdef _DEBUG
#pragma comment(lib, "opencv_world320d.lib")

//릴리즈 모드 일 때
#else
#pragma comment(lib, "opencv_world320.lib")

#endif

int main(int, char)
{
	//Mat img(500, 500, CV_8UC3);
	//img.setTo(0);

	
	/*
	//line Drawing
	Point pt(300, 300);
	line(img, Point(10, 10), pt, CV_RGB(255, 0, 0), 1);
	line(img, Point(300, 10), Point(30, 300), Scalar(255, 0, 0), 3);//Scalar는 b,g,r 순서로 들어간다


	//circle drawing
	circle(img, Point(250, 250), 100, CV_RGB(0, 200, 0), 3);
	Point center(400, 400);
	circle(img, center, 300, Scalar(23, 142, 33), 10);
	circle(img, Point(40, 40), 10, Scalar(255, 0, 255), -1); //-1은 색을 채움

	//Rectangle drawing
	rectangle(img, Rect(10, 10, 200, 250), CV_RGB(255, 0, 0), 2);
	

	//ellips drawing
	ellipse(img, Point(100, 100), Size(100, 50),0, 0, 270, CV_RGB(255, 0, 0), -1);

	//ellips drawing Type2
	RotatedRect rRect = RotatedRect(Point2f(300, 300), Size2f(300, 100), 30);
	ellipse(img, rRect, CV_RGB(255, 0, 0),1);

	//rotatedRect
	Point2f vertices[4];
	rRect.points(vertices);
	for (int i = 0; i < 4; i++)
		line(img, vertices[i], vertices[(i + 1) % 4], Scalar(255, 0, 0));

	Rect brect = rRect.boundingRect();
	rectangle(img, brect, Scalar(255, 0, 0));
	
	

	//polyline 다각형
	vector<Point> contour;
	contour.push_back(Point(50, 50));
	contour.push_back(Point(300, 50));
	contour.push_back(Point(350, 200));
	contour.push_back(Point(300, 150));
	contour.push_back(Point(150, 350));
	contour.push_back(Point(100, 100));

	const Point *pts = (const Point*)Mat(contour).data;
	int npts = Mat(contour).rows;

	cout << "Number of polygon vertices >> " << npts << endl;

	//polylines(img, &pts, &npts, 1, false, Scalar(0, 255, 0));

	vector<Point> contour2;
	contour2.push_back(Point(400, 200));
	contour2.push_back(Point(100, 230));
	contour2.push_back(Point(270, 300));

	const Point *pts2 = (const Point*)Mat(contour2).data;
	int npts2 = Mat(contour2).rows;

	const Point *n_pts[2] = { pts,pts2 };
	int n_npts[2] = { npts,npts2 };

	polylines(img, n_pts, n_npts, 2, true, Scalar(255,0,0),1);
	*/
	/*
	Mat img = imread("aa.jpg");

	char TestStr[100];
	sprintf(TestStr, "total time : %lf sec", 0.001);
	putText(img, TestStr, Point(10, 200), CV_FONT_NORMAL, 1, Scalar(0, 255, 0), 1, 1);
	*/

	namedWindow("show1", 1);
	namedWindow("threshold", 0);
	namedWindow("contours", 0);

	Mat img = imread("aa.jpg");

	cvtColor(img, img, CV_RGB2GRAY);

	imshow("show1", img);

	threshold(img, img, 128, 255, CV_THRESH_BINARY);
	imshow("threshold", img);

	Mat dst = Mat::zeros(img.rows, img.cols, CV_8UC3);

	vector<vector<Point>>contours;
	vector<Vec4i> hierarchy;

	findContours(img.clone(), contours, hierarchy,RETR_CCOMP,CHAIN_APPROX_SIMPLE);

	drawContours(dst, contours, -1, CV_RGB(255, 0, 0), 1, 8, hierarchy);

	imshow("contours", dst);

	waitKey(0);
}