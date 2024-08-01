### uboot使用
- 清除上一次使用uboot生成的所有文件，包括配置文件、镜像文件
`make distclean`
- 配置ARCH(架构)为arm、CROSS_COMPILE(交叉编译器)为arm-linux-gnueabi-，两种方法
   - 直接配置Makefile文件，在文件里面找到CROSS_COMPILE ?=，在fi后面新加一行，CROSS_COMPILE ?=arm-linux-gnueabi-，在config.mk文件里面找到ARCH :=，改成ARCH :=arm
   - 每次编译时都传参数进去，make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- 选项
- 配置开发板信息，不同开发板有不同的uboot、linux系统配置
  - 如果是采用上面的1方法直接配置文件架构和交叉编译器的，直接：
  `make 开发板名字_defconfig`
  - 注意旧版的u-boot可能采用make 开发板名字_config来进行
- 编译uboot
  `make --j4`
- 注意后面的j4是使用4个cpu编译，加快速度。
- qemu仿真
  `qemu-system-arm -M vexpress-a9 -m 512M -nographic -kernel u-boot`
- -M 表示Machine，机器，这里指开发板
- -m表示memory，表示虚拟运行内存大小
- -nographic表示不需要图形界面
- -kernel表示运行的镜像