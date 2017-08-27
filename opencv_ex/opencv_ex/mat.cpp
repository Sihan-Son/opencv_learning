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
	/*Mat mtx(3, 3, CV_32F);
	Mat cmtx(10, 1, CV_64FC2);

	Mat img(Size(5, 3), CV_8UC3);

	Mat mtx2;
	mtx2 = Mat(3, 3, CV_32F);

	Mat cmtx2;
	cmtx2 = Mat(10, 1, CV_64FC1);

	Mat* mtx3 = new Mat(3, 3, CV_32F);
	delete mtx3;

	cmtx.setTo(10);
	cout << cmtx << endl;*/

	//기초 연산

	/*Mat m = Mat::ones(3, 3, CV_64F);
	m *= 3;
	cout << m << endl<<endl;

	double dm[3][3] = { {1,2,1},{0,1,1},{1,0,0} };
	Mat m2 = Mat(3, 3, CV_64F, dm);

	cout << m2 << endl << endl;

	cout << m.mul(m2) << endl;
	cout << m*m2 << endl<<endl;

	cout << m2.inv() << endl << endl;

	cout << m2.t() << endl;*/

	//Mat img = imread("ss.jpg");
	//Mat img2;
	//Mat img3;

	//Sobel(img, img2, img.depth(), 1, 0);
	//flip(img, img3, 1);

	//namedWindow("img", 0);
	//namedWindow("img2", 0);
	//namedWindow("img3", 0);

	//imshow("img", img);
	//imshow("img2", img2);
	//imshow("img3", img3);
	//waitKey(0);
	//destroyAllWindows();
	//Mat img = imread("ss.jpg",0);

	//namedWindow("img", 0);
	//imshow("img", img);
	//

	//while (1)
	//{
	//	int keyValue;
	//	keyValue = waitKey(0);
	//	cout << keyValue << endl;
	//	if (keyValue == 'c')
	//		break;
	//}

	//VideoCapture capture(0);
	//Mat frame;

	//if (!capture.isOpened())
	//{
	//	cout << "AVI file can not open.\n";
	//	return 0;
	//}
	//namedWindow("w");

	//while (1)
	//{
	//	capture >> frame;
	//	if (frame.empty())
	//		break;

	//	//Sobel(frame, frame, frame.depth(), 1, 0);
	//	flip(frame, frame, 1);

	  //	imshow("w", frame);
	//	if (waitKey(10) == 27)
	//		break;
	//}
	//return 0;

	/*Mat img_s = img;
	bitwise_not(img, img);

	imshow("img_s", img_s);
	*/

	/*
	Mat img = imread("ss.jpg");
	Mat img2 = img.clone();
	Rect r(img.cols / 4, img.rows / 4, img.cols / 4 * 2, img.rows / 4 * 2);
	Mat img5 = img(r).clone();
	Mat cimg;
	Mat cimg2;

	img.copyTo(cimg);
	img(r).copyTo(cimg2);
	cout << r << endl;

	//bitwise_not(img, img);


	Mat cimg3(Size(img.cols * 2, img.rows), img.type());
	cimg.setTo(255);
	img.copyTo(cimg3(Range::all(), Range(0, img.cols)));
	img2.copyTo(cimg3(Range::all(), Range(img2.cols, img2.cols * 2)));

	Mat roi(img, r);
	bitwise_not(roi, roi);

	imshow("roi", roi);


	imshow("img", img);
	//imshow("cimg3", cimg3);


	imshow("img2", img2);
	imshow("img5", img5);
	imshow("cimg", cimg);
	imshow("cimg2", cimg2);
	*/



	/*
	cout << img.elemSize() << endl;
	cout << img.channels() << endl;
	cout << img.rows << endl;
	cout << img.step / img.rows << endl;
	cout << img.step << endl;

	//data
	/*
	for (int i = 0; i < img.rows / 10 * 8; i++)
	//for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			unsigned char r, g, b;
			b = img.data[i*img.step + j*img.elemSize() + 0];
			g = img.data[i*img.step + j*img.elemSize() + 1];
			r = img.data[i*img.step + j*img.elemSize() + 2];

			img.data[i*img.step + j*img.elemSize() + 0] = unsigned char(255 - b);
			img.data[i*img.step + j*img.elemSize() + 1] = unsigned char(255 - g);
			img.data[i*img.step + j*img.elemSize() + 2] = unsigned char(255 - r);
		}
	}

	*/

	// using at
	/*
	for (int i = img.rows / 10 * 3; i < img.rows /10 * 5; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			unsigned char b = img.at<cv::Vec3b>(i, j)[0]; // Vec3b 는 이미지 타입에 맞게 적어야함
			unsigned char g = img.at<cv::Vec3b>(i, j)[1];
			unsigned char r = img.at<cv::Vec3b>(i, j)[2];

			img.at<cv::Vec3b>(i, j)[0] = unsigned char(255 - b);
			img.at<cv::Vec3b>(i, j)[1] = unsigned char(255 - g);
			img.at<cv::Vec3b>(i, j)[2] = unsigned char(255 - r);
		}
	}
	*/

	/*namedWindow("img", 1);
	Mat img = imread("aa.jpg");*/


	/*

	//using ptr
	for (int i = img.rows / 10 * 5; i < img.rows / 10 * 6; i++)
	{
		cv::Vec3b*ptr = img.ptr<cv::Vec3b>(i);
		for (int j = 0; j < img.cols; j++)
		{
			unsigned char b1 = (ptr[j][0]);
			unsigned char g1 = (ptr[j][1]);
			unsigned char r1 = (ptr[j][2]);

			cv::Vec3b bgr = ptr[j];
			unsigned char b2 = (bgr[0]);
			unsigned char g2 = (bgr[1]);
			unsigned char r2 = (bgr[2]);

			ptr[j] = cv::Vec3b(255 - b1, 255 - g1, 255 - r1);
		}
	}

	*/


	//using iteration
	/*
	cv::MatIterator_<Vec3b> itd = img.begin<Vec3b>(), itd_end = img.end<Vec3b>();
	for (int i = 0; itd != itd_end; ++itd, ++i)
	{
		Vec3b bgr = (*itd);

		(*itd)[0] = 255 - bgr[0];
		(*itd)[1] = 255 - bgr[1];
		(*itd)[2] = 255 - bgr[2];
	}
	
	imshow("img", img);
	

	Mat img = imread("aa.jpg");
	namedWindow("img", 0);

	imshow("img", img);


	Mat img2;
	Sobel(img, img2, CV_8U, 1, 0);
	//imwrite("sobel_img.png", img2);

	vector<Mat> rgbMat(3);
	split(img, rgbMat);
	//imwrite("r.jpg", rgbMat[2]);
	//imwrite("g.jpg", rgbMat[1]);
	//imwrite("b.jpg", rgbMat[0]);

	cout << img.channels() << endl;
	cout << rgbMat[2].channels() << endl;
	


	VideoCapture capture(".\\car.mp4");

	Mat frame;

	int askFileTypeBox = 0;
	int Color = 1;
	Size S = Size((int)capture.get(CV_CAP_PROP_FRAME_WIDTH), (int)capture.get(CV_CAP_PROP_FRAME_HEIGHT));

	VideoWriter outVideo;
	outVideo.open(".\\outVideo.avi", askFileTypeBox, capture.get(CV_CAP_PROP_FPS), S, Color);

	if (!capture.isOpened())
	{
		cout << "AVI file can not open " << endl;
		return 0;
	}

	namedWindow("w");
	
	while (1)
	{
		capture >> frame;
		if (frame.empty())
			break;

		outVideo << frame;
		imshow("w", frame);

		if (waitKey(10) > 0)
			break;

		
	}
	*/


	//Vector product

	//double va[] = { 1,2,3 };
	//double vb[] = { 0,0,1 };
	//double vc[3];

	//Mat Va(3, 1, CV_64FC1, va);
	//Mat Vb(3, 1, CV_64FC1, vb);
	//Mat Vc(3, 1, CV_64FC1, vc);

	//double res = Va.dot(Vb);
	//Vc = Va.cross(Vb);

	//cout << res << endl << Vc << endl;
	
	double dm2[3][3] = { {1,2,3,},{4,5,6},{7,8,9} };
	Mat A(3, 3, CV_64FC1, dm2);
	Mat x(3, 1, CV_64FC1);

	double vvb[] = { 14,32,52 };
	Mat b(3, 1, CV_64FC1, vvb);
	solve(A, b, x, DECOMP_SVD);
	cout << x << endl;

	cout << A*x << endl;


}