# PMSM_FOC

基于Axdr开发板和2312s搭建仿真
## 滑膜观测器
使用高阶滑膜，避免了因低通滤波器产生的相位差，但是实物上仍然会有角度偏差，需要根据不同转速进行角度补偿
## 高频注入
采用方波注入的形式，在角度收敛后使用注入两次电压的方式对极性进行辨识，支持0速启动，但是噪声大。
## 非线性磁链观测器
角度跟随性好，支持0速启动，在启动的初始阶段，通过在d轴注入电流可以使启动更加流畅，大大降低启动失败率。
