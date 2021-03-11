# include<iostream>
#include<ceres/ceres.h>
#include<glog/logging.h>
using namespace std;

// Problem need to be solved
//    f(x) = 1/2(10-x)^2        min f(x),    x is needed to be estimated.

////// 使用Ceres求解非线性优化问题，一共分为三个部分：

// 第一部分：构建cost fuction，即代价函数，也就是寻优的目标式。这个部分需要使用仿函数（functor）这一技巧来实现做法是定义
//一个cost function的结构体，在结构体内重载 () 运算符.

struct Costfunctor{
// 使用 Template parameter
template< typename T>
// 重载（） 运算符
bool operator()(const T* const x, T* residual) const {
   residual[0] = T(10.0) - x[0];   // 这里残差和等待估计的量都是一维的
    return true;
        }
};

// 第二部分：通过代价函数构建待求解的优化问题。
void optimizeAuto(){
/// 设置优化的初始值
const double init_x  = 0;
double estimated_x = init_x;
/// 定义问题
ceres::Problem problem;
//使用自动求导，将之前的代价函数结构体传入，第一个1是输出维度，即残差的维度，第二个1是输入维度，即待寻优参数x的维度。
ceres::CostFunction* constFunction = new ceres::AutoDiffCostFunction<Costfunctor,1,1>(new  Costfunctor);
problem.AddResidualBlock(constFunction,NULL,&estimated_x);  // NULL 表示不使用核函数
/// 配置求解器
ceres::Solver::Options options;
options.linear_solver_type = ceres::DENSE_QR;  // 使用QR分解求解
options.minimizer_progress_to_stdout = true; // 显示优化过程

ceres::Solver::Summary summary; 
// 求解
ceres::Solve(options,&problem,&summary);

std::cout<<summary.BriefReport()<<endl;

std::cout<<"init x from "<<init_x<<" ----> "<<estimated_x<<endl;

}

// 第三部分：配置求解器参数并求解问题，这个步骤就是设置方程怎么求解、求解过程是否输出等，然后调用一下Solve方法。

int main(int argc, char ** argv){
google::InitGoogleLogging(argv[0]);

optimizeAuto();

    return 0;
}