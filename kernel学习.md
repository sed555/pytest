### kernel学习
- 修改Makefile文件里的ARCH、CROSS_COMPILE
`ARCH            ?= $(SUBARCH)`
- 改成
`ARCH            ?= arm`
- 对于
  `CROSS_COMPILE   ?= $(CONFIG_CROSS_COMPILE:"%"=%)`
- 改成
  `CROSS_COMPILE   ?= arm-linux-gnueabi-`
-配置开发板信息
`make vexpress_defconfig`
- 制作镜像
  `make zImage`
- 注意I是大写
- 如果有报错，编译Linux内核出现：usr/bin/ld: scripts/dtc/dtc-parser.tab.o:(.bss+0x50): multiple definition of `yylloc’; scripts/dtc/dtc-lexer.lex.o:(.bss+0x0): first defined here
- 解决办法
`修改scripts/dtc目录下的dtc-lexer.lex.c_shipped文件中找到
YYLTYPE yyloc这一行，在640行，在之前面加上extern 
保存退出，
make 编译 
正常编译 `
- 编译模块
  `make modules`
- 编译dtbs，这个是开发板配置的文件，内核是通用的。
- 在arch/arm/boot路径下生成了zImage镜像文件
- 在arch/arm/boot/dts下生成了vexpress-v2p-ca9-dtb文件
- qemu-system-arm -M vexpress-a9 -m 521M -kernel arch/arm/boot/zImage -dtb arch/arm/boot/dts/vexpress-v2p-ca9.dtb -nographic -append "console=ttyAMA0"
- 因为没挂载文件系统，所以要卡住。