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
//	::google::InitGoogleLogging(argv[0]);  //用第一个参数来初始化日志
//	::google::SetLogDestination(0, "../tmp/");   //将日志放入/tmp/文件夹下
//	if (argc < 2 || argc > 3) {
//		LOG(ERROR) << "Usage: train_net solver_proto_file [resume_point_file]";
//		return 1;
//	}
//
//#if 0
//	SolverParameter solver_param;  //创建测试参数对象
//	ReadProtoFromTextFileOrDie(argv[1], &solver_param);  //读取具体的参数配置 
//
//	LOG(INFO) << "Starting Optimization";   //打印日志信息
//	SGDSolver<float> solver(solver_param);  //开始优化
//	if (argc == 3) {
//		LOG(INFO) << "Resuming from " << argv[2];
//		solver.Solve(argv[2]);
//	}
//	else {
//		solver.Solve();
//	}
//#endif 										//根据调用时，是否带第三个参数，进行不同的测试
//
//	LOG(INFO) << "Optimization Done.";  //优化结束，打印日志信息
//
//	return 0;
//}