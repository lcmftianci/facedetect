#include <iostream>
#include "opencv2/video.hpp"
#include "opencv/cv.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

//模型文件
String face_cascade_file_name = "E:\\code\\opencv\\buildx64\\install\\etc\\haarcascades\\haarcascade_frontalface_alt2.xml";
String eyes_cascade_file_name = "E:\\code\\opencv\\buildx64\\install\\etc\\haarcascades\\haarcascade_eye_tree_eyeglasses.xml";

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

//输入视频文件检测视频文件上的人脸数据
void VideoToFile(String strFilePath, Size st)
{
	VideoWriter vw;
	
	//打开文件
	vw.open(strFilePath, -1, 30.0, st, true);

	

}


//人脸检测
void detectFace(Mat frame)
{
	//存储检测到的人脸
	vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 3, 3);
	for (int inx = 0; inx < faces.size(); ++inx)
	{
		//绘制框圈人脸
		rectangle(frame, faces[inx], Scalar(255, 0, 0), 2, 8, 0);
		Mat faceROI = frame_gray(faces[inx]);
		vector<Rect> eyes;
		eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 1, 0);
		for (size_t jnx = 0; jnx < eyes.size(); ++jnx)
		{
			Rect rect(faces[inx].x + eyes[jnx].x, faces[inx].y + eyes[jnx].y, eyes[jnx].width, eyes[jnx].height);
			rectangle(frame, rect, Scalar(0, 244, 0), 2, 8, 0);
		}
	}
	namedWindow("人脸识别", 2);
	imshow("人脸识别", frame);
}

#if 1

int main(void)
{

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
#if 1
	VideoCapture cap(0);
	Mat frame;
	VideoWriter vw;

	String strFilePath = "face.avi";
	Size st = Size(cap.get(CV_CAP_PROP_FRAME_WIDTH), cap.get(CV_CAP_PROP_FRAME_HEIGHT));

	//打开文件
	vw.open(strFilePath, -1, 30.0, st, true);
	if (!vw.isOpened()) {
		cout << "fail to open!" << endl;
		return -1;
	}


	while (true)
	{
		cap >> frame;

		//显示视频
		//imshow(strFilePath, frame);

		//写入文件
		//vw << frame;
		detectFace(frame);
		waitKeyEx(10);
	}
#endif

#if 0
	//人脸检测
	Mat frame = imread("E:\\file\\database\\netimg\\timg.jpg");
#endif 
	return 0;
}


#endif		//main
