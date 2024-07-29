### uboot使用
- 清除上一次使用uboot生成的所有文件，包括配置文件、镜像文件
`make distclean`
- 配置ARCH(架构)为arm、CROSS_COMPILE(交叉编译器)为arm-linux-gnueabi-，两种方法
   - 直接配置Makefile文件，在文件里面找到ARCH ?=、CROSS_COMPILE ?=，改成ARCH ?=arm、CROSS_COMPILE ?=arm-linux-gnueabi-
   - 每次编译时都传参数进去，make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- 选项
- 配置开发板信息，不同开发板有不同的uboot、linux系统配置
  - 如果是采用上面的1方法直接配置文件架构和交叉编译器的，直接：
  `make 开发板名字_defconfig`
  - 注意旧版的u-boot可能采用make 开发板名字_config来进行
- 编译uboot
  `make --j4`
- 注意后面的j4是使用4个cpu编译，加快速度。