#include <iostream>
#include "opencv2/video.hpp"
#include "opencv/cv.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

//模型文件
String face_cascade_file_name = "E:\\code\\opencv\\buildx64\\install\\etc\\haarcascades\\haarcascade_eye_tree_eyeglasses.xml";
String eyes_cascade_file_name = "E:\\code\\opencv\\buildx64\\install\\etc\\haarcascades\\haarcascade_frontalface_default.xml";

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

//人脸检测
void detectFace(Mat frame)
{
	//存储检测到的人脸
	vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 3, CV_HAAR_DO_ROUGH_SEARCH, Size(70, 70), Size(100, 100));
	for (int inx = 0; inx < faces.size(); ++inx)
	{
		//绘制框圈人脸
		rectangle(frame, faces[inx], Scalar(255, 0, 0), 2, 8, 0);
		Mat faceROI = frame_gray(faces[inx]);
		vector<Rect> eyes;
		eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 1, CV_HAAR_DO_ROUGH_SEARCH, Size(3, 3));
		for (size_t jnx = 0; jnx < eyes.size(); ++jnx)
		{
			Rect rect(faces[inx].x + eyes[jnx].x, faces[inx].y + eyes[jnx].y, eyes[jnx].width, eyes[jnx].height);
			rectangle(frame, rect, Scalar(0, 244, 0), 2, 8, 0);
		}
		namedWindow("人脸识别", 2);
		imshow("人脸识别", frame);
	}
}


int main(void)
{
#if 0
	VideoCapture cap(0);
	Mat frame;
	while (true)
	{
		cap >> frame;
		imshow("hello cv", frame);
		waitKeyEx(10);
	}
#endif

	//人脸检测
	Mat frame = imread("C:\\Users\\long\\Downloads\\byzdl.jpg");

	if (!face_cascade.load(face_cascade_file_name))
	{
		printf("加载人脸模型出错\n");
		return -1;
	}

	if (!eyes_cascade.load(eyes_cascade_file_name))
	{
		printf("加载人眼模型出错\n");
		return -1;
	}

	detectFace(frame);

	//while (true)
	//{
	//	int a = 0;
	//	cin >> a;
	//	if (a == 12)
	//		return 0;
	//}

	int c = waitKey(10000);
	if((char)c == 27) 
	{
		return 0;
	} // escape 
	return 0;
}

