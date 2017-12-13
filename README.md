# dvbinfoForAndroid
### 简介

dvbinfo是libdvbpsi工程中的一个demo程序，如果想学习libdvbpsi的使用，那么它就是一个不错的切入点。我的另一个工程<https://github.com/xugaoxiang/libdvbpsiForAndroid>已经实现了libdvbpsi在android系统中的编译，dvbinfo依赖于libdvbpsi.

### Android版本的编译

将源码拷贝到android源码树的external目录下

```
cd $android
git clone https://github.com/xugaoxiang/dvbinfoForAndroid.git external/dvbinfo
source build/envsetup.sh
mmm external/dvbinfo
```

模块编译完毕后，会生成out/target/product/$芯片厂家/system/bin/dvbinfo, 然后执行

```
make snod
```

重新生成system.img镜像文件