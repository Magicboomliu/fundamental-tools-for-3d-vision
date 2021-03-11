#include<ceres/ceres.h>
#include <opencv2/core/core.hpp>
#include <chrono>
using namespace std;
using namespace ceres;

// 定义第一个子方程
struct powell_function_f1{
    template<typename T>
    bool operator()(const T* const x1, const T* const x2, T* residual ) const{
   residual[0] =  x1[0]+    10.0    *  x2[0];  // 注意所有的数据都是有维度的，这里不要忘记
   return true;
    }
};
// 定义第2个子方程
struct powell_function_f2{
    template<typename T>
    bool operator()(const T* const x3, const T* const x4, T* residual ) const{
   residual[0] = sqrt(5.0) * (x3[0]- x4[0]);  // 注意所有的数据都是有维度的，这里不要忘记
   return true;
    }
};
// 定义第3个子方程
struct powell_function_f3{
    template<typename T>
    bool operator()(const T* const x2, const T* const x3, T* residual ) const{
   residual[0] = (x2[0]- 2.0 *x3[0]) *(x2[0]- 2.0 *x3[0]);  // 注意所有的数据都是有维度的，这里不要忘记
   return true;
    }
};
// 定义第4个子方程
struct powell_function_f4{
    template<typename T>
    bool operator()(const T* const x1, const T* const x4, T* residual ) const{
   residual[0] = sqrt(10.0) * (x1[0]- x4[0]) * (x1[0]- x4[0]);  // 注意所有的数据都是有维度的，这里不要忘记
   return true;
    }
};

void optimalizedAuto(){

// 初始化
double x1 =1.0; 
double x2 =2.0; 
double x3 =3.0; 
double x4 =5.0;

ceres::Problem problem;
problem.AddResidualBlock(new AutoDiffCostFunction<powell_function_f1,1,1,1>(new powell_function_f1),
    NULL, &x1,&x2);
problem.AddResidualBlock(new AutoDiffCostFunction<powell_function_f2,1,1,1>(new powell_function_f2),
    NULL, &x3,&x4);
problem.AddResidualBlock(new AutoDiffCostFunction<powell_function_f3,1,1,1>(new powell_function_f3),
    NULL, &x2,&x3);
problem.AddResidualBlock(new AutoDiffCostFunction<powell_function_f4,1,1,1>(new powell_function_f4),
    NULL, &x1,&x4);

ceres::Solver::Options options;
options.linear_solver_type = ceres::DENSE_QR;
options.max_num_iterations = 200;
options.minimizer_progress_to_stdout = true;

ceres::Solver::Summary summary;
ceres::Solve(options,&problem,&summary);
std::cout<<summary.BriefReport()<<endl;
std::cout<<"estimated x1 is "<<x1<<endl;
std::cout<<"estimated x2 is "<<x2<<endl;
std::cout<<"estimated x3 is "<<x3<<endl;
std::cout<<"estimated x4 is "<<x4<<endl;
}
int main(int argc, char const *argv[])
{
    google::InitGoogleLogging(argv[0]);
    optimalizedAuto();
    return 0;
}
