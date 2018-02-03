#include <iostream>
#include "opencv2/video.hpp"
#include "opencv/cv.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

//ģ���ļ�
String face_cascade_file_name = "E:\\code\\opencv\\buildx64\\install\\etc\\haarcascades\\haarcascade_frontalface_alt2.xml";
String eyes_cascade_file_name = "E:\\code\\opencv\\buildx64\\install\\etc\\haarcascades\\haarcascade_eye_tree_eyeglasses.xml";

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

//������Ƶ�ļ������Ƶ�ļ��ϵ���������
void VideoToFile(String strFilePath, Size st)
{
	VideoWriter vw;
	
	//���ļ�
	vw.open(strFilePath, -1, 30.0, st, true);

	

}


//�������
void detectFace(Mat frame)
{
	//�洢��⵽������
	vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 3, 3);
	for (int inx = 0; inx < faces.size(); ++inx)
	{
		//���ƿ�Ȧ����
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
	namedWindow("����ʶ��", 2);
	imshow("����ʶ��", frame);
}

#if 1

int main(void)
{

	if (!face_cascade.load(face_cascade_file_name))
	{
		printf("��������ģ�ͳ���\n");
		return -1;
	}

	if (!eyes_cascade.load(eyes_cascade_file_name))
	{
		printf("��������ģ�ͳ���\n");
		return -1;
}
#if 1
	VideoCapture cap(0);
	Mat frame;
	VideoWriter vw;

	String strFilePath = "face.avi";
	Size st = Size(cap.get(CV_CAP_PROP_FRAME_WIDTH), cap.get(CV_CAP_PROP_FRAME_HEIGHT));

	//���ļ�
	vw.open(strFilePath, -1, 30.0, st, true);
	if (!vw.isOpened()) {
		cout << "fail to open!" << endl;
		return -1;
	}


	while (true)
	{
		cap >> frame;

		//��ʾ��Ƶ
		//imshow(strFilePath, frame);

		//д���ļ�
		//vw << frame;
		detectFace(frame);
		waitKeyEx(10);
	}
#endif

#if 0
	//�������
	Mat frame = imread("E:\\file\\database\\netimg\\timg.jpg");
#endif 
	return 0;
}


#endif		//main
