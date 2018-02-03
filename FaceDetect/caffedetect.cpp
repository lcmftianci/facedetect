//#include "caffeheader.h"
//#include "google/protobuf/message.h"  
//#include "caffe/blob.hpp"  
//#include "caffe/common.hpp"  
//#include "caffe/proto/caffe.pb.h"  
//
//
//using namespace caffe;  // NOLINT(build/namespaces)
//
//int main(int argc, char** argv) {
//	::google::InitGoogleLogging(argv[0]);  //�õ�һ����������ʼ����־
//	::google::SetLogDestination(0, "../tmp/");   //����־����/tmp/�ļ�����
//	if (argc < 2 || argc > 3) {
//		LOG(ERROR) << "Usage: train_net solver_proto_file [resume_point_file]";
//		return 1;
//	}
//
//#if 0
//	SolverParameter solver_param;  //�������Բ�������
//	ReadProtoFromTextFileOrDie(argv[1], &solver_param);  //��ȡ����Ĳ������� 
//
//	LOG(INFO) << "Starting Optimization";   //��ӡ��־��Ϣ
//	SGDSolver<float> solver(solver_param);  //��ʼ�Ż�
//	if (argc == 3) {
//		LOG(INFO) << "Resuming from " << argv[2];
//		solver.Solve(argv[2]);
//	}
//	else {
//		solver.Solve();
//	}
//#endif 										//���ݵ���ʱ���Ƿ�����������������в�ͬ�Ĳ���
//
//	LOG(INFO) << "Optimization Done.";  //�Ż���������ӡ��־��Ϣ
//
//	return 0;
//}