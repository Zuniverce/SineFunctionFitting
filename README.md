# SineFunctionFitting

从零实现的 C++ 神经网络，用于拟合正弦函数 `y = sin(x)`。

## 项目简介

本项目不使用任何机器学习库，完全手动实现了一个前馈神经网络（Feedforward Neural Network），包含前向传播、反向传播和梯度下降优化。网络通过学习 `x → sin(x)` 的映射关系，在区间 `[0, π+2]` 上逼近正弦曲线。

这是一个学习/教学项目，展示了：

- 可配置的隐藏层结构（层数和每层神经元数量）
- Sigmoid 激活函数（隐藏层）和线性输出（输出层）
- 基于梯度的权重和偏置更新
- 自定义的四次代价函数

## 项目结构

```
SineFunctionFitting/
├── SineFunctionFitting.sln          # Visual Studio 解决方案文件
├── SineFunctionFitting/             # 源代码目录
│   ├── SineFunctionFitting.cpp      # 主入口，训练循环
│   ├── Network.h / Network.cpp      # 神经网络类
│   ├── Layer.h / Layer.cpp          # 网络层类
│   ├── Neuron.h / Neuron.cpp        # 神经元类（权重、前向、反向、更新）
│   ├── Definition.h / Definition.cpp # 全局变量、激活函数、代价函数
│   ├── Global.h / Global.cpp        # 公共头文件
│   └── *.vcxproj                    # MSBuild 项目文件
├── in.txt                           # 输入数据（100 个 x 值）
└── Sine FunctionFitterData.xlsx     # 训练输出数据
```

## 核心组件

| 组件 | 功能 |
|------|------|
| **Neuron** | 神经元基本单元，存储权重和偏置，实现前向传播、反向传播和梯度下降更新 |
| **Layer** | 神经元集合，将前向/反向/更新操作委托给每个神经元 |
| **Network** | 完整网络，管理多层结构，处理输入重置、真值计算、训练循环 |
| **Definition** | 全局配置（学习率、收敛阈值、初始化范围）和数学函数（sigmoid、激活函数、代价函数） |

## 关键参数

| 参数 | 默认值 | 说明 |
|------|--------|------|
| `eta` (学习率) | 0.001 | 梯度下降的学习率 |
| `flag` (收敛阈值) | 0.0005 | 总代价低于此值时停止训练 |
| `maxWeight` | 3.0 | 权重初始化范围 |
| `maxBias` | 5.0 | 偏置初始化范围 |

## 构建和运行

### Windows (Visual Studio)

1. 用 Visual Studio 2022 打开 `SineFunctionFitting.sln`
2. 确保 `in.txt` 文件路径正确（修改 `SineFunctionFitting.cpp` 第 4 行的路径）
3. 生成并运行（F5）
4. 程序会交互式提示输入隐藏层层数和每层神经元数量

### macOS / Linux

需要添加 Makefile 或 CMakeLists.txt 才能编译。当前代码使用 Visual Studio 的 `.vcxproj` 构建系统，在 macOS/Linux 上需要手动调整。

## 训练流程

1. 读取输入数据 `in.txt`（100 个 x 值，从 0.0 到 4.95，步长 0.05）
2. 用户配置网络架构（隐藏层层数、每层神经元数）
3. 每个 epoch 内：
   - 在 `[0, 4.95]` 区间以步长 0.005 扫描 1000 个点
   - 对每个点执行：前向传播 → 反向传播 → 累加代价
   - epoch 结束时更新权重并清零梯度
4. 每 100 个 epoch 打印一次当前总代价
5. 当总代价低于 0.0005 时停止训练
6. 输出训练结果和 100 个测试点的预测值

## 技术栈

- **语言**: C++（标准 C++，无 C++11/14/17/20 特性）
- **依赖**: 仅使用标准库（`iostream`, `vector`, `random`, `math.h`, `fstream`, `ctime`）
- **IDE**: Visual Studio 2022（MSBuild）
- **无第三方库**

## License

MIT License
