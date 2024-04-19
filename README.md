# PMSM_FOC

基于Axdr开发板和2312s搭建仿真,Axdr开发板在立创开源广场上可以看到工程，2312s电机为大疆精灵的拆机电机
![pic](/AxDr.png)
## mt6816编码器  
mt6816编码器可以直接输出电机的机械角度，在启动时可以将电机拉到0度，校准编码器位置。使用非常简单
## 滑膜观测器
使用高阶滑膜，避免了因低通滤波器产生的相位差，但是实物上仍然会有角度偏差，需要根据不同转速进行角度补偿
## 高频注入
采用方波注入的形式，在角度收敛后使用注入两次电压的方式对极性进行辨识，支持0速启动，但是噪声大。
## 非线性磁链观测器
角度跟随性好，支持0速启动，在启动的初始阶段，通过在d轴注入电流可以使启动更加流畅，大大降低启动失败率。
## 电机参数辨识
一.电阻
  1、设置电压矢量角度为0(或其他恒定值)。令Vd = 0，Vq = 0，通过svpwm输出。  
  2、将采样到的相电流进行clark变换，计算   
  3、逐渐增加电压幅值， 等待达到1/2额定电流。  
  4、保持步骤3的Vd幅值，采集此时的电流和电压，并分别低通滤波。  
  5、等待一定时间后，记录滤波后的电流和电压值 。  
  6、计算相电阻。  
二.电感  
  保持电角度为0，分别在dq轴注入高频正弦波。  
三.磁链  
 
  磁链的计算需要角度，首先让电机开环转动。  
  ![image](https://github.com/lemontree1433223/PMSM_FOC/assets/54848981/3979329b-be84-4372-b9cd-75067452a5d4)  
   ![image](https://github.com/lemontree1433223/PMSM_FOC/assets/54848981/a8fac7a7-8d5b-4753-95ca-58f2debf53a1)  
  根据公式很容易计算出磁链值，通过对电压积分计算时，因为积分漂移的原因，需要加一个高通滤波器。

