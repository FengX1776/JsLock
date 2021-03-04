#include <Windows.h>
#include "Detours.hpp"
#include <string>
#include <vector>

/*

 - - - - - - - - - - - - - - - - - - - - - - - - - - - 
|													  |
|	ExtremeBlackLiu		JsLock						  |
|													  |
 - - - - - - - - - - - - - - - - - - - - - - - - - - - 

	-	-	-	- 你知道我是谁,2021.	-	-	-	-

P.S
往控制台打印文本已经是很低级的东西了,我建议你应该自己完成.
无论你是复制粘贴出售又或者是拿去炫耀自己的结果,不要忘记原作者
我通常不建议你用这个异或的方式去加解密,因为已经不安全.
另外,不要笑那个硬编码,这只是第一个版本

---------------------------------------------------------------------------------------------
							题外话:
这里嘲讽一下我们的出参大神 东哥
大号被MC圈子挂云黑，所以现在你们看他的号很干净，因为是小号，之前他跟wiki起冲突Wiki都没查到他q绑。
因为莫心看不起我而把我换下来把东哥换上去。
实际上你们也可以看到，东哥的东西质量都不咋地，LauncherSU 0.5.8的源码泄露在莫心的内部群
因此东哥实际上从旧版的LauncherSU复制粘贴了不少东西，另外我要嘲笑他，Js锁就这么简单的东西还琢磨不透
不过也是，技术很差但是喜欢装的人多了去了，我只是懒得理他。我猜东哥看到Js锁开源之后又要复制粘贴一个"东哥锁"了吧
期待你的作品，xddddd
黑历史莫心多了去了，其实我一直都不傻，只是装作跟莫心装不知道而已，人人都有心机
这里也懒得说了，过去的都过去了，不过还是得列出一条没影响到多数人的，免得又说我吹牛逼了
就是wish当时好像确实只给莫心供应邀请码，但是你知道，垄断的后果吗？
没错，莫心疯了一样，把邀请码提到4000块钱，因为他垄断了，除了他以外没有人知道价格其实还是2000多块钱没有涨(真的是除他以外，当时连我也不知道)
不过后面他自己在他内部群说漏嘴，说他给别人返现600自己还有赚1000块钱，所以被我知道了，这个秘密基本上没有几个人知道。
说实话，我现在倒是希望东哥继续跟莫心干，死得快那是杠杠的xdddd
现在其实还有很多旧的人在老群里面什么也不知道，被蒙在鼓里，不过我也不在乎那些人。
----------------------------------------------------------------------------------------------
总之，不聊那么多题外话，你们可以在github上pull request来改进，我看到我会处理的。
或者是自己下载并改进代码,这里拥有完好可运行的框架,实际上写的有点垃圾,因为这是第一个版本,写的比较急促
只需要你做一些反调试啊，反解密啊，混淆啊，模块隐藏啊，等等...你想做的都可以做
可惜shellcode没法和vmp兼容，不然就上vmp壳子了。另外这里还有很多注释，非常容易看懂

*/

typedef FILE*(fopen_or)(const char* path, const char* way); //先把要call的函数定义了
typedef size_t(fread_or)(void*, size_t, size_t, FILE*);	//同上
fopen_or* o_fopen; //用于call的函数指针
fread_or* o_fread; //同上
bool isjs = false; //判断是不是js

DWORD getfun(const char* modulename,const char* funname) //一个简单的取模块函数
{
    HMODULE mo = GetModuleHandleA(modulename); //先取模块句柄
    if (!mo) //没有加载这个模块?
    {
        mo = LoadLibraryA(modulename); //那就我来加载
    }
    return (DWORD)GetProcAddress(mo,funname); //返回的时候强制转换一下，没有人喜欢用windows.h那个FARPROC
}

const char* js_filename; //js的文件名带目录

size_t hk_fread(void* buffer, size_t size, size_t count, FILE* stream)//hook 后的 fread
{
    size_t bRet;
    if (isjs)
    {
        static char buffer_[100000];    //不要在意硬编码,这是我们的缓冲区
        
        bRet = o_fread(buffer_, size, count, stream);  //先读到文件,然后文件内容会到缓冲区里面
        
        std::string abc;	//string在这里比const char*管用,const char*是指向一串字符串的指针,而string是一个类
        for (int i : buffer_) //
        {
            i = i ^ 0x6;				//简单的异或解密
            abc.push_back(i);			//把解密后的单个字符串加入到abc里面
        }


        const char* decoded = abc.c_str(); //取abc的字符串指针,赋值给decoded

        memcpy(buffer, decoded, size);	//把buffer复制给onetap 然后onetap就会收到解密后的js了
    }
    else
    {
        bRet = o_fread(buffer,size,count,stream); //如果不是js? 放行
    }
    return bRet;
}

FILE* hk_fopen(const char* path,const char* mode) //hook后的fopen
{
    const char* FG = strrchr(path, '.'); //分割文本
    if (FG != NULL)
    {
        if (_strcmpi(FG, ".js") == 0) //比较是否是js文件
        {
            isjs = true;//是js文件，我们就赋值个true
            js_filename = path; //把目录复制一下
        }
        else
        {
            isjs = false; //不是就赋值false
            js_filename = "";//清空目录
        }
		//其实这里可以简化的,但是为了更好的阅读我还是用了if else
    }
    return o_fopen(path, mode);//调用原函数并返回
}


void setup_hook() //初始化hook
{
    DWORD fopen = getfun("ucrtbase.dll", "fopen"); //取函数地址
    DWORD fread = getfun("ucrtbase.dll", "fread"); //同上

    o_fopen = (fopen_or*)(DetourFunction((PBYTE)fopen, (PBYTE)hk_fopen)); //detour函数(hook)
    o_fread = (fread_or*)(DetourFunction((PBYTE)fread, (PBYTE)hk_fread));//同上
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)setup_hook, 0, 0, 0); //创建线程好点,起码不会卡住csgo
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

