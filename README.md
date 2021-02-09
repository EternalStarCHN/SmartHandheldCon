# SmartHandheldCon（智能掌上游戏机）介绍
 SmartHandheldCon是大学本科嵌入式系统课程的期末设计作业，它基于STM32F407单片机设计和制作，主要功能为贪吃蛇游戏、环境监测和PWM波控制LED灯，功能实现表如下：
 | 功能 | 实现方法 |
 | :--------- | :--------- |
 | 贪吃蛇 | LCD显示屏+游戏算法 |
 | 环境检测 | 光线传感器+空气质量传感器 |
 | LED灯 | LED5050+控制算法 |
 | 蓝牙 | HC05 |
# 实现流程
菜单部分是整个程序运行的主体，由菜单进入其它各个功能界面。  
<img src="https://github.com/EternalStarCHN/SmartHandheldCon/blob/master/%E8%8F%9C%E5%8D%95%E6%B5%81%E7%A8%8B%E5%9B%BE%20.png?raw=true" width="80%" height="80%" alt="菜单流程图"/><br/>
贪吃蛇游戏流程较为复杂  
<img src="https://github.com/EternalStarCHN/SmartHandheldCon/blob/master/%E8%B4%AA%E5%90%83%E8%9B%87%E6%B5%81%E7%A8%8B%E5%9B%BE.png?raw=true" width="80%" height="80%" alt="贪吃蛇流程图"/><br/>  
环境检测主要用于检测环境亮度以及环境空气质量，从而控制面板上的两个LED灯的亮灭以及蓝牙信号的输出。  
<img src="https://github.com/EternalStarCHN/SmartHandheldCon/blob/master/%E7%8E%AF%E5%A2%83%E6%A3%80%E6%B5%8B%E6%B5%81%E7%A8%8B%E5%9B%BE%20.png?raw=true" width="80%" height="80%" alt="环境检测流程图"/><br/>
最后是PWM控制流程图  
<img src="https://github.com/EternalStarCHN/SmartHandheldCon/blob/master/pwm%E6%B5%81%E7%A8%8B%E5%9B%BE%20.png?raw=true" width="80%" height="80%" alt="PWM控制流程图"/><br/>
# 硬件部分
SmartHandheldCon的原理图和PCB图均使用**Altium Designer 19**进行设计和绘制，通过修改原理图和PCB文件即可修改硬件设计。
# 许可证
SmartHandheldCon is licensed under [MIT License](https://github.com/EternalStarCHN/SmartHandheldCon/blob/master/LICENSE).
