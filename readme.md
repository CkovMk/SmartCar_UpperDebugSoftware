# 智能车调试上位机

by: C.M.



## 移植说明

该项目需要Visual Studio、Qt5、OpenCV4。

Qt版本是Qt5.13 Community，可以从Qt官网注册后免费下载安装。

OpenCV版本是OpenCV 4.10。



首先安装Qt。仅安装MSVC2017 x64支持即可。由于从openCV2的某个版本起，openCV不再提供32位二进制文件，如想使用必须自行编译，这里只能使用64位文件。这样一来，同一份代码再电脑上跑时为64位，在单片机上跑为32位，可能造成一些兼容性问题，编写代码时须特别注意。后期如有必要，可以考虑切换为32位版本。因此这里x86支持亦可一并安装。

随后安装Visual Studio Community 2019，仅安装C++支持即可。安装完成后进入VS扩展商店页面，安装Qt VS Tools。重启VS，在Qt VS Tools内设置Qt路径。

安装OpenCV4.10。解压文件至`C:\OpenCV410`并添加至系统环境变量。无需对VS进行设置。如果文件放在其他位置，则需要对VS工程进行配置。

最后Clone此Repo，直接打开VS工程即可。选择x64 Debug 或 ReleaseO2编译。Release选项无效。